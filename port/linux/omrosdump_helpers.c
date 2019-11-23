/*******************************************************************************
 * Copyright (c) 1991, 2015 IBM Corp. and others
 *
 * This program and the accompanying materials are made available under
 * the terms of the Eclipse Public License 2.0 which accompanies this
 * distribution and is available at https://www.eclipse.org/legal/epl-2.0/
 * or the Apache License, Version 2.0 which accompanies this distribution and
 * is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * This Source Code may also be made available under the following
 * Secondary Licenses when the conditions for such availability set
 * forth in the Eclipse Public License, v. 2.0 are satisfied: GNU
 * General Public License, version 2 with the GNU Classpath
 * Exception [1] and GNU General Public License, version 2 with the
 * OpenJDK Assembly Exception [2].
 *
 * [1] https://www.gnu.org/software/classpath/license.html
 * [2] http://openjdk.java.net/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH
 *Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
 *******************************************************************************/

/**
 * @file
 * @ingroup Port
 * @brief Dump formatting
 */

#include <sys/mman.h>
#include <sys/param.h>
#include <sys/stat.h>
#if defined(LINUX)
#include <sys/prctl.h>
#include <sys/resource.h>
#endif
#include <ctype.h>
#include <dirent.h>
#include <elf.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#include "omrosdump_helpers.h"
#include "portnls.h"

#define MAX_PTR_SIZE_BYTES 8

static intptr_t waitCore(char *path);
static void
setChecksumMarkAllPagesWritableHeader(MarkAllPagesWritableHeader *header);
static char linuxMemoryMapsFile[] = "/proc/self/maps";
static uintptr_t
getSharedAndPrivateDataSegments(struct OMRPortLibrary *portLibrary, intptr_t fd,
                                uintptr_t addrSize, uint8_t **ppStart,
                                uint8_t **ppEnd);

static uintptr_t readElfHeader(struct OMRPortLibrary *portLibrary, intptr_t fd,
                               Elf64_Ehdr *pElfheader);
static uintptr_t findProgramHeader(struct OMRPortLibrary *portLibrary,
                                   intptr_t fd, uintptr_t addrSize,
                                   Elf64_Off phoff, Elf64_Half phnum,
                                   uint8_t *start, uint8_t *end);
static void copyDataIntoELFCore(struct OMRPortLibrary *portLibrary,
                                intptr_t fd_core, uintptr_t addrSize,
                                Elf64_Off phoff);
static intptr_t
getContentsFromProcFileSystem(struct OMRPortLibrary *portLibrary,
                              const char *fileName, char *buffer,
                              size_t buflen);
static void
insertSharedAndPrivateDataSegments(struct OMRPortLibrary *portLibrary,
                                   char *corePath);
static intptr_t deriveCoreFileName(struct OMRPortLibrary *portLibrary,
                                   char *corePatterFormat, BOOLEAN coreUsesPID,
                                   char *baseDir, char *derivedCoreFileName,
                                   uintptr_t derivedCoreFileNameLen, pid_t pid,
                                   int signalNumber);

#ifdef DUMP_DBG
static void printMemoryMap(struct OMRPortLibrary *portLibrary,
                           uintptr_t addrSize);
static void printProgramHeader(struct OMRPortLibrary *portLibrary,
                               uintptr_t addrSize, void *pelfPgmHdr,
                               uintptr_t count);
static void printProgramHeaders(struct OMRPortLibrary *portLibrary, intptr_t fd,
                                uintptr_t addrSize, Elf64_Off phoff,
                                Elf64_Half phnum);
#endif

/* @internal
 *
 * @param[in]	fileName	absolute path of name of file to open
 * @param[out]	buffer		user allocated buffer to write contents to
 * @param[in]	bufLen		the size of @ref buffer.
 *
 * @return:
 *	1 file does not exist
 *	0 file exists and buffer contains the contents.
 *	negative value on error (in which case there was a problem looking for
 *or opening the file).
 */
static intptr_t
getContentsFromProcFileSystem(struct OMRPortLibrary *portLibrary,
                              const char *fileName, char *buffer,
                              size_t buflen) {

  J9FileStat j9fstat;
  int32_t j9fstatRc;
  intptr_t fd;

  buffer[0] = '\0';
  j9fstatRc = portLibrary->file_stat(portLibrary, fileName, 0, &j9fstat);
  if (0 == j9fstatRc) {
    if (0 == j9fstat.isFile) {
      /* file does not exist */
      return 1;
    } else {
      /* file exists */
      fd = portLibrary->file_open(portLibrary, fileName, EsOpenRead, 0);

      if (fd != -1) {
        intptr_t bytesRead;

        bytesRead = portLibrary->file_read(portLibrary, fd, buffer, buflen);

        if (bytesRead != -1) {
          /* we've read the contents of the file */
          return 0;
        }
      }
    }
  }

  return -1;
}

/*
 * @internal
 *
 * Figures out what the system core file name that was generated by the child
 * process will be according to man core{5}, then renames it to @ref filename.
 *
 *  Note that the %t token in core_pattern is not supported.
 *
 *  If @ref filename is an empty string, renameDump writes in the name of the
 * OS-generated core file.
 *
 * @param[in]
 * @param[in]	filename	user-allocated buffer of size EsMaxPath
 * containing the desired core filename
 * @param[out]	filename	on success, the name of the generated core file,
 * otherwise, the error message
 * @param[in]	pid			pid of process that generated the core
 * file.
 *
 * @return 0 on success, otherwise non-zero and @ref filename contains error
 * message.
 *
 * @note: This relies on the child process having created the core file in the
 * directory specified by @ref filename,
 * or the cwd if @ref filename was empty. */
