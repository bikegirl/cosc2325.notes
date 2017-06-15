#include <iostream>
using namespace std;

Component s1("s1"), s2("s2"), s3("s3");
    Wire w1, w2, w3;

void circuit() {
    // connect wires to components
    w1.in = &s1;
    w1.out = &s2;

    w2.in = &s2;
    w2.out = $s3;

    w3.in = &s3;
    w3.out = &s1;
}

int main(void) {
    for(int t=0; t<20;t++) {
        w1.read();
        w1.write();
    return 0;
}
