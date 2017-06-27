#include <iostream>
using namespace std;
#include "../controller/mnemonics.h"

int main(int argc, char *argv[]) {
    int mnemonic;
    int mode1, mode2;
    int reg1, reg2;
    int inst;

    // packing demo

    // setup
    mnemonic = ADD;
    mode1 = 3;                  // register ref
    reg1 = 4;                   // r4
    mode2 = 4;                  // register indirect
    reg2 = 7;                   // r7

    cout << mnemonic << endl;
    cout << mode1 << endl;
    cout << reg1 << endl;
    cout << mode2 << endl;
    cout << reg2 << endl;

    inst = 0;
    inst += mnemonic << 12;     // slide left 12 bits
    inst += mode1 << 9;         // slide left 9 bits
    inst += reg1 << 6;          // slide left 6 bits
    inst += mode2 << 3;         // slide left 3 bits
    inst += reg2;               // add in the final result
    cout << inst << endl;

    // unpacking demo
    mnemonic = (inst >> 12) & 0x1E;
    mode1 = (inst >> 9) & 0x07;
    reg1 = (inst >> 6) & 0x07;
    mode2 = (inst >> 3) & 0x7;
    reg2 = (inst & 0x7);

    cout << mnemonic << endl;
    cout << mode1 << endl;
    cout << reg1 << endl;
    cout << mode2 << endl;
    cout << reg2 << endl;

}

