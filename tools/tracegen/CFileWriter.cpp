/*******************************************************************************
 * Copyright (c) 2014, 2016 IBM Corp. and others
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
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CFileWriter.hpp"
#include "EventTypes.hpp"
#include "FileUtils.hpp"

#define PRETTY_PRINT_TP_LIMIT 30

RCType CFileWriter::writeOutputFiles(
  J9TDFOptions* options, J9TDFFile* tdf, J9TDFGroup* groups, unsigned int groupsCount)
{
  RCType rc = RC_FAILED;
  FILE* fd = NULL;
  unsigned int* levels = NULL;
  unsigned int* assertDefaults = NULL;

  const char* fileName
    = FileUtils::getTargetFileName(options, tdf->fileName, UT_FILENAME_PREFIX, tdf->header.executable, ".c");

  time_t sourceFileMtime = FileUtils::getMtime(tdf->fileName);
  time_t targetFileMtime = FileUtils::getMtime(fileName);

  if ((false == options->force) && (targetFileMtime > sourceFileMtime)) {
    if (options->verboseOutput) {
      printf("C file is already up-to-date: %s\n", fileName);
    }
    Port::omrmem_free((void**)&fileName);
    return RC_OK;
  }

  if (options->verboseOutput) {
    printf("Creating c file: %s\n", fileName);
  }

  fd = Port::fopen(fileName, "wb");

  if (NULL == fd) {
    perror("Error opening file");
    goto failed;
  } else {
    J9TDFTracepoint* tp = tdf->tracepoints;
    unsigned int tpCount = 0;
    unsigned int i = 0;

    while (NULL != tp) {
      tp = tp->nexttp;
      tpCount += 1;
    }

    if (tpCount > 0) {
      levels = (unsigned int*)Port::omrmem_calloc(tpCount, sizeof(unsigned int));
      assertDefaults = (unsigned int*)Port::omrmem_calloc(tpCount, sizeof(unsigned int));
    } else {
      levels = (unsigned int*)Port::omrmem_calloc(1, sizeof(unsigned int));
      assertDefaults = (unsigned int*)Port::omrmem_calloc(1, sizeof(unsigned int));
    }

    if (NULL == levels || NULL == assertDefaults) {
      eprintf("Failed to allocate memory");
      goto failed;
    }

    fprintf(fd, "/* File generated by tracegen, do not edit */\n");

    fprintf(fd, "#include \"ut_%s.h\"\n\n\n\n", tdf->header.executable);
    fprintf(fd, "#define UT_TRACE_VERSION 8\n");
    fprintf(fd, "UtTraceVersionInfo %s_UtTraceVersionInfo = {UT_TRACE_VERSION};\n", tdf->header.executable);
    fprintf(fd, "#if defined(UT_TRACE_ENABLED_IN_BUILD)\n");

    tp = tdf->tracepoints;

    while (NULL != tp) {
      levels[i] = tp->level;
      if ((UT_ASSERT_TYPE == tp->type) && (1 == tp->level)) {
        assertDefaults[i] = 1; /* Enable default assertions prior to full trace initialisation. */
      } else {
        assertDefaults[i] = 0;
      }
      tp = tp->nexttp;
      i += 1;
    }

    if (RC_OK != writeComponentDataOnStream(fd, tdf, tpCount, levels, assertDefaults, groups, groupsCount)) {
      eprintf("Failed to write component data");
      goto failed;
    }
    fprintf(fd, "\n\n#else\n");
    if (RC_OK != writeComponentDataForNonTraceEnabledBuildsOnStream(fd, tdf)) {
      eprintf("Failed to write component data for non trace enabled build");
      goto failed;
    }
    fprintf(fd, "\n#endif /* defined(UT_TRACE_ENABLED_IN_BUILD) */\n");

    if (RC_OK != writeRegistrationFunctionsOnStream(fd, tdf)) {
      eprintf("Failed to write registration functions");
      goto failed;
    }

    fprintf(fd, "/* End of generated file */\n");

    if (0 == fclose(fd)) {
      rc = RC_OK;
    } else {
      eprintf("Failed to close file %s", fileName);
      rc = RC_FAILED;
      goto failed;
    }
  }
  Port::omrmem_free((void**)&levels);
  Port::omrmem_free((void**)&assertDefaults);
  Port::omrmem_free((void**)&fileName);

  return rc;

