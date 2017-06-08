#include <stdio.h>
#include "macros.h"

unsigned int data[] = {
    5,3,7,10,42,6,22, 15, 32
};

        RESD( cnt );
        RESD( sum );
        RESD( flag );
        DD( odd, 0 );

MAIN
        MOV( cnt,0 );
label1: CMP( cnt, 9 );
        JZ( label2 );
        CMP( odd, 0 );
        JZ( label3 );;
        sum += data[ cnt ];
label3: NOT( odd );
        INC( cnt );
        printf( "%d %d\n", cnt, sum );
        JMP( label1 );
label2: printf( "%d %d\n", cnt, sum );
        RET

