#pragma once
#include <cstdint>

class ALU {
    public:
        ALU();
        void execute(uint16_t op1, uint16_t op2, int op);
        uint16_t read_valid( void );
        bool carry( void );
    private:
        uint16_t val;
        bool carry_flag;
};

