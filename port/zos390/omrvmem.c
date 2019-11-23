/*******************************************************************************
 * Copyright (c) 1991, 2019 IBM Corp. and others
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
 * @brief Virtual memory
 */

#include "omrvmem.h"
#include "omriarv64.h"
#include "omrport.h"
#include "omrportasserts.h"
#include "omrportpg.h"
#include "omrportpriv.h"
#include "omrsimap.h"
#include "ut_omrport.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#if 0
#define LP_DEBUG
#endif

#if defined(LP_DEBUG)
#define LP_DEBUG_PRINTF(format) omrtty_printf(portLibrary, format);
#define LP_DEBUG_PRINTF1(format, v1) omrtty_printf(portLibrary, format, v1);
#define LP_DEBUG_PRINTF2(format, v1, v2)                                       \
  omrtty_printf(portLibrary, format, v1, v2);
#define LP_DEBUG_PRINTF3(format, v1, v2, v3)                                   \
  omrtty_printf(portLibrary, format, v1, v2, v3);
#define LP_DEBUG_PRINTF4(format, v1, v2, v3, v4)                               \
  omrtty_printf(portLibrary, format, v1, v2, v3, v4);
#define LP_DEBUG_PRINTF5(format, v1, v2, v3, v4, v5)                           \
  omrtty_printf(portLibrary, format, v1, v2, v3, v4, v5);
#else
#define LP_DEBUG_PRINTF(format)
#define LP_DEBUG_PRINTF1(format, v1)
#define LP_DEBUG_PRINTF2(format, v1, v2)
#define LP_DEBUG_PRINTF3(format, v1, v2, v3)
#define LP_DEBUG_PRINTF4(format, v1, v2, v3, v4)
#define LP_DEBUG_PRINTF5(format, v1, v2, v3, v4, v5)
#endif /* LP_DEBUG */

/* See MVS Data Areas, Volume 1 (ABEP - DALT) for flag definitions */
/* Need to access CVTZOS_V1R9 and CVTEDAT (not documented in v1.7)
 *  can infer what CVTZPS_V1R9 is from CVTZOS_V1R7
 * CVTEDAT is likely in CVTFLAG2. */
#define CVTPTR (*(struct __cvt_s * __ptr32 * __ptr32)16)

void
update_vmemIdentifier(J9PortVmemIdentifier* identifier,
                      void* address,
                      void* handle,
                      uintptr_t byteAmount,
                      uintptr_t mode,
                      uintptr_t pageSize,
                      uintptr_t pageFlags,
                      uintptr_t allocator,
                      OMRMemCategory* category);
int
get_protectionBits(uintptr_t mode);

#define FOUR_K_MINUS_1 (4 * 1024 - 1)

/* we use the 4G limit as the point where we switch from the malloc31 allocator
 * to malloc.  We use 4G-1 here so that we don't overflow on 32-bit */
/* (note that we also use this define in the legacy
 * Trc_PRT_vmem_default_reserve* tracepoints so we can determine which one of
 * the default page size allocators we were using (0 is for low mem and this
 * constant is for the general allocator)) */
#define FOUR_GIG_LIMIT ((uintptr_t)U_32_MAX)

#define TWO_GIGBYTES ((uintptr_t)2 * 1024 * 1024 * 1024)

#define GET_4K_ALIGNED_PTR(alignedPtr, ptr)                                    \
  {                                                                            \
    alignedPtr =                                                               \
      (((uintptr_t)ptr) + FOUR_K_MINUS_1 + sizeof(uintptr_t)) & ~0xfff;        \
    *(uintptr_t*)(alignedPtr - sizeof(uintptr_t)) = (uintptr_t)ptr;            \
  }

#define GET_BASE_PTR_FROM_ALIGNED_PTR(alignedPtr)                              \
  (*(void**)((uintptr_t)alignedPtr - sizeof(uintptr_t)))

#define GET_4K_ALIGNED_ALLOCATION_SIZE(byteAmount)                             \
  (byteAmount + FOUR_K_MINUS_1 + sizeof(uintptr_t))

/* omrget_large_pageable_pages_supported.s */
#pragma linkage(GLPPS, OS)
#pragma map(Get_Large_Pageable_Pages_Supported, "GLPPS")
uintptr_t
Get_Large_Pageable_Pages_Supported();

#pragma linkage(PGSERRM, OS)
#pragma map(Pgser_Release, "PGSERRM")
intptr_t
Pgser_Release(void* address, int byteAmount);

/* omrvmem_support_below_bar_[31|64].s */
#pragma linkage(omrallocate_1M_pageable_pages_below_bar, OS_NOSTACK)
void*
omrallocate_1M_pageable_pages_below_bar(long numBytes, int subpool);

/* omrvmem_support_below_bar_[31|64].s */
#pragma linkage(omrallocate_4K_pages_below_bar, OS_NOSTACK)
void*
omrallocate_4K_pages_below_bar(long numBytes, int subpool);

/* omrvmem_support_below_bar_[31|64].s */
#pragma linkage(omrfree_memory_below_bar, OS_NOSTACK)
int
omrfree_memory_below_bar(void* address, long length, int subpool);

#if 0
/* Enable this to use hand coded assembler routine instead of the one generated by Metal-C. */
#pragma linkage(ALPPBB, OS)
#pragma map(omrallocate_1M_pageable_pages_below_bar, "ALPPBB")
void *omrallocate_1M_pageable_pages_below_bar(size_t length, int subpool);
#endif

#if defined(OMR_ENV_DATA64)

/* omrget_large_pages_supported.s */
#pragma linkage(GETLPSUP, OS)
#pragma map(Get_Large_Pages_Supported, "GETLPSUP")
uintptr_t
Get_Large_Pages_Supported();

/* omrget_large_2gb_pages_supported.s */
#pragma linkage(GL2GBPS, OS)
#pragma map(Get_Large_2GB_Pages_Supported, "GL2GBPS")
uintptr_t
Get_Large_2GB_Pages_Supported();

/**
 * Retrieve the IPT ttoken for an LE process or thread (64-bit only)
 * @param[in] buf Buffer where ttoken should be written
 * @param[in] len Length of buf. It should be at least BUF_SZ.
 * @return -1 in case of error. Otherwise, 0
 */
int32_t
omrget_ipt_ttoken(char* buf, uint32_t len);

/**
 * Helper function used to retrieve the IPT (Initial Program Thread)
 * TTOKEN. This is a special TTOKEN value that LE (64-bit only) saves
 * in one of its data areas.
 *
 * @param[in] portLibrary pointer to port library
 * @param[in] buf Buffer where ttoken value should be written to
 * @param[in] buf_len Lenght of buf
 */
static void
get_ipt_ttoken(struct OMRPortLibrary* portLibrary, char* buf, uint32_t buf_len)
{
  if (NULL != buf) {
    const int32_t ttkret = omrget_ipt_ttoken(buf, buf_len);

    if (0 == ttkret) {
      uint32_t i = 0U;
      LP_DEBUG_PRINTF("get_ipt_ttoken() : 0x");
      for (i = 0U; i < buf_len; i++) {
        LP_DEBUG_PRINTF1("%02X", buf[i]);
      }
      LP_DEBUG_PRINTF("\n");
    } else {
      omrtty_printf(portLibrary, "get_ipt_ttoken() failed: %d\n", ttkret);
    }
  }

  return;
}

/* omrvmem_support_above_bar.s */
#pragma linkage(omrallocate_1M_fixed_pages, OS_NOSTACK)
void*
omrallocate_1M_fixed_pages(int numMBSegments,
                           int userExtendedPrivateAreaMemoryType,
                           const char* ttkn);

/* omrvmem_support_above_bar.s */
#pragma linkage(omrfree_memory_above_bar, OS_NOSTACK)
int
omrfree_memory_above_bar(void* address, const char* ttkn);

/* omrvmem_support_above_bar.s */
#pragma linkage(omrallocate_4K_pages_above_bar, OS_NOSTACK)
void*
omrallocate_4K_pages_above_bar(int numMBSegments, const char* ttkn);

/* omrvmem_support_above_bar.s */
#pragma linkage(omrallocate_4K_pages_in_userExtendedPrivateArea, OS_NOSTACK)
void*
omrallocate_4K_pages_in_userExtendedPrivateArea(
  int numMBSegments,
  int userExtendedPrivateAreaMemoryType,
  const char* ttkn);

/* omrvmem_support_above_bar.s */
#pragma linkage(omrallocate_1M_pageable_pages_above_bar, OS_NOSTACK)
void*
omrallocate_1M_pageable_pages_above_bar(int numMBSegments,
                                        int userExtendedPrivateAreaMemoryType,
                                        const char* ttkn);

/* omrvmem_support_above_bar.s */
#pragma linkage(omrallocate_2G_pages, OS_NOSTACK)
void*
omrallocate_2G_pages(int num2GBUnits,
                     int userExtendedPrivateAreaMemoryType,
                     const char* ttkn);

#pragma linkage(omrdiscard_data, OS_NOSTACK)
int
omrdiscard_data(void* address, int numFrames);

/* omrget_userExtendedPrivateAreaMemoryType.s */
#pragma linkage(GETTTT, OS)
#pragma map(getUserExtendedPrivateAreaMemoryType, "GETTTT")
uintptr_t
getUserExtendedPrivateAreaMemoryType();

static BOOLEAN
isRmode64Supported();
static void*
reserve_memory_with_moservices(struct OMRPortLibrary* portLibrary,
                               struct J9PortVmemIdentifier* identifier,
                               struct J9PortVmemParams* params,
                               OMRMemCategory* category);
#endif /* defined(OMR_ENV_DATA64) */

/* Subpool number to be used when allocating memory using STORAGE macro.
 * This number is suggested by LE.
 * This is the same subpool number as used by LE to allocate storage on behalf
 * of user application in AMODE31.
 */
#define OMRPORT_VMEM_SUBPOOL 2

/* Macro to clear existing flags for page type and set it to new type */
#define SET_PAGE_TYPE(pageFlags, pageType)                                     \
  ((pageFlags) = (((pageFlags) & ~OMRPORT_VMEM_PAGE_FLAG_TYPE_MASK) | pageType))

#define IS_VMEM_PAGE_FLAG_NOT_USED(pageFlags)                                  \
  (OMRPORT_VMEM_PAGE_FLAG_NOT_USED ==                                          \
   (OMRPORT_VMEM_PAGE_FLAG_NOT_USED & (pageFlags)))

static BOOLEAN
isStrictAndOutOfRange(struct J9PortVmemParams*, void*);
static BOOLEAN
rangeIsValid(struct J9PortVmemIdentifier* identifier,
             void* address,
             uintptr_t byteAmount);
