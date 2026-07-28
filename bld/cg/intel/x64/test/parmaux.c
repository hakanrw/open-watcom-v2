/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2026 The Open Watcom Contributors. All Rights Reserved.
*
****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../../cc/x64/target.h"
#include "_cgstd.h"
#include "coderep.h"
#include "procdef.h"
#include "parmreg.h"
#include "pragdefn.h"


void *CMemAlloc( size_t size )
{
    return( malloc( size ) );
}

char *CMemStrdup( const char *str )
{
    char *copy;

    copy = malloc( strlen( str ) + 1 );
    if( copy != NULL )
        strcpy( copy, str );
    return( copy );
}

void CMemFree( void *p )
{
    free( p );
}

#include "callinfo.c"

static struct {
    const char  *name;
    aux_info    *info;
} AuxAliases[] = {
    #define pick(a,b,c,d) { b, d },
    #include "auxinfo.h"
    #undef pick
};

static aux_info *LookupAlias( const char *name )
{
    unsigned i;

    for( i = 0; i < sizeof( AuxAliases ) / sizeof( AuxAliases[0] ); ++i ) {
        if( strcmp( name, AuxAliases[i].name ) == 0 )
            return( AuxAliases[i].info );
    }
    return( NULL );
}


static void InitAuxInfo( void )
{
    SetAuxWatcallInfo();
    CdeclInfo    = WatcallInfo;
    PascalInfo   = WatcallInfo;
    SyscallInfo  = WatcallInfo;
    StdcallInfo  = WatcallInfo;
    OptlinkInfo  = WatcallInfo;
    FortranInfo  = WatcallInfo;
    FastcallInfo = WatcallInfo;
    Win64Info    = WatcallInfo;
    SysVInfo     = WatcallInfo;
    AuxInfoInit( false );
}

static void *TestFEAuxInfo( aux_info *info, aux_class request )
{
    switch( request ) {
    case FEINF_CALL_CLASS_TARGET:
        return( (void *)(pointer_uint)info->cclass_target );
    case FEINF_PARM_REGS:
        return( info->parms );
    case FEINF_SAVE_REGS:
        return( &info->save );
    default:
        return( NULL );
    }
}

static void InitCallState( call_state *state, aux_info *info )
{
    call_class_target cclass_target;
    hw_reg_set        *save;

    memset( state, 0, sizeof( *state ) );
    cclass_target = (call_class_target)(pointer_uint)
                    TestFEAuxInfo( info, FEINF_CALL_CLASS_TARGET );
    if( cclass_target & FECALL_X64_WIN64_CC )
        state->attr |= ROUTINE_X64_WIN64_CC;
    if( cclass_target & FECALL_X64_SYSV_CC )
        state->attr |= ROUTINE_X64_SYSV_CC;
    state->parm.table = TestFEAuxInfo( info, FEINF_PARM_REGS );
    state->parm.curr_entry = state->parm.table;
    HW_CAsgn( state->parm.used, HW_EMPTY );
    save = TestFEAuxInfo( info, FEINF_SAVE_REGS );
    state->modify = *save;
}

static int CheckReg( hw_reg_set got, hw_reg_set expected, const char *what )
{
    if( !HW_Equal( got, expected ) ) {
        printf( "%s: unexpected register\n", what );
        return( 1 );
    }
    return( 0 );
}

static int CheckWin64( void )
{
    call_state state;
    int        failed;

    failed = 0;
    InitCallState( &state, &Win64Info );
    failed += CheckReg( ParmReg( I4, 4, 4, &state ), HW_ECX, "win64 int 0" );
    failed += CheckReg( ParmReg( FD, 8, 8, &state ), HW_XMM1, "win64 double 1" );
    failed += CheckReg( ParmReg( I8, 8, 8, &state ), HW_R8, "win64 int64 2" );
    failed += CheckReg( ParmReg( FS, 4, 4, &state ), HW_XMM3, "win64 float 3" );
    failed += CheckReg( ParmReg( I4, 4, 4, &state ), HW_EMPTY, "win64 stack 4" );
    return( failed );
}

static int CheckSysV( void )
{
    call_state state;
    int        failed;

    failed = 0;
    InitCallState( &state, &SysVInfo );
    failed += CheckReg( ParmReg( I4, 4, 4, &state ), HW_EDI, "sysv int 0" );
    failed += CheckReg( ParmReg( FD, 8, 8, &state ), HW_XMM0, "sysv double 0" );
    failed += CheckReg( ParmReg( I8, 8, 8, &state ), HW_RSI, "sysv int64 1" );
    failed += CheckReg( ParmReg( FS, 4, 4, &state ), HW_XMM1, "sysv float 1" );
    failed += CheckReg( ParmReg( I4, 4, 4, &state ), HW_EDX, "sysv int 2" );
    failed += CheckReg( ParmReg( FD, 8, 8, &state ), HW_XMM2, "sysv double 2" );
    return( failed );
}

int main( void )
{
    int failed;

    InitAuxInfo();
    failed = (Win64Info.cclass_target & FECALL_X64_CC_MASK)
          != FECALL_X64_WIN64_CC;
    failed += (SysVInfo.cclass_target & FECALL_X64_CC_MASK)
           != FECALL_X64_SYSV_CC;
    failed += !HW_COvlap( Win64Info.save, HW_RSI );
    failed += !HW_COvlap( Win64Info.save, HW_XMM6 );
    failed += HW_COvlap( Win64Info.save, HW_RAX );
    failed += !HW_COvlap( SysVInfo.save, HW_RBX );
    failed += HW_COvlap( SysVInfo.save, HW_RSI );
    failed += HW_COvlap( SysVInfo.save, HW_XMM6 );
    failed += LookupAlias( "__win64" ) != &Win64Info;
    failed += LookupAlias( "__sysv" ) != &SysVInfo;
    DftCallConv = &Win64Info;
    failed += DftCallConv != &Win64Info;
    DftCallConv = &SysVInfo;
    failed += DftCallConv != &SysVInfo;
    failed += CheckWin64();
    failed += CheckSysV();
    return( failed != 0 );
}
