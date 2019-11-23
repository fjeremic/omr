/*******************************************************************************
 * Copyright (c) 2015, 2017 IBM Corp. and others
 *
 * This program and the accompanying materials are made available under
 * the terms of the Eclipse Public License 2.0 which accompanies this
 * distribution and is available at http://eclipse.org/legal/epl-2.0
 * or the Apache License, Version 2.0 which accompanies this distribution
 * and is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * This Source Code may also be made available under the following Secondary
 * Licenses when the conditions for such availability set forth in the
 * Eclipse Public License, v. 2.0 are satisfied: GNU General Public License,
 * version 2 with the GNU Classpath Exception [1] and GNU General Public
 * License, version 2 with the OpenJDK Assembly Exception [2].
 *
 * [1] https://www.gnu.org/software/classpath/license.html
 * [2] http://openjdk.java.net/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH
 *Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
 *******************************************************************************/

#include "cudaTests.hpp"

static const J9CudaError errors[] = {
    J9CUDA_NO_ERROR,
    J9CUDA_ERROR_MISSING_CONFIGURATION,
    J9CUDA_ERROR_MEMORY_ALLOCATION,
    J9CUDA_ERROR_INITIALIZATION_ERROR,
    J9CUDA_ERROR_LAUNCH_FAILURE,
    J9CUDA_ERROR_LAUNCH_TIMEOUT,
    J9CUDA_ERROR_LAUNCH_OUT_OF_RESOURCES,
    J9CUDA_ERROR_INVALID_DEVICE_FUNCTION,
    J9CUDA_ERROR_INVALID_CONFIGURATION,
    J9CUDA_ERROR_INVALID_DEVICE,
    J9CUDA_ERROR_INVALID_VALUE,
    J9CUDA_ERROR_INVALID_PITCH_VALUE,
    J9CUDA_ERROR_INVALID_SYMBOL,
    J9CUDA_ERROR_MAP_BUFFER_OBJECT_FAILED,
    J9CUDA_ERROR_UNMAP_BUFFER_OBJECT_FAILED,
    J9CUDA_ERROR_INVALID_HOST_POINTER,
    J9CUDA_ERROR_INVALID_DEVICE_POINTER,
    J9CUDA_ERROR_INVALID_TEXTURE,
    J9CUDA_ERROR_INVALID_TEXTURE_BINDING,
    J9CUDA_ERROR_INVALID_CHANNEL_DESCRIPTOR,
    J9CUDA_ERROR_INVALID_MEMCPY_DIRECTION,
    J9CUDA_ERROR_INVALID_FILTER_SETTING,
    J9CUDA_ERROR_INVALID_NORM_SETTING,
    J9CUDA_ERROR_CUDART_UNLOADING,
    J9CUDA_ERROR_UNKNOWN,
    J9CUDA_ERROR_INVALID_RESOURCE_HANDLE,
    J9CUDA_ERROR_NOT_READY,
    J9CUDA_ERROR_INSUFFICIENT_DRIVER,
    J9CUDA_ERROR_SET_ON_ACTIVE_PROCESS,
    J9CUDA_ERROR_INVALID_SURFACE,
    J9CUDA_ERROR_NO_DEVICE,
    J9CUDA_ERROR_ECCUNCORRECTABLE,
    J9CUDA_ERROR_SHARED_OBJECT_SYMBOL_NOT_FOUND,
    J9CUDA_ERROR_SHARED_OBJECT_INIT_FAILED,
    J9CUDA_ERROR_UNSUPPORTED_LIMIT,
    J9CUDA_ERROR_DUPLICATE_VARIABLE_NAME,
    J9CUDA_ERROR_DUPLICATE_TEXTURE_NAME,
    J9CUDA_ERROR_DUPLICATE_SURFACE_NAME,
    J9CUDA_ERROR_DEVICES_UNAVAILABLE,
    J9CUDA_ERROR_INVALID_KERNEL_IMAGE,
    J9CUDA_ERROR_NO_KERNEL_IMAGE_FOR_DEVICE,
    J9CUDA_ERROR_INCOMPATIBLE_DRIVER_CONTEXT,
    J9CUDA_ERROR_PEER_ACCESS_ALREADY_ENABLED,
    J9CUDA_ERROR_PEER_ACCESS_NOT_ENABLED,
    J9CUDA_ERROR_DEVICE_ALREADY_IN_USE,
    J9CUDA_ERROR_PROFILER_DISABLED,
    J9CUDA_ERROR_ASSERT,
    J9CUDA_ERROR_TOO_MANY_PEERS,
    J9CUDA_ERROR_HOST_MEMORY_ALREADY_REGISTERED,
    J9CUDA_ERROR_HOST_MEMORY_NOT_REGISTERED,
    J9CUDA_ERROR_OPERATING_SYSTEM,
    J9CUDA_ERROR_PEER_ACCESS_UNSUPPORTED,
    J9CUDA_ERROR_LAUNCH_MAX_DEPTH_EXCEEDED,
    J9CUDA_ERROR_LAUNCH_FILE_SCOPED_TEX,
    J9CUDA_ERROR_LAUNCH_FILE_SCOPED_SURF,
    J9CUDA_ERROR_SYNC_DEPTH_EXCEEDED,
    J9CUDA_ERROR_LAUNCH_PENDING_COUNT_EXCEEDED,
    J9CUDA_ERROR_NOT_PERMITTED,
    J9CUDA_ERROR_NOT_SUPPORTED,
    J9CUDA_ERROR_NOT_FOUND};

/**
 * Verify errors API.
 */
TEST_F(CudaDeviceTest, error) {
  OMRPORT_ACCESS_FROM_OMRPORT(getPortLibrary());

  for (uint32_t index = 0; index < LENGTH_OF(errors); ++index) {
    int32_t error = errors[index];
    const char* text = omrcuda_getErrorString(error);

    ASSERT_TRUE((NULL != text) || !isErrorStringRequired(error))
        << "no text for error " << error;
  }
}
