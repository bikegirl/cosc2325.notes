#include <stdio.h>

unsigned int data[] = {
    5,3,7,10,42,6,22, 15, 32
};

int cnt;
int sum;
unsigned int odd = 0;:set number
uuu

int main( void ) {
        cnt = 0;
label1: if( cnt >= 9 ) goto label2;
        if( odd )        
            sum += data[ cnt ];
        odd = !odd;
        cnt++;
        printf( "%d %d\n", cnt, sum );
        goto label1;
label2: printf( "%d %d\n", cnt, sum );
}

