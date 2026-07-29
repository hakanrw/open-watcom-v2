/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2026 The Open Watcom Contributors. All Rights Reserved.
*
****************************************************************************/


#ifndef _TARGET_INCLUDED
#define _TARGET_INCLUDED
#include "targdef.h"
#include "langenvd.h"
#include "ctargabi.h"

typedef short               target_short;
typedef unsigned short      target_ushort;
typedef int                 target_int;
typedef unsigned int        target_uint;
typedef int                 target_long;
typedef unsigned int        target_ulong;

typedef signed __int64      target_ssize;
typedef unsigned __int64    target_size;

#define _CPU            _X64

#define __TGT_SYS       __TGT_SYS_X86

#endif
