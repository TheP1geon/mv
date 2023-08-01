#ifndef __ETYPES_H
#define __ETYPES_H

typedef enum {
    None = 0, 

    STACK_StackOverflow,
    STACK_StackUnderflow,
    STACK_NodeAllocFail,
    STACK_StackAllocFail,
    STACK_EmptyStack,
    STACK_EmptyStackPop,
    STACK_EmptyStackPeek,
    STACK_IndexOutofBounds,
    STACK_DestStackNotEmpty,
    STACK_NullStack,

    MV_DivisionByZero,
    MV_Stop,
    MV_FileOpenFail,
    MV_ProgramNotFound,

    INST_IllegalInstruction,
    INST_TooManyParameters,
    INST_MissingParameters,
} ErrType;

const char* err_type_to_str(ErrType e) {
    switch (e) {
        case None: return "None";
        case STACK_StackOverflow: return "STACK_StackOverflow";
        case STACK_StackUnderflow: return "STACK_StackUnderflow";
        case STACK_NodeAllocFail: return "STACK_NodeAllocFail";
        case STACK_StackAllocFail: return "STACK_StackAllocFail";
        case STACK_EmptyStack: return "STACK_EmptyStack";
        case STACK_EmptyStackPop: return "STACK_EmptyStackPop";
        case STACK_EmptyStackPeek: return "STACK_EmptyStackPeek";
        case STACK_IndexOutofBounds: return "STACK_IndexOutofBounds";
        case STACK_DestStackNotEmpty: return "STACK_DestStackNotEmpty";
        case STACK_NullStack: return "STACK_NullStack";
        case MV_DivisionByZero: return "MV_DivisionByZero";
        case MV_Stop: return "MV_Stop";
        case MV_FileOpenFail: return "MV_FileOpenFail";
        case MV_ProgramNotFound: return "MV_ProgramNotFound";
        case INST_IllegalInstruction: return "INST_IllegalInstruction";
        case INST_TooManyParameters: return "INST_TooManyParameters";
        case INST_MissingParameters: return "INST_MissingParameters";
        default: return "Unknown Error";
    }
}

#endif //__ETYPES_H