uintptr_t renameDump(struct OMRPortLibrary *portLibrary, char *filename,
                     pid_t pid, int signalNumber) {
  char tempPath[PATH_MAX];
  char corePatternFormat[PATH_MAX];
  char coreUsesPIDBuffer[PATH_MAX];
  char derivedAbsoluteCorePath[PATH_MAX];
  const char *corePatternFileName = "/proc/sys/kernel/core_pattern";
  const char *coreUsesPIDFileName = "/proc/sys/kernel/core_uses_pid";
  BOOLEAN coreUsesPID = FALSE;
  intptr_t procRC = -1;
  intptr_t waitCoreRC = -1;
  char *lastSep;
  intptr_t createCoreFileNameRC;
  intptr_t renameRC = -1;
  struct stat attrBuf;

  memset(corePatternFormat, 0, sizeof(corePatternFormat));

  procRC = getContentsFromProcFileSystem(portLibrary, corePatternFileName,
                                         corePatternFormat, PATH_MAX);
  if (0 == procRC) {
    /* corePatternFormat contains format, strip out the '\n' */
    char *newLine = strchr(corePatternFormat, '\n');
    if (NULL != newLine) {
      *newLine = '\0';
    }
    if ('|' == corePatternFormat[0]) {
      /*
       * core pattern is being used to pipe the core file to a tool such as
       * ABRT. In this case, the file is in core.<pid>
       */
      portLibrary->nls_printf(portLibrary, J9NLS_WARNING | J9NLS_STDERR,
                              J9NLS_PORT_LINUXDUMP_PIPE_CORE,
                              corePatternFileName, corePatternFormat, pid);
      strncpy(corePatternFormat, "core", PATH_MAX);
    }
  } else if (1 == procRC) {
    /* corePatternFileName does not exist (it should be there from kernel 2.5
     * onwards), use the default core file name */
    strncpy(corePatternFormat, "core", PATH_MAX);
  } else {
    /* there was an error opening corePatternFileName */
    portLibrary->str_printf(portLibrary, filename, EsMaxPath,
                            "Error opening \"%s\". Look for core file "
                            "generated by child process with pid = %i",
                            corePatternFileName, pid);
    return 1;
  }

  procRC = getContentsFromProcFileSystem(portLibrary, coreUsesPIDFileName,
                                         coreUsesPIDBuffer, PATH_MAX);
  if (0 == procRC) {
    /* coreUsesPIDBuffer contains ascii representation of 0 or non-zero value */
    if (0 != atoi(coreUsesPIDBuffer)) {
      coreUsesPID = TRUE;
    }
  } else if (1 == procRC) {
    /* coreUsesPIDFileName does not exist, we should not get here */
  } else {
    /* there was an error opening coreUsesPIDFileName */
    portLibrary->str_printf(portLibrary, filename, EsMaxPath,
                            "Error opening \"%s\". Look for core file "
                            "generated by child process with pid = %i",
                            coreUsesPIDFileName, pid);
    return 1;
  }

  /* determine base directory */
  lastSep = filename ? strrchr(filename, DIR_SEPARATOR) : NULL;
  if (NULL != lastSep) {
    /* filename was an absolute path: strip it down to the directory name, make
     * sure to preserve the trailing front slash */
    size_t charsToCopy = lastSep - filename + 1;

    strncpy(tempPath, filename, charsToCopy);
    tempPath[charsToCopy] = '\0';
  } else {
    *tempPath = '\0';
  }

  /* If we got here there were no errors getting the contents of core_pattern
   * and core_uses_pid */
  createCoreFileNameRC =
      deriveCoreFileName(portLibrary, corePatternFormat, coreUsesPID, tempPath,
                         derivedAbsoluteCorePath, PATH_MAX, pid, signalNumber);

  if (0 != createCoreFileNameRC) {
    /* we could not derive the name from core_pattern */
    portLibrary->str_printf(
        portLibrary, filename, EsMaxPath,
        "Unable to derive system core filename from pattern in %s: \"%s\". "
        "%s"
        " Look for core file generated by child process with pid = %i",
        corePatternFileName, corePatternFormat, derivedAbsoluteCorePath, pid);
    return 1;
  }

  /* wait until the core file is created, or timeout */
  waitCoreRC = waitCore(derivedAbsoluteCorePath);
  if (0 != waitCoreRC) {
    /* the core file does not exist, bail */
    portLibrary->str_printf(
        portLibrary, filename, EsMaxPath,
        "The core file created by child process with pid = %i was not found. "
        "Expected to find core file with name \"%s\"",
        pid, derivedAbsoluteCorePath);
    return 1;
  }

  /* at this point we know the file in derivedCorePath exists */

#ifdef DUMP_DBG
  {
    /* In the parent process, check that the coredump_filter is not present on
     * this system. If it is, then the child process will have set it to force
     * the automatic inclusion of the shared classes cache. In that case we need
     * do nothing. If the file is not present then go forth and copy the
     * unmapped shared cache segments into the core file.
     */
    intptr_t filter = portLibrary->file_open(
        portLibrary, "/proc/self/coredump_filter", EsOpenRead, 0);
    if (filter != -1) {
      portLibrary->file_close(portLibrary, filter);
      portLibrary->tty_err_printf(portLibrary,
                                  "found /proc/self/coredump_filter\n");
    } else {
      portLibrary->tty_err_printf(portLibrary,
                                  "didn't find /proc/self/coredump_filter\n");
    }
  }
#endif

  /* Check that the path we found was to a regular file (not to an existing
   * directory, pipe, symlink etc) */
  if (stat(derivedAbsoluteCorePath, &attrBuf) == 0) {
    if (!S_ISREG(attrBuf.st_mode)) {
      portLibrary->nls_printf(portLibrary, J9NLS_ERROR | J9NLS_STDERR,
                              J9NLS_PORT_DUMP_PATH_EXISTS,
                              derivedAbsoluteCorePath);
      return 1;
    }
  } else {
    portLibrary->str_printf(
        portLibrary, filename, EsMaxPath,
        "Unable to read file status for core file path \"%s\"",
        derivedAbsoluteCorePath);
    return 1;
  }

  /* In all cases, attempt to insert the extra segments of memory needed for a
   * complete core file image. The insertion process should only add memory
   * segments that have a program header, but no data in the core file itself.
   */
  insertSharedAndPrivateDataSegments(portLibrary, derivedAbsoluteCorePath);

  /* Rename the file as required by the specified (or default) -Xdump agent file
   * option */
  if (filename[0] != '\0') {
    renameRC = rename(derivedAbsoluteCorePath, filename);

    if ((0 != renameRC) &&
        (errno == EXDEV)) { /* failed with 'cross device rename error' */
      memset(tempPath, 0, PATH_MAX);
      /* we retry leaving the dump directory location unchanged */
      lastSep = strrchr(derivedAbsoluteCorePath, DIR_SEPARATOR);
      if (NULL != lastSep) {
        size_t charsToCopy = lastSep - derivedAbsoluteCorePath + 1;
        strncpy(tempPath, derivedAbsoluteCorePath, charsToCopy);
      }
      /* using the dump agent requested file name */
      lastSep = strrchr(filename, DIR_SEPARATOR);
      if (NULL != lastSep) {
        strcat(tempPath, lastSep + 1);
      } else {
        strcat(tempPath, filename);
      }
      /* message warning that the -Xdump option was not fully honoured */
      portLibrary->tty_printf(
          portLibrary,
          "Warning: unable to move dump to \"%s\" across file systems (check "
          "kernel core_pattern). Using alternate file location \"%s\"\n",
          filename, tempPath);
      /* copy the new file destination back into the supplied filename for the
       * RAS messages */
      strncpy(filename, tempPath, EsMaxPath);
      renameRC = rename(derivedAbsoluteCorePath, filename);
    }

    if (0 != renameRC) {
      portLibrary->tty_printf(
          portLibrary,
          "Attempt to rename \"%s\" to \"%s\" failed with error: %s\n",
          derivedAbsoluteCorePath, filename, strerror(errno));
      return 1;
    }

  } else {
    /* filename was empty */
    strncpy(filename, derivedAbsoluteCorePath, EsMaxPath);
  }

  return 0;
}

