#ifndef MNEMONICS_H
#define MNEMONICS_H

// this list is not organized in any particular way
// You might find decoding easier if you modify this

enum mnemonics {
    UNDEF,

    // data movement
    MOV,

    // arithmetic
    ADD,
    SUB,
    MUL,
    DIV,

    // logic
    AND,
    OR,
    XOR,
    NOT,

    // branching
    JMP,
    CMP,
    JE,
    JNE,
    JG,
    JGE,
    JL,
    JLE,

    // procedures
    CALL,
    RET,

    // stack
    POP,
    PUSH,

    // system control
    OUT,
    HLT
};

#endif

