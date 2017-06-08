#include <stdio.h>
#include "macros.h"

        SEG(.data)

        DD_(data, 5,3,7,10,42,6,22, 15, 32 );
        DDp_( dptr,data );

        RESD( cnt );
        RESD( sum );
        RESD( flag );
        DD( odd, 0 );

        DB( msg1,"%d" );
        DB( msg2," " );
        DB( msg3,"\n" );
        DDps( fmt );
        DD( pdata,0 );

        SEG(.text)

DISPLAY
        MOV( fmt,msg1 );
        MOV( pdata,cnt )
        CALLp1( printf );
        MOV( fmt,msg2 );
        CALLp0( printf );
        MOV( fmt,msg1 );
        MOV( pdata, sum );
        CALLp1( printf );
        MOV( fmt,msg3 );
        CALLp0( printf );
        RET

MAIN
        MOV( cnt,0 );
label1: CMP( cnt, 9 );
        JZ( label2 );
        CMP( odd, 0 );
        JZ( label3 );;
        ADD( sum, (dptr + cnt) );
label3: NOT( odd );
        INC( cnt );
        CALL( display );
        JMP( label1 );
label2: CALL( display );
        RET

