/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2026 The Open Watcom Contributors. All Rights Reserved.
*
****************************************************************************/


#include "_cgstd.h"
#include "coderep.h"
#include "procdef.h"
#include "types.h"
#include "regset.h"
#include "rgtbl.h"
#include "parmreg.h"


type_length ParmAlignment( const type_def *tipe )
{
    type_length alignment;

    alignment = tipe->length;
    if( alignment == 0 )
        return( 1 );
    if( alignment > REG_SIZE )
        alignment = REG_SIZE;
    return( alignment );
}


hw_reg_set ParmReg( type_class_def type_class, type_length len,
                    type_length alignment, call_state *state )
{
    const hw_reg_set    *possible;
    const hw_reg_set    *reg_set;
    hw_reg_set          regs;
    hw_reg_set          conflicts;

    /* Scalar register selection is independent of stack size/alignment. */
    (void)len;
    (void)alignment;

    possible = ParmChoices( type_class );
    if( possible == NULL || HW_CEqual( *possible, HW_EMPTY ) ) {
        /*
         * A Win64 argument consumes one of the four positional slots even
         * when its type cannot be assigned directly to a scalar register.
         * SysV memory arguments do not consume either scalar register bank.
         */
        if( (state->attr & ROUTINE_X64_WIN64_CC)
          && !HW_CEqual( *state->parm.curr_entry, HW_EMPTY ) ) {
            state->parm.curr_entry++;
        }
        return( HW_EMPTY );
    }

    for( ; !HW_CEqual( *state->parm.curr_entry, HW_EMPTY );
           state->parm.curr_entry++ ) {
        for( reg_set = possible; !HW_CEqual( *reg_set, HW_EMPTY ); ++reg_set ) {
            regs = *reg_set;
            if( HW_Ovlap( regs, state->parm.used ) )
                continue;
            if( !HW_Subset( *state->parm.curr_entry, regs ) )
                continue;
            conflicts = FullReg( regs );
            if( state->attr & ROUTINE_X64_WIN64_CC )
                HW_TurnOn( conflicts, *state->parm.curr_entry );
            HW_TurnOn( state->parm.used, conflicts );
            return( regs );
        }
    }

    /*
     * SysV has independent GPR and SSE banks.  Failure in one bank must not
     * prevent a later argument from using the other bank.
     */
    if( state->attr & ROUTINE_X64_SYSV_CC )
        state->parm.curr_entry = state->parm.table;
    return( HW_EMPTY );
}