static void*
reservePages(struct OMRPortLibrary* portLibrary,
             struct J9PortVmemIdentifier* identifier,
             struct J9PortVmemParams* params,
             OMRMemCategory* category);
static void*
reserve4KPages(struct OMRPortLibrary* portLibrary,
               struct J9PortVmemIdentifier* identifier,
               struct J9PortVmemParams* params,
               OMRMemCategory* category);
static struct J9PortVmemParams
includeAlignmentInAllocation(struct J9PortVmemParams* incomingParams);
static void*
adjustForRequestedAlignment(struct J9PortVmemParams* params,
                            void* memoryPointer);
static void
getPageInfo(struct OMRPortLibrary* portLibrary);
static BOOLEAN
isLargePageSizeSupported(struct OMRPortLibrary* portLibrary,
                         uintptr_t pageSize,
                         uintptr_t pageFlags);

void*
omrvmem_commit_memory(struct OMRPortLibrary* portLibrary,
                      void* address,
                      uintptr_t byteAmount,
                      struct J9PortVmemIdentifier* identifier)
{
  void* ptr = NULL;
  Trc_PRT_vmem_omrvmem_commit_memory_Entry(address, byteAmount);

  if (rangeIsValid(identifier, address, byteAmount)) {
    ASSERT_VALUE_IS_PAGE_SIZE_ALIGNED(address, identifier->pageSize);
    ASSERT_VALUE_IS_PAGE_SIZE_ALIGNED(byteAmount, identifier->pageSize);
    ptr = address;
  } else {
    Trc_PRT_vmem_omrvmem_commit_memory_invalidRange(
      identifier->address, identifier->size, address, byteAmount);
    portLibrary->error_set_last_error(
      portLibrary, -1, OMRPORT_ERROR_VMEM_INVALID_PARAMS);
  }

  Trc_PRT_vmem_omrvmem_commit_memory_Exit(address);
  return ptr;
}

intptr_t
omrvmem_decommit_memory(struct OMRPortLibrary* portLibrary,
                        void* address,
                        uintptr_t byteAmount,
                        struct J9PortVmemIdentifier* identifier)
{
  intptr_t result = -1;

  Trc_PRT_vmem_omrvmem_decommit_memory_Entry(address, byteAmount);

  if (1 == portLibrary->portGlobals->vmemAdviseOSonFree) {
    if (rangeIsValid(identifier, address, byteAmount)) {
      ASSERT_VALUE_IS_PAGE_SIZE_ALIGNED(address, identifier->pageSize);
      ASSERT_VALUE_IS_PAGE_SIZE_ALIGNED(byteAmount, identifier->pageSize);

      if (byteAmount > 0) {
        switch (identifier->allocator) {
          case OMRPORT_VMEM_RESERVE_USED_MALLOC31:
            result = Pgser_Release((void*)address, byteAmount);
            break;
          case OMRPORT_VMEM_RESERVE_USED_J9MEM_ALLOCATE_MEMORY:
#if defined(OMR_ENV_DATA64)
            result = omrdiscard_data((void*)address,
                                     byteAmount >> ZOS_REAL_FRAME_SIZE_SHIFT);
#else
            result = Pgser_Release((void*)address, byteAmount);
#endif /* defined(OMR_ENV_DATA64) */
            break;
          case OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_LARGE_PAGES_BELOW_BAR:
          case OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_4K_PAGES_BELOW_BAR:
            result = Pgser_Release((void*)address, byteAmount);
            break;
#if defined(OMR_ENV_DATA64)
          case OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_4K_PAGES_IN_2TO32G_AREA: /* FALLTHROUGH */
          case OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_LARGE_PAGEABLE_PAGES_ABOVE_BAR: /* FALLTHROUGH */
          case OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_4K_PAGES_ABOVE_BAR: /* FALLTHROUGH
                                                                         */
          case OMRPORT_VMEM_RESERVE_USED_MOSERVICES:
            result = omrdiscard_data((void*)address,
                                     byteAmount >> ZOS_REAL_FRAME_SIZE_SHIFT);
            break;
          case OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_LARGE_FIXED_PAGES_ABOVE_BAR:
            /* do nothing, fixed pages cannot be de-committed. */
            result = 0;
            break;
#endif /* defined(OMR_ENV_DATA64) */
          default:
            /* Invalid allocator */
            Trc_PRT_Assert_ShouldNeverHappen();
        }
        if (0 != result) {
          Trc_PRT_vmem_omrvmem_decommit_memory_failure(
            result, address, byteAmount);
        }
      } else {
        /* nothing to de-commit. */
        Trc_PRT_vmem_decommit_memory_zero_pages();
        result = 0;
      }
    } else {
      result = -1;
      Trc_PRT_vmem_omrvmem_decommit_memory_invalidRange(
        identifier->address, identifier->size, address, byteAmount);
      portLibrary->error_set_last_error(
        portLibrary, result, OMRPORT_ERROR_VMEM_INVALID_PARAMS);
    }
  } else {
    if (!rangeIsValid(identifier, address, byteAmount)) {
      result = -1;
      Trc_PRT_vmem_omrvmem_decommit_memory_invalidRange(
        identifier->address, identifier->size, address, byteAmount);
      portLibrary->error_set_last_error(
        portLibrary, result, OMRPORT_ERROR_VMEM_INVALID_PARAMS);
    } else {
      ASSERT_VALUE_IS_PAGE_SIZE_ALIGNED(address, identifier->pageSize);
      ASSERT_VALUE_IS_PAGE_SIZE_ALIGNED(byteAmount, identifier->pageSize);

      /* JVM is not allowed to decommit, just return success */
      Trc_PRT_vmem_decommit_memory_not_allowed(
        portLibrary->portGlobals->vmemAdviseOSonFree);
      result = 0;
    }
  }
  Trc_PRT_vmem_omrvmem_decommit_memory_Exit(result);
  return (intptr_t)result;
}

int32_t
omrvmem_free_memory(struct OMRPortLibrary* portLibrary,
                    void* address,
                    uintptr_t byteAmount,
                    struct J9PortVmemIdentifier* identifier)
{
  int32_t rc = 0;

  Trc_PRT_vmem_omrvmem_free_memory_Entry(address, byteAmount);

  uintptr_t pageSize = identifier->pageSize;
  uintptr_t size = identifier->size;
  uintptr_t pageFlags = identifier->pageFlags;
  uintptr_t allocator = identifier->allocator;
  OMRMemCategory* category = identifier->category;

  update_vmemIdentifier(identifier, NULL, NULL, 0, 0, 0, 0, 0, NULL);

#if defined(LP_DEBUG)
  /* Using omrtty_printf in this function has caused the VM to crash on shutdown
   */
  printf("omrvmem_free_memory freeing %p, pageSize 0x%x pageFlags %u using "
         "allocate %zu\n",
         address,
         pageSize,
         pageFlags,
         allocator);
#endif /* LP_DEBUG */

  switch (allocator) {
    /* Default page Size */
    case OMRPORT_VMEM_RESERVE_USED_J9MEM_ALLOCATE_MEMORY: {
      /* calculating the base address is done in omrvmem_reserve_memory, so the
       * free address here must reflect the allocation address there */
      void* freeAddress = GET_BASE_PTR_FROM_ALIGNED_PTR(address);
      Trc_PRT_vmem_omrvmem_free_memory_using_mem_free_memory(address,
                                                             byteAmount);
      /* remember, we didn't give the user the baseAddress - we stored it - make
       * sure to free the baseAddress */
      portLibrary->mem_free_memory(portLibrary, freeAddress);
      /* No need to call omrmem_categories_decrement_counters - mem_free_memory
       * will have done it */
    } break;
    case OMRPORT_VMEM_RESERVE_USED_MALLOC31: {
      /* malloc31 is 8byte aligned */
      void* freeAddress = GET_BASE_PTR_FROM_ALIGNED_PTR(address);
      Trc_PRT_vmem_omrvmem_free_memory_using_mem_free_memory32(address,
                                                               byteAmount);
      free(freeAddress);
      omrmem_categories_decrement_counters(category, size);
    } break;
    case OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_LARGE_PAGES_BELOW_BAR: /* FALLTHROUGH
                                                                      */
    case OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_4K_PAGES_BELOW_BAR:
      Trc_PRT_vmem_omrvmem_free_memory_using_free_memory_below_bar(address,
                                                                   byteAmount);
      rc = omrfree_memory_below_bar(address, size, OMRPORT_VMEM_SUBPOOL);
      omrmem_categories_decrement_counters(category, size);
      break;
#if defined(OMR_ENV_DATA64)
    case OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_4K_PAGES_IN_2TO32G_AREA: /* FALLTHROUGH
                                                                        */
    case OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_LARGE_FIXED_PAGES_ABOVE_BAR: /* FALLTHROUGH
                                                                            */
    case OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_LARGE_PAGEABLE_PAGES_ABOVE_BAR: /* FALLTHROUGH */
    {
      const char* const ttkn = PPG_ipt_ttoken;

      Trc_PRT_vmem_omrvmem_free_memory_using_free_memory_above_bar(
        address, byteAmount, allocator);
      rc = omrfree_memory_above_bar(address, ttkn);
      omrmem_categories_decrement_counters(category, size);
    } break;
    case OMRPORT_VMEM_RESERVE_USED_MOSERVICES:
      Trc_PRT_vmem_omrvmem_free_memory_using_moservices(
        address, byteAmount, allocator); /* FALLTHROUGH */
    case OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_4K_PAGES_ABOVE_BAR:
      Trc_PRT_vmem_omrvmem_free_memory_using_free_memory_above_bar(
        address, byteAmount, allocator);
      rc = __moservices(__MO_DETACH, 0, NULL, &address);
      omrmem_categories_decrement_counters(category, size);
      break;
#endif
    default:
      /* Invalid allocator */
      rc = -1;
      break;
  } /* switch {identifier->allocator) */
  Trc_PRT_vmem_omrvmem_free_memory_Exit(rc);

#if defined(LP_DEBUG)
  printf("omrvmem_free_memory rc = %u\n", rc);
#endif /* LP_DEBUG */

  return rc;
}

