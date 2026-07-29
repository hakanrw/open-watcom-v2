/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2026 The Open Watcom Contributors. All Rights Reserved.
*
****************************************************************************/


#ifndef _C_TARGET_ABI_INCLUDED
#define _C_TARGET_ABI_INCLUDED

#include "cgtargabi.h"

typedef struct target_type_dimension {
    unsigned char       size;
    unsigned char       alignment;
} target_type_dimension;

typedef struct target_abi_info {
    cg_target_abi           abi;
    target_type_dimension   bool_type;
    target_type_dimension   char_type;
    target_type_dimension   short_type;
    target_type_dimension   int_type;
    target_type_dimension   pointer_type;
    target_type_dimension   near_pointer_type;
    target_type_dimension   far_pointer_type;
    target_type_dimension   long_type;
    target_type_dimension   long64_type;
    target_type_dimension   float_type;
    target_type_dimension   double_type;
    target_type_dimension   long_double_type;
    target_type_dimension   float_complex_type;
    target_type_dimension   double_complex_type;
    target_type_dimension   long_double_complex_type;
    target_type_dimension   float_imaginary_type;
    target_type_dimension   double_imaginary_type;
    target_type_dimension   long_double_imaginary_type;
    target_type_dimension   wchar_type;
    unsigned char           bitfield_size;
} target_abi_info;

/*
 * Target dimensions are runtime properties.  These names remain as accessors
 * while their users are migrated away from the old compile-time constants.
 */
#define TARGET_BOOL             (TargetInfo->bool_type.size)
#define TARGET_CHAR             (TargetInfo->char_type.size)
#define TARGET_SHORT            (TargetInfo->short_type.size)
#define TARGET_INT              (TargetInfo->int_type.size)
#define TARGET_UINT             TARGET_INT
#define TARGET_POINTER          (TargetInfo->pointer_type.size)
#define TARGET_NEAR_POINTER     (TargetInfo->near_pointer_type.size)
#define TARGET_FAR_POINTER      (TargetInfo->far_pointer_type.size)
#define TARGET_LONG             (TargetInfo->long_type.size)
#define TARGET_ULONG            TARGET_LONG
#define TARGET_LONG64           (TargetInfo->long64_type.size)
#define TARGET_ULON64           TARGET_LONG64
#define TARGET_FLOAT            (TargetInfo->float_type.size)
#define TARGET_DOUBLE           (TargetInfo->double_type.size)
#define TARGET_LDOUBLE          (TargetInfo->long_double_type.size)
#define TARGET_FCOMPLEX         (TargetInfo->float_complex_type.size)
#define TARGET_DCOMPLEX         (TargetInfo->double_complex_type.size)
#define TARGET_LDCOMPLEX        (TargetInfo->long_double_complex_type.size)
#define TARGET_FIMAGINARY       (TargetInfo->float_imaginary_type.size)
#define TARGET_DIMAGINARY       (TargetInfo->double_imaginary_type.size)
#define TARGET_LDIMAGINARY      (TargetInfo->long_double_imaginary_type.size)
#define TARGET_WCHAR            (TargetInfo->wchar_type.size)
#define TARGET_BITFIELD         (TargetInfo->bitfield_size)

#define TARGET_BOOL_ALIGN       (TargetInfo->bool_type.alignment)
#define TARGET_CHAR_ALIGN       (TargetInfo->char_type.alignment)
#define TARGET_SHORT_ALIGN      (TargetInfo->short_type.alignment)
#define TARGET_INT_ALIGN        (TargetInfo->int_type.alignment)
#define TARGET_LONG_ALIGN       (TargetInfo->long_type.alignment)
#define TARGET_LONG64_ALIGN     (TargetInfo->long64_type.alignment)
#define TARGET_FLOAT_ALIGN      (TargetInfo->float_type.alignment)
#define TARGET_DOUBLE_ALIGN     (TargetInfo->double_type.alignment)
#define TARGET_LDOUBLE_ALIGN    (TargetInfo->long_double_type.alignment)
#define TARGET_FCOMPLEX_ALIGN   (TargetInfo->float_complex_type.alignment)
#define TARGET_DCOMPLEX_ALIGN   (TargetInfo->double_complex_type.alignment)
#define TARGET_LDCOMPLEX_ALIGN  (TargetInfo->long_double_complex_type.alignment)
#define TARGET_FIMAGINARY_ALIGN (TargetInfo->float_imaginary_type.alignment)
#define TARGET_DIMAGINARY_ALIGN (TargetInfo->double_imaginary_type.alignment)
#define TARGET_LDIMAGINARY_ALIGN (TargetInfo->long_double_imaginary_type.alignment)
#define TARGET_WCHAR_ALIGN      (TargetInfo->wchar_type.alignment)

#define TARGET_INT_MAX          ((TARGET_INT == 2) ? 32767U : 2147483647U)
#define TARGET_INT_MIN          ((TARGET_INT == 2) ? -32767 - 1 : -2147483647 - 1)
#define TARGET_UINT_MAX         ((TARGET_INT == 2) ? 65535U : 4294967295U)
#define TARGET_FLT_MAX          3.402823466e+38f

#endif
