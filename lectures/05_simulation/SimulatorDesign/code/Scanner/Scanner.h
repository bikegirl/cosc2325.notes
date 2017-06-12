#pragma once
#include <fstream>

class Scanner {
    public:
        // constructor
        Scanner();

        // deconstructor
        ~Scanner();

        // accessors
        bool setFile(char[]);
        char getc();
    private:
        std::ifstream fin;
        char c;
};

