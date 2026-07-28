/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2023-2026 The Open Watcom Contributors. All Rights Reserved.
*    Portions Copyright (c) 1983-2002 Sybase, Inc. All Rights Reserved.
*
*  ========================================================================
*
*    This file contains Original Code and/or Modifications of Original
*    Code as defined in and that are subject to the Sybase Open Watcom
*    Public License version 1.0 (the 'License'). You may not use this file
*    except in compliance with the License. BY USING THIS FILE YOU AGREE TO
*    ALL TERMS AND CONDITIONS OF THE LICENSE. A copy of the License is
*    provided with the Original Code and Modifications, and is also
*    available at www.sybase.com/developer/opensource.
*
*    The Original Code and all software distributed under the License are
*    distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
*    EXPRESS OR IMPLIED, AND SYBASE AND ALL CONTRIBUTORS HEREBY DISCLAIM
*    ALL SUCH WARRANTIES, INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF
*    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR
*    NON-INFRINGEMENT. Please see the License for the specific language
*    governing rights and limitations under the License.
*
*  ========================================================================
*
* Description:  C frontend data type properties.
*
****************************************************************************/

/*
 * Code-generator, assembler, and data-initializer types are derived at
 * their respective handoff points.
 */

/*      type             signedness    size                 alignment */
pick1( TYP_BOOL,        CTS_UNSIGNED,  TARGET_BOOL,         TARGET_BOOL_ALIGN        )
pick1( TYP_CHAR,        CTS_SIGNED,    TARGET_CHAR,         TARGET_CHAR_ALIGN        )
pick1( TYP_UCHAR,       CTS_UNSIGNED,  TARGET_CHAR,         TARGET_CHAR_ALIGN        )
pick1( TYP_SHORT,       CTS_SIGNED,    TARGET_SHORT,        TARGET_SHORT_ALIGN       )
pick1( TYP_USHORT,      CTS_UNSIGNED,  TARGET_SHORT,        TARGET_SHORT_ALIGN       )
pick1( TYP_INT,         CTS_SIGNED,    TARGET_INT,          TARGET_INT_ALIGN         )
pick1( TYP_UINT,        CTS_UNSIGNED,  TARGET_INT,          TARGET_INT_ALIGN         )
pick1( TYP_LONG,        CTS_SIGNED,    TARGET_LONG,         TARGET_LONG_ALIGN        )
pick1( TYP_ULONG,       CTS_UNSIGNED,  TARGET_LONG,         TARGET_LONG_ALIGN        )
pick1( TYP_LONG64,      CTS_SIGNED,    TARGET_LONG64,       TARGET_LONG64_ALIGN      )
pick1( TYP_ULONG64,     CTS_UNSIGNED,  TARGET_LONG64,       TARGET_LONG64_ALIGN      )
pick1( TYP_FLOAT,       CTS_NONE,      TARGET_FLOAT,        TARGET_FLOAT_ALIGN       )
pick1( TYP_DOUBLE,      CTS_NONE,      TARGET_DOUBLE,       TARGET_DOUBLE_ALIGN      )
pick1( TYP_LONG_DOUBLE, CTS_NONE,      TARGET_LDOUBLE,      TARGET_LDOUBLE_ALIGN     )
pick1( TYP_FIMAGINARY,  CTS_NONE,      TARGET_FIMAGINARY,   TARGET_FIMAGINARY_ALIGN  )
pick1( TYP_DIMAGINARY,  CTS_NONE,      TARGET_DIMAGINARY,   TARGET_DIMAGINARY_ALIGN  )
pick1( TYP_LDIMAGINARY, CTS_NONE,      TARGET_LDIMAGINARY,  TARGET_LDIMAGINARY_ALIGN )
pick1( TYP_POINTER,     CTS_NONE,      0,                   0                        )
pick1( TYP_ARRAY,       CTS_NONE,      0,                   0                        )
pick1( TYP_STRUCT,      CTS_NONE,      0,                   0                        )
pick1( TYP_UNION,       CTS_NONE,      0,                   0                        )
pick1( TYP_FUNCTION,    CTS_NONE,      0,                   0                        )
pick1( TYP_FIELD,       CTS_NONE,      0,                   0                        )
pick1( TYP_VOID,        CTS_NONE,      0,                   0                        )
pick1( TYP_ENUM,        CTS_NONE,      0,                   0                        )
pick1( TYP_TYPEDEF,     CTS_NONE,      0,                   0                        )
pick1( TYP_UFIELD,      CTS_NONE,      0,                   0                        )
pick1( TYP_DOT_DOT_DOT, CTS_NONE,      0,                   0                        )
pick1( TYP_PLAIN_CHAR,  CTS_NONE,      TARGET_CHAR,         TARGET_CHAR_ALIGN        )
pick1( TYP_WCHAR,       CTS_UNSIGNED,  TARGET_WCHAR,        TARGET_WCHAR_ALIGN       )
pick1( TYP_FCOMPLEX,    CTS_NONE,      TARGET_FCOMPLEX,     TARGET_FCOMPLEX_ALIGN    )
pick1( TYP_DCOMPLEX,    CTS_NONE,      TARGET_DCOMPLEX,     TARGET_DCOMPLEX_ALIGN    )
pick1( TYP_LDCOMPLEX,   CTS_NONE,      TARGET_LDCOMPLEX,    TARGET_LDCOMPLEX_ALIGN   )
