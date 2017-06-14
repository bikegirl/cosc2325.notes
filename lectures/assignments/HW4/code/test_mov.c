// time_move.c - simple experiment to time a single mov instruction
#include <stdio.h>
#include "rdtsc.h"

int main(int argc, char *argv[]) {
    unsigned long long start, stop;

    start = rdtsc();
    asm volatile(
        "mov $0, %rax"
    );
    stop = rdtsc();
    printf("MOV took %lld cycles\n", stop-start);
}

