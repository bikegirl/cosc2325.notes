#include <stdio.h>

unsigned int data[] = {
    5,3,7,10,42,6,22, 15, 32
};

int cnt;
int sum;
unsigned int odd = 0;

int main( void ) {
    cnt = 0;
    while( cnt < 9 ) {
        if( odd )        
            sum += data[ cnt ];
        odd = !odd;
        cnt++;
        printf( "%d %d\n", cnt, sum );
    }
}

