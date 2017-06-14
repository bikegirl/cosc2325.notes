#include <stdio.h>

#include "rdtsc.h"

int main(void) {
    unsigned long long int start, stop;    
    start = rdtsc();
    sleep(1);
    stop = rdtsc();    
    printf("clock frequency = %llu\n", stop - start);
}
