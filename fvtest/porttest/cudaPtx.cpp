/*******************************************************************************
 * Copyright (c) 2015, 2015 IBM Corp. and others
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
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
 *******************************************************************************/

#include "cudaTests.hpp"

/**
 * The following arrays were generated using
 *     nvcc -ptx --generate-code arch=compute_20,code=compute_20
 * from *.cu files in the cuda.tests project for 32- and 64-bit targets.
 */

static char fragment1_code[] = { ".version 3.2\n"
                                 ".target sm_20\n"
#if defined(OMR_ENV_DATA64)
                                 ".address_size 64\n"
                                 "\n"
                                 ".extern .func (.param .b32 func_retval0) add\n"
                                 "(\n"
                                 "    .param .b32 add_param_0,\n"
                                 "    .param .b32 add_param_1\n"
                                 ");\n"
                                 "\n"
                                 ".visible .global .align 4 .u32 adderCount;\n"
                                 "\n"
                                 ".visible .entry adder(\n"
                                 "    .param .u64 adder_param_0,\n"
                                 "    .param .u64 adder_param_1,\n"
                                 "    .param .u64 adder_param_2,\n"
                                 "    .param .u32 adder_param_3\n"
                                 ")\n"
                                 "{\n"
                                 "    .reg .pred          %p<3>;\n"
                                 "    .reg .s32           %r<11>;\n"
                                 "    .reg .s64           %rd<11>;\n"
                                 "\n"
                                 "    ld.param.u64        %rd4, [adder_param_0];\n"
                                 "    ld.param.u64        %rd5, [adder_param_1];\n"
                                 "    ld.param.u64        %rd6, [adder_param_2];\n"
                                 "    ld.param.u32        %r2, [adder_param_3];\n"
                                 "    cvta.to.global.u64  %rd1, %rd4;\n"
                                 "    cvta.to.global.u64  %rd2, %rd6;\n"
                                 "    cvta.to.global.u64  %rd3, %rd5;\n"
                                 "    mov.u32             %r3, %ntid.x;\n"
                                 "    mov.u32             %r4, %ctaid.x;\n"
                                 "    mov.u32             %r5, %tid.x;\n"
                                 "    mad.lo.s32          %r1, %r3, %r4, %r5;\n"
                                 "    setp.ne.s32         %p1, %r1, 0;\n"
                                 "    @%p1 bra            BB0_2;\n"
                                 "\n"
                                 "    ldu.global.u32      %r6, [adderCount];\n"
                                 "    add.s32             %r7, %r6, 1;\n"
                                 "    st.global.u32       [adderCount], %r7;\n"
                                 "\n"
                                 "BB0_2:\n"
                                 "    setp.ge.s32         %p2, %r1, %r2;\n"
                                 "    @%p2 bra            BB0_4;\n"
                                 "\n"
                                 "    mul.wide.s32        %rd7, %r1, 4;\n"
                                 "    add.s64             %rd8, %rd3, %rd7;\n"
                                 "    add.s64             %rd9, %rd2, %rd7;\n"
                                 "    ld.global.u32       %r8, [%rd9];\n"
                                 "    ld.global.u32       %r9, [%rd8];\n"
                                 "    {\n"
                                 "    .reg .b32           temp_param_reg;\n"
                                 "    .param .b32         param0;\n"
                                 "    st.param.b32        [param0+0], %r9;\n"
                                 "    .param .b32         param1;\n"
                                 "    st.param.b32        [param1+0], %r8;\n"
                                 "    .param .b32         retval0;\n"
                                 "    call.uni (retval0), \n"
                                 "    add, \n"
                                 "    (\n"
                                 "    param0, \n"
                                 "    param1\n"
                                 "    );\n"
                                 "    ld.param.b32        %r10, [retval0+0];\n"
                                 "    }\n"
                                 "    add.s64             %rd10, %rd1, %rd7;\n"
                                 "    st.global.u32       [%rd10], %r10;\n"
                                 "\n"
                                 "BB0_4:\n"
                                 "    ret;\n"
                                 "}\n"
#else
                                 ".address_size 32\n"
                                 "\n"
                                 ".extern .func (.param .b32 func_retval0) add\n"
                                 "(\n"
                                 "    .param .b32 add_param_0,\n"
                                 "    .param .b32 add_param_1\n"
                                 ");\n"
                                 "\n"
                                 ".visible .global .align 4 .u32 adderCount;\n"
                                 "\n"
                                 ".visible .entry adder(\n"
                                 "    .param .u32 adder_param_0,\n"
                                 "    .param .u32 adder_param_1,\n"
                                 "    .param .u32 adder_param_2,\n"
                                 "    .param .u32 adder_param_3\n"
                                 ")\n"
                                 "{\n"
                                 "    .reg .pred          %p<3>;\n"
                                 "    .reg .s32           %r<21>;\n"
                                 "\n"
                                 "    ld.param.u32        %r6, [adder_param_0];\n"
                                 "    ld.param.u32        %r7, [adder_param_1];\n"
                                 "    ld.param.u32        %r8, [adder_param_2];\n"
                                 "    ld.param.u32        %r5, [adder_param_3];\n"
                                 "    cvta.to.global.u32  %r1, %r6;\n"
                                 "    cvta.to.global.u32  %r2, %r8;\n"
                                 "    cvta.to.global.u32  %r3, %r7;\n"
                                 "    mov.u32             %r9, %ntid.x;\n"
                                 "    mov.u32             %r10, %ctaid.x;\n"
                                 "    mov.u32             %r11, %tid.x;\n"
                                 "    mad.lo.s32          %r4, %r9, %r10, %r11;\n"
                                 "    setp.ne.s32         %p1, %r4, 0;\n"
                                 "    @%p1 bra            BB0_2;\n"
                                 "\n"
                                 "    ldu.global.u32      %r12, [adderCount];\n"
                                 "    add.s32             %r13, %r12, 1;\n"
                                 "    st.global.u32       [adderCount], %r13;\n"
                                 "\n"
                                 "BB0_2:\n"
                                 "    setp.ge.s32         %p2, %r4, %r5;\n"
                                 "    @%p2 bra            BB0_4;\n"
                                 "\n"
                                 "    shl.b32             %r14, %r4, 2;\n"
                                 "    add.s32             %r15, %r3, %r14;\n"
                                 "    add.s32             %r16, %r2, %r14;\n"
                                 "    ld.global.u32       %r17, [%r16];\n"
                                 "    ld.global.u32       %r18, [%r15];\n"
                                 "    {\n"
                                 "    .reg .b32           temp_param_reg;\n"
                                 "    .param .b32         param0;\n"
                                 "    st.param.b32        [param0+0], %r18;\n"
                                 "    .param .b32         param1;\n"
                                 "    st.param.b32        [param1+0], %r17;\n"
                                 "    .param .b32         retval0;\n"
                                 "    call.uni (retval0), \n"
                                 "    add, \n"
                                 "    (\n"
                                 "    param0, \n"
                                 "    param1\n"
                                 "    );\n"
                                 "    ld.param.b32        %r19, [retval0+0];\n"
                                 "    }\n"
                                 "    \n"
                                 "    add.s32             %r20, %r1, %r14;\n"
                                 "    st.global.u32       [%r20], %r19;\n"
                                 "\n"
                                 "BB0_4:\n"
                                 "    ret;\n"
                                 "}\n"
#endif /* OMR_ENV_DATA64 */
};

