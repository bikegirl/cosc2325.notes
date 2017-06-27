#include <iostream>
#include <fstream>
using namespace std;

#include "mnemonics.h"

struct INST {
    int mnemonic;
    int mod1;       // mode for op1
    int reg1;       // register for op1
    int mod2;       // mode for op2
    int reg2;       // register for op2
    int oper;       // optional operand
};

INST testcode[] = {
    { MOV, 3, 1, 1, 0, 15 },    // 00:      MOV R1, 15
    { MOV, 3, 2, 1, 0, 0 },     // 02:      MOV R2, 0
    { OUT, 4, 2, 0, 0, 0 },     // 04: LP1: OUT [R2]
    { ADD, 4, 2, 1, 0, 1 },     // 05:      ADD [R1], 1
    { CMP, 4, 2, 1, 0, 20 },    // 07:      CMP [R2], 20
    { JNE, 1, 0, 0, 0, 4 },     // 09:      JNE LP1
    { HLT, 0, 0, 0, 0, 0 },     // 10:      HLT
};

int packer(INST inst) {
    int res = 0;
    res += inst.mnemonic << 12;
    res += inst.mod1 << 9;
    res += inst.reg1 << 6;
    res += inst.mod2 << 3;
    res += inst.reg2;
    return res;
}

int main(int argc, char *argv[]) {
    cout << "Creating \"test.cal\"" << endl;
    ofstream fout;
    int inst;
    int addr = 0;

    fout.open("test.cal", ios::out);
    if(fout.is_open()) {
        for(int i=i;i<7;i++) {
            // fout << "addr: " << addr << " ";
            inst = packer(testcode[i]);     // basic packer inst
            fout << inst << " ";
            addr++;
            if(    (testcode[i].mod1 == 1) 
                || (testcode[i].mod1 == 2)
                || (testcode[i].mod1 == 5)
            ) {
                fout << testcode[i].oper;
                addr++;
            }
            if(    (testcode[i].mod2 == 1) 
                || (testcode[i].mod2 == 2)
                || (testcode[i].mod2 == 5)
            ) {
                fout << testcode[i].oper;
                addr++;
            }
            fout << endl;
        }
    }
}