static void*
default_pageSize_reserve_low_memory(struct OMRPortLibrary* portLibrary,
                                    uintptr_t byteAmount,
                                    struct J9PortVmemIdentifier* identifier,
                                    uintptr_t mode,
                                    OMRMemCategory* category)
{
  void* ptr = NULL;
  uintptr_t allocSize = 0;
  uintptr_t allocator = OMRPORT_VMEM_RESERVE_USED_INVALID;

  Trc_PRT_vmem_default_reserve_entry(0, byteAmount);

  if (OMR_ARE_ANY_BITS_SET(OMRPORT_VMEM_MEMORY_MODE_VIRTUAL, mode)) {
    /* No need to make byteAmount pagesize (=4K) aligned, as the caller
     * omrvmem_reserve_memory_ex() already ensures that */
    allocSize = byteAmount;
    Trc_PRT_vmem_default_reserve_low_using_4K_pages_below_bar(byteAmount);
    ptr = omrallocate_4K_pages_below_bar(allocSize, OMRPORT_VMEM_SUBPOOL);
    allocator = OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_4K_PAGES_BELOW_BAR;
  } else {
    /* malloc31 is not guaranteed to be 4k aligned.  So align to 4k.  Add an
     * extra uintptr_t to store the original address, which can be used by free
     */
    allocSize = GET_4K_ALIGNED_ALLOCATION_SIZE(byteAmount);
    Trc_PRT_vmem_default_reserve_using_mem_allocate_memory32(allocSize);
    ptr = __malloc31(allocSize);
    allocator = OMRPORT_VMEM_RESERVE_USED_MALLOC31;
    if (NULL != ptr) {
      uintptr_t alignedPtr;
      GET_4K_ALIGNED_PTR(alignedPtr, ptr);
      ptr = (void*)alignedPtr;
    }
  }

  if (NULL != ptr) {
    omrmem_categories_increment_counters(category, allocSize);
    /* Update identifier and commit memory if required, else return reserved
     * memory */
    update_vmemIdentifier(identifier,
                          (void*)ptr,
                          (void*)ptr,
                          allocSize,
                          mode,
                          FOUR_K,
                          OMRPORT_VMEM_PAGE_FLAG_PAGEABLE,
                          allocator,
                          category);
    if (0 != (OMRPORT_VMEM_MEMORY_MODE_COMMIT & mode)) {
      ptr =
        omrvmem_commit_memory(portLibrary, (void*)ptr, byteAmount, identifier);
    }
  } else {
    Trc_PRT_vmem_default_reserve_failed(0, byteAmount);
    update_vmemIdentifier(identifier, NULL, NULL, 0, 0, 0, 0, 0, NULL);
  }
  Trc_PRT_vmem_default_reserve_exit(ptr, 0, byteAmount);
  return ptr;
}

/*
 * Use STORAGE OBTAIN macro via omrallocate_1M_pageable_pages_below_bar() to
 * allocate memory below 2GB bar. Allocated memory is backed by 1MB page size.
 *
 * @params[in] portLibrary the portLibrary
 * @params[out] identifier the vmem identifier to updated with the results of
 * the allocation attempt
 * @params[in] mode the mode
 * @params[in] byteAmount the size to allocate
 * @params[in] category Memory category
 *
 * @return NULL on failure, otherwise pointer to the memory that was allocated.
 */
static void*
reserve1MPageableBelowBar(struct OMRPortLibrary* portLibrary,
                          J9PortVmemIdentifier* identifier,
                          uintptr_t mode,
                          uintptr_t byteAmount,
                          OMRMemCategory* category)
{
  void* ptr = NULL;
  uintptr_t actualSize = byteAmount;
  uintptr_t allocator = OMRPORT_VMEM_RESERVE_USED_INVALID;

  Trc_PRT_vmem_reserve1MPageableBelowBar_Entry(byteAmount);

  LP_DEBUG_PRINTF2(
    "\t reserve1MPageableBelowBar mode = 0x%zx, byteAmount = 0x%zx\n",
    mode,
    byteAmount);
  LP_DEBUG_PRINTF1("\t reserve1MPageableBelowBar calling "
                   "omrallocate_1M_pageable_pages_below_bar(0x%x bytes)\n",
                   byteAmount);

  ptr =
    omrallocate_1M_pageable_pages_below_bar(byteAmount, OMRPORT_VMEM_SUBPOOL);

  LP_DEBUG_PRINTF2(
    "\t omrallocate_1M_pageable_pages_below_bar(0x%x bytes) returned 0x%zx\n",
    byteAmount,
    ptr);

  if (NULL != ptr) {
    allocator = OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_LARGE_PAGES_BELOW_BAR;
    omrmem_categories_increment_counters(category, byteAmount);
    update_vmemIdentifier(identifier,
                          ptr,
                          ptr,
                          byteAmount,
                          mode,
                          ONE_M,
                          OMRPORT_VMEM_PAGE_FLAG_PAGEABLE,
                          allocator,
                          category);
  } else {
    update_vmemIdentifier(identifier, 0, 0, 0, 0, 0, 0, 0, NULL);
  }

  LP_DEBUG_PRINTF1("\t reserve1MPageableBelowBar base address = %p\n", ptr);

  Trc_PRT_vmem_reserve1MPageableBelowBar_Exit(ptr);

  return ptr;
}

#if defined(OMR_ENV_DATA64)
/*
 * Use IARV64 macro via omrallocate_xxx family of routines to allocate memory
 *above 2GB bar. For large page sizes (> 4KB), it attempts to use page sizes in
 *following order (provided OMRPORT_VMEM_STRICT_PAGE_SIZE is not set) to satisfy
 *the allocation request, starting with the requested page size :
 * 	- 2GB fixed pages
 *	- 1MB fixed pages
 *	- 1MB pageable pages
 *
 * This is the reverse order of page sizes stored in PPG_vmem_pageSize array.
 *
 * If the order in PPG_vmem_pageSize is changed, this method would have to be
 *modified to maintain above mentioned order of page sizes to be attempted.
 *
 * @params[in] portLibrary the portLibrary
 * @params[out] identifier the vmem identifier to be updated with the results of
 *the allocation attempt
 * @params[in] mode the mode
 * @params[in] byteAmount the size to allocate
 * @params[in] pageSize the pageSize to request
 * @params[in] pageFlags flags indicating type of page to be used
 * @params[in] options flags to indicate allocation strategy
 * @params[in] category Memory category
 *
 * @return NULL on failure, otherwise pointer to the memory that was allocated.
 */