/*
 * @internal Parse the corePatternString following the rules from the linux man
 * pages, replace the tokens and store the resulting absolute path core file in
 * corePath.
 *
 * If corePatterFormat does not contain %p and coreUsesPID is TRUE, append the
 * PID to the formatted core file name.
 *
 * If corePatternString does not specify an absolute path and and baseDir is not
 * empty, use the absolute path in baseDir as the base directory for the core
 * file.
 *
 * 		%%  A single % character
 * 		%p  PID of dumped process
 * 		%u  real UID of dumped process
 * 		%g  real GID of dumped process
 * 		%s  number of signal causing dump
 * 		%t  time of dump (seconds since 0:00h, 1 Jan 1970)
 * 		%h  hostname (same as 'nodename' returned by uname(2))
 * 		%e  executable filename
 *
 * 	Note: We cannot determine the exact time of the dump, as set by the OS.
 * If we find a %t token, and %p is also specified, we use a wildcard to obtain
 * a filename match. The child process PID provides reasonable confidence that
 * we will find the correct dump. Otherwise return failure. Note: From the man
 * pages: "A single % at the end of the template is dropped from the core
 * filename, as is the combination of a % followed by any character other than
 * those listed above."
 *
 * If we cannot reasonably infer what the fileName should be, return -1
 *
 * @param[in] corePatternFormat the null-terminated string, with no line
 * delimiters, representing the format of the core file name.
 * 									- if there was no core_pattern
 * file, corePatternFormat should be empty string.
 * @param[in] coreUsesPID		TRUE indicates that core_uses_pid indicated
 * that the PID should be appended to the filename
 * @param[in] baseDir			the null-terminated string indicating the
 * absolute path (with trailing dir separator) of the base directory to use if
 * corePatternFormat does not specify an absolute path.
 * 									- should be empty string if no
 * baseDirectory was specified.
 *
 * @param[out] derivedCoreFileName user-allocated buffer containing the
 * constructed absolute path.
 * 					- derivedCoreFileName will always contain a
 * null-terminated string.
 * 					- On success, derivedCoreFileName contains the name
 * of the core file.
 * 					- On failure, derivedCoreFileName contains a message
 * detailing the cause.
 * @param[in]	corePathLen	the size of the buffer @ref corePath.
 * @param[in]	pid	the process ID of the child process that triggered the
 * core file generation.
 */
static intptr_t deriveCoreFileName(struct OMRPortLibrary *portLibrary,
                                   char *corePatterFormat, BOOLEAN coreUsesPID,
                                   char *baseDir, char *derivedCoreFileName,
                                   uintptr_t derivedCoreFileNameLen, pid_t pid,
                                   int signalNumber) {
  char *inCursor = corePatterFormat;
  char *outCursor = derivedCoreFileName;
  BOOLEAN corePatternSpecifiesPercentP = FALSE;
  int numWildcards = 0;
  intptr_t charsPrinted;
  char scratchSpace[PATH_MAX];

  while ('\0' != *inCursor) {
    uintptr_t bytesLeft =
        derivedCoreFileNameLen - (outCursor - derivedCoreFileName);
    charsPrinted = 0;

    switch (*inCursor) {
    case '%':
      inCursor++;
      switch (*inCursor) {
      case '%':
        /* literal '%' */
        charsPrinted =
            portLibrary->str_printf(portLibrary, outCursor, bytesLeft, "%%");
        break;
#if defined(LINUX)
      case 'c': {
        struct rlimit limit = {0};
        int rc = getrlimit(RLIMIT_CORE, &limit);
        if (-1 == rc) {
          portLibrary->str_printf(portLibrary, derivedCoreFileName, PATH_MAX,
                                  "%s", "Failed to obtain core limit");
          return -1;
        }
        charsPrinted = portLibrary->str_printf(
            portLibrary, outCursor, bytesLeft, "%lu", limit.rlim_cur);
      } break;
      case 'd': {
        int dumpableFlag = prctl(PR_GET_DUMPABLE, scratchSpace);
        if (0 > dumpableFlag) {
          charsPrinted = portLibrary->str_printf(portLibrary, outCursor,
                                                 bytesLeft, "%d", dumpableFlag);
        } else {
          portLibrary->str_printf(portLibrary, derivedCoreFileName, PATH_MAX,
                                  "%s", "Failed to obtain dumpable flag");
          return -1;
        }
      } break;
      case 'P':
        charsPrinted = portLibrary->str_printf(portLibrary, outCursor,
                                               bytesLeft, "%s", "*");
        ++numWildcards;
        break;
      case 'E': {
        char *pathSep = NULL;
        int readlinkRc = readlink("/proc/self/exe", scratchSpace, PATH_MAX);

        if (-1 == readlinkRc) {
          portLibrary->str_printf(portLibrary, derivedCoreFileName, PATH_MAX,
                                  "readlink() on \"/proc/self/exe\" failed: %s",
                                  scratchSpace, strerror(errno));
          return -1;
        }
        scratchSpace[readlinkRc] = '\0';

        pathSep = strchr(scratchSpace, DIR_SEPARATOR);
        while (NULL != pathSep) {
          *pathSep = '!';
          pathSep = strchr(pathSep, DIR_SEPARATOR);
        }
        charsPrinted = portLibrary->str_printf(portLibrary, outCursor,
                                               bytesLeft, "%s", scratchSpace);
      } break;
      case 'I':
        charsPrinted = portLibrary->str_printf(portLibrary, outCursor,
                                               bytesLeft, "%s", "*");
        ++numWildcards;
        break;
#endif
      case 'i':
        /* Forked process will have only 1 thread, thus TID == PID */
        /* Intentionall fall through */
      case 'p':
        corePatternSpecifiesPercentP = TRUE;
        charsPrinted = portLibrary->str_printf(portLibrary, outCursor,
                                               bytesLeft, "%i", pid);
        break;
      case 'u':
        charsPrinted =
            portLibrary->str_printf(portLibrary, outCursor, bytesLeft, "%u",
                                    portLibrary->sysinfo_get_euid(portLibrary));
        break;
      case 'g':
        charsPrinted =
            portLibrary->str_printf(portLibrary, outCursor, bytesLeft, "%u",
                                    portLibrary->sysinfo_get_egid(portLibrary));
        break;
      case 's':
        charsPrinted = portLibrary->str_printf(portLibrary, outCursor,
                                               bytesLeft, "%i", signalNumber);
        break;
      case 'h':
        if (-1 != gethostname(scratchSpace, PATH_MAX)) {
          charsPrinted = portLibrary->str_printf(portLibrary, outCursor,
                                                 bytesLeft, "%s", scratchSpace);
          break;
        } else {
          portLibrary->str_printf(portLibrary, derivedCoreFileName, PATH_MAX,
                                  "%s", "Failed to obtain hostname");
          return -1;
        }
      case 'e':
#if defined(LINUX)
#ifndef PR_GET_NAME
#define PR_GET_NAME 16
#endif
        /* thread name is at most 16 bytes long, in which case it is not
         * null-terminated. */
        if (prctl(PR_GET_NAME, scratchSpace) >= 0) {
          /*
           * the function is supported and succeeded.
           * scratchSpace contains the thread name, which is null terminated if
           * shorter than 16 bytes.
           */
          scratchSpace[16] = '\0'; /* ensure the name is terminated by a null if
                                      it is exactly 16 bytes long */
          charsPrinted = portLibrary->str_printf(portLibrary, outCursor,
                                                 bytesLeft, "%s", scratchSpace);
        } else
#endif
        {
          char *lastSep, *startExeName;
          int readlinkRc = readlink("/proc/self/exe", scratchSpace, PATH_MAX);

          if (-1 == readlinkRc) {
            portLibrary->str_printf(
                portLibrary, derivedCoreFileName, PATH_MAX,
                "readlink() on \"/proc/self/exe\" failed: %s", scratchSpace,
                strerror(errno));
            return -1;
          }
          scratchSpace[readlinkRc] = '\0';
          lastSep = strrchr(scratchSpace, DIR_SEPARATOR);
          if (NULL == lastSep) {
            startExeName = scratchSpace;
          } else {
            startExeName = lastSep + 1;
          }
          charsPrinted = portLibrary->str_printf(portLibrary, outCursor,
                                                 bytesLeft, "%s", startExeName);
        }
        break;
      case 't':
        charsPrinted = portLibrary->str_printf(portLibrary, outCursor,
                                               bytesLeft, "%s", "*");
        ++numWildcards;
        break;
      default:
        /* unknown token, skip */
        charsPrinted = 0;
      }
      break;
    default:
      *outCursor = *inCursor;
      charsPrinted = 1;
    }
    outCursor = outCursor + charsPrinted;
    inCursor++;
  }
  *outCursor = '\0';

  if ((0 < numWildcards) && !corePatternSpecifiesPercentP) {
    /* no PID in the filename, indicate unsupported dump pattern and bail out*/
    portLibrary->str_printf(
        portLibrary, derivedCoreFileName, PATH_MAX, "%s",
        "\"%t\",\"%P\",\"%I\"  specifiers are not supported without \"%p\".");
    return -1;
  }

  if (1 < numWildcards) {
    portLibrary->str_printf(
        portLibrary, derivedCoreFileName, PATH_MAX, "%s",
        "only one instance of \"%t\",\"%P\", or\"%I\"  is supported.");
    return -1;
  }

  /* do we need to append with the PID? */
  if (!corePatternSpecifiesPercentP && coreUsesPID) {
    charsPrinted = portLibrary->str_printf(
        portLibrary, outCursor,
        derivedCoreFileNameLen - (outCursor - derivedCoreFileName), ".%i", pid);
    /*outCursor = outCursor + charsPrinted;*/
  }

  /* if derivedCoreFileName does not specify an absolute path, use the one
   * provided in baseDir (if there is one)
   * 	- check for directory separator in derivedCoreFileName */
  if (NULL == strchr(derivedCoreFileName, '/')) {
    if (0 != strlen(baseDir)) {
      strncpy(scratchSpace, baseDir, PATH_MAX);
      strncat(scratchSpace, derivedCoreFileName,
              PATH_MAX - (strlen(scratchSpace) + 1));
      strncpy(derivedCoreFileName, scratchSpace, PATH_MAX);
    }
  }

  return 0;
}

