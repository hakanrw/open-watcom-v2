/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2026 The Open Watcom Contributors. All Rights Reserved.
*
****************************************************************************/


#ifndef _CG_TARGET_ABI_INCLUDED
#define _CG_TARGET_ABI_INCLUDED

typedef enum {
    CG_ABI_X64_WIN64,
    CG_ABI_X64_SYSV,
    CG_ABI_X64_COUNT
} cg_target_abi;

#define CG_ABI_DEFAULT  CG_ABI_X64_WIN64
#define CG_ABI_COUNT    CG_ABI_X64_COUNT

#endif