failed:
  if (NULL != fd) {
    fclose(fd);
  }
  Port::omrmem_free((void**)&levels);
  Port::omrmem_free((void**)&assertDefaults);
  Port::omrmem_free((void**)&fileName);
  return rc;
}

RCType CFileWriter::writeComponentDataOnStream(FILE* fd, J9TDFFile* tdf, unsigned int ntracepoints,
  unsigned int* levels, unsigned int* earlyAssertDefaults, J9TDFGroup* groups, unsigned int groupsCount)
{
  RCType rc = RC_OK;
  if (0 == ntracepoints) {
    /* allow empty components e.g. frame */
    ntracepoints = 1;
  }
  if (RC_OK != writeActiveArray(fd, tdf, ntracepoints, earlyAssertDefaults)) {
    eprintf("Failed to write active array");
    goto failed;
  }

  /* output level structure */
  if (RC_OK != writeLevels(fd, tdf, ntracepoints, levels)) {
    eprintf("Failed to write levels");
    goto failed;
  }
  if (RC_OK != writeGroups(fd, tdf, groups, groupsCount)) {
    eprintf("Failed to write groups");
    goto failed;
  }
  if (RC_OK != writeModuleInfo(fd, tdf, ntracepoints)) {
    eprintf("Failed to write module info");
    goto failed;
  }
  return rc;

failed:
  return RC_FAILED;
}