/**
 * Wait for the core dump file to be written..
 *
 * @param[in] path	absolute path of the expected core file, null
 *terminated, maximum length including null is PATH_MAX. the filename portion of
 *the path may contain a single '*' wildcard.
 *
 * @return intptr_t	0 if the file was found, otherwise 1 indicating timeout
 *while looking for the file
 *
 */
static intptr_t waitCore(char *path) {
  int rc = 1;
  time_t starttime;
  FILE *fd;
  starttime = time(NULL);
  char *wildcardPos = strchr(path, '*'); /* position of '*' wildcard, if any, in
                                            the expected core dump filename */

  if (NULL == wildcardPos) {
    /* Normal case, no wildcard in the dump filename. Wait for the expected dump
     * file to appear, using fopen() to check whether the file exists.
     */
    while (0 != rc) {
      fd = fopen(path, "r");
      if (NULL == fd) {
        /* could not open the file */
        rc = 1;
        if (difftime(time(NULL), starttime) > 5) {
          break;
        }
        usleep(100000);
      } else {
        /* opened the file successfully, so we know it exists, now close it */
        fclose(fd);
        rc = 0;
      }
    }
  } else {
    /* Special case, wildcard in the dump filename. Wait for the expected dump
     * file to appear, listing files in the core dump directory to look for a
     * file name that matches the expected core dump name.
     */
    char *pathSeparator =
        strrchr(path, DIR_SEPARATOR); /* locate the end of the directory path */
    if (NULL == pathSeparator) {
      return rc; /* error, we should have an absolute path, bail out */
    }
    *pathSeparator =
        '\0'; /* truncate the path at the end of the last directory */
    *wildcardPos =
        '\0'; /* also truncate the core dump file name at the wild card */

    while (0 != rc) {
      struct dirent *entry = NULL;
      /* Open the directory in which we expect to find the core dump */
      DIR *coreDirectory = opendir(path);
      if (NULL == coreDirectory) {
        break; /* error, we should have a good directory path, bail out */
      }

      /* Search the directory for a matching file */
      while (NULL != (entry = readdir(coreDirectory))) {
        char *filename = entry->d_name;
        /* Check for a match for both halves of the expected core dump file name
         */
        if (strstr(filename, pathSeparator + 1) &&
            strstr(filename, wildcardPos + 1)) {
          /* Good match, fix up the supplied core dump file name using the
           * actual file name */
          if (strlen(path) + strlen(filename) + 2 <=
              PATH_MAX) { /* overflow check */
            strcpy(pathSeparator + 1, filename);
            rc = 0; /* success */
          }
          break;
        }
      }
      closedir(coreDirectory);

      /* If no matching file name was found, loop and repeat until timeout */
      if (0 != rc) {
        if (difftime(time(NULL), starttime) > 5) {
          break; /* timeout */
        }
        usleep(100000);
      }
    }
    *pathSeparator = DIR_SEPARATOR; /* restore the path separator */
    if (0 != rc) {
      *wildcardPos = '*'; /* restore the wildcard character, on failure only */
    }
  }
  return rc;
}

