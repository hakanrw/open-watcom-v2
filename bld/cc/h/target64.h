/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2026 The Open Watcom Contributors. All Rights Reserved.
*
****************************************************************************/


/*
 * Initial x64 data model.  This is the Win64 LLP64 model; making C type
 * dimensions selectable for a SysV LP64 environment is separate work.
 */

#define TARGET_CHAR         1
#define TARGET_SHORT        2
#define TARGET_INT          4
#define TARGET_POINTER      8
#define TARGET_NEAR_POINTER 8
#define TARGET_FAR_POINTER  8
#define TARGET_LONG         4
#define TARGET_ULONG        4
#define TARGET_LONG64       8
#define TARGET_ULON64       8
#define TARGET_UINT         4
#define TARGET_FLOAT        4
#define TARGET_DOUBLE       8
#define TARGET_LDOUBLE      8
#define TARGET_FCOMPLEX     8
#define TARGET_DCOMPLEX     16
#define TARGET_LDCOMPLEX    16
#define TARGET_FIMAGINARY   4
#define TARGET_DIMAGINARY   8
#define TARGET_LDIMAGINARY  8
#define TARGET_BOOL         1
#define TARGET_WCHAR        2
#define TARGET_BITFIELD     8

#define TARGET_CHAR_MAX     127
#define TARGET_UCHAR_MAX    255U
#define TARGET_SHORT_MAX    32767
#define TARGET_USHORT_MAX   65535U
#define TARGET_INT_MAX      2147483647
#define TARGET_INT_MIN      (-2147483647-1)
#define TARGET_UINT_MAX     4294967295U
#define TARGET_LONG_MAX     2147483647
#define TARGET_ULONG_MAX    4294967295U
#define TARGET_FLT_MAX      3.402823466e+38f

typedef short               target_short;
typedef unsigned short      target_ushort;
typedef int                 target_int;
typedef unsigned int        target_uint;
typedef int                 target_long;
typedef unsigned int        target_ulong;

typedef signed __int64      target_ssize;
typedef unsigned __int64    target_size;