RCType CFileWriter::writeRegistrationFunctionsOnStream(FILE* fd, J9TDFFile* tdf)
{
  const char* parameterType = "UtInterface *";
  const char* parameterName = "utIntf";
  const char* ok = "0";
  const char* err = "-1";
  char* unregisterSubmodule = NULL;
  char* registerSubmodule = NULL;
  char* submodules = NULL;
  RCType rc = RC_FAILED;

  fprintf(fd, "/* function to register with trace engine and configure current module */\n");
  fprintf(fd, "int32_t\n"); /* type */
  fprintf(fd, "register%sWithTrace(%s%s, UtModuleInfo * containerModule)\n", tdf->header.executable, parameterType,
    parameterName); /* func name */
  fprintf(fd, "{\n");
  fprintf(fd, "\tI_32 rc = %s;\n\n", ok); /* func vars */
  fprintf(fd, "#if defined(UT_TRACE_ENABLED_IN_BUILD)\n");

  /* trace enabled function body */
  fprintf(fd, "\n\t%s_UtModuleInfo.containerModule = containerModule;\n\n", tdf->header.executable);

  fprintf(fd, "\tif( utIntf == NULL ) {\n");
  fprintf(fd, "\t\trc = %s;\n", err);
  fprintf(fd, "\t}\n");

  fprintf(fd, "\n\tif (rc == %s) {\n", ok);
  fprintf(fd, "\t\tutIntf->module->TraceInit(NULL, &%s_UtModuleInfo);\n", tdf->header.executable);
  fprintf(fd, "\t}\n");

  if (NULL != tdf->header.submodules) {
    submodules = strdup(tdf->header.submodules);
    if (NULL == submodules) {
      eprintf("Failed to allocate memory");
      goto failed;
    }

    registerSubmodule = strtok(submodules, ",");
    while (NULL != registerSubmodule) {
      fprintf(fd, "\n\tif (rc == %s) {\n", ok);
      fprintf(fd, "\t\textern int32_t register%sWithTrace(%s%s, UtModuleInfo* containerModule);\n\n", registerSubmodule,
        parameterType, parameterName);
      fprintf(fd, "\t\trc = register%sWithTrace(%s, &%s_UtModuleInfo);\n", registerSubmodule, parameterName,
        tdf->header.executable);
      fprintf(fd, "\t}\n");
      registerSubmodule = strtok(NULL, ",");
    }
    Port::omrmem_free((void**)&submodules);
  }

  fprintf(fd, "\n#else\n");
  fprintf(fd, "\t/* trace not present in build - NOOP */");
  fprintf(fd, "\n#endif /* defined(UT_TRACE_ENABLED_IN_BUILD) */\n");
  fprintf(fd, "\treturn rc;\n"); /* function return */
  fprintf(fd, "}\n"); /* function close */

  /* include a shutdown function */
  fprintf(fd, "\n/* function to deregister with trace engine and configure current module */\n");
  fprintf(fd, "int32_t\n"); /* type */
  fprintf(fd, "deregister%sWithTrace(%s%s)\n", tdf->header.executable, parameterType, parameterName); /* func name */
  fprintf(fd, "{\n");
  fprintf(fd, "\tI_32 rc = %s;\n\n", ok); /* func vars */
  fprintf(fd, "#if defined(UT_TRACE_ENABLED_IN_BUILD)\n");

  fprintf(fd, "\tif( utIntf == NULL ) {\n");
  fprintf(fd, "\t\trc = %s;\n", err);
  fprintf(fd, "\t}\n");

  fprintf(fd, "\n\tif (rc == %s) {\n", ok);
  fprintf(fd, "\t\tutIntf->module->TraceTerm(NULL, &%s_UtModuleInfo);\n", tdf->header.executable);
  fprintf(fd, "\t}\n");

  if (NULL != tdf->header.submodules) {
    submodules = strdup(tdf->header.submodules);
    if (NULL == submodules) {
      eprintf("Failed to allocate memory");
      goto failed;
    }

    unregisterSubmodule = strtok(submodules, ",");
    while (NULL != unregisterSubmodule) {
      fprintf(fd, "\n\tif (rc == %s) {\n", ok);
      fprintf(
        fd, "\t\textern int32_t deregister%sWithTrace(%s%s);\n\n", unregisterSubmodule, parameterType, parameterName);
      fprintf(fd, "\t\trc = deregister%sWithTrace(%s);\n", unregisterSubmodule, parameterName);
      fprintf(fd, "\t}\n");
      unregisterSubmodule = strtok(NULL, ",");
    }
    Port::omrmem_free((void**)&submodules);
    submodules = NULL;
  }

  fprintf(fd, "#else\n");
  fprintf(fd, "\t/* trace not present in build - NOOP */\n");
  fprintf(fd, "#endif /* defined(UT_TRACE_ENABLED_IN_BUILD) */\n");
  fprintf(fd, "\treturn rc;\n"); /* function return */
  fprintf(fd, "}\n"); /* function close */

  rc = RC_OK;
  return rc;

failed:
  return rc;
}

RCType CFileWriter::writeComponentDataForNonTraceEnabledBuildsOnStream(FILE* fd, J9TDFFile* tdf)
{
  RCType rc = RC_FAILED;
  fprintf(fd, "unsigned char %s_UtActive[1];\n", tdf->header.executable);
  fprintf(fd,
    "UtModuleInfo %s_UtModuleInfo = {(char*) \"%s\", %u, 0, 0, NULL, NULL, NULL, &%s_UtTraceVersionInfo, (char*) "
    "\"%s\", NULL, NULL, NULL, NULL, 0, 0};\n",
    tdf->header.executable, tdf->header.executable, (unsigned int)strlen(tdf->header.executable),
    tdf->header.executable, tdf->header.datfilename);
  rc = RC_OK;
  return rc;
}