static void
setChecksumMarkAllPagesWritableHeader(MarkAllPagesWritableHeader *header) {
  void *end_ptr = (void *)(header + 1);
  int32_t sum = 0;
  int32_t *ptr = (int32_t *)header;
  header->checksum = 0;
  while ((void *)ptr < end_ptr) {
    sum ^= *ptr++;
  }
  header->checksum = sum;
}

/**
 * @internal  read /proc/self/maps to determine what pages are mapped for this
 * process. Modify each page to be writable. This will cause it to be included
 * in core dumps.
 *
 * The format of /proc/self/maps is:
 *   40000000-40013000 r-xp 00000000 03:03 1161002    /lib/ld-2.2.5.so
 *   40013000-40014000 rw-p 00013000 03:03 1161002    /lib/ld-2.2.5.so
 *   40014000-40016000 rw-p 00000000 00:00 0
 * ...
 *
 * This implementation expects the format to be strictly conformed to.
 * If deviations in the format are discovered, we'll have to make this routine
 * more robust.
 *
 * See also CMVC 107677. On Linux 2.6, using mprotect while reading
 * /proc/self/maps can cause the contents of the file to change beneath us.
 * In particular, consecutive identical entries can be coalesced. To avoid this
 * we make multiple passes over the file. We stop when we no longer discover
 * any pages that can be modified or when we've made log2(n) passes,
 * where n is the number of pages. At worst we'll miss less than half of the
 * pages on each pass, so log2(n) is the upper bound on the number of passes.
 *
 * CMVC 128452 Where we are running a JVM compiled as a 32 bit application
 * on a 64 bit linux, the buffer for reading data from /proc/self/maps was too
 * short. Its length has now been increased to accomodate the wider data. On 32
 * bit the minimum line length is sufficient to allow us to read more than we
 * need.
 *
 * CMVC 150400: As this is in a linux child process, only the failing thread
 * will have been maintained. Any locks taken by other threads cannot be
 * unlocked by this one. Hence the use of native file IO in markAllPagesWritable
 * to avoid the mutex in memory check and a potential hang.
 */

char *markAllPagesWritable(struct OMRPortLibrary *portLibrary) {
  BOOLEAN modified = TRUE;
  uintptr_t log2N = (sizeof(void *) * 8) - 12; /* assume 4096 byte pages */
  uintptr_t pass;

  MarkAllPagesWritableHeader *buffer =
      (MarkAllPagesWritableHeader *)portLibrary->portGlobals->procSelfMap;

  /* Record proc/self/maps file into the pre-allocated buffer before changing
   * the pages to writable */
  /* Nothing should be changing any more as this fork is frozen and will die */

  /* CMVC 150400 We are using native file io calls here to avoid the mutex in
   * the memcheck library. */
  if (buffer != NULL) {
    FILE *fd = fopen(linuxMemoryMapsFile, "r");
    if (fd != NULL) {
      /* Gratuitous xors prevent the eyecatcher constant from appearing in the
       * code */
      uint32_t eyeCatcher = J9OSDUMP_EYECATCHER ^ 0xffffffff;
      char *bufferData = (char *)(buffer + 1);
      char readBuffer[1];
      buffer->eyeCatcher = eyeCatcher ^ 0xffffffff;
      buffer->size = 0;
      buffer->maxSize = J9OSDUMP_SIZE - sizeof(MarkAllPagesWritableHeader);

      while ((fread(readBuffer, 1, 1, fd) == 1) &&
             (buffer->size < buffer->maxSize)) {
        *bufferData++ = readBuffer[0];
        (buffer->size)++;
      }
      fclose(fd);
      setChecksumMarkAllPagesWritableHeader(buffer);
    }
  }

  for (pass = 0; modified && (pass < log2N); pass++) {
    FILE *fd = fopen(linuxMemoryMapsFile, "r");

    modified = FALSE;

    if (fd != NULL) {
      /* buf is big enough to fit the address range and permissions for 32 & 64
       * bit */
      char buf[MAX_PTR_SIZE_BYTES * 4 + sizeof("- rwxp")];
      while (fread(buf, 1, sizeof(buf) - 1, fd) == sizeof(buf) - 1) {
        char *next;
        uint8_t *start, *end;
        int rc;
        int prot = 0;

        /*
         * we've now read into buf:
         * for 32 bit: something like "40000000-40013000 r-xp"
         * for 64 bit: something like "0000002a95893000-0000002a95894000 rw-p"
         */

        /* NUL terminate buf for extra safety */
        buf[sizeof(buf) - 1] = '\0';

        /* use strtoull for correctness on 64-bit platforms and gratuitous extra
         * precision on 32-bit platforms */
        start = (uint8_t *)(uintptr_t)strtoull(buf, &next, 16);

        /* skip the '-' */
        next += 1;

        end = (uint8_t *)(uintptr_t)strtoull(next, &next, 16);

        if (strchr(next, 'r')) {
          prot |= PROT_READ;
        }
        if (strchr(next, 'w')) {
          prot |= PROT_WRITE;
        }
        if (strchr(next, 'x')) {
          prot |= PROT_EXEC;
        }
        if (0 == (prot & PROT_WRITE)) {
          /* mark the pages as writable */
          rc = mprotect(start, end - start, prot | PROT_WRITE);
          if (rc == 0) {
            modified = TRUE;
          }
        }

        /* skip to the next line */
        while (fread(buf, 1, 1, fd) == 1) {
          if (buf[0] == '\n') {
            break;
          }
        }
      }
      fclose(fd);
    }
  }

  return (char *)buffer;
}

#ifdef DUMP_DBG
static void printProgramHeader(struct OMRPortLibrary *portLibrary,
                               uintptr_t addrSize, void *pelfPgmHdr,
                               uintptr_t count) {
  Elf32_Phdr *p32elfPgmHdr = NULL;
  Elf64_Phdr *p64elfPgmHdr = NULL;

  if (32 == addrSize) {
    p32elfPgmHdr = (Elf32_Phdr *)pelfPgmHdr;
    portLibrary->tty_printf(portLibrary, "===32 bit=== ====pgmhdr# %d====\n",
                            count);
    portLibrary->tty_printf(portLibrary, "p_offset %d\n",
                            p32elfPgmHdr->p_offset);
    portLibrary->tty_printf(portLibrary, "p_vaddr %lx\n",
                            p32elfPgmHdr->p_vaddr);
    portLibrary->tty_printf(portLibrary, "p_paddr %lx\n",
                            p32elfPgmHdr->p_paddr);
    portLibrary->tty_printf(portLibrary, "p_filesz %d\n",
                            p32elfPgmHdr->p_filesz);
    portLibrary->tty_printf(portLibrary, "p_memsz %ld\n",
                            p32elfPgmHdr->p_memsz);
    portLibrary->tty_printf(portLibrary, "p_align %ld\n",
                            p32elfPgmHdr->p_align);
  } else if (64 == addrSize) {
    p64elfPgmHdr = pelfPgmHdr;
    portLibrary->tty_printf(portLibrary, "===64 bit=== ====pgmhdr# %d====\n",
                            count);
    portLibrary->tty_printf(portLibrary, "p_offset %d\n",
                            p64elfPgmHdr->p_offset);
    portLibrary->tty_printf(portLibrary, "p_vaddr %llx\n",
                            p64elfPgmHdr->p_vaddr);
    portLibrary->tty_printf(portLibrary, "p_paddr %llx\n",
                            p64elfPgmHdr->p_paddr);
    portLibrary->tty_printf(portLibrary, "p_filesz %d\n",
                            p64elfPgmHdr->p_filesz);
    portLibrary->tty_printf(portLibrary, "p_memsz %lld\n",
                            p64elfPgmHdr->p_memsz);
    portLibrary->tty_printf(portLibrary, "p_align %lld\n",
                            p64elfPgmHdr->p_align);
  }
}

