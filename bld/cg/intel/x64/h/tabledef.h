typedef enum {
    #define pick(enum,opcode,fpopcode)  enum,
    #include "_tables.h"
    #undef pick
} table_def;