static char fragment2_code[] = { ".version 3.2\n"
                                 ".target sm_20\n"
#if defined(OMR_ENV_DATA64)
                                 ".address_size 64\n"
#else
                                 ".address_size 32\n"
#endif /* OMR_ENV_DATA64 */
                                 "\n"
                                 ".visible .global .align 4 .u32 addCount;\n"
                                 "\n"
                                 ".visible .func  (.param .b32 func_retval0) add(\n"
                                 "    .param .b32 add_param_0,\n"
                                 "    .param .b32 add_param_1\n"
                                 ")\n"
                                 "{\n"
                                 "    .reg .s32   %r<6>;\n"
                                 "\n"
                                 "    ld.param.u32    %r1, [add_param_0];\n"
                                 "    ld.param.u32    %r2, [add_param_1];\n"
                                 "    ld.global.u32   %r3, [addCount];\n"
                                 "    add.s32         %r4, %r3, 1;\n"
                                 "    st.global.u32   [addCount], %r4;\n"
                                 "    add.s32         %r5, %r2, %r1;\n"
                                 "    st.param.b32    [func_retval0+0], %r5;\n"
                                 "    ret;\n"
                                 "}\n" };

static char module_code[] = { ".version 3.2\n"
                              ".target sm_20\n"
#if defined(OMR_ENV_DATA64)
                              ".address_size 64\n"
                              "\n"
                              ".visible .global .surfref surfaceHandle;\n"
                              ".visible .global .texref textureHandle;\n"
                              ".visible .global .align 4 .u32 swapCount;\n"
                              "\n"
                              ".visible .entry stepFirst(\n"
                              "    .param .u64 stepFirst_param_0,\n"
                              "    .param .u32 stepFirst_param_1,\n"
                              "    .param .u32 stepFirst_param_2\n"
                              ")\n"
                              "{\n"
                              "    .reg .pred          %p<3>;\n"
                              "    .reg .s32           %r<18>;\n"
                              "    .reg .s64           %rd<7>;\n"
                              "\n"
                              "    ld.param.u64        %rd4, [stepFirst_param_0];\n"
                              "    ld.param.u32        %r5, [stepFirst_param_1];\n"
                              "    ld.param.u32        %r6, [stepFirst_param_2];\n"
                              "    cvta.to.global.u64  %rd1, %rd4;\n"
                              "    mov.u32             %r7, %ntid.x;\n"
                              "    mov.u32             %r8, %ctaid.x;\n"
                              "    mov.u32             %r9, %tid.x;\n"
                              "    mad.lo.s32          %r10, %r7, %r8, %r9;\n"
                              "    shl.b32             %r11, %r10, 1;\n"
                              "    add.s32             %r12, %r6, -1;\n"
                              "    and.b32             %r13, %r10, %r12;\n"
                              "    sub.s32             %r1, %r11, %r13;\n"
                              "    shl.b32             %r14, %r6, 1;\n"
                              "    add.s32             %r15, %r14, -1;\n"
                              "    xor.b32             %r2, %r1, %r15;\n"
                              "    setp.ge.s32         %p1, %r2, %r5;\n"
                              "    @%p1 bra            BB0_3;\n"
                              "\n"
                              "    mul.wide.s32        %rd5, %r1, 4;\n"
                              "    add.s64             %rd2, %rd1, %rd5;\n"
                              "    mul.wide.s32        %rd6, %r2, 4;\n"
                              "    add.s64             %rd3, %rd1, %rd6;\n"
                              "    ld.global.u32       %r3, [%rd3];\n"
                              "    ld.global.u32       %r4, [%rd2];\n"
                              "    setp.le.s32         %p2, %r4, %r3;\n"
                              "    @%p2 bra            BB0_3;\n"
                              "\n"
                              "    st.global.u32       [%rd2], %r3;\n"
                              "    st.global.u32       [%rd3], %r4;\n"
                              "    ld.global.u32       %r16, [swapCount];\n"
                              "    add.s32             %r17, %r16, 1;\n"
                              "    st.global.u32       [swapCount], %r17;\n"
                              "\n"
                              "BB0_3:\n"
                              "    ret;\n"
                              "}\n"
                              "\n"
                              ".visible .entry stepOther(\n"
                              "    .param .u64 stepOther_param_0,\n"
                              "    .param .u32 stepOther_param_1,\n"
                              "    .param .u32 stepOther_param_2\n"
                              ")\n"
                              "{\n"
                              "    .reg .pred          %p<3>;\n"
                              "    .reg .s32           %r<16>;\n"
                              "    .reg .s64           %rd<7>;\n"
                              "\n"
                              "    ld.param.u64        %rd4, [stepOther_param_0];\n"
                              "    ld.param.u32        %r5, [stepOther_param_1];\n"
                              "    ld.param.u32        %r6, [stepOther_param_2];\n"
                              "    cvta.to.global.u64  %rd1, %rd4;\n"
                              "    mov.u32             %r7, %ntid.x;\n"
                              "    mov.u32             %r8, %ctaid.x;\n"
                              "    mov.u32             %r9, %tid.x;\n"
                              "    mad.lo.s32          %r10, %r7, %r8, %r9;\n"
                              "    shl.b32             %r11, %r10, 1;\n"
                              "    add.s32             %r12, %r6, -1;\n"
                              "    and.b32             %r13, %r10, %r12;\n"
                              "    sub.s32             %r1, %r11, %r13;\n"
                              "    add.s32             %r2, %r1, %r6;\n"
                              "    setp.ge.s32         %p1, %r2, %r5;\n"
                              "    @%p1 bra            BB1_3;\n"
                              "\n"
                              "    mul.wide.s32        %rd5, %r1, 4;\n"
                              "    add.s64             %rd2, %rd1, %rd5;\n"
                              "    mul.wide.s32        %rd6, %r2, 4;\n"
                              "    add.s64             %rd3, %rd1, %rd6;\n"
                              "    ld.global.u32       %r3, [%rd3];\n"
                              "    ld.global.u32       %r4, [%rd2];\n"
                              "    setp.le.s32         %p2, %r4, %r3;\n"
                              "    @%p2 bra            BB1_3;\n"
                              "\n"
                              "    st.global.u32       [%rd2], %r3;\n"
                              "    st.global.u32       [%rd3], %r4;\n"
                              "    ld.global.u32       %r14, [swapCount];\n"
                              "    add.s32             %r15, %r14, 1;\n"
                              "    st.global.u32       [swapCount], %r15;\n"
                              "\n"
                              "BB1_3:\n"
                              "    ret;\n"
                              "}\n"
#else
                              ".address_size 32\n"
                              "\n"
                              ".visible .global .surfref surfaceHandle;\n"
                              ".visible .global .texref textureHandle;\n"
                              ".visible .global .align 4 .u32 swapCount;\n"
                              "\n"
                              ".visible .entry stepFirst(\n"
                              "    .param .u32 stepFirst_param_0,\n"
                              "    .param .u32 stepFirst_param_1,\n"
                              "    .param .u32 stepFirst_param_2\n"
                              ")\n"
                              "{\n"
                              "    .reg .pred          %p<3>;\n"
                              "    .reg .s32           %r<24>;\n"
                              "\n"
                              "    ld.param.u32        %r8, [stepFirst_param_0];\n"
                              "    ld.param.u32        %r9, [stepFirst_param_1];\n"
                              "    ld.param.u32        %r10, [stepFirst_param_2];\n"
                              "    cvta.to.global.u32  %r1, %r8;\n"
                              "    mov.u32             %r11, %ntid.x;\n"
                              "    mov.u32             %r12, %ctaid.x;\n"
                              "    mov.u32             %r13, %tid.x;\n"
                              "    mad.lo.s32          %r14, %r11, %r12, %r13;\n"
                              "    shl.b32             %r15, %r14, 1;\n"
                              "    add.s32             %r16, %r10, -1;\n"
                              "    and.b32             %r17, %r14, %r16;\n"
                              "    sub.s32             %r2, %r15, %r17;\n"
                              "    shl.b32             %r18, %r10, 1;\n"
                              "    add.s32             %r19, %r18, -1;\n"
                              "    xor.b32             %r3, %r2, %r19;\n"
                              "    setp.ge.s32         %p1, %r3, %r9;\n"
                              "    @%p1 bra            BB0_3;\n"
                              "\n"
                              "    shl.b32             %r20, %r2, 2;\n"
                              "    add.s32             %r4, %r1, %r20;\n"
                              "    shl.b32             %r21, %r3, 2;\n"
                              "    add.s32             %r5, %r1, %r21;\n"
                              "    ld.global.u32       %r6, [%r5];\n"
                              "    ld.global.u32       %r7, [%r4];\n"
                              "    setp.le.s32         %p2, %r7, %r6;\n"
                              "    @%p2 bra            BB0_3;\n"
                              "\n"
                              "    st.global.u32       [%r4], %r6;\n"
                              "    st.global.u32       [%r5], %r7;\n"
                              "    ld.global.u32       %r22, [swapCount];\n"
                              "    add.s32             %r23, %r22, 1;\n"
                              "    st.global.u32       [swapCount], %r23;\n"
                              "\n"
                              "BB0_3:\n"
                              "    ret;\n"
                              "}\n"
                              "\n"
                              ".visible .entry stepOther(\n"
                              "    .param .u32 stepOther_param_0,\n"
                              "    .param .u32 stepOther_param_1,\n"
                              "    .param .u32 stepOther_param_2\n"
                              ")\n"
                              "{\n"
                              "    .reg .pred          %p<3>;\n"
                              "    .reg .s32           %r<22>;\n"
                              "\n"
                              "    ld.param.u32        %r8, [stepOther_param_0];\n"
                              "    ld.param.u32        %r9, [stepOther_param_1];\n"
                              "    ld.param.u32        %r10, [stepOther_param_2];\n"
                              "    cvta.to.global.u32  %r1, %r8;\n"
                              "    mov.u32             %r11, %ntid.x;\n"
                              "    mov.u32             %r12, %ctaid.x;\n"
                              "    mov.u32             %r13, %tid.x;\n"
                              "    mad.lo.s32          %r14, %r11, %r12, %r13;\n"
                              "    shl.b32             %r15, %r14, 1;\n"
                              "    add.s32             %r16, %r10, -1;\n"
                              "    and.b32             %r17, %r14, %r16;\n"
                              "    sub.s32             %r2, %r15, %r17;\n"
                              "    add.s32             %r3, %r2, %r10;\n"
                              "    setp.ge.s32         %p1, %r3, %r9;\n"
                              "    @   %p1 bra         BB1_3;\n"
                              "\n"
                              "    shl.b32             %r18, %r2, 2;\n"
                              "    add.s32             %r4, %r1, %r18;\n"
                              "    shl.b32             %r19, %r3, 2;\n"
                              "    add.s32             %r5, %r1, %r19;\n"
                              "    ld.global.u32       %r6, [%r5];\n"
                              "    ld.global.u32       %r7, [%r4];\n"
                              "    setp.le.s32         %p2, %r7, %r6;\n"
                              "    @   %p2 bra         BB1_3;\n"
                              "\n"
                              "    st.global.u32       [%r4], %r6;\n"
                              "    st.global.u32       [%r5], %r7;\n"
                              "    ld.global.u32       %r20, [swapCount];\n"
                              "    add.s32             %r21, %r20, 1;\n"
                              "    st.global.u32       [swapCount],    %r21;\n"
                              "\n"
                              "BB1_3:\n"
                              "    ret;\n"
                              "}\n"
#endif /* OMR_ENV_DATA64 */
};

