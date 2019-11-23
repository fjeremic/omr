/*******************************************************************************
 * Copyright (c) 2016, 2018 IBM Corp. and others
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
#include "InliningRecFib.hpp"
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
/* Un comment to enable debug output */
/* #define RFIB_DEBUG_OUTPUT */
static void printString(int64_t stringPointer) {
#define PRINTSTRING_LINE LINETOSTR(__LINE__)
  char *strPtr = (char *)stringPointer;
  fprintf(stderr, "%s", strPtr);
}
static void printInt32(int32_t value) {
#define PRINTINT32_LINE LINETOSTR(__LINE__)
  fprintf(stderr, "%d", value);
}
InliningRecursiveFibonacciMethod::InliningRecursiveFibonacciMethod(
    OMR::JitBuilder::TypeDictionary *types, int32_t inlineDepth)
    : MethodBuilder(types), _inlineDepth(inlineDepth) {
  defineStuff();
}
InliningRecursiveFibonacciMethod::InliningRecursiveFibonacciMethod(
    InliningRecursiveFibonacciMethod *callerMB)
    : MethodBuilder(callerMB), _inlineDepth(callerMB->_inlineDepth - 1) {
  defineStuff();
}
void InliningRecursiveFibonacciMethod::defineStuff() {
  DefineLine(LINETOSTR(__LINE__));
  DefineFile(__FILE__);
  DefineName("fib");
  DefineParameter("n", Int32);
  DefineReturnType(Int32);
  DefineFunction((char *)"printString", (char *)__FILE__,
                 (char *)PRINTSTRING_LINE, (void *)&printString, NoType, 1,
                 Int64);
  DefineFunction((char *)"printInt32", (char *)__FILE__,
                 (char *)PRINTINT32_LINE, (void *)&printInt32, NoType, 1,
                 Int32);
}
static const char *prefix = "fib(";
static const char *middle = ") = ";
static const char *suffix = "\n";
bool InliningRecursiveFibonacciMethod::buildIL() {
  OMR::JitBuilder::IlBuilder *baseCase = NULL, *recursiveCase = NULL;
  IfThenElse(&baseCase, &recursiveCase, LessThan(Load("n"), ConstInt32(2)));
  DefineLocal("result", Int32);
  baseCase->Store("result", baseCase->Load("n"));
  OMR::JitBuilder::IlValue *nMinusOne = recursiveCase->Sub(
      recursiveCase->Load("n"), recursiveCase->ConstInt32(1));
  OMR::JitBuilder::IlValue *fib_nMinusOne;
  if (_inlineDepth > 0) {
    // memory leak here, but just an example
    InliningRecursiveFibonacciMethod *inlineFib =
        new InliningRecursiveFibonacciMethod(this);
    fib_nMinusOne = recursiveCase->Call(inlineFib, 1, nMinusOne);
  } else
    fib_nMinusOne = recursiveCase->Call("fib", 1, nMinusOne);
  OMR::JitBuilder::IlValue *nMinusTwo = recursiveCase->Sub(
      recursiveCase->Load("n"), recursiveCase->ConstInt32(2));

  OMR::JitBuilder::IlValue *fib_nMinusTwo;
  if (_inlineDepth > 0) {
    // memory leak here, but just an example
    InliningRecursiveFibonacciMethod *inlineFib =
        new InliningRecursiveFibonacciMethod(this);
    fib_nMinusTwo = recursiveCase->Call(inlineFib, 1, nMinusTwo);
  } else
    fib_nMinusTwo = recursiveCase->Call("fib", 1, nMinusTwo);
  recursiveCase->Store("result",
                       recursiveCase->Add(fib_nMinusOne, fib_nMinusTwo));
#if defined(RFIB_DEBUG_OUTPUT)
  Call("printString", 1, ConstInt64((int64_t)prefix));
  Call("printInt32", 1, Load("n"));
  Call("printString", 1, ConstInt64((int64_t)middle));
  Call("printInt32", 1, Load("result"));
  Call("printString", 1, ConstInt64((int64_t)suffix));
#endif
  Return(Load("result"));
  return true;
}
int main(int argc, char *argv[]) {
  int32_t inliningDepth = 1;  // by default, inline one level of calls
  if (argc == 2) inliningDepth = atoi(argv[1]);
  printf("Step 1: initialize JIT\n");
  bool initialized = initializeJit();
  if (!initialized) {
    fprintf(stderr, "FAIL: could not initialize JIT\n");
    exit(-1);
  }
  printf("Step 2: define relevant types\n");
  OMR::JitBuilder::TypeDictionary types;
  printf("Step 3: compile method builder, inlining one level\n");
  InliningRecursiveFibonacciMethod method(&types, inliningDepth);
  void *entry = 0;
  int32_t rc = compileMethodBuilder(&method, &entry);
  if (rc != 0) {
    fprintf(stderr, "FAIL: compilation error %d\n", rc);
    exit(-2);
  }
  printf("Step 4: invoke compiled code\n");
  RecursiveFibFunctionType *fib = (RecursiveFibFunctionType *)entry;
  for (int32_t n = 0; n < 20; n++) printf("fib(%2d) = %d\n", n, fib(n));
  printf("Step 5: shutdown JIT\n");
  shutdownJit();
  printf("PASS\n");
}
