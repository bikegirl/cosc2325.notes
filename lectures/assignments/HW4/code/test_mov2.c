// time_move.c - simple experiment to time a single mov instruction
#include <stdio.h>
#include "rdtsc.h"

int main(int argc, char *argv[]) {
    unsigned long long start, stop, basic, overhead;

    start = rdtsc();
    asm volatile(
        "mov $0, %rax"
    );
    stop = rdtsc();
    basic = stop - start;

    start = rdtsc();
    stop = rdtsc();
    overhead = stop - start;
    printf("MOV took %lld cycles\n", basic-overhead);
}

