typedef enum {
    #define PICK(e,name,op,class,left,right,result) e,
    #define PICK1(e,name,op,class,left,right,result) __FP80BIT(PICK(e,name,op,class,left,right,result),)
    #include "_rtinfo.h"
    #undef PICK1
    #undef PICK
    RTSIZE
} rt_class;
