#pragma once
#include <cstdint>

const int MAX_SIZE = 1000;

class Memory {
    public:
        // constructor
        Memory(int read_time, int write_time);

        // accessors
        void read(uint64_t address, int size);
        uint64_t read_valid(void);
        bool ready(void);

        // mutators
        void write(uint64_t address, int size, uint64_t data);
    private:
        uint8_t mem[MAX_SIZE];
        int read_access_time;
        int write_access_time;
};