static void printProgramHeaders(struct OMRPortLibrary *portLibrary, intptr_t fd,
                                uintptr_t addrSize, Elf64_Off phoff,
                                Elf64_Half phnum) {
  uintptr_t count = 0;
  int offset = 0;
  int bytesread = 0;
  int position;

  Elf64_Phdr elfPgmHdr;
  Elf32_Phdr *p32elfPgmHdr = (Elf32_Phdr *)&elfPgmHdr;
  Elf64_Phdr *p64elfPgmHdr = &elfPgmHdr;

  /* run through the program headers until we find a matching program header. */

  /* remember the original position */
  position = portLibrary->file_seek(portLibrary, fd, 0, EsSeekCur);

  /* set the start position */
  offset = portLibrary->file_seek(portLibrary, fd, phoff, EsSeekSet);

  if (32 == addrSize) {
    for (count = 0; count < phnum; count++) {
      bytesread = portLibrary->file_read(portLibrary, fd, p32elfPgmHdr,
                                         sizeof(Elf32_Phdr));
      printProgramHeader(portLibrary, 32, (Elf64_Phdr *)p32elfPgmHdr, count);
    }
  } else if (64 == addrSize) {
    for (count = 0; count < phnum; count++) {
      bytesread = portLibrary->file_read(portLibrary, fd, p64elfPgmHdr,
                                         sizeof(Elf64_Phdr));
      printProgramHeader(portLibrary, 64, p64elfPgmHdr, count);
    }
  }
  /* reset the original position */
  position = portLibrary->file_seek(portLibrary, fd, position, EsSeekSet);
}

static void printMemoryMap(struct OMRPortLibrary *portLibrary,
                           uintptr_t addrSize) {
  int32_t fd =
      portLibrary->file_open(portLibrary, linuxMemoryMapsFile, EsOpenRead, 0);
  char ch;
  char outbuf[256];
  int32_t outcursor = 0;
  int32_t bytesRead = 0;
  char *next;
  uint8_t *start = 0;
  uint8_t *end = 0;
  char flags[5];
  int offset;
  char device[6];
  int inode;
  char path[256];

  memset(outbuf, '\0', sizeof(outbuf));

  if (fd != -1) {
    portLibrary->tty_printf(portLibrary, "Memory Map:\n");
    while (bytesRead > -1) {
      bytesRead = portLibrary->file_read(portLibrary, fd, &ch, sizeof(ch));
      if (bytesRead > 0) {
        outbuf[outcursor] = ch;
        if (ch == '\n') {
          /* process the entire line */
          outbuf[outcursor] = '\0';
          outcursor = 0;
          path[0] = '\0';

          /* use strtoull for correctness on 64-bit platforms and gratuitous
           * extra precision on 32-bit platforms */
          start = (uint8_t *)(uintptr_t)strtoull(outbuf, &next, 16);

          /* skip the '-' */
          next++;

          end = (uint8_t *)(uintptr_t)strtoull(next, &next, 16);

          /* get the flags as a string */
          next++;
          flags[0] = *next;
          next++;
          flags[1] = *next;
          next++;
          flags[2] = *next;
          next++;
          flags[3] = *next;
          flags[4] = '\0';

          /* get the offset */
          next++;
          offset = strtoull(next, &next, 16);

          /* get the device as a string */
          next++;
          device[0] = *next;
          next++;
          device[1] = *next;
          next++;
          device[2] = *next;
          next++;
          device[3] = *next;
          next++;
          device[4] = *next;
          device[5] = '\0';

          /* get the inode */
          next++;
          inode = strtoull(next, &next, 10);

          /* get the path */
          while (isspace(*next)) {
            /* eat up leading whitespace */
            next++;
          }
          strcpy(path, next);

          if (32 == addrSize) {
            portLibrary->tty_printf(portLibrary, "%lx %lx %s %s\n", start, end,
                                    flags, path);
          } else if (64 == addrSize) {
            portLibrary->tty_printf(portLibrary, "%llx %llx %s %s\n", start,
                                    end, flags, path);
          }
        } else {
          outcursor++;
        }
      }
    }
    portLibrary->file_close(portLibrary, fd);
  }
}
#endif

/**
 * @internal  read from a passed file descriptor to locate the
 * details of a memory segments that are used by the process.
 * The fd must already be opened on /proc/self/maps for this to
 * work. Repeated calls should return details of each segment in
 * turn. When no more segments are available, the function will
 * return a false (0) value.
 *
 * @param[in] portLibrary The port library.
 * @param[in] fd The opened file descriptor for the maps file .
 * @param[in] addrSize Size of the machine addresses.
 * @param[out] ppStart address of start ptr.
 * @param[out] ppEnd address of end ptr.
 *
 * @return non zero on success, zero otherwise.
 */
