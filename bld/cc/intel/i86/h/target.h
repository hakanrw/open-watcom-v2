/****************************************************************************
*
*                            Open Watcom Project
*
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
* Description:  Configuration for Win32 x86 host, 16-bit x86 target.
*
****************************************************************************/


#ifndef _TARGET_INCLUDED
#define _TARGET_INCLUDED
#include "targdef.h"
#include "langenvd.h"
#include "ctargabi.h"

typedef short               target_short;
typedef unsigned short      target_ushort;
typedef short               target_int;
typedef unsigned short      target_uint;
typedef int                 target_long;
typedef unsigned int        target_ulong;

typedef int                 target_ssize;
typedef unsigned int        target_size;

#define _CPU            8086

#define __TGT_SYS       __TGT_SYS_X86

#endif
