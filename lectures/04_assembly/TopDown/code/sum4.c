#include <stdio.h>

unsigned int data[] = {
    5,3,7,10,42,6,22, 15, 32
};

int cnt;
int sum;
int flag;
unsigned int odd = 0;

int main( void ) {
        cnt = 0;
label1: flag = ( cnt == 9 );
        if( flag ) goto label2;
        if( !odd ) goto label3;
        sum += data[ cnt ];
label3: odd = !odd;
        cnt++;
        printf( "%d %d\n", cnt, sum );
        goto label1;
label2: printf( "%d %d\n", cnt, sum );
}

