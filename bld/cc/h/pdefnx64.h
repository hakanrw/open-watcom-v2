/****************************************************************************
*
*                            Open Watcom Project
*
* Copyright (c) 2026 The Open Watcom Contributors. All Rights Reserved.
*
****************************************************************************/


hw_reg_set DefaultVarParms[] = {
    HW_D( HW_EMPTY )
};

#define X64_REG_DEFS \
REG_PICK( ES,    "es"    ) \
REG_PICK( DS,    "ds"    ) \
REG_PICK( CS,    "cs"    ) \
REG_PICK( SS,    "ss"    ) \
REG_PICK( FS,    "fs"    ) \
REG_PICK( GS,    "gs"    ) \
REG_PICK( RAX,   "rax"   ) \
REG_PICK( RBX,   "rbx"   ) \
REG_PICK( RCX,   "rcx"   ) \
REG_PICK( RDX,   "rdx"   ) \
REG_PICK( RSI,   "rsi"   ) \
REG_PICK( RDI,   "rdi"   ) \
REG_PICK( RBP,   "rbp"   ) \
REG_PICK( RSP,   "rsp"   ) \
REG_PICK( R8,    "r8"    ) \
REG_PICK( R9,    "r9"    ) \
REG_PICK( R10,   "r10"   ) \
REG_PICK( R11,   "r11"   ) \
REG_PICK( R12,   "r12"   ) \
REG_PICK( R13,   "r13"   ) \
REG_PICK( R14,   "r14"   ) \
REG_PICK( R15,   "r15"   ) \
REG_PICK( EAX,   "eax"   ) \
REG_PICK( EBX,   "ebx"   ) \
REG_PICK( ECX,   "ecx"   ) \
REG_PICK( EDX,   "edx"   ) \
REG_PICK( ESI,   "esi"   ) \
REG_PICK( EDI,   "edi"   ) \
REG_PICK( EBP,   "ebp"   ) \
REG_PICK( ESP,   "esp"   ) \
REG_PICK( XMM0,  "xmm0"  ) \
REG_PICK( XMM1,  "xmm1"  ) \
REG_PICK( XMM2,  "xmm2"  ) \
REG_PICK( XMM3,  "xmm3"  ) \
REG_PICK( XMM4,  "xmm4"  ) \
REG_PICK( XMM5,  "xmm5"  ) \
REG_PICK( XMM6,  "xmm6"  ) \
REG_PICK( XMM7,  "xmm7"  ) \
REG_PICK( XMM8,  "xmm8"  ) \
REG_PICK( XMM9,  "xmm9"  ) \
REG_PICK( XMM10, "xmm10" ) \
REG_PICK( XMM11, "xmm11" ) \
REG_PICK( XMM12, "xmm12" ) \
REG_PICK( XMM13, "xmm13" ) \
REG_PICK( XMM14, "xmm14" ) \
REG_PICK( XMM15, "xmm15" )

char Registers[] = {
    #define REG_PICK(c,t) t "\0"
    X64_REG_DEFS
    "\0"
    #undef REG_PICK
};

enum {
    #define REG_PICK(c,t) REG_INDEX_##c,
    X64_REG_DEFS
    #undef REG_PICK
};

unsigned char RegMap[] = {
    #define REG_PICK(c,t) REG_INDEX_##c,
    X64_REG_DEFS
    #undef REG_PICK
};

hw_reg_set RegBits[] = {
    #define REG_PICK(c,t) HW_D( HW_##c ),
    X64_REG_DEFS
    #undef REG_PICK
};

#undef X64_REG_DEFS

aux_info InlineInfo;

#define EMPTY_INLINE_TABLE(name) \
    const inline_funcs name[] = { { NULL } }

EMPTY_INLINE_TABLE( SInline_Functions );
EMPTY_INLINE_TABLE( Inline_Functions );
EMPTY_INLINE_TABLE( Flat_Functions );
EMPTY_INLINE_TABLE( BigData_Functions );
EMPTY_INLINE_TABLE( BigDataNoDs_Functions );
EMPTY_INLINE_TABLE( SBigData_Functions );
EMPTY_INLINE_TABLE( SBigDataNoDs_Functions );
EMPTY_INLINE_TABLE( Common_Functions );
EMPTY_INLINE_TABLE( _8087_Functions );

#undef EMPTY_INLINE_TABLE
