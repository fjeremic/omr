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
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
 *******************************************************************************/

#if !defined(REFERENCECHAINWALKERMARKMAP_HPP_)
#define REFERENCECHAINWALKERMARKMAP_HPP_

#include "omrcomp.h"

#include "HeapMap.hpp"

class MM_EnvironmentBase;

class MM_ReferenceChainWalkerMarkMap : public MM_HeapMap {
private:
    /**
	 * Clear Mark Map for Reference Chain Walker:
	 * commit memory if necessary and zero it
	 * @param env current thread environment
	 * @param commit if true memory should be commited first
	 * @return true if initialization is successful
	 */
    bool clearMapForRegions(MM_EnvironmentBase* env, bool commit);

protected:
    /**
 * Initialize Mark Map for Reference Chain Walker:
 * create mark map correspondent with each region: commit memory and zero it
 * @param env current thread environment
 * @return true if initialization is successful
 */
    bool initialize(MM_EnvironmentBase* env);

public:
    /**
	 * Create a new instance of Reference Chain Walker Mark Map object
	 */
    static MM_ReferenceChainWalkerMarkMap* newInstance(MM_EnvironmentBase* env, uintptr_t maxHeapSize);

    /**
 	 * Clear Mark Map
 	 */
    void clearMap(MM_EnvironmentBase* env);

    /**
	 * Create a MarkMap for Reference Chain Walker object.
	 */
    MM_ReferenceChainWalkerMarkMap(MM_EnvironmentBase* env, uintptr_t maxHeapSize)
        : MM_HeapMap(env, maxHeapSize, env->getExtensions()->isMetronomeGC())
    {
        _typeId = __FUNCTION__;
    };
};

#endif /* REFERENCECHAINWALKERMARKMAP_HPP_ */
