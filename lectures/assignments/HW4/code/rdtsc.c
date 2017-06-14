// rdtsc.c - read the RDTSC register on 64-bit processors

#include "rdtsc.h"

unsigned long long rdtsc(void) {
    unsigned long long hi = 0, lo = 0;
    asm volatile("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)lo | (((unsigned long long)hi) << 32));
}

