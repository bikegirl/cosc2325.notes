#include "INV.h"

INV::INV() {
    iReg = 0;   // input holding register
    oReg = 1;   // output holding register
}

INV::tick() {
    oReg = !iReg;
}
