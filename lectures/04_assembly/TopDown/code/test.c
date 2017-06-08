#define REV(a,b,c) b; a;
#define DBs(label, val) char * label = val
#define CALLp( a,b )    a(b)
    DBs( msg1, "%d" )
    CALLp( printf, cnt )
