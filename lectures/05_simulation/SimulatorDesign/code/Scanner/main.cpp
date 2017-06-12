#include <iostream>
#include "Scanner.h"

#define BUFSIZE 256
int main() {
    std::cout << "Enter file name: ";
    char filename[BUFSIZE];
    std::cin.get(filename,BUFSIZE);
    char ch;

    // create scanner
    Scanner s;

    // open file
    if (!s.setFile(filename) ) {
        std::cout << "File open error: " << filename << std::endl;
        std::exit(1);
    }
    while( (ch = s.getc()) ) {
        std::cout << ch << "(" << (int)ch << ")" << std::endl;
    }
    std::cout << "reached end of file" << std::endl;
    return 0;
} 