static void*
reservePagesAboveBar(struct OMRPortLibrary* portLibrary,
                     J9PortVmemIdentifier* identifier,
                     uintptr_t mode,
                     uintptr_t byteAmount,
                     uintptr_t pageSize,
                     uintptr_t pageFlags,
                     uintptr_t options,
                     OMRMemCategory* category)
{
  /* The maximum amount of memory that can be allocated with
   * userExtendedPrivateAreaMemoryType detected for 2To32G and 2To64 */
#define MAX_2TO32G_MEMORY_IN_MB                                                \
  ((UDATA)30 * 1024) /* unit is MB i.e. 30*1024 MB = 30 GB */
#define MAX_2TO64G_MEMORY_IN_MB                                                \
  ((UDATA)62 * 1024) /* unit is MB i.e. 62*1024 MB = 62 GB */

  void* ptr = NULL;
  uintptr_t numSegments = 0;
  uintptr_t numUnits = 0;
  uintptr_t actualSize = byteAmount;
  uintptr_t allocator = OMRPORT_VMEM_RESERVE_USED_INVALID;
  uintptr_t actualPageSize = 0;
  uintptr_t actualPageFlags = OMRPORT_VMEM_PAGE_FLAG_NOT_USED;
  BOOLEAN useStrictPageSize = (OMRPORT_VMEM_STRICT_PAGE_SIZE ==
                               (OMRPORT_VMEM_STRICT_PAGE_SIZE & options));
  uintptr_t userExtendedPrivateAreaMemoryType = ZOS64_VMEM_ABOVE_BAR_GENERAL;
  uintptr_t userExtendedPrivateAreaMemoryMax = 0;

  if (OMRPORT_VMEM_ZOS_USE2TO32G_AREA ==
      (OMRPORT_VMEM_ZOS_USE2TO32G_AREA & options)) {
    userExtendedPrivateAreaMemoryType = PPG_userExtendedPrivateAreaMemoryType;
    /*
     * Requesting more memory as supported would cause ZOS System failure
     * To prevent this an amount requested must be controlled manually
     */
    switch (userExtendedPrivateAreaMemoryType) {
      case ZOS64_VMEM_ABOVE_BAR_GENERAL:
        /* 2To32G or 2To64 are not supported */
      default:
        break;
      case ZOS64_VMEM_2_TO_32G:
        /* 2To32G is supported */
        userExtendedPrivateAreaMemoryMax = MAX_2TO32G_MEMORY_IN_MB;
        break;
      case ZOS64_VMEM_2_TO_64G:
        /* 2To64G is supported */
        userExtendedPrivateAreaMemoryMax = MAX_2TO64G_MEMORY_IN_MB;
        break;
    }
  }

  Trc_PRT_vmem_reservePagesAboveBar_Entry(byteAmount,
                                          pageSize,
                                          pageFlags,
                                          options,
                                          userExtendedPrivateAreaMemoryType);

  LP_DEBUG_PRINTF5(
    "\t reservePagesAboveBar byteAmount=0x%zx, pageSize=x%zx, pageFlags=0x%zx, "
    "useStrictPageSize=0x%x, userExtendedPrivateAreaMemoryType=0x%x\n",
    byteAmount,
    pageSize,
    pageFlags,
    useStrictPageSize,
    userExtendedPrivateAreaMemoryType);

  /* determine number of 1MB segments required */
  numSegments = ((byteAmount + ONE_M - 1) & (~(ONE_M - 1))) / ONE_M;

  /* determine number of 2GB units required */
  numUnits = ((byteAmount + TWO_G - 1) & (~(TWO_G - 1))) / TWO_G;

  if ((ZOS64_VMEM_ABOVE_BAR_GENERAL != userExtendedPrivateAreaMemoryType) &&
      (numSegments > userExtendedPrivateAreaMemoryMax)) {
    if (TWO_G == pageSize) {
      LP_DEBUG_PRINTF2("\t *** ERROR reservePagesAboveBar max 1GB units is "
                       "0x%zx, requesting (0x%zx)\n",
                       (userExtendedPrivateAreaMemoryMax / 1024),
                       numUnits);
    } else {
      LP_DEBUG_PRINTF2("\t *** ERROR reservePagesAboveBar max 1MB segments is "
                       "0x%zx, requesting (0x%zx)\n",
                       userExtendedPrivateAreaMemoryMax,
                       numSegments);
    }
    goto _end;
  }

  if ((FOUR_K == pageSize) &&
      (ZOS64_VMEM_ABOVE_BAR_GENERAL != userExtendedPrivateAreaMemoryType)) {
    const char* const ttkn = PPG_ipt_ttoken;

    LP_DEBUG_PRINTF1(
      "\t reservePagesAboveBar calling "
      "omrallocate_4K_pages_in_userExtendedPrivate_area(0x%zx)\n",
      numSegments);

    Trc_PRT_vmem_reservePagesAboveBar_allocate_4K_pages_in_2to32G_area(
      numSegments);
    allocator = OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_4K_PAGES_IN_2TO32G_AREA;
    ptr = omrallocate_4K_pages_in_userExtendedPrivateArea(
      numSegments, userExtendedPrivateAreaMemoryType, ttkn);

    LP_DEBUG_PRINTF2(
      "\t omrallocate_4K_pages_in_userExtendedPrivateArea(0x%zx) returned "
      "0x%zx\n",
      numSegments,
      ptr);

    if (NULL != ptr) {
      actualPageSize = pageSize;
      SET_PAGE_TYPE(actualPageFlags, OMRPORT_VMEM_PAGE_FLAG_PAGEABLE);
    }
  } else {
    intptr_t index = 0;

    /* Search requested page size in the page size array */
    do {
      index++; /* we can skip first entry as it points to default page size */
      if ((pageSize == PPG_vmem_pageSize[index]) &&
          (pageFlags == PPG_vmem_pageFlags[index])) {
        break;
      }
    } while (0 != PPG_vmem_pageSize[index]);

    if (0 != PPG_vmem_pageSize[index]) {
      if ((index > 0) && (TWO_G == PPG_vmem_pageSize[index]) &&
          (0 != (OMRPORT_VMEM_PAGE_FLAG_FIXED & PPG_vmem_pageFlags[index]))) {
        const char* const ttkn = PPG_ipt_ttoken;

        LP_DEBUG_PRINTF2(
          "\t reservePagesAboveBar calling omrallocate_2G_pages(0x%zx, 0x%x)\n",
          numUnits,
          userExtendedPrivateAreaMemoryType);
        Trc_PRT_vmem_reservePagesAboveBar_allocate_large_2G_pages(
          numUnits, userExtendedPrivateAreaMemoryType);
        ptr = omrallocate_2G_pages(
          numUnits, userExtendedPrivateAreaMemoryType, ttkn);

        LP_DEBUG_PRINTF3(
          "\t omrallocate_2G_pages(0x%zx, 0x%x) returned 0x%zx\n",
          numUnits,
          userExtendedPrivateAreaMemoryType,
          ptr);
        if (NULL == ptr) {
          if (TRUE == useStrictPageSize) {
            goto _end;
          } else {
            index--;
          }
        } else {
          SET_PAGE_TYPE(actualPageFlags, OMRPORT_VMEM_PAGE_FLAG_FIXED);
          allocator =
            OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_LARGE_FIXED_PAGES_ABOVE_BAR;
        }
      }
      if ((NULL == ptr) && (index > 0) && (ONE_M == PPG_vmem_pageSize[index]) &&
          (0 != (OMRPORT_VMEM_PAGE_FLAG_FIXED & PPG_vmem_pageFlags[index]))) {
        const char* const ttkn = PPG_ipt_ttoken;

        LP_DEBUG_PRINTF2("\t reservePagesAboveBar calling "
                         "omrallocate_1M_fixed_pages(0x%zx, 0x%x)\n",
                         numSegments,
                         userExtendedPrivateAreaMemoryType);
        Trc_PRT_vmem_reservePagesAboveBar_allocate_large_pages(
          numSegments, userExtendedPrivateAreaMemoryType);
        ptr = omrallocate_1M_fixed_pages(
          numSegments, userExtendedPrivateAreaMemoryType, ttkn);

        LP_DEBUG_PRINTF3(
          "\t omrallocate_1M_fixed_pages(0x%zx, 0x%x) returned 0x%zx\n",
          numSegments,
          userExtendedPrivateAreaMemoryType,
          ptr);
        if (NULL == ptr) {
          if (TRUE == useStrictPageSize) {
            goto _end;
          } else {
            index--;
          }
        } else {
          SET_PAGE_TYPE(actualPageFlags, OMRPORT_VMEM_PAGE_FLAG_FIXED);
          allocator =
            OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_LARGE_FIXED_PAGES_ABOVE_BAR;
        }
      }
      if ((NULL == ptr) && (index > 0) && (ONE_M == PPG_vmem_pageSize[index]) &&
          (0 !=
           (OMRPORT_VMEM_PAGE_FLAG_PAGEABLE & PPG_vmem_pageFlags[index]))) {
        const char* const ttkn = PPG_ipt_ttoken;

        LP_DEBUG_PRINTF2(
          "\t reservePagesAboveBar calling "
          "omrallocate_1M_pageable_pages_above_bar(0x%zx, 0x%x)\n",
          numSegments,
          userExtendedPrivateAreaMemoryType);
        Trc_PRT_vmem_reservePagesAboveBar_allocate_large_pageable_pages_above_bar(
          numSegments, userExtendedPrivateAreaMemoryType);
        ptr = omrallocate_1M_pageable_pages_above_bar(
          numSegments, userExtendedPrivateAreaMemoryType, ttkn);

        LP_DEBUG_PRINTF3("\t omrallocate_1M_pageable_pages_above_bar(0x%zx, "
                         "0x%x) returned 0x%zx\n",
                         numSegments,
                         userExtendedPrivateAreaMemoryType,
                         ptr);
        if (NULL == ptr) {
          if (TRUE == useStrictPageSize) {
            goto _end;
          } else {
            index--;
          }
        } else {
          SET_PAGE_TYPE(actualPageFlags, OMRPORT_VMEM_PAGE_FLAG_PAGEABLE);
          allocator =
            OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_LARGE_PAGEABLE_PAGES_ABOVE_BAR;
        }
      }
      if (NULL != ptr) {
        actualPageSize = PPG_vmem_pageSize[index];
      }
    } else {
      /* error, we were given an invalid page size */
      LP_DEBUG_PRINTF4(
        "\t reservePagesAboveBar invalid params: byteAmount = 0x%x, pageSize = "
        "0x%x, pageFlags = 0x%x, userExtendedPrivateAreaMemoryType = 0x%x\n",
        byteAmount,
        pageSize,
        pageFlags,
        userExtendedPrivateAreaMemoryType);
    }
  }

_end:
  if (NULL != ptr) {
    omrmem_categories_increment_counters(category, byteAmount);
    update_vmemIdentifier(identifier,
                          ptr,
                          ptr,
                          byteAmount,
                          mode,
                          actualPageSize,
                          actualPageFlags,
                          allocator,
                          category);
  } else {
    update_vmemIdentifier(identifier, 0, 0, 0, 0, 0, 0, 0, NULL);
  }

  LP_DEBUG_PRINTF1("\t reservePagesAboveBar base address = %p\n", ptr);
  Trc_PRT_vmem_reservePagesAboveBar_Exit(ptr);
  return ptr;
}
#endif /* OMR_ENV_DATA64 */

static void*
default_pageSize_reserve_memory(struct OMRPortLibrary* portLibrary,
                                uintptr_t byteAmount,
                                struct J9PortVmemIdentifier* identifier,
                                uintptr_t mode,
                                OMRMemCategory* category)
{
  void* ptr = NULL;
  uintptr_t allocSize = 0;
  uintptr_t allocator = OMRPORT_VMEM_RESERVE_USED_INVALID;

  if (mode & OMRPORT_VMEM_MEMORY_MODE_SHARE_FILE_OPEN) {
    portLibrary->error_set_last_error(
      portLibrary, errno, OMRPORT_ERROR_VMEM_NOT_SUPPORTED);
    return ptr;
  }

  Trc_PRT_vmem_default_reserve_entry(FOUR_GIG_LIMIT, byteAmount);

  if (OMR_ARE_ANY_BITS_SET(OMRPORT_VMEM_MEMORY_MODE_VIRTUAL, mode)) {
#if defined(OMR_ENV_DATA64)
    /* Need to make byteAmount 1M aligned as __moservices()/IARV64 macro
     * allocates memory in 1M chunks */
    uintptr_t numSegments = ((byteAmount + ONE_M - 1) & (~(ONE_M - 1))) / ONE_M;
    allocSize = numSegments * ONE_M;
    Trc_PRT_vmem_default_reserve_using_4K_pages_above_bar(numSegments);
#if 0
		/* omrallocate_4K_pages_above_bar() uses IARV64 to reserve memory.
		 * Current implementation of calling IARV64 is known to fail in multi-thread scenario
		 * when the memory is freed by a thread other than the one that allocated it.
		 */
		ptr = omrallocate_4K_pages_above_bar(allocSize);
#else  /* if 0 */
    {
      __mopl_t mymopl;
      int32_t rc;

      memset(&mymopl, 0, sizeof(__mopl_t));
      mymopl.__mopldumppriority = __MO_DUMP_PRIORITY_HEAP;
      mymopl.__moplrequestsize = numSegments;
      rc = __moservices(__MO_GETSTOR, sizeof(mymopl), &mymopl, &ptr);
      if (0 != rc) {
        /* As per z/OS C/C++ Run-Time Library Reference, __moservices() returns
         * EINVAL or EMVSERR in case of failure. EINVAL indicates invalid
         * argument. More detailed information is returned by __errno2().
         * EMVSERR indicates underlying IARV64 call failed.
         */
        ptr = NULL;
        if (EINVAL == errno) {
          Trc_PRT_vmem_default_reserve_using_4K_pages_above_bar_invalid_argument(
            rc, __errno2());
        } else if (EMVSERR == errno) {
          Trc_PRT_vmem_default_reserve_using_4K_pages_above_bar_iarv64_failed(
            mymopl.__mopl_iarv64_rc, mymopl.__mopl_iarv64_rsn);
        }
      } else {
        allocator = OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_4K_PAGES_ABOVE_BAR;
      }
    }
#endif /* if 0 */

#else  /* defined(OMR_ENV_DATA64) */
    /* No need to make byteAmount pagesize (=4K) aligned, as the caller
     * omrvmem_reserve_memory_ex() already ensures that */
    Trc_PRT_vmem_default_reserve_using_4K_pages_below_bar(byteAmount);
    ptr = omrallocate_4K_pages_below_bar(allocSize, OMRPORT_VMEM_SUBPOOL);
    allocator = OMRPORT_VMEM_RESERVE_USED_J9ALLOCATE_4K_PAGES_BELOW_BAR;
#endif /* defined(OMR_ENV_DATA64) */
    if (NULL != ptr) {
      omrmem_categories_increment_counters(category, allocSize);
    }
  } else {
    /* malloc is not guaranteed to be 4k aligned.  So align to 4k.  Add an extra
     * uintptr_t to store the original address, which can be used by free
     */
    allocSize = GET_4K_ALIGNED_ALLOCATION_SIZE(byteAmount);

    Trc_PRT_vmem_default_reserve_using_mem_allocate_memory(byteAmount);
    ptr = portLibrary->mem_allocate_memory(
      portLibrary, allocSize, OMR_GET_CALLSITE(), category->categoryCode);
    allocator = OMRPORT_VMEM_RESERVE_USED_J9MEM_ALLOCATE_MEMORY;
    if (NULL != ptr) {
      uintptr_t alignedPtr;
      GET_4K_ALIGNED_PTR(alignedPtr, ptr);
      ptr = (void*)alignedPtr;
    }
  }

  if (NULL != ptr) {
    /* Update identifier and commit memory if required, else return reserved
     * memory */
    update_vmemIdentifier(identifier,
                          (void*)ptr,
                          (void*)ptr,
                          allocSize,
                          mode,
                          FOUR_K,
                          OMRPORT_VMEM_PAGE_FLAG_PAGEABLE,
                          allocator,
                          category);
    if (0 != (OMRPORT_VMEM_MEMORY_MODE_COMMIT & mode)) {
      ptr =
        omrvmem_commit_memory(portLibrary, (void*)ptr, byteAmount, identifier);
    }
  } else {
    Trc_PRT_vmem_default_reserve_failed(FOUR_GIG_LIMIT, byteAmount);
    update_vmemIdentifier(identifier, NULL, NULL, 0, 0, 0, 0, 0, NULL);
  }
  Trc_PRT_vmem_default_reserve_exit(ptr, FOUR_GIG_LIMIT, byteAmount);
  return ptr;
}

