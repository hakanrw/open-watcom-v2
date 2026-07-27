/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2026 The Open Watcom Contributors. All Rights Reserved.
*
****************************************************************************/


/*  left       right      result      zap          need       id */
RG( RL_,       RL_,       RL_,        RL_,         RL_,       RG_ ),
RG( RL_BYTE,   RL_BYTE,   RL_BYTE,    RL_,         RL_,       RG_BYTE ),
RG( RL_BYTE,   RL_BYTE,   RL_BYTE,    RL_,         RL_BYTE,   RG_BYTE_NEED ),
RG( RL_WORD,   RL_WORD,   RL_WORD,    RL_,         RL_,       RG_WORD ),
RG( RL_WORD,   RL_WORD,   RL_WORD,    RL_,         RL_WORD,   RG_WORD_NEED ),
RG( RL_DWORD,  RL_DWORD,  RL_DWORD,   RL_,         RL_,       RG_DWORD ),
RG( RL_DWORD,  RL_DWORD,  RL_DWORD,   RL_,         RL_DWORD,  RG_DWORD_NEED ),
RG( RL_QWORD,  RL_QWORD,  RL_QWORD,   RL_,         RL_,       RG_QWORD ),
RG( RL_QWORD,  RL_QWORD,  RL_QWORD,   RL_,         RL_QWORD,  RG_QWORD_NEED ),
RG( RL_XMM,    RL_XMM,    RL_XMM,     RL_,         RL_,       RG_XMM ),
RG( RL_XMM,    RL_XMM,    RL_XMM,     RL_,         RL_XMM,    RG_XMM_NEED ),

RG( RL_RAX,    RL_QWORD,  RL_RAX,     RL_RDX,      RL_,       RG_QWORD_DIV ),
RG( RL_RAX,    RL_QWORD,  RL_RDX,     RL_RAX,      RL_,       RG_QWORD_MOD ),
RG( RL_QWORD,  RL_CL,     RL_QWORD,   RL_,         RL_,       RG_QWORD_SHIFT ),
RG( RL_DWORD,  RL_CL,     RL_DWORD,   RL_,         RL_,       RG_DWORD_SHIFT ),
RG( RL_WORD,   RL_CL,     RL_WORD,    RL_,         RL_,       RG_WORD_SHIFT ),
RG( RL_BYTE,   RL_CL,     RL_BYTE,    RL_,         RL_,       RG_BYTE_SHIFT ),

/*
 * MAX_RG is the maximum number of candidates in a register list, including
 * the terminating HW_EMPTY entry.
 */
#define MAX_RG  17