static char parameters_code[] = { ".version 3.2\n"
                                  ".target sm_20\n"
#if defined(OMR_ENV_DATA64)
                                  ".address_size 64\n"
                                  "\n"
                                  ".visible .entry store(\n"
                                  "    .param .u64 store_param_0,\n"
                                  "    .param .u32 store_param_1,\n"
                                  "    .param .u8  store_param_2,\n"
                                  "    .param .u16 store_param_3,\n"
                                  "    .param .f64 store_param_4,\n"
                                  "    .param .f32 store_param_5,\n"
                                  "    .param .u32 store_param_6,\n"
                                  "    .param .u64 store_param_7,\n"
                                  "    .param .u16 store_param_8\n"
                                  ")\n"
                                  "{\n"
                                  "    .reg .pred          %p<10>;\n"
                                  "    .reg .s16           %rs<4>;\n"
                                  "    .reg .s32           %r<4>;\n"
                                  "    .reg .f32           %f<2>;\n"
                                  "    .reg .s64           %rd<5>;\n"
                                  "    .reg .f64           %fd<2>;\n"
                                  "\n"
                                  "    ld.param.u64        %rd3, [store_param_0];\n"
                                  "    ld.param.u32        %r3, [store_param_1];\n"
                                  "    ld.param.u16        %rs2, [store_param_3];\n"
                                  "    ld.param.f64        %fd1, [store_param_4];\n"
                                  "    ld.param.f32        %f1, [store_param_5];\n"
                                  "    ld.param.u32        %r2, [store_param_6];\n"
                                  "    ld.param.u64        %rd4, [store_param_7];\n"
                                  "    ld.param.u16        %rs3, [store_param_8];\n"
                                  "    cvta.to.global.u64  %rd1, %rd3;\n"
                                  "    setp.lt.s32         %p1, %r3, 40;\n"
                                  "    ld.param.s8         %rs1, [store_param_2];\n"
                                  "    @%p1 bra            BB0_17;\n"
                                  "\n"
                                  "    mov.u32             %r1, %tid.x;\n"
                                  "    setp.eq.s32         %p2, %r1, 0;\n"
                                  "    @%p2 bra            BB0_16;\n"
                                  "\n"
                                  "    setp.eq.s32         %p3, %r1, 1;\n"
                                  "    @%p3 bra            BB0_15;\n"
                                  "\n"
                                  "    setp.eq.s32         %p4, %r1, 2;\n"
                                  "    @%p4 bra            BB0_14;\n"
                                  "\n"
                                  "    setp.eq.s32         %p5, %r1, 3;\n"
                                  "    @%p5 bra            BB0_13;\n"
                                  "\n"
                                  "    setp.eq.s32         %p6, %r1, 4;\n"
                                  "    @%p6 bra            BB0_12;\n"
                                  "\n"
                                  "    setp.eq.s32         %p7, %r1, 5;\n"
                                  "    @%p7 bra            BB0_11;\n"
                                  "\n"
                                  "    setp.eq.s32         %p8, %r1, 6;\n"
                                  "    @%p8 bra            BB0_10;\n"
                                  "\n"
                                  "    setp.ne.s32         %p9, %r1, 7;\n"
                                  "    @%p9 bra            BB0_17;\n"
                                  "\n"
                                  "    st.global.u16       [%rd1+34], %rs3;\n"
                                  "    bra.uni             BB0_17;\n"
                                  "\n"
                                  "BB0_10:\n"
                                  "    st.global.u64       [%rd1+8], %rd4;\n"
                                  "    bra.uni             BB0_17;\n"
                                  "\n"
                                  "BB0_11:\n"
                                  "    st.global.u32       [%rd1+28], %r2;\n"
                                  "    bra.uni             BB0_17;\n"
                                  "\n"
                                  "BB0_12:\n"
                                  "    st.global.f32       [%rd1+24], %f1;\n"
                                  "    bra.uni             BB0_17;\n"
                                  "\n"
                                  "BB0_13:\n"
                                  "    st.global.f64       [%rd1], %fd1;\n"
                                  "    bra.uni             BB0_17;\n"
                                  "\n"
                                  "BB0_14:\n"
                                  "    st.global.u16       [%rd1+32], %rs2;\n"
                                  "    bra.uni             BB0_17;\n"
                                  "\n"
                                  "BB0_15:\n"
                                  "    st.global.u8        [%rd1+36], %rs1;\n"
                                  "    bra.uni             BB0_17;\n"
                                  "\n"
                                  "BB0_16:\n"
                                  "    st.global.u64       [%rd1+16], %rd3;\n"
                                  "\n"
                                  "BB0_17:\n"
                                  "    ret;\n"
                                  "}\n"
#else
                                  ".address_size 32\n"
                                  "\n"
                                  ".visible .entry store(\n"
                                  "    .param .u32 store_param_0,\n"
                                  "    .param .u32 store_param_1,\n"
                                  "    .param .u8  store_param_2,\n"
                                  "    .param .u16 store_param_3,\n"
                                  "    .param .f64 store_param_4,\n"
                                  "    .param .f32 store_param_5,\n"
                                  "    .param .u32 store_param_6,\n"
                                  "    .param .u64 store_param_7,\n"
                                  "    .param .u16 store_param_8\n"
                                  ")\n"
                                  "{\n"
                                  "    .reg .pred          %p<10>;\n"
                                  "    .reg .s16           %rs<4>;\n"
                                  "    .reg .s32           %r<7>;\n"
                                  "    .reg .f32           %f<2>;\n"
                                  "    .reg .s64           %rd<3>;\n"
                                  "    .reg .f64           %fd<2>;\n"
                                  "\n"
                                  "    ld.param.u32        %r4, [store_param_0];\n"
                                  "    ld.param.u32        %r6, [store_param_1];\n"
                                  "    ld.param.u16        %rs2, [store_param_3];\n"
                                  "    ld.param.f64        %fd1, [store_param_4];\n"
                                  "    ld.param.f32        %f1, [store_param_5];\n"
                                  "    ld.param.u32        %r5, [store_param_6];\n"
                                  "    ld.param.u64        %rd1, [store_param_7];\n"
                                  "    ld.param.u16        %rs3, [store_param_8];\n"
                                  "    cvta.to.global.u32  %r1, %r4;\n"
                                  "    setp.lt.s32 %p1,    %r6, 40;\n"
                                  "    ld.param.s8         %rs1, [store_param_2];\n"
                                  "    @%p1 bra            BB0_17;\n"
                                  "\n"
                                  "    mov.u32             %r2, %tid.x;\n"
                                  "    setp.eq.s32         %p2, %r2, 0;\n"
                                  "    @%p2 bra            BB0_16;\n"
                                  "\n"
                                  "    setp.eq.s32         %p3, %r2, 1;\n"
                                  "    @%p3 bra            BB0_15;\n"
                                  "\n"
                                  "    setp.eq.s32         %p4, %r2, 2;\n"
                                  "    @%p4 bra            BB0_14;\n"
                                  "\n"
                                  "    setp.eq.s32         %p5, %r2, 3;\n"
                                  "    @%p5 bra            BB0_13;\n"
                                  "\n"
                                  "    setp.eq.s32         %p6, %r2, 4;\n"
                                  "    @%p6 bra            BB0_12;\n"
                                  "\n"
                                  "    setp.eq.s32         %p7, %r2, 5;\n"
                                  "    @%p7 bra            BB0_11;\n"
                                  "\n"
                                  "    setp.eq.s32         %p8, %r2, 6;\n"
                                  "    @%p8 bra            BB0_10;\n"
                                  "\n"
                                  "    setp.ne.s32         %p9, %r2, 7;\n"
                                  "    @%p9 bra            BB0_17;\n"
                                  "\n"
                                  "    st.global.u16       [%r1+34], %rs3;\n"
                                  "    bra.uni             BB0_17;\n"
                                  "\n"
                                  "BB0_10:\n"
                                  "    st.global.u64       [%r1+8], %rd1;\n"
                                  "    bra.uni             BB0_17;\n"
                                  "\n"
                                  "BB0_11:\n"
                                  "    st.global.u32       [%r1+28], %r5;\n"
                                  "    bra.uni             BB0_17;\n"
                                  "\n"
                                  "BB0_12:\n"
                                  "    st.global.f32       [%r1+24], %f1;\n"
                                  "    bra.uni             BB0_17;\n"
                                  "\n"
                                  "BB0_13:\n"
                                  "    st.global.f64       [%r1], %fd1;\n"
                                  "    bra.uni             BB0_17;\n"
                                  "\n"
                                  "BB0_14:\n"
                                  "    st.global.u16       [%r1+32], %rs2;\n"
                                  "    bra.uni             BB0_17;\n"
                                  "\n"
                                  "BB0_15:\n"
                                  "    st.global.u8        [%r1+36], %rs1;\n"
                                  "    bra.uni             BB0_17;\n"
                                  "\n"
                                  "BB0_16:\n"
                                  "    cvt.u64.u32 %rd2,   %r4;\n"
                                  "    st.global.u64       [%r1+16], %rd2;\n"
                                  "\n"
                                  "BB0_17:\n"
                                  "    ret;\n"
                                  "}\n"
#endif /* OMR_ENV_DATA64 */
};

#define PTX_INIT(code)     \
    {                      \
        sizeof(code), code \
    }

const CudaTestArray<char> CudaDeviceTest::ptxFragment1 = PTX_INIT(fragment1_code);
const CudaTestArray<char> CudaDeviceTest::ptxFragment2 = PTX_INIT(fragment2_code);
const CudaTestArray<char> CudaDeviceTest::ptxModule = PTX_INIT(module_code);
const CudaTestArray<char> CudaDeviceTest::ptxParameters = PTX_INIT(parameters_code);
