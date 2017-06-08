#define CMP( d1, d2 )       flag = ( d1 == d2 )
#define JZ( label )         if( flag ) goto label
#define JMP( lab )          goto lab

#define MOV( a,b )          a = b;
#define NOT( val )          val = !val
#define INC( val )          val++

#define DD( n, v)           int n = v
#define DB(n, v)            char *n = v
#define RESD( n )           int n

#define MAIN                int main(void) {
#define RET                 }

#define DD_(lab, ...)       unsigned int lab [] = { __VA_ARGS__ }
#define DDp_( lab, val)     unsigned int *lab = &val[0]

#define DDps( lab)          char *lab
#define CALL( lab )         lab();
#define CALLp0( a )         a( fmt )
#define CALLp1( a )         a( fmt, pdata)
#define DISPLAY             void display() {
#define ADD( a, b)          a += *b
#define SEG( a )            // segment a