static uintptr_t
getSharedAndPrivateDataSegments(struct OMRPortLibrary *portLibrary, intptr_t fd,
                                uintptr_t addrSize, uint8_t **ppStart,
                                uint8_t **ppEnd) {
  char ch;
  char outbuf[EsMaxPath];
  char path[EsMaxPath];
  int32_t outcursor = 0;
  int32_t bytesRead = 0;
  uint8_t *start;
  uint8_t *end;
  char attr_flag;
  char *next;
  uintptr_t rc = 0;

  memset(outbuf, '\0', sizeof(outbuf));

  if (fd != -1) {
    while (bytesRead > -1) {
      bytesRead = portLibrary->file_read(portLibrary, fd, &ch, sizeof(ch));
      if (bytesRead > 0) {
        outbuf[outcursor] = ch;
        if ('\n' == ch) {
          /* process the entire line */
          outbuf[outcursor] = '\0';
          outcursor = 0;

          path[0] = '\0';

          /* use strtoull for correctness on 64-bit platforms and gratuitous
           * extra precision on 32-bit platforms */
          start = (uint8_t *)(uintptr_t)strtoull(outbuf, &next, 16);

          /* skip the '-' */
          next++;

          end = (uint8_t *)(uintptr_t)strtoull(next, &next, 16);

          /* skip the read flag */
          next++;

          /* skip the write flag */
          next++;

          /* skip the exec flag */
          next++;

          /* get the attr flag */
          next++;
          attr_flag = *next;

          if ('s' == attr_flag || 'p' == attr_flag) {
            /* found a shared or private memory segment */

            /* get the offset */
            next++;
            strtoull(next, &next, 16);

            /* skip over the device */
            next += 5;

            /* get the inode */
            next++;
            strtoull(next, &next, 10);

            /* get the path */
            while (isspace(*next)) {
              /* eat up leading whitespace */
              next++;
            }
            strcpy(path, next);

#ifdef DUMP_DBG
            if (32 == addrSize) {
              portLibrary->tty_printf(
                  portLibrary, "found Shared/Private mem: %s 0x%lx->0x%lx\n",
                  path, start, end);
            } else if (64 == addrSize) {
              portLibrary->tty_printf(
                  portLibrary, "found Shared/Private mem: %s 0x%llx->0x%llx\n",
                  path, start, end);
            }
#endif
            *ppStart = start;
            *ppEnd = end;
            rc = 1;
            break;
          }
        } else {
          outcursor++;
        }
      }
    }
  }
  return rc;
}

/**
 * @internal read data from the passed file descriptor to determine if the file
 * is a valid ELF file.
 *
 * @param[in] portLibrary The port library.
 * @param[in] fd The opened file descriptor for the core file .
 * @param[out] pElfHeader Address of an ELF header structure to populate.
 *
 * @return zero on error, and the machine size the core file was generated for
 * on success (32 or 64).
 */
static uintptr_t readElfHeader(struct OMRPortLibrary *portLibrary, intptr_t fd,
                               Elf64_Ehdr *pElfHeader) {
  /* read the Elf magic number and class */
  int count = 0;
  char magic[4] = {'\177', 'E', 'L', 'F'};

  Elf32_Ehdr *p32elfHeader = (Elf32_Ehdr *)pElfHeader;
  Elf64_Ehdr *p64elfHeader = pElfHeader;

  /* set position to the start of the file. */
  portLibrary->file_seek(portLibrary, fd, 0, EsSeekSet);

  /* read for the length of the ELF identifier. */
  count = portLibrary->file_read(portLibrary, fd, pElfHeader, EI_NIDENT);

  if (count == EI_NIDENT) {
    /* read the correct number of bytes. */
    if (memcmp(pElfHeader->e_ident, magic, sizeof(magic)) == 0) {
      /* magic number is correct, we've got an ELF file. */
      if (1 == pElfHeader->e_ident[EI_CLASS]) {
        /* it's for a 32 bit machine. */
        /* now read the rest of the header. */
        count = portLibrary->file_read(portLibrary, fd, &p32elfHeader->e_type,
                                       sizeof(Elf32_Ehdr) - EI_NIDENT);
        return 32;
      } else if (2 == pElfHeader->e_ident[EI_CLASS]) {
        /* it's for a 64 bit machine. */
        /* now read the rest of the header. */
        count = portLibrary->file_read(portLibrary, fd, &p64elfHeader->e_type,
                                       sizeof(Elf64_Ehdr) - EI_NIDENT);
        return 64;
      }
    }
  }
  return 0;
}

/**
 * @internal locate a program header within an ELF file that fits within the
 * start and end addresses.
 *
 * @param[in] portLibrary The port library.
 * @param[in] fd The opened file descriptor for the core file .
 * @param[in] addrSize Size of the machine addresses.
 * @param[in] phoff Offset of the program headers in the ELF file.
 * @param[in] phnum Number of program headers in the ELF file.
 * @param[in] start Start address to search for.
 * @param[in] end End address to search for.
 *
 * @return zero on error, and the offset of a matching program header on
 * success.
 */
static uintptr_t findProgramHeader(struct OMRPortLibrary *portLibrary,
                                   intptr_t fd, uintptr_t addrSize,
                                   Elf64_Off phoff, Elf64_Half phnum,
                                   uint8_t *start, uint8_t *end) {
  uintptr_t count;
  uintptr_t offset = 0;
  uintptr_t bytesread = 0;

  Elf64_Phdr elfPgmHdr;
  Elf32_Phdr *p32elfPgmHdr = (Elf32_Phdr *)&elfPgmHdr;
  Elf64_Phdr *p64elfPgmHdr = &elfPgmHdr;

  /* run through the program headers until we find a matching program header. */

  /* set the start position */
  offset = portLibrary->file_seek(portLibrary, fd, phoff, EsSeekSet);

  for (count = 0; count < phnum; count++) {
    if (32 == addrSize) {
      /* handle 32 bit machines */
      bytesread = portLibrary->file_read(portLibrary, fd, p32elfPgmHdr,
                                         sizeof(Elf32_Phdr));
      if (p32elfPgmHdr->p_vaddr >= (uintptr_t)start &&
          p32elfPgmHdr->p_vaddr <= (uintptr_t)end) {
#ifdef DUMP_DBG
        portLibrary->tty_printf(portLibrary, "%s", "program header found:\n");
        printProgramHeader(portLibrary, 32, p32elfPgmHdr, count);
#endif
        return offset;
      }
    } else if (64 == addrSize) {
      /* handle 64 bit machines */
      bytesread = portLibrary->file_read(portLibrary, fd, p64elfPgmHdr,
                                         sizeof(Elf64_Phdr));
      if (p64elfPgmHdr->p_vaddr >= (uintptr_t)start &&
          p64elfPgmHdr->p_vaddr <= (uintptr_t)end) {
#ifdef DUMP_DBG
        portLibrary->tty_printf(portLibrary, "%s", "program header found:\n");
        printProgramHeader(portLibrary, 64, p64elfPgmHdr, count);
#endif
        return offset;
      }
    }
    offset += bytesread;
  }

  /* didn't find a matching header */
  return 0;
}

/**
 * @internal Copy data from memory segments into an ELF
 * core file and update the appropriate program header.
 *
 * @param[in] portLibrary The port library.
 * @param[in] fd_core File handle to the open core file
 * @param[in] addrSize The machine word size in bits
 * @param[in] phoff Offset of the program header being updated
 *
 * @return void.
 */
