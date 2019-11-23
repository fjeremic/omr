/*******************************************************************************
 * Copyright (c) 2000, 2018 IBM Corp. and others
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

#ifndef OMR_OPCODEPROPERTIES_INCL
#define OMR_OPCODEPROPERTIES_INCL

// OMR opcode properties

{
    /* .opcode               = */ TR::BadILOp,
    /* .name                 = */ "BadILOp",
    /* .properties1          = */ 0,
    /* .properties2          = */ 0,
    /* .properties3          = */ 0,
    /* .properties4          = */ 0,
    /* .dataType             = */ TR::NoType,
    /* .typeProperties       = */ 0,
    /* .childProperties      = */ ILChildProp::NoChildren,
    /* .swapChildrenOpCode   = */ TR::BadILOp,
    /* .reverseBranchOpCode  = */ TR::BadILOp,
    /* .booleanCompareOpCode = */ TR::BadILOp,
    /* .ifCompareOpCode      = */ TR::BadILOp,
},

    {
        /* .opcode               = */ TR::aconst,
        /* .name                 = */ "aconst",
        /* .properties1          = */ ILProp1::LoadConst,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iconst,
        /* .name                 = */ "iconst",
        /* .properties1          = */ ILProp1::LoadConst,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lconst,
        /* .name                 = */ "lconst",
        /* .properties1          = */ ILProp1::LoadConst,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fconst,
        /* .name                 = */ "fconst",
        /* .properties1          = */ ILProp1::LoadConst,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dconst,
        /* .name                 = */ "dconst",
        /* .properties1          = */ ILProp1::LoadConst,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bconst,
        /* .name                 = */ "bconst",
        /* .properties1          = */ ILProp1::LoadConst,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sconst,
        /* .name                 = */ "sconst",
        /* .properties1          = */ ILProp1::LoadConst,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iload,
        /* .name                 = */ "iload",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fload,
        /* .name                 = */ "fload",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dload,
        /* .name                 = */ "dload",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::aload,
        /* .name                 = */ "aload",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bload,
        /* .name                 = */ "bload",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sload,
        /* .name                 = */ "sload",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lload,
        /* .name                 = */ "lload",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::irdbar,
        /* .name                 = */ "irdbar",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack |
            ILProp2::ReadBarrierLoad,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::frdbar,
        /* .name                 = */ "frdbar",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack |
            ILProp2::ReadBarrierLoad,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::drdbar,
        /* .name                 = */ "drdbar",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack |
            ILProp2::ReadBarrierLoad,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ardbar,
        /* .name                 = */ "ardbar",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack |
            ILProp2::ReadBarrierLoad,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::brdbar,
        /* .name                 = */ "brdbar",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack |
            ILProp2::ReadBarrierLoad,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::srdbar,
        /* .name                 = */ "srdbar",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack |
            ILProp2::ReadBarrierLoad,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lrdbar,
        /* .name                 = */ "lrdbar",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack |
            ILProp2::ReadBarrierLoad,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iloadi,
        /* .name                 = */ "iloadi",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::floadi,
        /* .name                 = */ "floadi",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dloadi,
        /* .name                 = */ "dloadi",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::aloadi,
        /* .name                 = */ "aloadi",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bloadi,
        /* .name                 = */ "bloadi",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sloadi,
        /* .name                 = */ "sloadi",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lloadi,
        /* .name                 = */ "lloadi",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::irdbari,
        /* .name                 = */ "irdbari",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack |
            ILProp2::ReadBarrierLoad,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::frdbari,
        /* .name                 = */ "frdbari",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack |
            ILProp2::ReadBarrierLoad,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::drdbari,
        /* .name                 = */ "drdbari",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack |
            ILProp2::ReadBarrierLoad,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ardbari,
        /* .name                 = */ "ardbari",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack |
            ILProp2::ReadBarrierLoad,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::brdbari,
        /* .name                 = */ "brdbari",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack |
            ILProp2::ReadBarrierLoad,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::srdbari,
        /* .name                 = */ "srdbari",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack |
            ILProp2::ReadBarrierLoad,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lrdbari,
        /* .name                 = */ "lrdbari",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack |
            ILProp2::ReadBarrierLoad,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::istore,
        /* .name                 = */ "istore",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lstore,
        /* .name                 = */ "lstore",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fstore,
        /* .name                 = */ "fstore",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dstore,
        /* .name                 = */ "dstore",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::astore,
        /* .name                 = */ "astore",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bstore,
        /* .name                 = */ "bstore",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sstore,
        /* .name                 = */ "sstore",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iwrtbar,
        /* .name                 = */ "iwrtbar",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::WriteBarrierStore | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Int32, TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lwrtbar,
        /* .name                 = */ "lwrtbar",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::WriteBarrierStore | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Int64, TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fwrtbar,
        /* .name                 = */ "fwrtbar",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::WriteBarrierStore | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_CHILD(TR::Float, TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dwrtbar,
        /* .name                 = */ "dwrtbar",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::WriteBarrierStore | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_CHILD(TR::Double, TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::awrtbar,
        /* .name                 = */ "awrtbar",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::WriteBarrierStore | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bwrtbar,
        /* .name                 = */ "bwrtbar",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::WriteBarrierStore | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Int8, TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::swrtbar,
        /* .name                 = */ "swrtbar",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::WriteBarrierStore | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Int16, TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lstorei,
        /* .name                 = */ "lstorei",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fstorei,
        /* .name                 = */ "fstorei",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dstorei,
        /* .name                 = */ "dstorei",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::astorei,
        /* .name                 = */ "astorei",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bstorei,
        /* .name                 = */ "bstorei",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sstorei,
        /* .name                 = */ "sstorei",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::istorei,
        /* .name                 = */ "istorei",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lwrtbari,
        /* .name                 = */ "lwrtbari",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::WriteBarrierStore | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */
        THREE_CHILD(TR::Address, TR::Int64, TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fwrtbari,
        /* .name                 = */ "fwrtbari",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::WriteBarrierStore | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */
        THREE_CHILD(TR::Address, TR::Float, TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dwrtbari,
        /* .name                 = */ "dwrtbari",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::WriteBarrierStore | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */
        THREE_CHILD(TR::Address, TR::Double, TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::awrtbari,
        /* .name                 = */ "awrtbari",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::WriteBarrierStore | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */
        THREE_CHILD(TR::Address, TR::Address, TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bwrtbari,
        /* .name                 = */ "bwrtbari",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::WriteBarrierStore | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */
        THREE_CHILD(TR::Address, TR::Int8, TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::swrtbari,
        /* .name                 = */ "swrtbari",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::WriteBarrierStore | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */
        THREE_CHILD(TR::Address, TR::Int16, TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iwrtbari,
        /* .name                 = */ "iwrtbari",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::WriteBarrierStore | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */
        THREE_CHILD(TR::Address, TR::Int32, TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::Goto,
        /* .name                 = */ "goto",
        /* .properties1          = */ ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ireturn,
        /* .name                 = */ "ireturn",
        /* .properties1          = */ ILProp1::Return | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */
        ONE_CHILD(
            ILChildProp::UnspecifiedChildType), // ireturn is used to return all
                                                // types smaller than Int32
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lreturn,
        /* .name                 = */ "lreturn",
        /* .properties1          = */ ILProp1::Return | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::freturn,
        /* .name                 = */ "freturn",
        /* .properties1          = */ ILProp1::Return | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dreturn,
        /* .name                 = */ "dreturn",
        /* .properties1          = */ ILProp1::Return | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::areturn,
        /* .name                 = */ "areturn",
        /* .properties1          = */ ILProp1::Return | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::Return,
        /* .name                 = */ "return",
        /* .properties1          = */ ILProp1::Return | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::asynccheck,
        /* .name                 = */ "asynccheck",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::MustBeLowered |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::athrow,
        /* .name                 = */ "athrow",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::MustBeLowered |
            ILProp2::CanRaiseException | ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::icall,
        /* .name                 = */ "icall",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lcall,
        /* .name                 = */ "lcall",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fcall,
        /* .name                 = */ "fcall",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dcall,
        /* .name                 = */ "dcall",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::acall,
        /* .name                 = */ "acall",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::call,
        /* .name                 = */ "call",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iadd,
        /* .name                 = */ "iadd",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::iadd,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ladd,
        /* .name                 = */ "ladd",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::ladd,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fadd,
        /* .name                 = */ "fadd",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::fadd,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dadd,
        /* .name                 = */ "dadd",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::dadd,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::badd,
        /* .name                 = */ "badd",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::badd,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sadd,
        /* .name                 = */ "sadd",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::sadd,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::isub,
        /* .name                 = */ "isub",
        /* .properties1          = */ ILProp1::Sub,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lsub,
        /* .name                 = */ "lsub",
        /* .properties1          = */ ILProp1::Sub,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fsub,
        /* .name                 = */ "fsub",
        /* .properties1          = */ ILProp1::Sub,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dsub,
        /* .name                 = */ "dsub",
        /* .properties1          = */ ILProp1::Sub,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bsub,
        /* .name                 = */ "bsub",
        /* .properties1          = */ ILProp1::Sub,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ssub,
        /* .name                 = */ "ssub",
        /* .properties1          = */ ILProp1::Sub,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::asub,
        /* .name                 = */ "asub",
        /* .properties1          = */ ILProp1::Sub,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::imul,
        /* .name                 = */ "imul",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Mul,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::imul,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lmul,
        /* .name                 = */ "lmul",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Mul,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lmul,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fmul,
        /* .name                 = */ "fmul",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Mul,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::fmul,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dmul,
        /* .name                 = */ "dmul",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Mul,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::dmul,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bmul,
        /* .name                 = */ "bmul",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Mul,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::bmul,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::smul,
        /* .name                 = */ "smul",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Mul,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::smul,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::idiv,
        /* .name                 = */ "idiv",
        /* .properties1          = */ ILProp1::Div,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ldiv,
        /* .name                 = */ "ldiv",
        /* .properties1          = */ ILProp1::Div,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fdiv,
        /* .name                 = */ "fdiv",
        /* .properties1          = */ ILProp1::Div,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ddiv,
        /* .name                 = */ "ddiv",
        /* .properties1          = */ ILProp1::Div,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bdiv,
        /* .name                 = */ "bdiv",
        /* .properties1          = */ ILProp1::Div,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sdiv,
        /* .name                 = */ "sdiv",
        /* .properties1          = */ ILProp1::Div,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iudiv,
        /* .name                 = */ "iudiv",
        /* .properties1          = */ ILProp1::Div,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ludiv,
        /* .name                 = */ "ludiv",
        /* .properties1          = */ ILProp1::Div,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    /*!
     * \brief remainder (int)
     *
     * irem(X, Y) is defined to be the remainder of the signed division of X by
     * Y. This is distinct from the iurem opcode. Note that iurem(-5,3) is 2
     * while irem(-5,3) is -2.
     */
    {
        /* .opcode               = */ TR::irem,
        /* .name                 = */ "irem",
        /* .properties1          = */ ILProp1::Rem,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    /*!
     * \brief remainder (long)
     *
     * See irem
     */
    {
        /* .opcode               = */ TR::lrem,
        /* .name                 = */ "lrem",
        /* .properties1          = */ ILProp1::Rem,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::frem,
        /* .name                 = */ "frem",
        /* .properties1          = */ ILProp1::Rem,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::drem,
        /* .name                 = */ "drem",
        /* .properties1          = */ ILProp1::Rem,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    /*!
     * \brief remainder (byte)
     *
     * See irem
     */
    {
        /* .opcode               = */ TR::brem,
        /* .name                 = */ "brem",
        /* .properties1          = */ ILProp1::Rem,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    /*!
     * \brief remainder (short)
     *
     * See irem
     */
    {
        /* .opcode               = */ TR::srem,
        /* .name                 = */ "srem",
        /* .properties1          = */ ILProp1::Rem,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    /*!
     * \brief unsigned remainder (int)
     *
     * irem(X, Y) is defined to be the remainder of the signed division of X by
     * Y. This is distinct from the iurem opcode. Note that iurem(-5,3) is 2
     * while irem(-5,3) is -2.
     */
    {
        /* .opcode               = */ TR::iurem,
        /* .name                 = */ "iurem",
        /* .properties1          = */ ILProp1::Rem,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ineg,
        /* .name                 = */ "ineg",
        /* .properties1          = */ ILProp1::Neg,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lneg,
        /* .name                 = */ "lneg",
        /* .properties1          = */ ILProp1::Neg,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fneg,
        /* .name                 = */ "fneg",
        /* .properties1          = */ ILProp1::Neg,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dneg,
        /* .name                 = */ "dneg",
        /* .properties1          = */ ILProp1::Neg,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bneg,
        /* .name                 = */ "bneg",
        /* .properties1          = */ ILProp1::Neg,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sneg,
        /* .name                 = */ "sneg",
        /* .properties1          = */ ILProp1::Neg,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iabs,
        /* .name                 = */ "iabs",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::Abs,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::labs,
        /* .name                 = */ "labs",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::Abs,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fabs,
        /* .name                 = */ "fabs",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::Abs,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dabs,
        /* .name                 = */ "dabs",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::Abs,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ishl,
        /* .name                 = */ "ishl",
        /* .properties1          = */ ILProp1::LeftShift,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lshl,
        /* .name                 = */ "lshl",
        /* .properties1          = */ ILProp1::LeftShift,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Int64, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bshl,
        /* .name                 = */ "bshl",
        /* .properties1          = */ ILProp1::LeftShift,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Int8, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sshl,
        /* .name                 = */ "sshl",
        /* .properties1          = */ ILProp1::LeftShift,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Int16, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ishr,
        /* .name                 = */ "ishr",
        /* .properties1          = */ ILProp1::RightShift,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lshr,
        /* .name                 = */ "lshr",
        /* .properties1          = */ ILProp1::RightShift,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Int64, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bshr,
        /* .name                 = */ "bshr",
        /* .properties1          = */ ILProp1::RightShift,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Int8, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sshr,
        /* .name                 = */ "sshr",
        /* .properties1          = */ ILProp1::RightShift,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Int16, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iushr,
        /* .name                 = */ "iushr",
        /* .properties1          = */ ILProp1::RightShift |
            ILProp1::ShiftLogical,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lushr,
        /* .name                 = */ "lushr",
        /* .properties1          = */ ILProp1::RightShift |
            ILProp1::ShiftLogical,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Int64, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bushr,
        /* .name                 = */ "bushr",
        /* .properties1          = */ ILProp1::RightShift |
            ILProp1::ShiftLogical,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Int8, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sushr,
        /* .name                 = */ "sushr",
        /* .properties1          = */ ILProp1::RightShift |
            ILProp1::ShiftLogical,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Int16, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::irol,
        /* .name                 = */ "irol",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::LeftRotate,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lrol,
        /* .name                 = */ "lrol",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::LeftRotate,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Int64, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iand,
        /* .name                 = */ "iand",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::And,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::iand,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::land,
        /* .name                 = */ "land",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::And,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::land,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::band,
        /* .name                 = */ "band",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::And,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::band,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sand,
        /* .name                 = */ "sand",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::And,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::sand,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ior,
        /* .name                 = */ "ior",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Or,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::ior,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lor,
        /* .name                 = */ "lor",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Or,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lor,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bor,
        /* .name                 = */ "bor",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Or,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::bor,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sor,
        /* .name                 = */ "sor",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Or,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::sor,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ixor,
        /* .name                 = */ "ixor",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Xor,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::ixor,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lxor,
        /* .name                 = */ "lxor",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Xor,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lxor,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bxor,
        /* .name                 = */ "bxor",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Xor,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::bxor,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sxor,
        /* .name                 = */ "sxor",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Xor,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::sxor,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::i2l,
        /* .name                 = */ "i2l",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::SignExtension,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::i2f,
        /* .name                 = */ "i2f",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::i2d,
        /* .name                 = */ "i2d",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::i2b,
        /* .name                 = */ "i2b",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::i2s,
        /* .name                 = */ "i2s",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::i2a,
        /* .name                 = */ "i2a",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iu2l,
        /* .name                 = */ "iu2l",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::ZeroExtension,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iu2f,
        /* .name                 = */ "iu2f",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iu2d,
        /* .name                 = */ "iu2d",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iu2a,
        /* .name                 = */ "iu2a",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::l2i,
        /* .name                 = */ "l2i",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::l2f,
        /* .name                 = */ "l2f",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::l2d,
        /* .name                 = */ "l2d",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::l2b,
        /* .name                 = */ "l2b",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::l2s,
        /* .name                 = */ "l2s",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::l2a,
        /* .name                 = */ "l2a",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lu2f,
        /* .name                 = */ "lu2f",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lu2d,
        /* .name                 = */ "lu2d",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lu2a,
        /* .name                 = */ "lu2a",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::f2i,
        /* .name                 = */ "f2i",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::f2l,
        /* .name                 = */ "f2l",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::f2d,
        /* .name                 = */ "f2d",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::f2b,
        /* .name                 = */ "f2b",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::f2s,
        /* .name                 = */ "f2s",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::d2i,
        /* .name                 = */ "d2i",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::d2l,
        /* .name                 = */ "d2l",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::d2f,
        /* .name                 = */ "d2f",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::d2b,
        /* .name                 = */ "d2b",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::d2s,
        /* .name                 = */ "d2s",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::b2i,
        /* .name                 = */ "b2i",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::SignExtension,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::b2l,
        /* .name                 = */ "b2l",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::SignExtension,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::b2f,
        /* .name                 = */ "b2f",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::b2d,
        /* .name                 = */ "b2d",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::b2s,
        /* .name                 = */ "b2s",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::SignExtension,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::b2a,
        /* .name                 = */ "b2a",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ONE_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bu2i,
        /* .name                 = */ "bu2i",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::ZeroExtension,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bu2l,
        /* .name                 = */ "bu2l",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::ZeroExtension,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bu2f,
        /* .name                 = */ "bu2f",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bu2d,
        /* .name                 = */ "bu2d",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bu2s,
        /* .name                 = */ "bu2s",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::ZeroExtension,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bu2a,
        /* .name                 = */ "bu2a",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::ZeroExtension,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ONE_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::s2i,
        /* .name                 = */ "s2i",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::SignExtension,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::s2l,
        /* .name                 = */ "s2l",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::SignExtension,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::s2f,
        /* .name                 = */ "s2f",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::s2d,
        /* .name                 = */ "s2d",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::s2b,
        /* .name                 = */ "s2b",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::s2a,
        /* .name                 = */ "s2a",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ONE_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::su2i,
        /* .name                 = */ "su2i",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::ZeroExtension,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::su2l,
        /* .name                 = */ "su2l",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::ZeroExtension,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::su2f,
        /* .name                 = */ "su2f",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::su2d,
        /* .name                 = */ "su2d",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::su2a,
        /* .name                 = */ "su2a",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ONE_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::a2i,
        /* .name                 = */ "a2i",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::a2l,
        /* .name                 = */ "a2l",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::a2b,
        /* .name                 = */ "a2b",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::a2s,
        /* .name                 = */ "a2s",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::icmpeq,
        /* .name                 = */ "icmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::icmpeq,
        /* .reverseBranchOpCode  = */ TR::icmpne,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ificmpeq,
    },

    {
        /* .opcode               = */ TR::icmpne,
        /* .name                 = */ "icmpne",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::icmpne,
        /* .reverseBranchOpCode  = */ TR::icmpeq,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ificmpne,
    },

    {
        /* .opcode               = */ TR::icmplt,
        /* .name                 = */ "icmplt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::icmpgt,
        /* .reverseBranchOpCode  = */ TR::icmpge,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ificmplt,
    },

    {
        /* .opcode               = */ TR::icmpge,
        /* .name                 = */ "icmpge",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::icmple,
        /* .reverseBranchOpCode  = */ TR::icmplt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ificmpge,
    },

    {
        /* .opcode               = */ TR::icmpgt,
        /* .name                 = */ "icmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::icmplt,
        /* .reverseBranchOpCode  = */ TR::icmple,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ificmpgt,
    },

    {
        /* .opcode               = */ TR::icmple,
        /* .name                 = */ "icmple",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::icmpge,
        /* .reverseBranchOpCode  = */ TR::icmpgt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ificmple,
    },

    {
        /* .opcode               = */ TR::iucmpeq,
        /* .name                 = */ "iucmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::iucmpeq,
        /* .reverseBranchOpCode  = */ TR::iucmpne,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifiucmpeq,
    },

    {
        /* .opcode               = */ TR::iucmpne,
        /* .name                 = */ "iucmpne",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::iucmpne,
        /* .reverseBranchOpCode  = */ TR::iucmpeq,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifiucmpne,
    },

    {
        /* .opcode               = */ TR::iucmplt,
        /* .name                 = */ "iucmplt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::iucmpgt,
        /* .reverseBranchOpCode  = */ TR::iucmpge,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifiucmplt,
    },

    {
        /* .opcode               = */ TR::iucmpge,
        /* .name                 = */ "iucmpge",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::iucmple,
        /* .reverseBranchOpCode  = */ TR::iucmplt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifiucmpge,
    },

    {
        /* .opcode               = */ TR::iucmpgt,
        /* .name                 = */ "iucmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::iucmplt,
        /* .reverseBranchOpCode  = */ TR::iucmple,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifiucmpgt,
    },

    {
        /* .opcode               = */ TR::iucmple,
        /* .name                 = */ "iucmple",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::iucmpge,
        /* .reverseBranchOpCode  = */ TR::iucmpgt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifiucmple,
    },

    {
        /* .opcode               = */ TR::lcmpeq,
        /* .name                 = */ "lcmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lcmpeq,
        /* .reverseBranchOpCode  = */ TR::lcmpne,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iflcmpeq,
    },

    {
        /* .opcode               = */ TR::lcmpne,
        /* .name                 = */ "lcmpne",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lcmpne,
        /* .reverseBranchOpCode  = */ TR::lcmpeq,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iflcmpne,
    },

    {
        /* .opcode               = */ TR::lcmplt,
        /* .name                 = */ "lcmplt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lcmpgt,
        /* .reverseBranchOpCode  = */ TR::lcmpge,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iflcmplt,
    },

    {
        /* .opcode               = */ TR::lcmpge,
        /* .name                 = */ "lcmpge",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lcmple,
        /* .reverseBranchOpCode  = */ TR::lcmplt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iflcmpge,
    },

    {
        /* .opcode               = */ TR::lcmpgt,
        /* .name                 = */ "lcmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lcmplt,
        /* .reverseBranchOpCode  = */ TR::lcmple,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iflcmpgt,
    },

    {
        /* .opcode               = */ TR::lcmple,
        /* .name                 = */ "lcmple",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lcmpge,
        /* .reverseBranchOpCode  = */ TR::lcmpgt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iflcmple,
    },

    {
        /* .opcode               = */ TR::lucmpeq,
        /* .name                 = */ "lucmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lucmpeq,
        /* .reverseBranchOpCode  = */ TR::lucmpne,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iflucmpeq,
    },

    {
        /* .opcode               = */ TR::lucmpne,
        /* .name                 = */ "lucmpne",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lucmpne,
        /* .reverseBranchOpCode  = */ TR::lucmpeq,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iflucmpne,
    },

    {
        /* .opcode               = */ TR::lucmplt,
        /* .name                 = */ "lucmplt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lucmpgt,
        /* .reverseBranchOpCode  = */ TR::lucmpge,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iflucmplt,
    },

    {
        /* .opcode               = */ TR::lucmpge,
        /* .name                 = */ "lucmpge",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lucmple,
        /* .reverseBranchOpCode  = */ TR::lucmplt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iflucmpge,
    },

    {
        /* .opcode               = */ TR::lucmpgt,
        /* .name                 = */ "lucmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lucmplt,
        /* .reverseBranchOpCode  = */ TR::lucmple,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iflucmpgt,
    },

    {
        /* .opcode               = */ TR::lucmple,
        /* .name                 = */ "lucmple",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lucmpge,
        /* .reverseBranchOpCode  = */ TR::lucmpgt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iflucmple,
    },

    {
        /* .opcode               = */ TR::fcmpeq,
        /* .name                 = */ "fcmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::fcmpeq,
        /* .reverseBranchOpCode  = */ TR::fcmpneu,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iffcmpeq,
    },

    {
        /* .opcode               = */ TR::fcmpne,
        /* .name                 = */ "fcmpne",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::fcmpne,
        /* .reverseBranchOpCode  = */ TR::fcmpequ,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iffcmpne,
    },

    {
        /* .opcode               = */ TR::fcmplt,
        /* .name                 = */ "fcmplt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::fcmpgt,
        /* .reverseBranchOpCode  = */ TR::fcmpgeu,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iffcmplt,
    },

    {
        /* .opcode               = */ TR::fcmpge,
        /* .name                 = */ "fcmpge",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::fcmple,
        /* .reverseBranchOpCode  = */ TR::fcmpltu,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iffcmpge,
    },

    {
        /* .opcode               = */ TR::fcmpgt,
        /* .name                 = */ "fcmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::fcmplt,
        /* .reverseBranchOpCode  = */ TR::fcmpleu,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iffcmpgt,
    },

    {
        /* .opcode               = */ TR::fcmple,
        /* .name                 = */ "fcmple",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::fcmpge,
        /* .reverseBranchOpCode  = */ TR::fcmpgtu,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iffcmple,
    },

    {
        /* .opcode               = */ TR::fcmpequ,
        /* .name                 = */ "fcmpequ",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual |
            ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::fcmpequ,
        /* .reverseBranchOpCode  = */ TR::fcmpne,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iffcmpequ,
    },

    {
        /* .opcode               = */ TR::fcmpneu,
        /* .name                 = */ "fcmpneu",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater | ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::fcmpneu,
        /* .reverseBranchOpCode  = */ TR::fcmpeq,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iffcmpneu,
    },

    {
        /* .opcode               = */ TR::fcmpltu,
        /* .name                 = */ "fcmpltu",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::fcmpgtu,
        /* .reverseBranchOpCode  = */ TR::fcmpge,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iffcmpltu,
    },

    {
        /* .opcode               = */ TR::fcmpgeu,
        /* .name                 = */ "fcmpgeu",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual | ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::fcmpleu,
        /* .reverseBranchOpCode  = */ TR::fcmplt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iffcmpgeu,
    },

    {
        /* .opcode               = */ TR::fcmpgtu,
        /* .name                 = */ "fcmpgtu",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::fcmpltu,
        /* .reverseBranchOpCode  = */ TR::fcmple,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iffcmpgtu,
    },

    {
        /* .opcode               = */ TR::fcmpleu,
        /* .name                 = */ "fcmpleu",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual | ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::fcmpgeu,
        /* .reverseBranchOpCode  = */ TR::fcmpgt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::iffcmpleu,
    },

    {
        /* .opcode               = */ TR::dcmpeq,
        /* .name                 = */ "dcmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::dcmpeq,
        /* .reverseBranchOpCode  = */ TR::dcmpneu,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifdcmpeq,
    },

    {
        /* .opcode               = */ TR::dcmpne,
        /* .name                 = */ "dcmpne",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::dcmpne,
        /* .reverseBranchOpCode  = */ TR::dcmpequ,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifdcmpne,
    },

    {
        /* .opcode               = */ TR::dcmplt,
        /* .name                 = */ "dcmplt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::dcmpgt,
        /* .reverseBranchOpCode  = */ TR::dcmpgeu,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifdcmplt,
    },

    {
        /* .opcode               = */ TR::dcmpge,
        /* .name                 = */ "dcmpge",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::dcmple,
        /* .reverseBranchOpCode  = */ TR::dcmpltu,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifdcmpge,
    },

    {
        /* .opcode               = */ TR::dcmpgt,
        /* .name                 = */ "dcmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::dcmplt,
        /* .reverseBranchOpCode  = */ TR::dcmpleu,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifdcmpgt,
    },

    {
        /* .opcode               = */ TR::dcmple,
        /* .name                 = */ "dcmple",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::dcmpge,
        /* .reverseBranchOpCode  = */ TR::dcmpgtu,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifdcmple,
    },

    {
        /* .opcode               = */ TR::dcmpequ,
        /* .name                 = */ "dcmpequ",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual |
            ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::dcmpequ,
        /* .reverseBranchOpCode  = */ TR::dcmpne,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifdcmpequ,
    },

    {
        /* .opcode               = */ TR::dcmpneu,
        /* .name                 = */ "dcmpneu",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater | ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::dcmpneu,
        /* .reverseBranchOpCode  = */ TR::dcmpeq,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifdcmpneu,
    },

    {
        /* .opcode               = */ TR::dcmpltu,
        /* .name                 = */ "dcmpltu",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::dcmpgtu,
        /* .reverseBranchOpCode  = */ TR::dcmpge,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifdcmpltu,
    },

    {
        /* .opcode               = */ TR::dcmpgeu,
        /* .name                 = */ "dcmpgeu",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual | ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::dcmpleu,
        /* .reverseBranchOpCode  = */ TR::dcmplt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifdcmpgeu,
    },

    {
        /* .opcode               = */ TR::dcmpgtu,
        /* .name                 = */ "dcmpgtu",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::dcmpltu,
        /* .reverseBranchOpCode  = */ TR::dcmple,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifdcmpgtu,
    },

    {
        /* .opcode               = */ TR::dcmpleu,
        /* .name                 = */ "dcmpleu",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual | ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::dcmpgeu,
        /* .reverseBranchOpCode  = */ TR::dcmpgt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifdcmpleu,
    },

    {
        /* .opcode               = */ TR::acmpeq,
        /* .name                 = */ "acmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::acmpeq,
        /* .reverseBranchOpCode  = */ TR::acmpne,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifacmpeq,
    },

    {
        /* .opcode               = */ TR::acmpne,
        /* .name                 = */ "acmpne",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::acmpne,
        /* .reverseBranchOpCode  = */ TR::acmpeq,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifacmpne,
    },

    {
        /* .opcode               = */ TR::acmplt,
        /* .name                 = */ "acmplt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::UnsignedCompare | ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::acmpgt,
        /* .reverseBranchOpCode  = */ TR::acmpge,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifacmplt,
    },

    {
        /* .opcode               = */ TR::acmpge,
        /* .name                 = */ "acmpge",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::UnsignedCompare | ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::acmple,
        /* .reverseBranchOpCode  = */ TR::acmplt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifacmpge,
    },

    {
        /* .opcode               = */ TR::acmpgt,
        /* .name                 = */ "acmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::UnsignedCompare | ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::acmplt,
        /* .reverseBranchOpCode  = */ TR::acmple,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifacmpgt,
    },

    {
        /* .opcode               = */ TR::acmple,
        /* .name                 = */ "acmple",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::UnsignedCompare | ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::acmpge,
        /* .reverseBranchOpCode  = */ TR::acmpgt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifacmple,
    },

    {
        /* .opcode               = */ TR::bcmpeq,
        /* .name                 = */ "bcmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::bcmpeq,
        /* .reverseBranchOpCode  = */ TR::bcmpne,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifbcmpeq,
    },

    {
        /* .opcode               = */ TR::bcmpne,
        /* .name                 = */ "bcmpne",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::bcmpne,
        /* .reverseBranchOpCode  = */ TR::bcmpeq,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifbcmpne,
    },

    {
        /* .opcode               = */ TR::bcmplt,
        /* .name                 = */ "bcmplt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::bcmpgt,
        /* .reverseBranchOpCode  = */ TR::bcmpge,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifbcmplt,
    },

    {
        /* .opcode               = */ TR::bcmpge,
        /* .name                 = */ "bcmpge",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::bcmple,
        /* .reverseBranchOpCode  = */ TR::bcmplt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifbcmpge,
    },

    {
        /* .opcode               = */ TR::bcmpgt,
        /* .name                 = */ "bcmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::bcmplt,
        /* .reverseBranchOpCode  = */ TR::bcmple,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifbcmpgt,
    },

    {
        /* .opcode               = */ TR::bcmple,
        /* .name                 = */ "bcmple",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::bcmpge,
        /* .reverseBranchOpCode  = */ TR::bcmpgt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifbcmple,
    },

    {
        /* .opcode               = */ TR::bucmpeq,
        /* .name                 = */ "bucmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::bucmpeq,
        /* .reverseBranchOpCode  = */ TR::bucmpne,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifbucmpeq,
    },

    {
        /* .opcode               = */ TR::bucmpne,
        /* .name                 = */ "bucmpne",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::bucmpne,
        /* .reverseBranchOpCode  = */ TR::bucmpeq,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifbucmpne,
    },

    {
        /* .opcode               = */ TR::bucmplt,
        /* .name                 = */ "bucmplt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::bucmpgt,
        /* .reverseBranchOpCode  = */ TR::bucmpge,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifbucmplt,
    },

    {
        /* .opcode               = */ TR::bucmpge,
        /* .name                 = */ "bucmpge",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::bucmple,
        /* .reverseBranchOpCode  = */ TR::bucmplt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifbucmpge,
    },

    {
        /* .opcode               = */ TR::bucmpgt,
        /* .name                 = */ "bucmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::bucmplt,
        /* .reverseBranchOpCode  = */ TR::bucmple,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifbucmpgt,
    },

    {
        /* .opcode               = */ TR::bucmple,
        /* .name                 = */ "bucmple",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::bucmpge,
        /* .reverseBranchOpCode  = */ TR::bucmpgt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifbucmple,
    },

    {
        /* .opcode               = */ TR::scmpeq,
        /* .name                 = */ "scmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::scmpeq,
        /* .reverseBranchOpCode  = */ TR::scmpne,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifscmpeq,
    },

    {
        /* .opcode               = */ TR::scmpne,
        /* .name                 = */ "scmpne",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::scmpne,
        /* .reverseBranchOpCode  = */ TR::scmpeq,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifscmpne,
    },

    {
        /* .opcode               = */ TR::scmplt,
        /* .name                 = */ "scmplt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::scmpgt,
        /* .reverseBranchOpCode  = */ TR::scmpge,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifscmplt,
    },

    {
        /* .opcode               = */ TR::scmpge,
        /* .name                 = */ "scmpge",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::scmple,
        /* .reverseBranchOpCode  = */ TR::scmplt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifscmpge,
    },

    {
        /* .opcode               = */ TR::scmpgt,
        /* .name                 = */ "scmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::scmplt,
        /* .reverseBranchOpCode  = */ TR::scmple,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifscmpgt,
    },

    {
        /* .opcode               = */ TR::scmple,
        /* .name                 = */ "scmple",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::scmpge,
        /* .reverseBranchOpCode  = */ TR::scmpgt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifscmple,
    },

    {
        /* .opcode               = */ TR::sucmpeq,
        /* .name                 = */ "sucmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::sucmpeq,
        /* .reverseBranchOpCode  = */ TR::sucmpne,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifsucmpeq,
    },

    {
        /* .opcode               = */ TR::sucmpne,
        /* .name                 = */ "sucmpne",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::sucmpne,
        /* .reverseBranchOpCode  = */ TR::sucmpeq,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifsucmpne,
    },

    {
        /* .opcode               = */ TR::sucmplt,
        /* .name                 = */ "sucmplt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::sucmpgt,
        /* .reverseBranchOpCode  = */ TR::sucmpge,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifsucmplt,
    },

    {
        /* .opcode               = */ TR::sucmpge,
        /* .name                 = */ "sucmpge",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::sucmple,
        /* .reverseBranchOpCode  = */ TR::sucmplt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifsucmpge,
    },

    {
        /* .opcode               = */ TR::sucmpgt,
        /* .name                 = */ "sucmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::sucmplt,
        /* .reverseBranchOpCode  = */ TR::sucmple,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifsucmpgt,
    },

    {
        /* .opcode               = */ TR::sucmple,
        /* .name                 = */ "sucmple",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::sucmpge,
        /* .reverseBranchOpCode  = */ TR::sucmpgt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ifsucmple,
    },

    {
        /* .opcode               = */ TR::lcmp,
        /* .name                 = */ "lcmp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::CondCodeComputation,
        /* .properties3          = */ ILProp3::Signum,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fcmpl,
        /* .name                 = */ "fcmpl",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fcmpg,
        /* .name                 = */ "fcmpg",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dcmpl,
        /* .name                 = */ "dcmpl",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dcmpg,
        /* .name                 = */ "dcmpg",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ificmpeq,
        /* .name                 = */ "ificmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::ificmpeq,
        /* .reverseBranchOpCode  = */ TR::ificmpne,
        /* .booleanCompareOpCode = */ TR::icmpeq,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ificmpne,
        /* .name                 = */ "ificmpne",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::ificmpne,
        /* .reverseBranchOpCode  = */ TR::ificmpeq,
        /* .booleanCompareOpCode = */ TR::icmpne,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ificmplt,
        /* .name                 = */ "ificmplt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::ificmpgt,
        /* .reverseBranchOpCode  = */ TR::ificmpge,
        /* .booleanCompareOpCode = */ TR::icmplt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ificmpge,
        /* .name                 = */ "ificmpge",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::ificmple,
        /* .reverseBranchOpCode  = */ TR::ificmplt,
        /* .booleanCompareOpCode = */ TR::icmpge,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ificmpgt,
        /* .name                 = */ "ificmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::ificmplt,
        /* .reverseBranchOpCode  = */ TR::ificmple,
        /* .booleanCompareOpCode = */ TR::icmpgt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ificmple,
        /* .name                 = */ "ificmple",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::ificmpge,
        /* .reverseBranchOpCode  = */ TR::ificmpgt,
        /* .booleanCompareOpCode = */ TR::icmple,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifiucmpeq,
        /* .name                 = */ "ifiucmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::ifiucmpeq,
        /* .reverseBranchOpCode  = */ TR::ifiucmpne,
        /* .booleanCompareOpCode = */ TR::iucmpeq,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifiucmpne,
        /* .name                 = */ "ifiucmpne",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::ifiucmpne,
        /* .reverseBranchOpCode  = */ TR::ifiucmpeq,
        /* .booleanCompareOpCode = */ TR::iucmpne,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifiucmplt,
        /* .name                 = */ "ifiucmplt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::ifiucmpgt,
        /* .reverseBranchOpCode  = */ TR::ifiucmpge,
        /* .booleanCompareOpCode = */ TR::iucmplt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifiucmpge,
        /* .name                 = */ "ifiucmpge",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::ifiucmple,
        /* .reverseBranchOpCode  = */ TR::ifiucmplt,
        /* .booleanCompareOpCode = */ TR::iucmpge,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifiucmpgt,
        /* .name                 = */ "ifiucmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::ifiucmplt,
        /* .reverseBranchOpCode  = */ TR::ifiucmple,
        /* .booleanCompareOpCode = */ TR::iucmpgt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifiucmple,
        /* .name                 = */ "ifiucmple",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::ifiucmpge,
        /* .reverseBranchOpCode  = */ TR::ifiucmpgt,
        /* .booleanCompareOpCode = */ TR::iucmple,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iflcmpeq,
        /* .name                 = */ "iflcmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::iflcmpeq,
        /* .reverseBranchOpCode  = */ TR::iflcmpne,
        /* .booleanCompareOpCode = */ TR::lcmpeq,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iflcmpne,
        /* .name                 = */ "iflcmpne",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::iflcmpne,
        /* .reverseBranchOpCode  = */ TR::iflcmpeq,
        /* .booleanCompareOpCode = */ TR::lcmpne,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iflcmplt,
        /* .name                 = */ "iflcmplt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::iflcmpgt,
        /* .reverseBranchOpCode  = */ TR::iflcmpge,
        /* .booleanCompareOpCode = */ TR::lcmplt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iflcmpge,
        /* .name                 = */ "iflcmpge",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::iflcmple,
        /* .reverseBranchOpCode  = */ TR::iflcmplt,
        /* .booleanCompareOpCode = */ TR::lcmpge,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iflcmpgt,
        /* .name                 = */ "iflcmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::iflcmplt,
        /* .reverseBranchOpCode  = */ TR::iflcmple,
        /* .booleanCompareOpCode = */ TR::lcmpgt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iflcmple,
        /* .name                 = */ "iflcmple",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::iflcmpge,
        /* .reverseBranchOpCode  = */ TR::iflcmpgt,
        /* .booleanCompareOpCode = */ TR::lcmple,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iflucmpeq,
        /* .name                 = */ "iflucmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::iflucmpeq,
        /* .reverseBranchOpCode  = */ TR::iflucmpne,
        /* .booleanCompareOpCode = */ TR::lucmpeq,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iflucmpne,
        /* .name                 = */ "iflucmpne",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::iflucmpne,
        /* .reverseBranchOpCode  = */ TR::iflucmpeq,
        /* .booleanCompareOpCode = */ TR::lucmpne,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iflucmplt,
        /* .name                 = */ "iflucmplt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::iflucmpgt,
        /* .reverseBranchOpCode  = */ TR::iflucmpge,
        /* .booleanCompareOpCode = */ TR::lucmplt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iflucmpge,
        /* .name                 = */ "iflucmpge",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::iflucmple,
        /* .reverseBranchOpCode  = */ TR::iflucmplt,
        /* .booleanCompareOpCode = */ TR::lucmpge,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iflucmpgt,
        /* .name                 = */ "iflucmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::iflucmplt,
        /* .reverseBranchOpCode  = */ TR::iflucmple,
        /* .booleanCompareOpCode = */ TR::lucmpgt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iflucmple,
        /* .name                 = */ "iflucmple",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::iflucmpge,
        /* .reverseBranchOpCode  = */ TR::iflucmpgt,
        /* .booleanCompareOpCode = */ TR::lucmple,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iffcmpeq,
        /* .name                 = */ "iffcmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::iffcmpeq,
        /* .reverseBranchOpCode  = */ TR::iffcmpneu,
        /* .booleanCompareOpCode = */ TR::fcmpeq,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iffcmpne,
        /* .name                 = */ "iffcmpne",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::iffcmpne,
        /* .reverseBranchOpCode  = */ TR::iffcmpequ,
        /* .booleanCompareOpCode = */ TR::fcmpne,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iffcmplt,
        /* .name                 = */ "iffcmplt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::iffcmpgt,
        /* .reverseBranchOpCode  = */ TR::iffcmpgeu,
        /* .booleanCompareOpCode = */ TR::fcmplt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iffcmpge,
        /* .name                 = */ "iffcmpge",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::iffcmple,
        /* .reverseBranchOpCode  = */ TR::iffcmpltu,
        /* .booleanCompareOpCode = */ TR::fcmpge,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iffcmpgt,
        /* .name                 = */ "iffcmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::iffcmplt,
        /* .reverseBranchOpCode  = */ TR::iffcmpleu,
        /* .booleanCompareOpCode = */ TR::fcmpgt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iffcmple,
        /* .name                 = */ "iffcmple",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::iffcmpge,
        /* .reverseBranchOpCode  = */ TR::iffcmpgtu,
        /* .booleanCompareOpCode = */ TR::fcmple,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iffcmpequ,
        /* .name                 = */ "iffcmpequ",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual |
            ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::iffcmpequ,
        /* .reverseBranchOpCode  = */ TR::iffcmpne,
        /* .booleanCompareOpCode = */ TR::fcmpequ,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iffcmpneu,
        /* .name                 = */ "iffcmpneu",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater | ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::iffcmpneu,
        /* .reverseBranchOpCode  = */ TR::iffcmpeq,
        /* .booleanCompareOpCode = */ TR::fcmpneu,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iffcmpltu,
        /* .name                 = */ "iffcmpltu",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::iffcmpgtu,
        /* .reverseBranchOpCode  = */ TR::iffcmpge,
        /* .booleanCompareOpCode = */ TR::fcmpltu,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iffcmpgeu,
        /* .name                 = */ "iffcmpgeu",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual | ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::iffcmpleu,
        /* .reverseBranchOpCode  = */ TR::iffcmplt,
        /* .booleanCompareOpCode = */ TR::fcmpgeu,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iffcmpgtu,
        /* .name                 = */ "iffcmpgtu",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::iffcmpltu,
        /* .reverseBranchOpCode  = */ TR::iffcmple,
        /* .booleanCompareOpCode = */ TR::fcmpgtu,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iffcmpleu,
        /* .name                 = */ "iffcmpleu",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual | ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::iffcmpgeu,
        /* .reverseBranchOpCode  = */ TR::iffcmpgt,
        /* .booleanCompareOpCode = */ TR::fcmpleu,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifdcmpeq,
        /* .name                 = */ "ifdcmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::ifdcmpeq,
        /* .reverseBranchOpCode  = */ TR::ifdcmpneu,
        /* .booleanCompareOpCode = */ TR::dcmpeq,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifdcmpne,
        /* .name                 = */ "ifdcmpne",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::ifdcmpne,
        /* .reverseBranchOpCode  = */ TR::ifdcmpequ,
        /* .booleanCompareOpCode = */ TR::dcmpne,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifdcmplt,
        /* .name                 = */ "ifdcmplt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::ifdcmpgt,
        /* .reverseBranchOpCode  = */ TR::ifdcmpgeu,
        /* .booleanCompareOpCode = */ TR::dcmplt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifdcmpge,
        /* .name                 = */ "ifdcmpge",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::ifdcmple,
        /* .reverseBranchOpCode  = */ TR::ifdcmpltu,
        /* .booleanCompareOpCode = */ TR::dcmpge,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifdcmpgt,
        /* .name                 = */ "ifdcmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::ifdcmplt,
        /* .reverseBranchOpCode  = */ TR::ifdcmpleu,
        /* .booleanCompareOpCode = */ TR::dcmpgt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifdcmple,
        /* .name                 = */ "ifdcmple",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::ifdcmpge,
        /* .reverseBranchOpCode  = */ TR::ifdcmpgtu,
        /* .booleanCompareOpCode = */ TR::dcmple,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifdcmpequ,
        /* .name                 = */ "ifdcmpequ",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual |
            ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::ifdcmpequ,
        /* .reverseBranchOpCode  = */ TR::ifdcmpne,
        /* .booleanCompareOpCode = */ TR::dcmpequ,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifdcmpneu,
        /* .name                 = */ "ifdcmpneu",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater | ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::ifdcmpneu,
        /* .reverseBranchOpCode  = */ TR::ifdcmpeq,
        /* .booleanCompareOpCode = */ TR::dcmpneu,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifdcmpltu,
        /* .name                 = */ "ifdcmpltu",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::ifdcmpgtu,
        /* .reverseBranchOpCode  = */ TR::ifdcmpge,
        /* .booleanCompareOpCode = */ TR::dcmpltu,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifdcmpgeu,
        /* .name                 = */ "ifdcmpgeu",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual | ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::ifdcmpleu,
        /* .reverseBranchOpCode  = */ TR::ifdcmplt,
        /* .booleanCompareOpCode = */ TR::dcmpgeu,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifdcmpgtu,
        /* .name                 = */ "ifdcmpgtu",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::ifdcmpltu,
        /* .reverseBranchOpCode  = */ TR::ifdcmple,
        /* .booleanCompareOpCode = */ TR::dcmpgtu,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifdcmpleu,
        /* .name                 = */ "ifdcmpleu",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual | ILProp3::CompareTrueIfUnordered,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::ifdcmpgeu,
        /* .reverseBranchOpCode  = */ TR::ifdcmpgt,
        /* .booleanCompareOpCode = */ TR::dcmpleu,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifacmpeq,
        /* .name                 = */ "ifacmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::ifacmpeq,
        /* .reverseBranchOpCode  = */ TR::ifacmpne,
        /* .booleanCompareOpCode = */ TR::acmpeq,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifacmpne,
        /* .name                 = */ "ifacmpne",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::ifacmpne,
        /* .reverseBranchOpCode  = */ TR::ifacmpeq,
        /* .booleanCompareOpCode = */ TR::acmpne,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifacmplt,
        /* .name                 = */ "ifacmplt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::ifacmpgt,
        /* .reverseBranchOpCode  = */ TR::ifacmpge,
        /* .booleanCompareOpCode = */ TR::acmplt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifacmpge,
        /* .name                 = */ "ifacmpge",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::ifacmple,
        /* .reverseBranchOpCode  = */ TR::ifacmplt,
        /* .booleanCompareOpCode = */ TR::acmpge,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifacmpgt,
        /* .name                 = */ "ifacmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::ifacmplt,
        /* .reverseBranchOpCode  = */ TR::ifacmple,
        /* .booleanCompareOpCode = */ TR::acmpgt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifacmple,
        /* .name                 = */ "ifacmple",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::ifacmpge,
        /* .reverseBranchOpCode  = */ TR::ifacmpgt,
        /* .booleanCompareOpCode = */ TR::acmple,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifbcmpeq,
        /* .name                 = */ "ifbcmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::ifbcmpeq,
        /* .reverseBranchOpCode  = */ TR::ifbcmpne,
        /* .booleanCompareOpCode = */ TR::bcmpeq,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifbcmpne,
        /* .name                 = */ "ifbcmpne",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::ifbcmpne,
        /* .reverseBranchOpCode  = */ TR::ifbcmpeq,
        /* .booleanCompareOpCode = */ TR::bcmpne,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifbcmplt,
        /* .name                 = */ "ifbcmplt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::ifbcmpgt,
        /* .reverseBranchOpCode  = */ TR::ifbcmpge,
        /* .booleanCompareOpCode = */ TR::bcmplt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifbcmpge,
        /* .name                 = */ "ifbcmpge",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::ifbcmple,
        /* .reverseBranchOpCode  = */ TR::ifbcmplt,
        /* .booleanCompareOpCode = */ TR::bcmpge,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifbcmpgt,
        /* .name                 = */ "ifbcmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::ifbcmplt,
        /* .reverseBranchOpCode  = */ TR::ifbcmple,
        /* .booleanCompareOpCode = */ TR::bcmpgt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifbcmple,
        /* .name                 = */ "ifbcmple",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::ifbcmpge,
        /* .reverseBranchOpCode  = */ TR::ifbcmpgt,
        /* .booleanCompareOpCode = */ TR::bcmple,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifbucmpeq,
        /* .name                 = */ "ifbucmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::ifbucmpeq,
        /* .reverseBranchOpCode  = */ TR::ifbucmpne,
        /* .booleanCompareOpCode = */ TR::bucmpeq,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifbucmpne,
        /* .name                 = */ "ifbucmpne",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::ifbucmpne,
        /* .reverseBranchOpCode  = */ TR::ifbucmpeq,
        /* .booleanCompareOpCode = */ TR::bucmpne,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifbucmplt,
        /* .name                 = */ "ifbucmplt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::ifbucmpgt,
        /* .reverseBranchOpCode  = */ TR::ifbucmpge,
        /* .booleanCompareOpCode = */ TR::bucmplt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifbucmpge,
        /* .name                 = */ "ifbucmpge",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::ifbucmple,
        /* .reverseBranchOpCode  = */ TR::ifbucmplt,
        /* .booleanCompareOpCode = */ TR::bucmpge,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifbucmpgt,
        /* .name                 = */ "ifbucmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::ifbucmplt,
        /* .reverseBranchOpCode  = */ TR::ifbucmple,
        /* .booleanCompareOpCode = */ TR::bucmpgt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifbucmple,
        /* .name                 = */ "ifbucmple",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::ifbucmpge,
        /* .reverseBranchOpCode  = */ TR::ifbucmpgt,
        /* .booleanCompareOpCode = */ TR::bucmple,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifscmpeq,
        /* .name                 = */ "ifscmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::ifscmpeq,
        /* .reverseBranchOpCode  = */ TR::ifscmpne,
        /* .booleanCompareOpCode = */ TR::scmpeq,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifscmpne,
        /* .name                 = */ "ifscmpne",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::ifscmpne,
        /* .reverseBranchOpCode  = */ TR::ifscmpeq,
        /* .booleanCompareOpCode = */ TR::scmpne,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifscmplt,
        /* .name                 = */ "ifscmplt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::ifscmpgt,
        /* .reverseBranchOpCode  = */ TR::ifscmpge,
        /* .booleanCompareOpCode = */ TR::scmplt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifscmpge,
        /* .name                 = */ "ifscmpge",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::ifscmple,
        /* .reverseBranchOpCode  = */ TR::ifscmplt,
        /* .booleanCompareOpCode = */ TR::scmpge,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifscmpgt,
        /* .name                 = */ "ifscmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::ifscmplt,
        /* .reverseBranchOpCode  = */ TR::ifscmple,
        /* .booleanCompareOpCode = */ TR::scmpgt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifscmple,
        /* .name                 = */ "ifscmple",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::ifscmpge,
        /* .reverseBranchOpCode  = */ TR::ifscmpgt,
        /* .booleanCompareOpCode = */ TR::scmple,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifsucmpeq,
        /* .name                 = */ "ifsucmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::ifsucmpeq,
        /* .reverseBranchOpCode  = */ TR::ifsucmpne,
        /* .booleanCompareOpCode = */ TR::sucmpeq,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifsucmpne,
        /* .name                 = */ "ifsucmpne",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::ifsucmpne,
        /* .reverseBranchOpCode  = */ TR::ifsucmpeq,
        /* .booleanCompareOpCode = */ TR::sucmpne,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifsucmplt,
        /* .name                 = */ "ifsucmplt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::ifsucmpgt,
        /* .reverseBranchOpCode  = */ TR::ifsucmpge,
        /* .booleanCompareOpCode = */ TR::sucmplt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifsucmpge,
        /* .name                 = */ "ifsucmpge",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::ifsucmple,
        /* .reverseBranchOpCode  = */ TR::ifsucmplt,
        /* .booleanCompareOpCode = */ TR::sucmpge,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifsucmpgt,
        /* .name                 = */ "ifsucmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::ifsucmplt,
        /* .reverseBranchOpCode  = */ TR::ifsucmple,
        /* .booleanCompareOpCode = */ TR::sucmpgt,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ifsucmple,
        /* .name                 = */ "ifsucmple",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::ifsucmpge,
        /* .reverseBranchOpCode  = */ TR::ifsucmpgt,
        /* .booleanCompareOpCode = */ TR::sucmple,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::loadaddr,
        /* .name                 = */ "loadaddr",
        /* .properties1          = */ ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack |
            ILProp2::LoadAddress,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ZEROCHK,
        /* .name                 = */ "ZEROCHK",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::Check | ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::callIf,
        /* .name                 = */ "callIf",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */
            CHILD_COUNT(ILChildProp::UnspecifiedChildCount) |
            FIRST_CHILD(TR::Int32) |
            SECOND_CHILD(ILChildProp::UnspecifiedChildType) |
            THIRD_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iRegLoad,
        /* .name                 = */ "iRegLoad",
        /* .properties1          = */ ILProp1::LoadReg,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::aRegLoad,
        /* .name                 = */ "aRegLoad",
        /* .properties1          = */ ILProp1::LoadReg,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lRegLoad,
        /* .name                 = */ "lRegLoad",
        /* .properties1          = */ ILProp1::LoadReg,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fRegLoad,
        /* .name                 = */ "fRegLoad",
        /* .properties1          = */ ILProp1::LoadReg,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dRegLoad,
        /* .name                 = */ "dRegLoad",
        /* .properties1          = */ ILProp1::LoadReg,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sRegLoad,
        /* .name                 = */ "sRegLoad",
        /* .properties1          = */ ILProp1::LoadReg,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bRegLoad,
        /* .name                 = */ "bRegLoad",
        /* .properties1          = */ ILProp1::LoadReg,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iRegStore,
        /* .name                 = */ "iRegStore",
        /* .properties1          = */ ILProp1::StoreReg | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::aRegStore,
        /* .name                 = */ "aRegStore",
        /* .properties1          = */ ILProp1::StoreReg | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lRegStore,
        /* .name                 = */ "lRegStore",
        /* .properties1          = */ ILProp1::StoreReg | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fRegStore,
        /* .name                 = */ "fRegStore",
        /* .properties1          = */ ILProp1::StoreReg | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dRegStore,
        /* .name                 = */ "dRegStore",
        /* .properties1          = */ ILProp1::StoreReg | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sRegStore,
        /* .name                 = */ "sRegStore",
        /* .properties1          = */ ILProp1::StoreReg | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bRegStore,
        /* .name                 = */ "bRegStore",
        /* .properties1          = */ ILProp1::StoreReg | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::GlRegDeps,
        /* .name                 = */ "GlRegDeps",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iternary,
        /* .name                 = */ "iternary",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Ternary,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */
        THREE_CHILD(TR::Int32, TR::Int32, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lternary,
        /* .name                 = */ "lternary",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Ternary,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */
        THREE_CHILD(TR::Int32, TR::Int64, TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bternary,
        /* .name                 = */ "bternary",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Ternary,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */
        THREE_CHILD(TR::Int32, TR::Int8, TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sternary,
        /* .name                 = */ "sternary",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Ternary,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */
        THREE_CHILD(TR::Int32, TR::Int16, TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::aternary,
        /* .name                 = */ "aternary",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Ternary,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */
        THREE_CHILD(TR::Int32, TR::Address, TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fternary,
        /* .name                 = */ "fternary",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Ternary,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */
        THREE_CHILD(TR::Int32, TR::Float, TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dternary,
        /* .name                 = */ "dternary",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Ternary,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */
        THREE_CHILD(TR::Int32, TR::Int8, TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::treetop,
        /* .name                 = */ "treetop",
        /* .properties1          = */ ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::MethodEnterHook,
        /* .name                 = */ "MethodEnterHook",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::MustBeLowered |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::MethodExitHook,
        /* .name                 = */ "MethodExitHook",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::MustBeLowered |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::PassThrough,
        /* .name                 = */ "PassThrough",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    /*!
     * \brief anchor load or store of a compressed reference
     *
     * This provides the tree evaluator with additional subexpressions needed
     * during the compression/decompression of a reference.  Presently, there is
     * only one such subexpression: the heap base offset.
     *
     * If the general decompression formula is this:
     *    decompressed = compressed << A + B
     * ...then the compressedRefs anchor takes this form:
     *
     *  compressedRefs
     *   - (load/store tree)
     *   - lconst B
     *
     * compressedRefs itself does nothing, and is not required for correct
     * operation in a compressed references environment.  Without it, the tree
     * evaluator may be forced to materialize the heap base offset in a less
     * efficient way.
     *
     */
    {
        /* .opcode               = */ TR::compressedRefs,
        /* .name                 = */ "compressedRefs",
        /* .properties1          = */ ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */
        TWO_CHILD(ILChildProp::UnspecifiedChildType, TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::BBStart,
        /* .name                 = */ "BBStart",
        /* .properties1          = */ ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::BBEnd,
        /* .name                 = */ "BBEnd",
        /* .properties1          = */ ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::virem,
        /* .name                 = */ "virem",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt32,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vimin,
        /* .name                 = */ "vimin",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt32,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vimax,
        /* .name                 = */ "vimax",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt32,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vigetelem,
        /* .name                 = */ "vigetelem",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::visetelem,
        /* .name                 = */ "visetelem",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt32,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vimergel,
        /* .name                 = */ "vimergel",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt32,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vimergeh,
        /* .name                 = */ "vimergeh",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt32,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmpeq,
        /* .name                 = */ "vicmpeq",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt32,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmpgt,
        /* .name                 = */ "vicmpgt",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt32,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmpge,
        /* .name                 = */ "vicmpge",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt32,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmplt,
        /* .name                 = */ "vicmplt",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt32,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmple,
        /* .name                 = */ "vicmple",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt32,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmpalleq,
        /* .name                 = */ "vicmpalleq",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmpallne,
        /* .name                 = */ "vicmpallne",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmpallgt,
        /* .name                 = */ "vicmpallgt",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmpallge,
        /* .name                 = */ "vicmpallge",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmpalllt,
        /* .name                 = */ "vicmpalllt",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmpallle,
        /* .name                 = */ "vicmpallle",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmpanyeq,
        /* .name                 = */ "vicmpanyeq",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmpanyne,
        /* .name                 = */ "vicmpanyne",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmpanygt,
        /* .name                 = */ "vicmpanygt",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmpanyge,
        /* .name                 = */ "vicmpanyge",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmpanylt,
        /* .name                 = */ "vicmpanylt",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vicmpanyle,
        /* .name                 = */ "vicmpanyle",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vnot,
        /* .name                 = */ "vnot",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt32,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vselect,
        /* .name                 = */ "vselect",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt32, /* todo: is it typeless?
                                                        */
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vperm,
        /* .name                 = */ "vperm",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt32, /* todo: is it typeless?
                                                        */
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vsplats,
        /* .name                 = */ "vsplats",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdmergel,
        /* .name                 = */ "vdmergel",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorDouble,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdmergeh,
        /* .name                 = */ "vdmergeh",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorDouble,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdsetelem,
        /* .name                 = */ "vdsetelem",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorDouble,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdgetelem,
        /* .name                 = */ "vdgetelem",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdsel,
        /* .name                 = */ "vdsel",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorDouble,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdrem,
        /* .name                 = */ "vdrem",
        /* .properties1          = */ ILProp1::Rem,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorDouble,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdmadd,
        /* .name                 = */ "vdmadd",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorDouble,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdnmsub,
        /* .name                 = */ "vdnmsub",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorDouble,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdmsub,
        /* .name                 = */ "vdmsub",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorDouble,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdmax,
        /* .name                 = */ "vdmax",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Max,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorDouble,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdmin,
        /* .name                 = */ "vdmin",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Min,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorDouble,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmpeq,
        /* .name                 = */ "vdcmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt64,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmpeq,
        /* .reverseBranchOpCode  = */ TR::vdcmpne,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmpne,
        /* .name                 = */ "vdcmpne",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt64,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmpne,
        /* .reverseBranchOpCode  = */ TR::vdcmpeq,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmpgt,
        /* .name                 = */ "vdcmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt64,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmplt,
        /* .reverseBranchOpCode  = */ TR::vdcmple,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmpge,
        /* .name                 = */ "vdcmpge",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt64,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmple,
        /* .reverseBranchOpCode  = */ TR::vdcmplt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmplt,
        /* .name                 = */ "vdcmplt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt64,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmpgt,
        /* .reverseBranchOpCode  = */ TR::vdcmpge,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmple,
        /* .name                 = */ "vdcmple",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt64,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmpge,
        /* .reverseBranchOpCode  = */ TR::vdcmpgt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmpalleq,
        /* .name                 = */ "vdcmpalleq",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmpalleq,
        /* .reverseBranchOpCode  = */ TR::vdcmpallne,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmpallne,
        /* .name                 = */ "vdcmpallne",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmpallne,
        /* .reverseBranchOpCode  = */ TR::vdcmpalleq,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmpallgt,
        /* .name                 = */ "vdcmpallgt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmpalllt,
        /* .reverseBranchOpCode  = */ TR::vdcmpallle,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmpallge,
        /* .name                 = */ "vdcmpallge",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmpallle,
        /* .reverseBranchOpCode  = */ TR::vdcmpalllt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmpalllt,
        /* .name                 = */ "vdcmpalllt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmpallgt,
        /* .reverseBranchOpCode  = */ TR::vdcmpallge,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmpallle,
        /* .name                 = */ "vdcmpallle",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmpallge,
        /* .reverseBranchOpCode  = */ TR::vdcmpallgt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmpanyeq,
        /* .name                 = */ "vdcmpanyeq",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmpanyeq,
        /* .reverseBranchOpCode  = */ TR::vdcmpanyne,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmpanyne,
        /* .name                 = */ "vdcmpanyne",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmpanyne,
        /* .reverseBranchOpCode  = */ TR::vdcmpanyeq,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmpanygt,
        /* .name                 = */ "vdcmpanygt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmpanylt,
        /* .reverseBranchOpCode  = */ TR::vdcmpanyle,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmpanyge,
        /* .name                 = */ "vdcmpanyge",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmpanyle,
        /* .reverseBranchOpCode  = */ TR::vdcmpanylt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmpanylt,
        /* .name                 = */ "vdcmpanylt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmpanygt,
        /* .reverseBranchOpCode  = */ TR::vdcmpanyge,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdcmpanyle,
        /* .name                 = */ "vdcmpanyle",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vdcmpanyge,
        /* .reverseBranchOpCode  = */ TR::vdcmpanygt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdsqrt,
        /* .name                 = */ "vdsqrt",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorDouble,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdlog,
        /* .name                 = */ "vdlog",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorDouble,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Floating_Point | ILTypeProp::Vector,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vinc,
        /* .name                 = */ "vinc",
        /* .properties1          = */ ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdec,
        /* .name                 = */ "vdec",
        /* .properties1          = */ ILProp1::Sub,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vneg,
        /* .name                 = */ "vneg",
        /* .properties1          = */ ILProp1::Neg,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vcom,
        /* .name                 = */ "vcom",
        /* .properties1          = */ ILProp1::Neg,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vadd,
        /* .name                 = */ "vadd",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vsub,
        /* .name                 = */ "vsub",
        /* .properties1          = */ ILProp1::Sub,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vmul,
        /* .name                 = */ "vmul",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Mul,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdiv,
        /* .name                 = */ "vdiv",
        /* .properties1          = */ ILProp1::Div,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vrem,
        /* .name                 = */ "vrem",
        /* .properties1          = */ ILProp1::Rem,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vand,
        /* .name                 = */ "vand",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::And,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vor,
        /* .name                 = */ "vor",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Or,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vxor,
        /* .name                 = */ "vxor",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Xor,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vshl,
        /* .name                 = */ "vshl",
        /* .properties1          = */ ILProp1::LeftShift,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vushr,
        /* .name                 = */ "vushr",
        /* .properties1          = */ ILProp1::RightShift,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vshr,
        /* .name                 = */ "vshr",
        /* .properties1          = */ ILProp1::RightShift,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vcmpeq,
        /* .name                 = */ "vcmpeq",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .swapChildrenOpCode   = */ TR::vcmpeq,
        /* .reverseBranchOpCode  = */ TR::vcmpne,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::ificmpeq,
    },

    {
        /* .opcode               = */ TR::vcmpne,
        /* .name                 = */ "vcmpne",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vcmpne,
        /* .reverseBranchOpCode  = */ TR::vcmpeq,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vcmplt,
        /* .name                 = */ "vcmplt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vcmpgt,
        /* .reverseBranchOpCode  = */ TR::vcmpge,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vucmplt,
        /* .name                 = */ "vucmplt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::Unsigned | ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vcmpgt,
        /* .reverseBranchOpCode  = */ TR::vcmpge,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vcmpgt,
        /* .name                 = */ "vcmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vcmplt,
        /* .reverseBranchOpCode  = */ TR::vcmple,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vucmpgt,
        /* .name                 = */ "vucmpgt",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::Unsigned | ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vcmplt,
        /* .reverseBranchOpCode  = */ TR::vcmple,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vcmple,
        /* .name                 = */ "vcmple",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vcmpge,
        /* .reverseBranchOpCode  = */ TR::vcmpgt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vucmple,
        /* .name                 = */ "vucmple",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfLess |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::Unsigned | ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vcmpge,
        /* .reverseBranchOpCode  = */ TR::vcmpgt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vcmpge,
        /* .name                 = */ "vcmpge",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vcmple,
        /* .reverseBranchOpCode  = */ TR::vcmplt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vucmpge,
        /* .name                 = */ "vucmpge",
        /* .properties1          = */ ILProp1::BooleanCompare,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare,
        /* .properties3          = */ ILProp3::CompareTrueIfGreater |
            ILProp3::CompareTrueIfEqual,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::Unsigned | ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::vcmple,
        /* .reverseBranchOpCode  = */ TR::vcmplt,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vload,
        /* .name                 = */ "vload",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vloadi,
        /* .name                 = */ "vloadi",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vstore,
        /* .name                 = */ "vstore",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vstorei,
        /* .name                 = */ "vstorei",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vrand,
        /* .name                 = */ "vrand",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::VectorReduction,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vreturn,
        /* .name                 = */ "vreturn",
        /* .properties1          = */ ILProp1::Return | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vcall,
        /* .name                 = */ "vcall",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vcalli,
        /* .name                 = */ "vcalli",
        /* .properties1          = */ ILProp1::Indirect | ILProp1::Call |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vternary,
        /* .name                 = */ "vternary",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Ternary,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        THREE_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::v2v,
        /* .name                 = */ "v2v",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vl2vd,
        /* .name                 = */ "vl2vd",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorDouble,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vconst,
        /* .name                 = */ "vconst",
        /* .properties1          = */ ILProp1::LoadConst,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::getvelem,
        /* .name                 = */ "getvelem",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vsetelem,
        /* .name                 = */ "vsetelem",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_16 | ILTypeProp::Vector |
            ILTypeProp::HasNoDataType,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vbRegLoad,
        /* .name                 = */ "vbRegLoad",
        /* .properties1          = */ ILProp1::LoadReg,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt8,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vsRegLoad,
        /* .name                 = */ "vsRegLoad",
        /* .properties1          = */ ILProp1::LoadReg,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt16,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::viRegLoad,
        /* .name                 = */ "viRegLoad",
        /* .properties1          = */ ILProp1::LoadReg,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt32,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vlRegLoad,
        /* .name                 = */ "vlRegLoad",
        /* .properties1          = */ ILProp1::LoadReg,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt64,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vfRegLoad,
        /* .name                 = */ "vfRegLoad",
        /* .properties1          = */ ILProp1::LoadReg,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorFloat,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdRegLoad,
        /* .name                 = */ "vdRegLoad",
        /* .properties1          = */ ILProp1::LoadReg,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorDouble,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vbRegStore,
        /* .name                 = */ "vbRegStore",
        /* .properties1          = */ ILProp1::StoreReg | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt8,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vsRegStore,
        /* .name                 = */ "vsRegStore",
        /* .properties1          = */ ILProp1::StoreReg | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt16,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::viRegStore,
        /* .name                 = */ "viRegStore",
        /* .properties1          = */ ILProp1::StoreReg | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt32,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vlRegStore,
        /* .name                 = */ "vlRegStore",
        /* .properties1          = */ ILProp1::StoreReg | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorInt64,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vfRegStore,
        /* .name                 = */ "vfRegStore",
        /* .properties1          = */ ILProp1::StoreReg | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorFloat,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::vdRegStore,
        /* .name                 = */ "vdRegStore",
        /* .properties1          = */ ILProp1::StoreReg | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::VectorDouble,
        /* .typeProperties       = */ ILTypeProp::Size_16 |
            ILTypeProp::Integer | ILTypeProp::Vector,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iuconst,
        /* .name                 = */ "iuconst",
        /* .properties1          = */ ILProp1::LoadConst,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::luconst,
        /* .name                 = */ "luconst",
        /* .properties1          = */ ILProp1::LoadConst,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::buconst,
        /* .name                 = */ "buconst",
        /* .properties1          = */ ILProp1::LoadConst,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iuload,
        /* .name                 = */ "iuload",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::luload,
        /* .name                 = */ "luload",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::buload,
        /* .name                 = */ "buload",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iuloadi,
        /* .name                 = */ "iuloadi",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::luloadi,
        /* .name                 = */ "luloadi",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::buloadi,
        /* .name                 = */ "buloadi",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iustore,
        /* .name                 = */ "iustore",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lustore,
        /* .name                 = */ "lustore",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bustore,
        /* .name                 = */ "bustore",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iustorei,
        /* .name                 = */ "iustorei",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lustorei,
        /* .name                 = */ "lustorei",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bustorei,
        /* .name                 = */ "bustorei",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iureturn,
        /* .name                 = */ "iureturn",
        /* .properties1          = */ ILProp1::Return | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lureturn,
        /* .name                 = */ "lureturn",
        /* .properties1          = */ ILProp1::Return | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iucall,
        /* .name                 = */ "iucall",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lucall,
        /* .name                 = */ "lucall",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iuadd,
        /* .name                 = */ "iuadd",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::iuadd,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::luadd,
        /* .name                 = */ "luadd",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::luadd,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::buadd,
        /* .name                 = */ "buadd",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::buadd,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iusub,
        /* .name                 = */ "iusub",
        /* .properties1          = */ ILProp1::Sub,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lusub,
        /* .name                 = */ "lusub",
        /* .properties1          = */ ILProp1::Sub,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::busub,
        /* .name                 = */ "busub",
        /* .properties1          = */ ILProp1::Sub,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iuneg,
        /* .name                 = */ "iuneg",
        /* .properties1          = */ ILProp1::Neg,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::luneg,
        /* .name                 = */ "luneg",
        /* .properties1          = */ ILProp1::Neg,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::f2iu,
        /* .name                 = */ "f2iu",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::f2lu,
        /* .name                 = */ "f2lu",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::f2bu,
        /* .name                 = */ "f2bu",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::f2c,
        /* .name                 = */ "f2c",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::d2iu,
        /* .name                 = */ "d2iu",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::d2lu,
        /* .name                 = */ "d2lu",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::d2bu,
        /* .name                 = */ "d2bu",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::d2c,
        /* .name                 = */ "d2c",
        /* .properties1          = */ ILProp1::Conversion,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iuRegLoad,
        /* .name                 = */ "iuRegLoad",
        /* .properties1          = */ ILProp1::LoadReg,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::luRegLoad,
        /* .name                 = */ "luRegLoad",
        /* .properties1          = */ ILProp1::LoadReg,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iuRegStore,
        /* .name                 = */ "iuRegStore",
        /* .properties1          = */ ILProp1::StoreReg | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::luRegStore,
        /* .name                 = */ "luRegStore",
        /* .properties1          = */ ILProp1::StoreReg | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::cconst,
        /* .name                 = */ "cconst",
        /* .properties1          = */ ILProp1::LoadConst,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::cload,
        /* .name                 = */ "cload",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::cloadi,
        /* .name                 = */ "cloadi",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Indirect |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::cstore,
        /* .name                 = */ "cstore",
        /* .properties1          = */ ILProp1::Store | ILProp1::TreeTop |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ONE_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::cstorei,
        /* .name                 = */ "cstorei",
        /* .properties1          = */ ILProp1::Store | ILProp1::Indirect |
            ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::monent,
        /* .name                 = */ "monent",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::monexit,
        /* .name                 = */ "monexit",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::monexitfence,
        /* .name                 = */ "monexitfence",
        /* .properties1          = */ ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::tstart,
        /* .name                 = */ "tstart",
        /* .properties1          = */ ILProp1::HasSymbolRef | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::JumpWithMultipleTargets,
        /* .properties3          = */ ILProp3::HasBranchChild,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ THREE_SAME_CHILD(TR::NoType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::tfinish,
        /* .name                 = */ "tfinish",
        /* .properties1          = */ ILProp1::HasSymbolRef | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::tabort,
        /* .name                 = */ "tabort",
        /* .properties1          = */ ILProp1::HasSymbolRef | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR:: instanceof
        ,
        /* .name                 = */ "instanceof",
        /* .properties1          = */ ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::SupportedForPRE |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::checkcast,
        /* .name                 = */ "checkcast",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::Check | ILProp2::CheckCast | ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::checkcastAndNULLCHK,
        /* .name                 = */ "checkcastAndNULLCHK",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::Check | ILProp2::CheckCast | ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::New,
        /* .name                 = */ "new",
        /* .properties1          = */ ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::MayUseSystemStack | ILProp2::New,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::newvalue,
        /* .name                 = */ "newvalue",
        /* .properties1          = */ ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::MayUseSystemStack | ILProp2::New,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::newarray,
        /* .name                 = */ "newarray",
        /* .properties1          = */ ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::MayUseSystemStack | ILProp2::New,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::anewarray,
        /* .name                 = */ "anewarray",
        /* .properties1          = */ ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::MayUseSystemStack | ILProp2::New,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::variableNew,
        /* .name                 = */ "variableNew",
        /* .properties1          = */ ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::variableNewArray,
        /* .name                 = */ "variableNewArray",
        /* .properties1          = */ ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::multianewarray,
        /* .name                 = */ "multianewarray",
        /* .properties1          = */ ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::MustBeLowered |
            ILProp2::CanRaiseException | ILProp2::MayUseSystemStack |
            ILProp2::New,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::arraylength,
        /* .name                 = */ "arraylength",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::MustBeLowered |
            ILProp2::ValueNumberShare | ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::ArrayLength,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::contigarraylength,
        /* .name                 = */ "contigarraylength",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::MustBeLowered |
            ILProp2::ValueNumberShare | ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::ArrayLength,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::discontigarraylength,
        /* .name                 = */ "discontigarraylength",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::MustBeLowered |
            ILProp2::ValueNumberShare | ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::ArrayLength,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::icalli,
        /* .name                 = */ "icalli",
        /* .properties1          = */ ILProp1::Indirect | ILProp1::Call |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::IndirectCallType,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iucalli,
        /* .name                 = */ "iucalli",
        /* .properties1          = */ ILProp1::Indirect | ILProp1::Call |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::IndirectCallType,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lcalli,
        /* .name                 = */ "lcalli",
        /* .properties1          = */ ILProp1::Indirect | ILProp1::Call |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::IndirectCallType,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lucalli,
        /* .name                 = */ "lucalli",
        /* .properties1          = */ ILProp1::Indirect | ILProp1::Call |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::IndirectCallType,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fcalli,
        /* .name                 = */ "fcalli",
        /* .properties1          = */ ILProp1::Indirect | ILProp1::Call |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ILChildProp::IndirectCallType,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dcalli,
        /* .name                 = */ "dcalli",
        /* .properties1          = */ ILProp1::Indirect | ILProp1::Call |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ILChildProp::IndirectCallType,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::acalli,
        /* .name                 = */ "acalli",
        /* .properties1          = */ ILProp1::Indirect | ILProp1::Call |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ILChildProp::IndirectCallType,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::calli,
        /* .name                 = */ "calli",
        /* .properties1          = */ ILProp1::Indirect | ILProp1::Call |
            ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::SupportedForPRE | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::IndirectCallType,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fence,
        /* .name                 = */ "fence",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::Fence | ILProp3::LikeUse |
            ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::luaddh,
        /* .name                 = */ "luaddh",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::luaddh,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::cadd,
        /* .name                 = */ "cadd",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::cadd,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::aiadd,
        /* .name                 = */ "aiadd",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::aiuadd,
        /* .name                 = */ "aiuadd",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::aladd,
        /* .name                 = */ "aladd",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::aluadd,
        /* .name                 = */ "aluadd",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Add,
        /* .properties2          = */ ILProp2::ValueNumberShare,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lusubh,
        /* .name                 = */ "lusubh",
        /* .properties1          = */ ILProp1::Sub,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::csub,
        /* .name                 = */ "csub",
        /* .properties1          = */ ILProp1::Sub,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::imulh,
        /* .name                 = */ "imulh",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Mul,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::imulh,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iumulh,
        /* .name                 = */ "iumulh",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Mul,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::iumulh,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lmulh,
        /* .name                 = */ "lmulh",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Mul,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lmulh,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lumulh,
        /* .name                 = */ "lumulh",
        /* .properties1          = */ ILProp1::Commutative |
            ILProp1::Associative | ILProp1::Mul,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::lumulh,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ibits2f,
        /* .name                 = */ "ibits2f",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fbits2i,
        /* .name                 = */ "fbits2i",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lbits2d,
        /* .name                 = */ "lbits2d",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dbits2l,
        /* .name                 = */ "dbits2l",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lookup,
        /* .name                 = */ "lookup",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::Switch,
        /* .properties2          = */ ILProp2::JumpWithMultipleTargets,
        /* .properties3          = */ ILProp3::HasBranchChild,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::trtLookup,
        /* .name                 = */ "trtLookup",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::Switch,
        /* .properties2          = */ ILProp2::JumpWithMultipleTargets,
        /* .properties3          = */ ILProp3::HasBranchChild,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::Case,
        /* .name                 = */ "case",
        /* .properties1          = */ ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::table,
        /* .name                 = */ "table",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::Switch,
        /* .properties2          = */ ILProp2::JumpWithMultipleTargets,
        /* .properties3          = */ ILProp3::HasBranchChild,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::exceptionRangeFence,
        /* .name                 = */ "exceptionRangeFence",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::ExceptionRangeFence,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dbgFence,
        /* .name                 = */ "dbgFence",
        /* .properties1          = */ ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::ExceptionRangeFence,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::NULLCHK,
        /* .name                 = */ "NULLCHK",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::CanRaiseException | ILProp2::Check | ILProp2::NullCheck |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ResolveCHK,
        /* .name                 = */ "ResolveCHK",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::CanRaiseException | ILProp2::Check |
            ILProp2::ResolveCheck | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ResolveAndNULLCHK,
        /* .name                 = */ "ResolveAndNULLCHK",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::CanRaiseException | ILProp2::Check | ILProp2::NullCheck |
            ILProp2::ResolveCheck | ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::DIVCHK,
        /* .name                 = */ "DIVCHK",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::Check | ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::OverflowCHK,
        /* .name                 = */ "OverflowCHK",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::Check |
            ILProp2::MayUseSystemStack | ILProp2::CanRaiseException,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */
        THREE_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::UnsignedOverflowCHK,
        /* .name                 = */ "UnsignedOverflowCHK",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::Check |
            ILProp2::MayUseSystemStack | ILProp2::CanRaiseException,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */
        THREE_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::BNDCHK,
        /* .name                 = */ "BNDCHK",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::CanRaiseException | ILProp2::Check | ILProp2::BndCheck |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ArrayCopyBNDCHK,
        /* .name                 = */ "ArrayCopyBNDCHK",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::CanRaiseException | ILProp2::Check | ILProp2::BndCheck |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */
        TWO_SAME_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::BNDCHKwithSpineCHK,
        /* .name                 = */ "BNDCHKwithSpineCHK",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::CanRaiseException | ILProp2::Check | ILProp2::BndCheck |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::SpineCheck,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::SpineCHK,
        /* .name                 = */ "SpineCHK",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::Check,
        /* .properties3          = */ ILProp3::SpineCheck,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    /*!
     * \brief ArrayStoreCHK
     *
     * Java specific opcode related to reference array storing semantics
     * around raising ArrayStoreException when the types of the arguments
     * are incompatible.
     * Java's type safety rules guarantee that an array of type C1[] can only
     * contain either null value, or non null value of type C2 where either :
     * C1 == C2 or C2 is a subclass of C1.
     * This opcode checks at each reference array store whether the rhs value
     * that is being stored has the appropriate type that is consistent
     * with the type of the array on the lhs as per Java's rules (discussed
     * above) This opcode has one child : the awrtbari node corresponding to the
     * reference store that needs to be checked. The rhs object being stored and
     * the lhs array object that is being stored to are picked up from the
     * awrtbari node's second and third children respectively. The child must
     * therefore remain an awrtbari and not be changed to an astorei even if
     * this is possible if the ArrayStoreCHK node is present.
     *
     */
    {
        /* .opcode               = */ TR::ArrayStoreCHK,
        /* .name                 = */ "ArrayStoreCHK",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::CanRaiseException | ILProp2::Check |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */
        ONE_CHILD(ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    /*!
     * \brief ArrayCHK
     *
     * Java specific opcode related to System.arraycopy semantics
     * around raising ArrayStoreException when the types of the arguments
     * to the System.arraycopy call are incompatible.
     * This opcode does the necessary checking to ensure that the exception
     * gets raised in the appropriate cases.
     * There are two children :
     * child1 loads the "src" argument to the call
     * child2 loads the "dest" argument to the call.
     * If child1/child2 are not array objects then an exception must be raised.
     * If one of the args is a primitive array and the other is a reference
     * array then an exception must be raised. Finally if the args are both
     * primitive arrays but of different types then an exception must be raised.
     * Note that this opcode does NOT check for the args being compatible
     * reference types; this is left to the array store checking done as each
     * copied element is examined individually when copying reference arrays.
     *
     */
    {
        /* .opcode               = */ TR::ArrayCHK,
        /* .name                 = */ "ArrayCHK",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::CanRaiseException | ILProp2::Check |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::Ret,
        /* .name                 = */ "Ret",
        /* .properties1          = */ ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    /*!
     * \brief copy memory or array elements
     *
     * Arraycopy can take two shapes. It can either have 3-children or
     * it can have 5 children. The 3-child version is a primitive memory
     * copy (i.e. analogous to libc memcpy).
     * arraycopy (3-child version)
     *  - src address
     *  - dest address
     *  - number of bytes to copy
     *
     * arraycopy (5-child version)
     *  - src object
     *  - dest object
     *  - src address
     *  - dest address
     *  - number of bytes to copy
     *
     * Normally the 5-child variant indicates the operation is a reference
     * array copy and hence it should be only generated when the CodeGen
     * sets SupportsReferenceArrayCopy flag.
     *
     * In the future we may extract the 3-child version into a distinct
     * opcode named memcpy.
     *
     */
    {
        /* .opcode               = */ TR::arraycopy,
        /* .name                 = */ "arraycopy",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::MayUseSystemStack |
            ILProp2::CanRaiseException | 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef |
            ILProp3::SkipDynamicLitPoolOnInts,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::arrayset,
        /* .name                 = */ "arrayset",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef |
            ILProp3::SkipDynamicLitPoolOnInts,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::arraytranslate,
        /* .name                 = */ "arraytranslate",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::arraytranslateAndTest,
        /* .name                 = */ "arraytranslateAndTest",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::BndCheck,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::long2String,
        /* .name                 = */ "long2String",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bitOpMem,
        /* .name                 = */ "bitOpMem",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CondCodeComputation,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef |
            ILProp3::SkipDynamicLitPoolOnInts,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bitOpMemND,
        /* .name                 = */ "bitOpMemND",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef |
            ILProp3::SkipDynamicLitPoolOnInts,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    /*!
     * \brief arraycmp
     *
     * part of a family of similar opcodes:  memcmp
     * also related to arraycmpWithPad, strcmp and strncmp
     *
     * arraycmp and  memcmp  each take three children:
     * array1: which has type OMR::Address
     * array2: which has type OMR::Address
     * length: which is an integer type and represents the number
     *         of bytes to be compared except for wmemcpy where it
     *         represents 1/2 the number of bytes
     * The returned value is: -1/0/+1 for memcmp and
     * 1/0/2 for arraycmp.  (-1/0/+1 means return -1 if array1 is
     * less than array2; return 0 if the arrays compare equal and
     * return 1 otherwise and 1/0/2 is interpreted similarly.)
     *
     * memcmp generally come in as BIFs.  arraycmp
     * can come in as a Java arraycmp or it can be geenrated internally
     * for general memory compare operations in Testarossa (especially
     * in IL generation and in early optimizations) using the ocmp
     * family of op-codes is preferred.
     */
    {
        /* .opcode               = */ TR::arraycmp,
        /* .name                 = */ "arraycmp",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CondCodeComputation,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef |
            ILProp3::SkipDynamicLitPoolOnInts,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */
        THREE_CHILD(TR::Address, TR::Address, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    /*!
     * \brief arraycmpWithPad
     *
     * An op-code that is similar to arraycmp (including
     * its return code) except that it takes five children:
     * address1   Address
     * length1    Integer
     * address2   Address
     * length2    Integer
     * pad        character
     *
     * min(length1, length2) bytes are actually compared.  if
     * the storage compares equal and one of length1 or length2 is
     * larger than min(length1, length2) the additional memory is
     * compared to the pad character
     *
     * This supports a BIF and in practice length2 is often 0.  Also
     * in practice, length1 and length2 are often equal
     *
     */
    {
        /* .opcode               = */ TR::arraycmpWithPad,
        /* .name                 = */ "arraycmpWithPad",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CondCodeComputation,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef |
            ILProp3::SkipDynamicLitPoolOnInts,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::allocationFence,
        /* .name                 = */ "allocationFence",
        /* .properties1          = */ ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::loadFence,
        /* .name                 = */ "loadFence",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::storeFence,
        /* .name                 = */ "storeFence",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fullFence,
        /* .name                 = */ "fullFence",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::MergeNew,
        /* .name                 = */ "MergeNew",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::CanRaiseException |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::computeCC,
        /* .name                 = */ "computeCC",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::CondCodeComputation,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::butest,
        /* .name                 = */ "butest",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::CondCodeComputation,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sutest,
        /* .name                 = */ "sutest",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::CondCodeComputation,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bucmp,
        /* .name                 = */ "bucmp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare |
            ILProp2::CondCodeComputation,
        /* .properties3          = */ ILProp3::Signum,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bcmp,
        /* .name                 = */ "bcmp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::CondCodeComputation,
        /* .properties3          = */ ILProp3::Signum,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sucmp,
        /* .name                 = */ "sucmp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare |
            ILProp2::CondCodeComputation,
        /* .properties3          = */ ILProp3::Signum,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::scmp,
        /* .name                 = */ "scmp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::CondCodeComputation,
        /* .properties3          = */ ILProp3::Signum,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iucmp,
        /* .name                 = */ "iucmp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare |
            ILProp2::CondCodeComputation,
        /* .properties3          = */ ILProp3::Signum,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::icmp,
        /* .name                 = */ "icmp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::CondCodeComputation,
        /* .properties3          = */ ILProp3::Signum,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lucmp,
        /* .name                 = */ "lucmp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::UnsignedCompare |
            ILProp2::CondCodeComputation,
        /* .properties3          = */ ILProp3::Signum,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer |
            ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ificmpo,
        /* .name                 = */ "ificmpo",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::OverflowCompare,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::ificmpno,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ificmpno,
        /* .name                 = */ "ificmpno",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::OverflowCompare,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::ificmpo,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iflcmpo,
        /* .name                 = */ "iflcmpo",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::OverflowCompare,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::iflcmpno,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iflcmpno,
        /* .name                 = */ "iflcmpno",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::OverflowCompare,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::iflcmpo,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ificmno,
        /* .name                 = */ "ificmno",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::OverflowCompare,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::ificmnno,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ificmnno,
        /* .name                 = */ "ificmnno",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::OverflowCompare,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::ificmno,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iflcmno,
        /* .name                 = */ "iflcmno",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::OverflowCompare,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::iflcmnno,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iflcmnno,
        /* .name                 = */ "iflcmnno",
        /* .properties1          = */ ILProp1::BooleanCompare |
            ILProp1::Branch | ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::OverflowCompare,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::iflcmno,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iuaddc,
        /* .name                 = */ "iuaddc",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::TernaryAdd,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::luaddc,
        /* .name                 = */ "luaddc",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::TernaryAdd,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iusubb,
        /* .name                 = */ "iusubb",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::TernarySub,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lusubb,
        /* .name                 = */ "lusubb",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::TernarySub,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::icmpset,
        /* .name                 = */ "icmpset",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */
        THREE_CHILD(TR::Address, TR::Int32, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lcmpset,
        /* .name                 = */ "lcmpset",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */
        THREE_CHILD(TR::Address, TR::Int64, TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bztestnset,
        /* .name                 = */ "bztestnset",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */
        TWO_CHILD(TR::Address, ILChildProp::UnspecifiedChildType),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ibatomicor,
        /* .name                 = */ "ibatomicor",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Store |
            ILProp1::Indirect | ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::isatomicor,
        /* .name                 = */ "isatomicor",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Store |
            ILProp1::Indirect | ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iiatomicor,
        /* .name                 = */ "iiatomicor",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Store |
            ILProp1::Indirect | ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ilatomicor,
        /* .name                 = */ "ilatomicor",
        /* .properties1          = */ ILProp1::LoadVar | ILProp1::Store |
            ILProp1::Indirect | ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::MayUseSystemStack,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_CHILD(TR::Address, TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dexp,
        /* .name                 = */ "dexp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::SignedExponentiation,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::branch,
        /* .name                 = */ "branch",
        /* .properties1          = */ ILProp1::Branch |
            ILProp1::CompBranchOnly | ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::igoto,
        /* .name                 = */ "igoto",
        /* .properties1          = */ ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::JumpWithMultipleTargets,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ONE_CHILD(TR::Address),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::bexp,
        /* .name                 = */ "bexp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::SignedExponentiation,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::buexp,
        /* .name                 = */ "buexp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::UnsignedExponentiation,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int8),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sexp,
        /* .name                 = */ "sexp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::SignedExponentiation,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::cexp,
        /* .name                 = */ "cexp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::UnsignedExponentiation,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int16),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iexp,
        /* .name                 = */ "iexp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::SignedExponentiation,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iuexp,
        /* .name                 = */ "iuexp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::UnsignedExponentiation,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lexp,
        /* .name                 = */ "lexp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::SignedExponentiation,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::luexp,
        /* .name                 = */ "luexp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::UnsignedExponentiation,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fexp,
        /* .name                 = */ "fexp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::SignedExponentiation,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fuexp,
        /* .name                 = */ "fuexp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::UnsignedExponentiation,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_CHILD(TR::Float, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::duexp,
        /* .name                 = */ "duexp",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::UnsignedExponentiation,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_CHILD(TR::Double, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ixfrs,
        /* .name                 = */ "ixfrs",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lxfrs,
        /* .name                 = */ "lxfrs",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fxfrs,
        /* .name                 = */ "fxfrs",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dxfrs,
        /* .name                 = */ "dxfrs",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fint,
        /* .name                 = */ "fint",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dint,
        /* .name                 = */ "dint",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fnint,
        /* .name                 = */ "fnint",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dnint,
        /* .name                 = */ "dnint",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fsqrt,
        /* .name                 = */ "fsqrt",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dsqrt,
        /* .name                 = */ "dsqrt",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::getstack,
        /* .name                 = */ "getstack",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Address,
        /* .typeProperties       = */ ILTypeProp::Reference,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dealloca,
        /* .name                 = */ "dealloca",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::idoz,
        /* .name                 = */ "idoz",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dcos,
        /* .name                 = */ "dcos",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dsin,
        /* .name                 = */ "dsin",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dtan,
        /* .name                 = */ "dtan",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dcosh,
        /* .name                 = */ "dcosh",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dsinh,
        /* .name                 = */ "dsinh",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dtanh,
        /* .name                 = */ "dtanh",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dacos,
        /* .name                 = */ "dacos",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dasin,
        /* .name                 = */ "dasin",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::datan,
        /* .name                 = */ "datan",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::datan2,
        /* .name                 = */ "datan2",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dlog,
        /* .name                 = */ "dlog",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dfloor,
        /* .name                 = */ "dfloor",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ffloor,
        /* .name                 = */ "ffloor",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dceil,
        /* .name                 = */ "dceil",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fceil,
        /* .name                 = */ "fceil",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ ONE_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ibranch,
        /* .name                 = */ "ibranch",
        /* .properties1          = */ ILProp1::TreeTop,
        /* .properties2          = */ ILProp2::JumpWithMultipleTargets,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::mbranch,
        /* .name                 = */ "mbranch",
        /* .properties1          = */ ILProp1::Branch,
        /* .properties2          = */ ILProp2::JumpWithMultipleTargets,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::getpm,
        /* .name                 = */ "getpm",
        /* .properties1          = */ 0,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::setpm,
        /* .name                 = */ "setpm",
        /* .properties1          = */ ILProp1::TreeTop,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::loadAutoOffset,
        /* .name                 = */ "loadAutoOffset",
        /* .properties1          = */ ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ ILChildProp::NoChildren,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::imax,
        /* .name                 = */ "imax",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Max,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iumax,
        /* .name                 = */ "iumax",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Max,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lmax,
        /* .name                 = */ "lmax",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Max,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lumax,
        /* .name                 = */ "lumax",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Max,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fmax,
        /* .name                 = */ "fmax",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Max,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dmax,
        /* .name                 = */ "dmax",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Max,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::imin,
        /* .name                 = */ "imin",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Min,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::iumin,
        /* .name                 = */ "iumin",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Min,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lmin,
        /* .name                 = */ "lmin",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Min,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lumin,
        /* .name                 = */ "lumin",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Min,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Unsigned,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Int64),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::fmin,
        /* .name                 = */ "fmin",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Min,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Float,
        /* .typeProperties       = */ ILTypeProp::Size_4 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Float),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::dmin,
        /* .name                 = */ "dmin",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::Min,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Double,
        /* .typeProperties       = */ ILTypeProp::Size_8 |
            ILTypeProp::Floating_Point,
        /* .childProperties      = */ TWO_SAME_CHILD(TR::Double),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::trt,
        /* .name                 = */ "trt",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::trtSimple,
        /* .name                 = */ "trtSimple",
        /* .properties1          = */ ILProp1::Call | ILProp1::HasSymbolRef,
        /* .properties2          = */ ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse | ILProp3::LikeDef,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ihbit,
        /* .name                 = */ "ihbit",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ilbit,
        /* .name                 = */ "ilbit",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::inolz,
        /* .name                 = */ "inolz",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::inotz,
        /* .name                 = */ "inotz",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ipopcnt,
        /* .name                 = */ "ipopcnt",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lhbit,
        /* .name                 = */ "lhbit",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::llbit,
        /* .name                 = */ "llbit",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lnolz,
        /* .name                 = */ "lnolz",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lnotz,
        /* .name                 = */ "lnotz",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lpopcnt,
        /* .name                 = */ "lpopcnt",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::SupportedForPRE,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ibyteswap,
        /* .name                 = */ "ibyteswap",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE | ILProp2::ByteSwap,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */ ONE_CHILD(TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    /*!
     * \brief bit permute
     *
     * An op-code that takes three children:
     * value   Integer
     * address Address
     * length  Integer
     *
     * Address points to a byte array, of size length.
     * These bytes are used as bit indices, specifying the bit from value
     * to use in the result. These bits are placed in the result's lowest
     * bits, based on their index in the byte array. Higher unspecified
     * bits are zeroed. This can be expressed as:
     *
     * result = 0
     * for (x = 0; x < length; ++x)
     *   result |= ((value >> address[x]) & 1) << x
     *
     * This mirrors shift's unspecified behaviour when specifying a shift amount
     * greater than the width of the value. This goes for both an specified
     * index that is not within the value and a length that exceeds the size of
     * the result.
     */
    {
        /* .opcode               = */ TR::bbitpermute,
        /* .name                 = */ "bbitpermute",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int8,
        /* .typeProperties       = */ ILTypeProp::Size_1 | ILTypeProp::Integer,
        /* .childProperties      = */
        THREE_CHILD(TR::Int8, TR::Address, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::sbitpermute,
        /* .name                 = */ "sbitpermute",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int16,
        /* .typeProperties       = */ ILTypeProp::Size_2 | ILTypeProp::Integer,
        /* .childProperties      = */
        THREE_CHILD(TR::Int16, TR::Address, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::ibitpermute,
        /* .name                 = */ "ibitpermute",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int32,
        /* .typeProperties       = */ ILTypeProp::Size_4 | ILTypeProp::Integer,
        /* .childProperties      = */
        THREE_CHILD(TR::Int32, TR::Address, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::lbitpermute,
        /* .name                 = */ "lbitpermute",
        /* .properties1          = */ 0,
        /* .properties2          = */ ILProp2::ValueNumberShare |
            ILProp2::SupportedForPRE,
        /* .properties3          = */ ILProp3::LikeUse,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::Int64,
        /* .typeProperties       = */ ILTypeProp::Size_8 | ILTypeProp::Integer,
        /* .childProperties      = */
        THREE_CHILD(TR::Int64, TR::Address, TR::Int32),
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

    {
        /* .opcode               = */ TR::Prefetch,
        /* .name                 = */ "Prefetch",
        /* .properties1          = */ ILProp1::TreeTop | ILProp1::HasSymbolRef,
        /* .properties2          = */ 0,
        /* .properties3          = */ 0,
        /* .properties4          = */ 0,
        /* .dataType             = */ TR::NoType,
        /* .typeProperties       = */ 0,
        /* .childProperties      = */ ILChildProp::Unspecified,
        /* .swapChildrenOpCode   = */ TR::BadILOp,
        /* .reverseBranchOpCode  = */ TR::BadILOp,
        /* .booleanCompareOpCode = */ TR::BadILOp,
        /* .ifCompareOpCode      = */ TR::BadILOp,
    },

#endif
