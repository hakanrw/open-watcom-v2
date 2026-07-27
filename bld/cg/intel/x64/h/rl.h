/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2026 The Open Watcom Contributors. All Rights Reserved.
*
****************************************************************************/


/*
 * x64 register lists.  These describe architectural storage classes only;
 * calling-convention volatility and parameter order come from aux info.
 */

RL( Empty,       RL_,          OTHER,    0 ),

RL( ALReg,       RL_AL,        BYTE,     0 ),
RL( AHReg,       RL_AH,        BYTE,     1 ),
RL( CLReg,       RL_CL,        BYTE,     2 ),
RL( ByteRegs,    RL_BYTE,      BYTE,     3 ),

RL( AXReg,       RL_AX,        WORD,     0 ),
RL( DXReg,       RL_DX,        WORD,     1 ),
RL( WordRegs,    RL_WORD,      WORD,     2 ),

RL( EAXReg,      RL_EAX,       DWORD,    0 ),
RL( EDXReg,      RL_EDX,       DWORD,    1 ),
RL( ECXReg,      RL_ECX,       DWORD,    2 ),
RL( DWordRegs,   RL_DWORD,     DWORD,    3 ),

RL( RAXReg,      RL_RAX,       QWORD,    0 ),
RL( RDXReg,      RL_RDX,       QWORD,    1 ),
RL( RCXReg,      RL_RCX,       QWORD,    2 ),
RL( QWordRegs,   RL_QWORD,     QWORD,    3 ),
RL( IndexRegs,   RL_INDEX,     QWORD,    4 ),
RL( RDXRAXReg,   RL_RDX_RAX,   QWORD,    5 ),

RL( XMM0Reg,     RL_XMM0,      FLOATING, 0 ),
RL( XMMRegs,     RL_XMM,       FLOATING, 1 ),

#define RL_MOVE     RL_QWORD