static void copyDataIntoELFCore(struct OMRPortLibrary *portLibrary,
                                intptr_t fd_core, uintptr_t addrSize,
                                Elf64_Off phoff) {
  intptr_t dataOffset;
  intptr_t dataSize;

  Elf64_Phdr elfPgmHdr;
  Elf32_Phdr *p32elfPgmHdr = (Elf32_Phdr *)&elfPgmHdr;
  Elf64_Phdr *p64elfPgmHdr = &elfPgmHdr;

  if (32 == addrSize) {
    /* read the 32bit program header to see if it needs updating. */
    portLibrary->file_seek(portLibrary, fd_core, phoff, EsSeekSet);
    portLibrary->file_read(portLibrary, fd_core, p32elfPgmHdr,
                           sizeof(Elf32_Phdr));

    if (0 == p32elfPgmHdr->p_filesz) {
      /* the memory is not included in the file, so copy it to the end and
       * update the 32bit program header. */

      /* copy the data to the end of the core file. */
      dataOffset = portLibrary->file_seek(portLibrary, fd_core, 0, EsSeekEnd);
      if (dataOffset != -1) {
        dataSize = portLibrary->file_write(
            portLibrary, fd_core,
            (const void *)(uintptr_t)p32elfPgmHdr->p_vaddr,
            p32elfPgmHdr->p_memsz);
        if (dataSize > 0) {
          /* set up the 32bit program header with filesize, offset and memory
           * size. */
          p32elfPgmHdr->p_filesz = p32elfPgmHdr->p_memsz;
          p32elfPgmHdr->p_offset = dataOffset;

          /* write the 32bit program header back into the core file. */
          portLibrary->file_seek(portLibrary, fd_core, phoff, EsSeekSet);
          portLibrary->file_write(portLibrary, fd_core, p32elfPgmHdr,
                                  sizeof(Elf32_Phdr));
        }
      }
    }
  } else if (64 == addrSize) {
    /* read the 64bit program header to see if it needs updating. */
    portLibrary->file_seek(portLibrary, fd_core, phoff, EsSeekSet);
    portLibrary->file_read(portLibrary, fd_core, p64elfPgmHdr,
                           sizeof(Elf64_Phdr));

    if (0 == p64elfPgmHdr->p_filesz) {
      /* the memory is not included in the file, so copy it to the end and
       * update the 64bit program header. */

      /* copy the data to the end of the core file. */
      dataOffset = portLibrary->file_seek(portLibrary, fd_core, 0, EsSeekEnd);
      if (dataOffset != -1) {
        dataSize = portLibrary->file_write(
            portLibrary, fd_core,
            (const void *)(uintptr_t)p64elfPgmHdr->p_vaddr,
            p64elfPgmHdr->p_memsz);
        if (dataSize > 0) {
          /* set up the 64bit program header with filesize, offset and memory
           * size. */
          p64elfPgmHdr->p_filesz = p64elfPgmHdr->p_memsz;
          p64elfPgmHdr->p_offset = dataOffset;

          /* write the 64bit program header back into the core file. */
          portLibrary->file_seek(portLibrary, fd_core, phoff, EsSeekSet);
          portLibrary->file_write(portLibrary, fd_core, p64elfPgmHdr,
                                  sizeof(Elf64_Phdr));
        }
      }
    }
  }
}

/**
 * @internal Insert any unmapped memory segments used by
 * the process into the core file.
 *
 * @param[in] portLibrary The port library.
 * @param[in] corepath Full path to the core file.
 * @param[in] cachePath Full path to the shared classes
 * cache file.
 *
 * @return void.
 */
void insertSharedAndPrivateDataSegments(struct OMRPortLibrary *portLibrary,
                                        char *corePath) {
  intptr_t fd_maps = 0;
  intptr_t fd_core = 0;
  uintptr_t addrSize;

  uint8_t *start;
  uint8_t *end;

  Elf64_Ehdr elfHeader;
  Elf32_Ehdr *p32elfHeader = (Elf32_Ehdr *)&elfHeader;
  Elf64_Ehdr *p64elfHeader = &elfHeader;

  Elf64_Off phoff;
  Elf64_Half phnum;
  Elf64_Off phoff_update = 0;

  /* open the maps file so we can look at the memory segments. */
  fd_maps =
      portLibrary->file_open(portLibrary, linuxMemoryMapsFile, EsOpenRead, 0);
  if (fd_maps != -1) {
    /* maps file opened ok, now open the core file so we can edit it. */
    fd_core = portLibrary->file_open(portLibrary, corePath,
                                     EsOpenWrite | EsOpenRead, 0);
    if (fd_core != -1) {
      /* core file opened ok, now get the shared classes cache file details */
      addrSize = readElfHeader(portLibrary, fd_core, &elfHeader);
      if (32 == addrSize) {
        /* get offset to program headers and number of program headers for 32
         * bit core. */
        phoff = p32elfHeader->e_phoff;
        phnum = p32elfHeader->e_phnum;
      } else if (64 == addrSize) {
        /* get offset to program headers and number of program headers for 64
         * bit core. */
        phoff = p64elfHeader->e_phoff;
        phnum = p64elfHeader->e_phnum;
      } else {
        /* the core file is corrupt, continuing is futile, so close files and
         * return. */
        portLibrary->file_close(portLibrary, fd_core);
        portLibrary->file_close(portLibrary, fd_maps);
        return;
      }

#ifdef DUMP_DBG
      printMemoryMap(portLibrary, addrSize);
#endif
      /* read all the shared classes segments */
      while (getSharedAndPrivateDataSegments(portLibrary, fd_maps, addrSize,
                                             &start, &end)) {
        /* find a program header that represents this data */
        phoff_update = findProgramHeader(portLibrary, fd_core, addrSize, phoff,
                                         phnum, start, end);
        if (0 == phoff_update) {
          /* cannot find the program header that represents this shared classes
           * segment */
          /* obviously this is an error but there is little we can do other than
           * carry on */
          /* processing the rest of the segments. */
#ifdef DUMP_DBG
          if (32 == addrSize) {
            portLibrary->tty_printf(
                portLibrary,
                "could not find ELF pgmhdr to match SC mem: 0x%lx->0x%lx\n",
                start, end);
          } else if (64 == addrSize) {
            portLibrary->tty_printf(
                portLibrary,
                "could not find ELF pgmhdr to match SC mem: 0x%llx->0x%llx\n",
                start, end);
          }
#endif
        } else {
          /* we have a program header to work with. if the ph shows the data is
           * not in the core */
          /* copy the data and update the program header */
          copyDataIntoELFCore(portLibrary, fd_core, addrSize, phoff_update);
        }
      }

#ifdef DUMP_DBG
      portLibrary->tty_printf(portLibrary, "program headers after update\n");
      printProgramHeaders(portLibrary, fd_core, addrSize, phoff, phnum);
#endif

      /* close the core file. */
      portLibrary->file_close(portLibrary, fd_core);
    }
    /* close the maps file. */
    portLibrary->file_close(portLibrary, fd_maps);
  }
}
