/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2026 The Open Watcom Contributors. All Rights Reserved.
*
****************************************************************************/


#include "_cgstd.h"
#include "coderep.h"
#include "data.h"
#include "rgtbl.h"


static const hw_reg_set Empty[] = {
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set ALReg[] = {
    HW_D_1( HW_AL ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set AHReg[] = {
    HW_D_1( HW_AH ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set CLReg[] = {
    HW_D_1( HW_CL ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set ByteRegs[] = {
    HW_D_1( HW_AL ),
    HW_D_1( HW_BL ),
    HW_D_1( HW_CL ),
    HW_D_1( HW_DL ),
    HW_D_1( HW_SIL ),
    HW_D_1( HW_DIL ),
    HW_D_1( HW_BPL ),
    HW_D_1( HW_SPL ),
    HW_D_1( HW_R8B ),
    HW_D_1( HW_R9B ),
    HW_D_1( HW_R10B ),
    HW_D_1( HW_R11B ),
    HW_D_1( HW_R12B ),
    HW_D_1( HW_R13B ),
    HW_D_1( HW_R14B ),
    HW_D_1( HW_R15B ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set AXReg[] = {
    HW_D_1( HW_AX ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set DXReg[] = {
    HW_D_1( HW_DX ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set WordRegs[] = {
    HW_D_1( HW_AX ),
    HW_D_1( HW_BX ),
    HW_D_1( HW_CX ),
    HW_D_1( HW_DX ),
    HW_D_1( HW_SI ),
    HW_D_1( HW_DI ),
    HW_D_1( HW_BP ),
    HW_D_1( HW_SP ),
    HW_D_1( HW_R8W ),
    HW_D_1( HW_R9W ),
    HW_D_1( HW_R10W ),
    HW_D_1( HW_R11W ),
    HW_D_1( HW_R12W ),
    HW_D_1( HW_R13W ),
    HW_D_1( HW_R14W ),
    HW_D_1( HW_R15W ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set EAXReg[] = {
    HW_D_1( HW_EAX ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set EDXReg[] = {
    HW_D_1( HW_EDX ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set ECXReg[] = {
    HW_D_1( HW_ECX ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set DWordRegs[] = {
    HW_D_1( HW_EAX ),
    HW_D_1( HW_EBX ),
    HW_D_1( HW_ECX ),
    HW_D_1( HW_EDX ),
    HW_D_1( HW_ESI ),
    HW_D_1( HW_EDI ),
    HW_D_1( HW_EBP ),
    HW_D_1( HW_ESP ),
    HW_D_1( HW_R8D ),
    HW_D_1( HW_R9D ),
    HW_D_1( HW_R10D ),
    HW_D_1( HW_R11D ),
    HW_D_1( HW_R12D ),
    HW_D_1( HW_R13D ),
    HW_D_1( HW_R14D ),
    HW_D_1( HW_R15D ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set RAXReg[] = {
    HW_D_1( HW_RAX ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set RDXReg[] = {
    HW_D_1( HW_RDX ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set RCXReg[] = {
    HW_D_1( HW_RCX ),
    HW_D_1( HW_EMPTY )
};

/*
 * This order is deliberately ABI-neutral.  Once calls are present, their
 * aux-derived zap sets and WorthProlog decide whether a volatile or preserved
 * register is cheaper for a particular live range.
 */
static const hw_reg_set QWordRegs[] = {
    HW_D_1( HW_RAX ),
    HW_D_1( HW_RBX ),
    HW_D_1( HW_RCX ),
    HW_D_1( HW_RDX ),
    HW_D_1( HW_RSI ),
    HW_D_1( HW_RDI ),
    HW_D_1( HW_RBP ),
    HW_D_1( HW_RSP ),
    HW_D_1( HW_R8 ),
    HW_D_1( HW_R9 ),
    HW_D_1( HW_R10 ),
    HW_D_1( HW_R11 ),
    HW_D_1( HW_R12 ),
    HW_D_1( HW_R13 ),
    HW_D_1( HW_R14 ),
    HW_D_1( HW_R15 ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set IndexRegs[] = {
    HW_D_1( HW_RAX ),
    HW_D_1( HW_RCX ),
    HW_D_1( HW_RDX ),
    HW_D_1( HW_RBX ),
    HW_D_1( HW_RSI ),
    HW_D_1( HW_RDI ),
    HW_D_1( HW_R8 ),
    HW_D_1( HW_R9 ),
    HW_D_1( HW_R10 ),
    HW_D_1( HW_R11 ),
    HW_D_1( HW_R12 ),
    HW_D_1( HW_R13 ),
    HW_D_1( HW_R14 ),
    HW_D_1( HW_R15 ),
    HW_D_1( HW_RBP ),
    HW_D_1( HW_RSP ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set RDXRAXReg[] = {
    HW_D_2( HW_RDX, HW_RAX ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set XMM0Reg[] = {
    HW_D_1( HW_XMM0 ),
    HW_D_1( HW_EMPTY )
};

static const hw_reg_set XMMRegs[] = {
    HW_D_1( HW_XMM0 ),
    HW_D_1( HW_XMM1 ),
    HW_D_1( HW_XMM2 ),
    HW_D_1( HW_XMM3 ),
    HW_D_1( HW_XMM4 ),
    HW_D_1( HW_XMM5 ),
    HW_D_1( HW_XMM6 ),
    HW_D_1( HW_XMM7 ),
    HW_D_1( HW_XMM8 ),
    HW_D_1( HW_XMM9 ),
    HW_D_1( HW_XMM10 ),
    HW_D_1( HW_XMM11 ),
    HW_D_1( HW_XMM12 ),
    HW_D_1( HW_XMM13 ),
    HW_D_1( HW_XMM14 ),
    HW_D_1( HW_XMM15 ),
    HW_D_1( HW_EMPTY )
};

const hw_reg_set * const RegSets[] = {
    #define RL(a,b,c,d) a
    #include "rl.h"
    #undef RL
    NULL
};

const op_regs RegList[] = {
    #define RG(a,b,c,d,e,f) { a, b, c, d, e }
    #include "rg.h"
    #undef RG
};

static const reg_set_index ClassSets[] = {
    RL_BYTE,       /* U1 */
    RL_BYTE,       /* I1 */
    RL_WORD,       /* U2 */
    RL_WORD,       /* I2 */
    RL_DWORD,      /* U4 */
    RL_DWORD,      /* I4 */
    RL_QWORD,      /* U8 */
    RL_QWORD,      /* I8 */
    RL_QWORD,      /* CP */
    RL_QWORD,      /* PT */
    RL_XMM,        /* FS */
    RL_XMM,        /* FD */
    RL_XMM,        /* FL */
    RL_            /* XX */
};

static bool RegInList( hw_reg_set reg, const hw_reg_set *list )
{
    for( ; !HW_CEqual( *list, HW_EMPTY ); ++list ) {
        if( HW_Equal( reg, *list ) )
            return( true );
    }
    return( false );
}

static hw_reg_set SubReg( hw_reg_set reg, const hw_reg_set *full,
                          const hw_reg_set *part )
{
    for( ; !HW_CEqual( *full, HW_EMPTY ); ++full, ++part ) {
        if( HW_Ovlap( reg, *full ) )
            return( *part );
    }
    return( HW_EMPTY );
}

void InitRegTbl( void )
{
}

reg_set_index RegIntersect( reg_set_index left, reg_set_index right )
{
    const hw_reg_set    *single;

    if( left == right )
        return( left );
    if( left == RL_NUMBER_OF_SETS )
        return( right );
    if( right == RL_NUMBER_OF_SETS )
        return( left );
    if( left == RL_ || right == RL_ )
        return( RL_ );
    if( (left == RL_QWORD && right == RL_INDEX)
      || (left == RL_INDEX && right == RL_QWORD) )
        return( RL_INDEX );

    single = RegSets[left];
    if( !HW_CEqual( *single, HW_EMPTY )
      && HW_CEqual( single[1], HW_EMPTY )
      && RegInList( *single, RegSets[right] ) )
        return( left );
    single = RegSets[right];
    if( !HW_CEqual( *single, HW_EMPTY )
      && HW_CEqual( single[1], HW_EMPTY )
      && RegInList( *single, RegSets[left] ) )
        return( right );
    return( RL_ );
}

const hw_reg_set *ParmChoices( type_class_def type_class )
{
    if( type_class >= XX )
        return( Empty );
    return( RegSets[ClassSets[type_class]] );
}

hw_reg_set InLineParm( hw_reg_set regs, hw_reg_set used )
{
    /* Parameter registers are selected by the callee's aux convention. */
    (void)used;
    return( regs );
}

hw_reg_set StructReg( void )
{
    return( HW_RAX );
}

hw_reg_set ReturnReg( type_class_def type_class, bool use_87 )
{
    /* x64 floating-point returns never use the x87 stack. */
    (void)use_87;
    switch( type_class ) {
    case FS:
    case FD:
    case FL:
        return( HW_XMM0 );
    case XX:
        return( HW_EMPTY );
    default:
        return( HW_RAX );
    }
}

reg_set_index SegIndex( void )
{
    return( RL_ );
}

reg_set_index NoSegments( reg_set_index regs_idx )
{
    return( regs_idx );
}

reg_set_index IndexIntersect( reg_set_index curr, type_class_def type_class,
                              bool is_temp_index )
{
    (void)is_temp_index;
    if( type_class == U8 || type_class == I8
      || type_class == CP || type_class == PT )
        return( RegIntersect( curr, RL_INDEX ) );
    return( RL_ );
}

bool IsIndexReg( hw_reg_set reg, type_class_def type_class,
                 bool is_temp_index )
{
    (void)is_temp_index;
    if( type_class != U8 && type_class != I8
      && type_class != CP && type_class != PT )
        return( false );
    return( RegInList( reg, IndexRegs ) );
}

type_class_def RegClass( hw_reg_set regs )
{
    type_class_def type_class;

    if( RegInList( regs, XMMRegs ) )
        return( FD );
    for( type_class = U1; type_class < XX; ++type_class ) {
        if( RegInList( regs, RegSets[ClassSets[type_class]] ) )
            return( type_class );
    }
    return( XX );
}

bool IndexRegOk( hw_reg_set reg, bool is_temp_index )
{
    (void)is_temp_index;
    return( RegInList( reg, IndexRegs ) );
}

bool IsSegReg( hw_reg_set regs )
{
    (void)regs;
    return( false );
}

hw_reg_set Low16Reg( hw_reg_set regs )
{
    return( SubReg( regs, QWordRegs, WordRegs ) );
}

hw_reg_set High16Reg( hw_reg_set regs )
{
    hw_reg_set high;
    hw_reg_set low32;

    high = regs;
    low32 = Low32Reg( regs );
    HW_OnlyOn( high, low32 );
    HW_TurnOff( high, Low16Reg( regs ) );
    return( high );
}

hw_reg_set Low32Reg( hw_reg_set regs )
{
    return( SubReg( regs, QWordRegs, DWordRegs ) );
}

hw_reg_set High32Reg( hw_reg_set regs )
{
    hw_reg_set high;

    high = regs;
    HW_TurnOff( high, Low32Reg( regs ) );
    return( high );
}

hw_reg_set High48Reg( hw_reg_set regs )
{
    (void)regs;
    return( HW_EMPTY );
}

hw_reg_set Low48Reg( hw_reg_set regs )
{
    (void)regs;
    return( HW_EMPTY );
}

hw_reg_set High64Reg( hw_reg_set regs )
{
    (void)regs;
    return( HW_EMPTY );
}

hw_reg_set Low64Reg( hw_reg_set regs )
{
    (void)regs;
    return( HW_EMPTY );
}

hw_reg_set HighReg( hw_reg_set regs )
{
    (void)regs;
    return( HW_EMPTY );
}

hw_reg_set HighOffsetReg( hw_reg_set regs )
{
    return( HighReg( regs ) );
}

hw_reg_set HighTreePart( hw_reg_set regs )
{
    return( HighReg( regs ) );
}

hw_reg_set LowReg( hw_reg_set regs )
{
    (void)regs;
    return( HW_EMPTY );
}

hw_reg_set LowOffsetReg( hw_reg_set regs )
{
    return( LowReg( regs ) );
}

hw_reg_set LowTreePart( hw_reg_set regs )
{
    return( LowReg( regs ) );
}

hw_reg_set FullReg( hw_reg_set regs )
{
    const hw_reg_set *full;

    if( HW_COvlap( regs, HW_XMMS ) )
        return( regs );
    for( full = QWordRegs; !HW_CEqual( *full, HW_EMPTY ); ++full ) {
        if( HW_Ovlap( regs, *full ) )
            return( *full );
    }
    return( regs );
}

bool IsRegClass( hw_reg_set regs, type_class_def type_class )
{
    if( type_class >= XX )
        return( false );
    return( RegInList( regs, RegSets[ClassSets[type_class]] ) );
}

hw_reg_set ActualParmReg( hw_reg_set reg )
{
    return( reg );
}

hw_reg_set FixedRegs( void )
{
    hw_reg_set fixed;

    HW_CAsgn( fixed, HW_RSP );
    /*
     * Keep RBP fixed until frame-pointer selection and unwind generation are
     * implemented.  This is a backend limitation, not an ABI save rule.
     */
    HW_CTurnOn( fixed, HW_RBP );
    return( fixed );
}

bool IsStackReg( name *sp )
{
    if( sp == NULL || sp->n.class != N_REGISTER )
        return( false );
    return( HW_Ovlap( sp->r.reg, HW_RSP ) );
}

hw_reg_set StackReg( void )
{
    return( HW_RSP );
}

hw_reg_set DisplayReg( void )
{
    return( HW_RBP );
}

int SizeDisplayReg( void )
{
    return( 8 );
}

hw_reg_set AllCacheRegs( void )
{
    hw_reg_set all;

    HW_CAsgn( all, HW_GPRS64 );
    HW_TurnOn( all, HW_XMMS );
    HW_TurnOff( all, FixedRegs() );
    return( all );
}

const hw_reg_set *IdxRegs( void )
{
    return( IndexRegs );
}

hw_reg_set ParmRegConflicts( hw_reg_set reg )
{
    return( FullReg( reg ) );
}

hw_reg_set VarargsHomePtr( void )
{
    return( HW_EMPTY );
}

hw_reg_set ReturnAddrReg( void )
{
    return( HW_EMPTY );
}

hw_reg_set FirstReg( reg_set_index regs_idx )
{
    return( *RegSets[regs_idx] );
}

hw_reg_set ScratchReg( void )
{
    return( HW_R11 );
}