#if defined(OMR_ENV_DATA64)
#if __EDC_TARGET < __EDC_LE4201
#define __MOPL_PAGEFRAMESIZE_PAGEABLE1MEG 0x20000000
#define __MOPL_PAGEFRAMESIZE_2G 0x10000000
#define __MOPL_USE2GTO32G 0x08000000
#endif /* __EDC_TARGET >= __EDC_LE4201 */

/*
 * Use this only on V2R2 or greater.
 */
static void*
reserve_memory_with_moservices(struct OMRPortLibrary* portLibrary,
                               struct J9PortVmemIdentifier* identifier,
                               struct J9PortVmemParams* params,
                               OMRMemCategory* category)
{
  void* ptr = NULL;
  /* Need to make byteAmount 1M aligned as __moservices()/IARV64 macro allocates
   * memory in 1M chunks */
  uintptr_t allocSize = ROUND_UP_TO_POWEROF2(params->byteAmount, ONE_M);
  uintptr_t numSegments = allocSize / ONE_M;
  __mopl_t mymopl;
  int32_t rc = 0;
  Trc_PRT_vmem_reserve_using_moservices_entry(params->pageSize,
                                              params->byteAmount);
  memset(&mymopl, 0, sizeof(__mopl_t));
  mymopl.__mopldumppriority = __MO_DUMP_PRIORITY_HEAP;
  mymopl.__moplrequestsize = numSegments;
  switch (params->pageSize) {
    case FOUR_K: /* 0 == __moplgetstorflags means 4k */
      if (!OMR_ARE_ANY_BITS_SET(params->pageFlags,
                                OMRPORT_VMEM_PAGE_FLAG_PAGEABLE)) {
        Trc_PRT_vmem_reserve_memory_using_moservices_invalid_page_flags(
          params->pageSize, params->pageFlags);
        rc = -1;
      }
      break;
    case ONE_M:
      if (OMR_ARE_ANY_BITS_SET(params->pageFlags,
                               OMRPORT_VMEM_PAGE_FLAG_PAGEABLE)) {
        mymopl.__moplgetstorflags = __MOPL_PAGEFRAMESIZE_PAGEABLE1MEG;
        /* If pageable 1MB page frames are not available at first reference,
         * pageable 4K page frames will be used. */
      } else {
        mymopl.__moplgetstorflags = __MOPL_PAGEFRAMESIZE1MEG;
      }
      break;
    case TWO_G:
      if (OMR_ARE_ANY_BITS_SET(params->pageFlags,
                               OMRPORT_VMEM_PAGE_FLAG_PAGEABLE)) {
        Trc_PRT_vmem_reserve_memory_using_moservices_invalid_page_flags(
          params->pageSize, params->pageFlags);
        rc = -1;
      } else {
        mymopl.__moplgetstorflags = __MOPL_PAGEFRAMESIZE_2G;
      }
      break;
    default:
      Trc_PRT_vmem_reserve_memory_using_moservices_invalid_page_size(
        params->pageSize);
      rc = -1;
  }
  if (0 == rc) { /* valid page size */
    rc = __moservices(__MO_GETSTOR, sizeof(mymopl), &mymopl, &ptr);
  }
  if (0 != rc) {
    /* As per z/OS C/C++ Run-Time Library Reference, __moservices() returns
     * EINVAL or EMVSERR in case of failure. EINVAL indicates invalid argument.
     * More detailed information is returned by __errno2(). EMVSERR indicates
     * underlying IARV64 call failed.
     */
    ptr = NULL;
    if (EINVAL == errno) {
      Trc_PRT_vmem_reserve_using_moservices_invalid_argument(rc, __errno2());
    } else if (EMVSERR == errno) {
      Trc_PRT_vmem_reserve_using_moservices_failed(mymopl.__mopl_iarv64_rc,
                                                   mymopl.__mopl_iarv64_rsn);
    }
    update_vmemIdentifier(identifier,
                          NULL,
                          NULL,
                          0,
                          0,
                          0,
                          0,
                          OMRPORT_VMEM_RESERVE_USED_MOSERVICES,
                          NULL);
  } else {
    omrmem_categories_increment_counters(category, allocSize);
    /* Update identifier and commit memory if required, else return reserved
     * memory */
    update_vmemIdentifier(identifier,
                          (void*)ptr,
                          (void*)ptr,
                          allocSize,
                          params->mode,
                          params->pageSize,
                          OMRPORT_VMEM_PAGE_FLAG_PAGEABLE,
                          OMRPORT_VMEM_RESERVE_USED_MOSERVICES,
                          category);
    if (OMR_ARE_ANY_BITS_SET(params->mode, OMRPORT_VMEM_MEMORY_MODE_COMMIT)) {
      ptr =
        omrvmem_commit_memory(portLibrary, (void*)ptr, allocSize, identifier);
    }
  }
  Trc_PRT_vmem_reserve_using_moservices_exit(ptr, params->byteAmount);
  return ptr;
}
#endif /* defined(OMR_ENV_DATA64) */

int32_t
omrvmem_vmem_params_init(struct OMRPortLibrary* portLibrary,
                         struct J9PortVmemParams* params)
{
  memset(params, 0, sizeof(struct J9PortVmemParams));
  params->startAddress = NULL;
  params->endAddress = OMRPORT_VMEM_MAX_ADDRESS;
  params->byteAmount = 0;
  params->pageSize = PPG_vmem_pageSize[0];
  params->pageFlags = PPG_vmem_pageFlags[0];
  params->mode = OMRPORT_VMEM_MEMORY_MODE_READ | OMRPORT_VMEM_MEMORY_MODE_WRITE;
  params->options = 0;
  params->category = OMRMEM_CATEGORY_UNKNOWN;
  params->alignmentInBytes = 0;
  return 0;
}

void*
omrvmem_reserve_memory(struct OMRPortLibrary* portLibrary,
                       void* address,
                       uintptr_t byteAmount,
                       struct J9PortVmemIdentifier* identifier,
                       uintptr_t mode,
                       uintptr_t pageSize,
                       uint32_t category)
{
  struct J9PortVmemParams params;
  omrvmem_vmem_params_init(portLibrary, &params);
  if (NULL != address) {
    params.startAddress = address;
    params.endAddress = address;
  }
  params.byteAmount = byteAmount;
  params.mode = mode;
  params.pageSize = pageSize;
  if (FOUR_K == pageSize) {
    SET_PAGE_TYPE(params.pageFlags, OMRPORT_VMEM_PAGE_FLAG_PAGEABLE);
  } else {
    SET_PAGE_TYPE(params.pageFlags, OMRPORT_VMEM_PAGE_FLAG_FIXED);
  }
  params.options = 0;
  params.category = category;
  return portLibrary->vmem_reserve_memory_ex(portLibrary, identifier, &params);
}

void*
omrvmem_reserve_memory_ex(struct OMRPortLibrary* portLibrary,
                          struct J9PortVmemIdentifier* identifier,
                          struct J9PortVmemParams* callerParams)
{
  /*
   * There are 6 allocation routines:
   *  1. malloc 							-
   * default_pageSize_reserve_memory()
   *  2. malloc 31 						-
   * default_pageSize_reserve_low_memory()
   *  3. IARV64 large 1MB pageable pages 	- 	reservePagesAboveBar()
   *  4. IARV64 large 1MB fixed pages 	- 	reservePagesAboveBar()
   *  5. IARV64 large 2GB fixed pages 	- 	reservePagesAboveBar()
   *  6. STORAGE large 1MB pageable pages - 	reserve1MPageableBelowBar()
   *
   *  Routines using IARV64 allocate memory above 2GB bar. Hence, they are
   * applicaable for 64-bit z/OS systems only. Routines using STORAGE allocate
   * memory below 2GB bar. Such routines can be used on both 31-bit and 64-bit
   * z/OS system.s
   */

  /* create a local copy of the parameters since we may change them and we don't
   * want to change the caller's arguments */
  /* The "includeAlignmentInAllocation" helper creates a copy of the struct but
   * also, until native alignment is implemented, adjusts the parameters to
   * ensure that the requested alignment can be honoured within the allocated
   * block.  Note that we still want to create a copy of the structure (because
   * this function modifies the struct) if we implement native alignment and
   * remove this helper.
   */
  struct J9PortVmemParams params = includeAlignmentInAllocation(callerParams);
  void* baseAddress = NULL;
  BOOLEAN useStrictAddress = (OMRPORT_VMEM_STRICT_ADDRESS ==
                              (OMRPORT_VMEM_STRICT_ADDRESS & params.options));
  BOOLEAN use2To32GArea = (OMRPORT_VMEM_ZOS_USE2TO32G_AREA ==
                           (OMRPORT_VMEM_ZOS_USE2TO32G_AREA & params.options));
  OMRMemCategory* category =
    omrmem_get_category(portLibrary, callerParams->category);

