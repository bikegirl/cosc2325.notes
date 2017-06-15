#include <iostream>
#include <fstream>
#include "Scanner.h"

Scanner::Scanner() {}

Scanner::~Scanner() {
    if( fin.good() )
        std::cout << "closing stream" << std::endl;
        fin.close();
}

bool Scanner::setFile(char filename[]) {
    std::cout << "...opening stream: " << filename << std::endl;
    std::ifstream fin(filename);
    if( fin.good() ) {
        std::cout << "stream is open" << std::endl;
        return true;
    }
    return false;
}

char Scanner::getc(void) {
    char ch;
    fin.get(ch);
    return ch;
}
 