RCType CFileWriter::writeModuleInfo(FILE* fd, J9TDFFile* tdf, unsigned int ntracepoints)
{
  RCType rc = RC_FAILED;
  fprintf(fd,
    "UtModuleInfo %s_UtModuleInfo = {(char*) \"%s\", %u, %u, 0, %s_UtActive , NULL, NULL, &%s_UtTraceVersionInfo, "
    "(char*) \"%s\", %s_UtLevels, &%s_group0, NULL, NULL, 0, %s};",
    tdf->header.executable, tdf->header.executable, (unsigned int)strlen(tdf->header.executable), ntracepoints,
    tdf->header.executable, tdf->header.executable, tdf->header.datfilename, tdf->header.executable,
    tdf->header.executable, tdf->header.auxiliary ? "1" : "0");
  rc = RC_OK;
  return rc;
}

RCType CFileWriter::writeGroups(FILE* fd, J9TDFFile* tdf, J9TDFGroup* groups, unsigned int tracegroups)
{
  J9TDFGroup* group = groups;
  unsigned int tracegroupsGen = tracegroups;
  RCType rc = RC_FAILED;

  fprintf(fd, "\n");
  while (NULL != group) {
    unsigned int i = 0;
    J9TDFGroupTp* ids = group->groupTpIds;

    if (NULL != ids) {
      fprintf(fd, "int32_t %s_tpids%u[] = {\n", tdf->header.executable, tracegroupsGen - 1);
      while (NULL != ids) {
        if (0 == (i % PRETTY_PRINT_TP_LIMIT)) {
          fprintf(fd, "\n\t");
        }
        fprintf(fd, "%u", ids->id);
        if (NULL != ids->next) {
          fprintf(fd, ",");
        }
        i += 1;
        ids = ids->next;
      }
      fprintf(fd, "\t};\n");
    }

    fprintf(fd, "\nUtGroupDetails %s_group%u = {\n", tdf->header.executable, tracegroupsGen - 1);
    fprintf(fd, "\t(char *)\"%s\",\n", group->name);
    fprintf(fd, "\t%u,\n", i);

    /* tpids */
    if (NULL != group->groupTpIds) {
      fprintf(fd, "\t%s_tpids%u,\n", tdf->header.executable, tracegroupsGen - 1);
    } else {
      fprintf(fd, "\tNULL,\n");
    }

    if (tracegroupsGen == tracegroups) {
      fprintf(fd, "\tNULL};\n");
    } else {
      fprintf(fd, "\t&%s_group%u};\n", tdf->header.executable, tracegroupsGen);
    }

    group = group->nextGroup;
    tracegroupsGen -= 1;
  }
  rc = RC_OK;
  return rc;
}

RCType CFileWriter::writeLevels(FILE* fd, J9TDFFile* tdf, unsigned int ntracepoints, unsigned int levels[])
{
  J9TDFTracepoint* tp = tdf->tracepoints;
  unsigned int id = 0;
  RCType rc = RC_FAILED;

  fprintf(fd, "unsigned char %s_UtLevels[%u] = { ", tdf->header.executable, ntracepoints);
  while (NULL != tp) {
    if (0 == (id % PRETTY_PRINT_TP_LIMIT)) {
      fprintf(fd, "\n\t");
    }
    fprintf(fd, "%u", levels[id]);

    tp = tp->nexttp;
    if (NULL != tp) {
      fprintf(fd, ",");
    }
    id += 1;
  }
  fprintf(fd, "};\n\n");

  rc = RC_OK;
  return rc;
}

RCType CFileWriter::writeActiveArray(
  FILE* fd, J9TDFFile* tdf, unsigned int ntracepoints, unsigned int earlyAssertDefaults[])
{
  J9TDFTracepoint* tp = tdf->tracepoints;
  unsigned int id = 0;
  RCType rc = RC_FAILED;

  fprintf(fd, "unsigned char %s_UtActive[%u] = { ", tdf->header.executable, ntracepoints);
  while (NULL != tp) {
    if (0 == (id % PRETTY_PRINT_TP_LIMIT)) {
      fprintf(fd, "\n\t");
    }
    fprintf(fd, "%u", earlyAssertDefaults[id]);

    tp = tp->nexttp;
    if (NULL != tp) {
      fprintf(fd, ",");
    }
    id += 1;
  }
  fprintf(fd, "};\n\n");

  rc = RC_OK;
  return rc;
}