  LP_DEBUG_PRINTF4("\n omrvmem_reserve_memory_ex: address=0x%zx, "
                   "byteAmount=0x%zx, pageSize=0x%zx, pageFlags=0x%zx\n",
                   params.startAddress,
                   params.byteAmount,
                   params.pageSize,
                   params.pageFlags);

  Trc_PRT_vmem_omrvmem_reserve_memory_Entry_replacement_v1(
    params.startAddress, params.byteAmount, params.pageSize, params.pageFlags);

  Assert_PRT_true(params.startAddress <= params.endAddress);
  ASSERT_VALUE_IS_PAGE_SIZE_ALIGNED(params.byteAmount, params.pageSize);

#if defined(OMR_ENV_DATA64)
  /* Invalid input */
  if (use2To32GArea &&
      (ZOS64_VMEM_ABOVE_BAR_GENERAL == PPG_userExtendedPrivateAreaMemoryType)) {
    /* We want to explicitly fail here even though malloc may be able to satisfy
     * the request as the caller needs to know with absolute certainty whether
     * or not they can rely on the 2to32G support being there
     *
     * Having done the check here, we only need to check for the request for
     * OMRPORT_VMEM_ZOS_USE2TO32G_AREA later on knowing that if they had asked
     * for it and made it that far that the support is there
     */

    LP_DEBUG_PRINTF(
      "\n omrvmem_reserve_memory_ex: OMRPORT_VMEM_ZOS_USE2TO32G_AREA requested "
      "but not supported\n");

    update_vmemIdentifier(identifier, NULL, NULL, 0, 0, 0, 0, 0, NULL);
    Trc_PRT_vmem_omrvmem_reserve_memory_invalid_input();
#else  /* OMR_ENV_DATA64 */
  if (0) {
#endif /* OMR_ENV_DATA64 */
  } else if (0 == params.pageSize) {
    /* Invalid input */
    update_vmemIdentifier(identifier, NULL, NULL, 0, 0, 0, 0, 0, NULL);
    Trc_PRT_vmem_omrvmem_reserve_memory_invalid_input();
  } else {
#if defined(OMR_ENV_DATA64)
    if (((UDATA)params.startAddress >= TWO_G) && isRmode64Supported() &&
        !use2To32GArea &&
        OMR_ARE_ALL_BITS_SET(params.mode, OMRPORT_VMEM_MEMORY_MODE_EXECUTE)) {
      baseAddress = reserve_memory_with_moservices(
        portLibrary, identifier, &params, category);
    } else
#endif /* OMR_ENV_DATA64 */
      if (FOUR_K == params.pageSize) {
      if (0 != (params.pageFlags & OMRPORT_VMEM_PAGE_FLAG_PAGEABLE)) {
        baseAddress =
          reserve4KPages(portLibrary, identifier, &params, category);
      } else {
        update_vmemIdentifier(identifier, NULL, NULL, 0, 0, 0, 0, 0, NULL);
        Trc_PRT_vmem_omrvmem_reserve_memory_invalid_input();
      }
    } else {
      baseAddress = reservePages(portLibrary, identifier, &params, category);
    }

    if ((NULL != baseAddress) && isStrictAndOutOfRange(&params, baseAddress)) {
      /* if strict flag is set and returned pointer is not within range then
       * fail */
      omrvmem_free_memory(
        portLibrary, baseAddress, params.byteAmount, identifier);
      Trc_PRT_vmem_omrvmem_reserve_memory_ex_UnableToAllocateWithinSpecifiedRange(
        params.byteAmount, params.startAddress, params.endAddress);
      baseAddress = NULL;
      update_vmemIdentifier(identifier, NULL, NULL, 0, 0, 0, 0, 0, NULL);
    }
  }
  Trc_PRT_vmem_omrvmem_reserve_memory_Exit_replacement(baseAddress,
                                                       params.startAddress);

  LP_DEBUG_PRINTF2(
    "\t omrvmem_reserve_memory_ex returning 0x%zx, allocator = %i, \n",
    baseAddress,
    identifier->allocator);
  return adjustForRequestedAlignment(callerParams, baseAddress);
}

/*
 * Primary responsibility of this method is to call routines to allocate large
 *pages. Before making any further calls, it performs some basic validation to
 *ensure the request is valid and is satisfiable:
 * 1. If the requested page size is not a supported large page size (which
 *doesn't include 4K page), it fails.
 * 2. If OMRPORT_VMEM_MEMORY_MODE_EXECUTE and OMRPORT_VMEM_ZOS_USE2TO32G_AREA
 *are both set, it fails.
 * 3. If request is for low memory range (< 4GB), and
 *OMRPORT_VMEM_ZOS_USE2TO32G_AREA is set, it tries to allocate memory above the
 *bar, failing which it falls back to default page size.
 * 4. If request is for low memory range (< 4GB), and
 *OMRPORT_VMEM_ZOS_USE2TO32G_AREA is not set,
 * 		- If requested page size is 1MB pageable, try to allocate memory
 *below the bar, else, if OMRPORT_VMEM_STRICT_ADDRESS is set, fall back to
 *default page size, else try to allocate memory above the bar.
 *
 * 3 & 4 need to be checked only for 64-bit.
 *
 * In above comment default page size refers to 4KB page size.
 *
 * If OMRPORT_VMEM_STRICT_ADDRESS is set, caller is responsible to verify the
 *address returned is within expected range.
 *
 * @param [in] portLibrary The port library.
 * @param [in] identifier Descriptor for virtual memory block.
 * @param [in] params Struct containing necessary information about requested
 *memory
 * @param [in] category Memory allocation category code
 *
 * @return on success pointer to allocated memory region, NULL on failure
 */
static void*
reservePages(struct OMRPortLibrary* portLibrary,
             struct J9PortVmemIdentifier* identifier,
             struct J9PortVmemParams* params,
             OMRMemCategory* category)
{
  void* baseAddress = NULL;
  uintptr_t numPages = 0;
  BOOLEAN useStrictAddress = (OMRPORT_VMEM_STRICT_ADDRESS ==
                              (OMRPORT_VMEM_STRICT_ADDRESS & params->options));
  BOOLEAN use2To32GArea = (OMRPORT_VMEM_ZOS_USE2TO32G_AREA ==
                           (OMRPORT_VMEM_ZOS_USE2TO32G_AREA & params->options));
  BOOLEAN useStrictPageSize =
    (OMRPORT_VMEM_STRICT_PAGE_SIZE ==
     (OMRPORT_VMEM_STRICT_PAGE_SIZE & params->options));
  BOOLEAN useExecutablePages =
    (OMRPORT_VMEM_MEMORY_MODE_EXECUTE ==
     (OMRPORT_VMEM_MEMORY_MODE_EXECUTE & params->mode));

  /* If the pageSize is not one of the large page sizes supported, error */
  if (FALSE == isLargePageSizeSupported(
                 portLibrary, params->pageSize, params->pageFlags)) {
    update_vmemIdentifier(identifier, NULL, NULL, 0, 0, 0, 0, 0, NULL);
    Trc_PRT_vmem_omrvmem_reserve_memory_unsupported_page_size(params->pageSize);
    goto _end;
  } else if (useExecutablePages
#if defined(OMR_ENV_DATA64)
             && !isRmode64Supported()
#endif
  ) {
    if (use2To32GArea ||
        (useStrictAddress &&
         ((UDATA)params->startAddress + params->byteAmount >= TWO_G))) {
      /* Fail. Not valid options. Cannot allocate executable page in 2-32G
       * range. */
      update_vmemIdentifier(identifier, NULL, NULL, 0, 0, 0, 0, 0, NULL);
      Trc_PRT_vmem_omrvmem_reserve_memory_parameter_mismatch(params->mode,
                                                             params->options);
      goto _end;
    }
    /* Large executable pages can be allocated only with large 1MB pageable
     * pages below 2GB bar */
    if ((ONE_M != params->pageSize) ||
        (0 == (OMRPORT_VMEM_PAGE_FLAG_PAGEABLE & params->pageFlags))) {
      update_vmemIdentifier(identifier, NULL, NULL, 0, 0, 0, 0, 0, NULL);
      Trc_PRT_vmem_omrvmem_reserve_memory_unsupported_page_size_executable_largepages(
        params->pageSize, params->pageFlags);
    } else {
      baseAddress = reserve1MPageableBelowBar(
        portLibrary, identifier, params->mode, params->byteAmount, category);
    }
#if defined(OMR_ENV_DATA64)
  } else if ((params->startAddress >= 0) &&
             ((uintptr_t)params->endAddress <= FOUR_GIG_LIMIT)) {
    /* Request is for low memory range.
     * If 2to32G flag is set, we may be able to allocate memory using large
     * pages above the bar. Else, if page size requested is 1MB pageable,
     * allocate large pages below the bar. Else fail.
     */
    if (TRUE == use2To32GArea) {
      baseAddress = reservePagesAboveBar(portLibrary,
                                         identifier,
                                         params->mode,
                                         params->byteAmount,
                                         params->pageSize,
                                         params->pageFlags,
                                         params->options,
                                         category);
      if ((NULL != baseAddress) &&
          (TRUE == isStrictAndOutOfRange(params, baseAddress))) {
        /* if strict flag is set and returned pointer is not within range then
         * free the allocated memory and try again with 4K page size.
         */
        Trc_PRT_vmem_reservePages_UnableToAllocateWithinSpecifiedRange(
          params->byteAmount, params->startAddress, params->endAddress);
        omrvmem_free_memory(
          portLibrary, baseAddress, params->byteAmount, identifier);
        baseAddress = NULL;
      }
    } else {
      if ((ONE_M == params->pageSize) &&
          (0 != (OMRPORT_VMEM_PAGE_FLAG_PAGEABLE & params->pageFlags))) {
        baseAddress = reserve1MPageableBelowBar(
          portLibrary, identifier, params->mode, params->byteAmount, category);
      }
      if ((NULL == baseAddress) && (FALSE == useStrictAddress)) {
        /* Allocating memory using large pages above bar is guaranteed not to
         * return memory in low memory range. Therefore, this can be done only
         * if strict address flag is not set.
         */
        baseAddress = reservePagesAboveBar(portLibrary,
                                           identifier,
                                           params->mode,
                                           params->byteAmount,
                                           params->pageSize,
                                           params->pageFlags,
                                           params->options,
                                           category);
      }
    }
  } else {
    baseAddress = reservePagesAboveBar(portLibrary,
                                       identifier,
                                       params->mode,
                                       params->byteAmount,
                                       params->pageSize,
                                       params->pageFlags,
                                       params->options,
                                       category);
#else  /* OMR_ENV_DATA64 */
  } else {
    baseAddress = reserve1MPageableBelowBar(
      portLibrary, identifier, params->mode, params->byteAmount, category);
#endif /* OMR_ENV_DATA64 */
  }

  if (NULL == baseAddress) {
    if (TRUE == useStrictPageSize) {
      /* fail if OMRPORT_VMEM_STRICT_PAGE_SIZE was set */
      update_vmemIdentifier(identifier, NULL, NULL, 0, 0, 0, 0, 0, NULL);
    } else {
      /* defer to the regular page size */
      Trc_PRT_vmem_omrvmem_reserve_memory_ex_large_page_request_failed_reverting_to_default_page_size(
        params->byteAmount, numPages);
      params->pageSize = FOUR_K;

      LP_DEBUG_PRINTF1("\t reservePages returned: %i, failed to allocate "
                       "memory using large pages\n",
                       baseAddress);
      LP_DEBUG_PRINTF("\t reservePages deferring to 4K pages\n");

      baseAddress = reserve4KPages(portLibrary, identifier, params, category);
    }
  }

_end:

  LP_DEBUG_PRINTF1("\t reservePages() returning %p\n", baseAddress);

  return baseAddress;
}

/*
 * Reserve virtual memory backed by 4K pages.
 * If OMRPORT_VMEM_ZOS_USE2TO32G_AREA is set, it allocates 4K pages above 2GB
 * bar. If OMRPORT_VMEM_STRICT_ADDRESS is set, caller is responsible to verify
 * the address returned is within expected range.
 *
 * @param [in] portLibrary The port library.
 * @param [in] identifier Descriptor for virtual memory block.
 * @param [in] params Struct containing necessary information about requested
 * memory
 * @param [in] category Memory allocation category code
 *
 * @return on success pointer to allocated memory region, NULL on failure
 */
static void*
reserve4KPages(struct OMRPortLibrary* portLibrary,
               struct J9PortVmemIdentifier* identifier,
               struct J9PortVmemParams* params,
               OMRMemCategory* category)
{
  void* baseAddress = NULL;
  BOOLEAN useStrictAddress = (OMRPORT_VMEM_STRICT_ADDRESS ==
                              (OMRPORT_VMEM_STRICT_ADDRESS & params->options));
  BOOLEAN useExecutablePages =
    (OMRPORT_VMEM_MEMORY_MODE_EXECUTE ==
     (OMRPORT_VMEM_MEMORY_MODE_EXECUTE & params->mode));

#if defined(OMR_ENV_DATA64)
  BOOLEAN use2To32GArea = (OMRPORT_VMEM_ZOS_USE2TO32G_AREA ==
                           (OMRPORT_VMEM_ZOS_USE2TO32G_AREA & params->options));

  if (!use2To32GArea) {
#endif /* OMR_ENV_DATA64 */
    /* default_pageSize_reserve_memory will update the vmem identifier with the
     * correct page size */
    if (((uintptr_t)params->endAddress <= FOUR_GIG_LIMIT) ||
        (TRUE == useExecutablePages)) {
      /* Allocate executable memory below the 2G bit bar as ZOS does not
       * properly support code loaded above this mark */
      /* Or if the desired address is in low memory, use the low 2G in the hopes
       * that that's close to what's wanted */
      /* asking for low memory => use malloc31 */
      baseAddress = default_pageSize_reserve_low_memory(
        portLibrary, params->byteAmount, identifier, params->mode, category);

      /* if malloc31 failed and the memory range isn't strict and we don't want
       * executable memory, try allocating in high memory */
      if ((NULL == baseAddress) && (FALSE == useStrictAddress) &&
          (FALSE == useExecutablePages)) {
        baseAddress = default_pageSize_reserve_memory(
          portLibrary, params->byteAmount, identifier, params->mode, category);
      }
    } else {
      /* use the general case malloc allocator */
      baseAddress = default_pageSize_reserve_memory(
        portLibrary, params->byteAmount, identifier, params->mode, category);
    }
#if defined(OMR_ENV_DATA64)
  } else {
    /* use the 2to32GArea */
    baseAddress = reservePagesAboveBar(portLibrary,
                                       identifier,
                                       params->mode,
                                       params->byteAmount,
                                       FOUR_K,
                                       OMRPORT_VMEM_PAGE_FLAG_PAGEABLE,
                                       params->options,
                                       category);
  }
#endif /* OMR_ENV_DATA64 */

  return baseAddress;
}

uintptr_t
omrvmem_get_page_size(struct OMRPortLibrary* portLibrary,
                      struct J9PortVmemIdentifier* identifier)
{
  return identifier->pageSize;
}

uintptr_t
omrvmem_get_page_flags(struct OMRPortLibrary* portLibrary,
                       struct J9PortVmemIdentifier* identifier)
{
  return identifier->pageFlags;
}

void
omrvmem_shutdown(struct OMRPortLibrary* portLibrary)
{}

int32_t
omrvmem_startup(struct OMRPortLibrary* portLibrary)
{

  getPageInfo(portLibrary);

#if defined(OMR_ENV_DATA64)
  get_ipt_ttoken(portLibrary, PPG_ipt_ttoken, sizeof(PPG_ipt_ttoken));
#endif /* defined(OMR_ENV_DATA64) */

  /* set default value to advise OS about vmem that is no longer needed */
  portLibrary->portGlobals->vmemAdviseOSonFree = 1;
  /* set default value to advise OS about vmem to consider for Transparent
   * HugePage (Only for Linux) */
  portLibrary->portGlobals->vmemEnableMadvise = 0;

  return 0;
}

uintptr_t*
omrvmem_supported_page_sizes(struct OMRPortLibrary* portLibrary)
{
  return PPG_vmem_pageSize;
}

uintptr_t*
omrvmem_supported_page_flags(struct OMRPortLibrary* portLibrary)
{
  return PPG_vmem_pageFlags;
}

/**
 * @internal
 * Update J9PortVmIdentifier structure
 *
 * @param[in] identifier The structure to be updated
 * @param[in] address Base address
 * @param[in] handle Platform specific handle for reserved memory
 * @param[in] byteAmount Size of allocated area
 * @param[in] mode Access Mode
 * @param[in] pageSize Constant describing pageSize
 * @param[in] pageFlags flags for describing page type
 * @param[in] allocator Constant describing how the virtual memory was
 * allocated.
 * @param[in] category Memory allocation category
 */
void
update_vmemIdentifier(J9PortVmemIdentifier* identifier,
                      void* address,
                      void* handle,
                      uintptr_t byteAmount,
                      uintptr_t mode,
                      uintptr_t pageSize,
                      uintptr_t pageFlags,
                      uintptr_t allocator,
                      OMRMemCategory* category)
{
  identifier->address = address;
  identifier->handle = handle;
  identifier->size = byteAmount;
  identifier->pageSize = pageSize;
  identifier->pageFlags = pageFlags;
  identifier->mode = mode;
  identifier->allocator = allocator;
  identifier->category = category;
}

int
get_protectionBits(uintptr_t mode)
{
  int protectionFlags = 0;
  return protectionFlags;
}

/**
 * On 31-bit system, default page size when mode is
 * OMRPORT_VMEM_MEMORY_MODE_EXECUTE is 1M pageable pages (provided it is
 * supported), else there is no default page size. On 64-bit system, default
 * page size when mode is OMRPORT_VMEM_MEMORY_MODE_EXECUTE is 1M pageable pages
 * (provided it is supported), else it is 1M fixed pages.
 */
void
omrvmem_default_large_page_size_ex(struct OMRPortLibrary* portLibrary,
                                   uintptr_t mode,
                                   uintptr_t* pageSize,
                                   uintptr_t* pageFlags)
{
  uint32_t index = 0;

  if ((NULL == pageSize) && (NULL == pageFlags)) {
    return;
  }
  if (NULL != pageSize) {
    *pageSize = 0;
  }
  if (NULL != pageFlags) {
    *pageFlags = OMRPORT_VMEM_PAGE_FLAG_NOT_USED;
  }

#if !defined(OMR_ENV_DATA64)
  if (0 == (OMRPORT_VMEM_MEMORY_MODE_EXECUTE & mode)) {
    return;
  }
#endif /* OMR_ENV_DATA64 */

  while (0 != PPG_vmem_pageSize[index]) {
    if (0 != (OMRPORT_VMEM_MEMORY_MODE_EXECUTE & mode)) {
      if ((ONE_M == PPG_vmem_pageSize[index]) &&
          (0 !=
           (OMRPORT_VMEM_PAGE_FLAG_PAGEABLE & PPG_vmem_pageFlags[index]))) {
        break;
      }
#if defined(OMR_ENV_DATA64)
    } else {
      if ((ONE_M == PPG_vmem_pageSize[index]) &&
          (0 != (OMRPORT_VMEM_PAGE_FLAG_FIXED & PPG_vmem_pageFlags[index]))) {
        break;
      }
#endif
    }
    index++;
  }
  if (NULL != pageSize) {
    *pageSize = PPG_vmem_pageSize[index];
  }
  if (NULL != pageFlags) {
    *pageFlags = PPG_vmem_pageFlags[index];
  }
  return;
}

/**
 * Note: Rules for determining valid large page size on z/OS are summarized in
 * JAZZ Design 57609: -Xlp:objectheap and -Xlp:codecache option details for
 * z/OS.
 */
intptr_t
omrvmem_find_valid_page_size(struct OMRPortLibrary* portLibrary,
                             uintptr_t mode,
                             uintptr_t* pageSize,
                             uintptr_t* pageFlags,
                             BOOLEAN* isSizeSupported)
{
  uintptr_t validPageSize = *pageSize;
  uintptr_t validPageFlags = *pageFlags;
  BOOLEAN pageSizeFound = FALSE;
  BOOLEAN useExecutablePages = FALSE;

  Assert_PRT_true_wrapper(0 != validPageFlags);

  if (0 != (mode & OMRPORT_VMEM_MEMORY_MODE_EXECUTE)) {
    useExecutablePages = TRUE;
  }

  /* Match the default page size ignoring the page type */
  if (validPageSize == PPG_vmem_pageSize[0]) {
    SET_PAGE_TYPE(validPageFlags, PPG_vmem_pageFlags[0]);
    goto _end;
  }

#if defined(OMR_ENV_DATA64)
  if (FALSE == useExecutablePages) {
    uintptr_t defaultLargePageSize = 0;
    uintptr_t defaultLargePageFlags = OMRPORT_VMEM_PAGE_FLAG_NOT_USED;

    /* If the page type is NOT_USED (as with the -Xlp<size> options)
     * the legacy behavior is to default to FIXED pages.
     */
    if (IS_VMEM_PAGE_FLAG_NOT_USED(validPageFlags)) {
      SET_PAGE_TYPE(validPageFlags, OMRPORT_VMEM_PAGE_FLAG_FIXED);
    }

    pageSizeFound =
      isLargePageSizeSupported(portLibrary, validPageSize, validPageFlags);
    if (TRUE == pageSizeFound) {
      goto _end;
    }

    /* If there was no match for the page size/type, fall back to the default
     * large page size/type if the requested page type matches
     */
    portLibrary->vmem_default_large_page_size_ex(
      portLibrary, mode, &defaultLargePageSize, &defaultLargePageFlags);
    if ((0 != defaultLargePageSize) &&
        (defaultLargePageFlags == validPageFlags)) {
      validPageSize = defaultLargePageSize;
      goto _end;
    }
  }
#endif /* OMR_ENV_DATA64 */

  /* If there is no default page size (or for executable pages), try 1MB
   * pageable pages */
  pageSizeFound = isLargePageSizeSupported(
    portLibrary, ONE_M, OMRPORT_VMEM_PAGE_FLAG_PAGEABLE);
  if (TRUE == pageSizeFound) {
    validPageSize = ONE_M;
    SET_PAGE_TYPE(validPageFlags, OMRPORT_VMEM_PAGE_FLAG_PAGEABLE);
  } else {
    /* Use default page size, if everything else fails */
    validPageSize = PPG_vmem_pageSize[0];
    validPageFlags = PPG_vmem_pageFlags[0];
  }

_end:
  if (IS_VMEM_PAGE_FLAG_NOT_USED(*pageFlags)) {
    /* In this case ignore page flags when setting isSizeSupported */
    *isSizeSupported = (*pageSize == validPageSize);
  } else {
    *isSizeSupported =
      ((*pageSize == validPageSize) && (*pageFlags == validPageFlags));
  }
  *pageSize = validPageSize;
  *pageFlags = validPageFlags;

  return 0;
}

/**
 * Returns TRUE if OMRPORT_VMEM_STRICT_ADDRESS flag is set and memoryPointer
 * is outside of range, otherwise returns FALSE
 */
static BOOLEAN
isStrictAndOutOfRange(struct J9PortVmemParams* params, void* memoryPointer)
{
  if ((0 != (OMRPORT_VMEM_STRICT_ADDRESS & params->options)) &&
      ((memoryPointer > params->endAddress) ||
       (memoryPointer < params->startAddress))) {
    return TRUE;
  } else {
    return FALSE;
  }
}

/**
 * Ensures that the requested address and (address + byteAmount) fall
 * within the reserved identifier->address and (identifier->address +
 * identifier->size)
 *
 * @param[in] identifier Descriptor for virtual memory block.
 * @param[in] address The starting address of memory block to be validated.
 * @param[in] byteAmount The number of bytes in the memory block to be
 * validated.
 *
 * @returns TRUE if the range is valid, FALSE otherwise
 */
static BOOLEAN
rangeIsValid(struct J9PortVmemIdentifier* identifier,
             void* address,
             uintptr_t byteAmount)
{
  BOOLEAN isValid = FALSE;
  uintptr_t requestedUpperLimit = (uintptr_t)address + byteAmount - 1;

  if (requestedUpperLimit + 1 >= byteAmount) {
    /* Requested range does not wrap around */
    uintptr_t realUpperLimit =
      (uintptr_t)identifier->address + identifier->size - 1;

    if (((uintptr_t)address >= (uintptr_t)identifier->address) &&
        (requestedUpperLimit <= realUpperLimit)) {
      isValid = TRUE;
    }
  }

  return isValid;
}

intptr_t
omrvmem_numa_set_affinity(struct OMRPortLibrary* portLibrary,
                          uintptr_t numaNode,
                          void* address,
                          uintptr_t byteAmount,
                          struct J9PortVmemIdentifier* identifier)
{
  return OMRPORT_ERROR_VMEM_OPFAILED;
}

intptr_t
omrvmem_numa_get_node_details(struct OMRPortLibrary* portLibrary,
                              J9MemoryNodeDetail* numaNodes,
                              uintptr_t* nodeCount)
{
  return OMRPORT_ERROR_VMEM_OPFAILED;
}

static struct J9PortVmemParams
includeAlignmentInAllocation(struct J9PortVmemParams* incomingParams)
{
  struct J9PortVmemParams params = *incomingParams;
  uintptr_t alignment = params.alignmentInBytes;
  if (alignment > 0) {
    uintptr_t newSize = params.byteAmount + alignment;
    params.byteAmount = newSize;
    params.alignmentInBytes = 0;
  }
  return params;
}

static void*
adjustForRequestedAlignment(struct J9PortVmemParams* params,
                            void* memoryPointer)
{
  void* alignedPointer = memoryPointer;
  uintptr_t alignment = params->alignmentInBytes;
  if ((NULL != memoryPointer) && (alignment > 0)) {
    uintptr_t existingPointer = (uintptr_t)memoryPointer;
    uintptr_t newPointer = (existingPointer + alignment) & ~(alignment - 1);
    alignedPointer = (void*)newPointer;
  }
  return alignedPointer;
}

/*
 * Determines page size(s) supported by underlying system.
 *
 * @param [in] portLibrary the portLibrary
 *
 * @return void
 */
static void
getPageInfo(struct OMRPortLibrary* portLibrary)
{
  uintptr_t largePagesSupported = 0;
  intptr_t nextIndex = 0;

  /* 0 terminate the table */
  memset(PPG_vmem_pageSize, 0, OMRPORT_VMEM_PAGESIZE_COUNT * sizeof(uintptr_t));
  memset(
    PPG_vmem_pageFlags, 0, OMRPORT_VMEM_PAGESIZE_COUNT * sizeof(uintptr_t));

  PPG_vmem_pageSize[nextIndex] = FOUR_K;
  SET_PAGE_TYPE(PPG_vmem_pageFlags[nextIndex], OMRPORT_VMEM_PAGE_FLAG_PAGEABLE);
  nextIndex++;

  largePagesSupported = Get_Large_Pageable_Pages_Supported();

  LP_DEBUG_PRINTF1("Get_Large_Pageable_Pages_Supported returned : %i\n",
                   largePagesSupported);
  if (1 == largePagesSupported) {
    PPG_vmem_pageSize[nextIndex] = ONE_M;
    SET_PAGE_TYPE(PPG_vmem_pageFlags[nextIndex],
                  OMRPORT_VMEM_PAGE_FLAG_PAGEABLE);
    nextIndex++;
  }

#if defined(OMR_ENV_DATA64)

  /* check if Rce_Use2gto64gEnable (return 2) or RCEUSE2GTo32GAREAOK (return 1)
   * bits in RCE are set */
  PPG_userExtendedPrivateAreaMemoryType =
    getUserExtendedPrivateAreaMemoryType();

  LP_DEBUG_PRINTF1("\getUserExtendedPrivateAreaMemoryType returned : %i\n",
                   PPG_userExtendedPrivateAreaMemoryType);

  largePagesSupported = Get_Large_Pages_Supported();

  LP_DEBUG_PRINTF1("Get_Large_Pages_Supported returned : %i\n",
                   largePagesSupported);

  if (1 == largePagesSupported) {
    PPG_vmem_pageSize[nextIndex] = ONE_M;
    SET_PAGE_TYPE(PPG_vmem_pageFlags[nextIndex], OMRPORT_VMEM_PAGE_FLAG_FIXED);
    nextIndex++;
  }

  largePagesSupported = Get_Large_2GB_Pages_Supported();

  LP_DEBUG_PRINTF1("Get_Large_2GB_Fixed_Pages_Supported returned : %i\n",
                   largePagesSupported);

  if (1 == largePagesSupported) {
    PPG_vmem_pageSize[nextIndex] = TWO_G;
    SET_PAGE_TYPE(PPG_vmem_pageFlags[nextIndex], OMRPORT_VMEM_PAGE_FLAG_FIXED);
  }

#endif /* OMR_ENV_DATA64 */

  return;
}

/*
 * Determines if the given combination of page size and page flag is large page
 * size supported by underlying system. Note that it does not check 4K page size
 * as it is not considered large page size.
 *
 * @param [in] portLibrary the portLibrary
 * @param [in] pageSize requested page size
 * @param [in] pageFlags flags describing 'pageSize'
 *
 * @return TRUE if the combination of page size and page flag is supported by
 * underlying system, FALSE otherwise.
 */
static BOOLEAN
isLargePageSizeSupported(struct OMRPortLibrary* portLibrary,
                         uintptr_t pageSize,
                         uintptr_t pageFlags)
{
  uint32_t index = 1; /* Skip the first entry as it points to 4KB page size
                         which is not considered large page size */

  while (0 != PPG_vmem_pageSize[index]) {
    if ((pageSize == PPG_vmem_pageSize[index]) &&
        (pageFlags == PPG_vmem_pageFlags[index])) {
      return TRUE;
    }
    index++;
  }
  return FALSE;
}

int32_t
omrvmem_get_available_physical_memory(struct OMRPortLibrary* portLibrary,
                                      uint64_t* freePhysicalMemorySize)
{
  return OMRPORT_ERROR_VMEM_NOT_SUPPORTED;
}

int32_t
omrvmem_get_process_memory_size(struct OMRPortLibrary* portLibrary,
                                J9VMemMemoryQuery queryType,
                                uint64_t* memorySize)
{
  return OMRPORT_ERROR_VMEM_NOT_SUPPORTED;
}

#if defined(OMR_ENV_DATA64)
static BOOLEAN
isRmode64Supported()
{
  J9CVT* __ptr32 cvtp = ((J9PSA * __ptr32)0)->flccvt;
  uint8_t cvtoslvl6 = cvtp->cvtoslvl[6];
  if (OMR_ARE_ANY_BITS_SET(cvtoslvl6, 0x10)) {
    return TRUE;
  }
  return FALSE;
}
#endif

void*
omrvmem_get_contiguous_region_memory(struct OMRPortLibrary* portLibrary,
                                     void* addresses[],
                                     uintptr_t addressesCount,
                                     uintptr_t addressSize,
                                     uintptr_t byteAmount,
                                     struct J9PortVmemIdentifier* oldIdentifier,
                                     struct J9PortVmemIdentifier* newIdentifier,
                                     uintptr_t mode,
                                     uintptr_t pageSize,
                                     OMRMemCategory* category)
{
  portLibrary->error_set_last_error(
    portLibrary, errno, OMRPORT_ERROR_VMEM_NOT_SUPPORTED);
  return NULL;
}
