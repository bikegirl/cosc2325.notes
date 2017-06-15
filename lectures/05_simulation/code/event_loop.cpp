#include <iostream>
using namespace std;

int s_time = 0;

bool NOT(bool in) {
    return !in;
}

bool AND(bool in1, bool in2) {
    return in1 & in2;
}

int main(void) {
    //start outer loop. new input vector each pass:
    bool a = false;     // input A
    bool b = true;      // input B
    bool c = false;     // output C
    bool w = false;     // wire g1 - g2
   
    // generate header line 
    cout << "      |A|B| |W|C| |W|C|" << endl;
    cout << "      ----- ----- ----" << endl;

    // start the basic simulation loop, new input vector each pass
    for(int cycle=0;cycle<10;cycle++) {
        if( cycle % 2 == 0 ) b = !b;        // update vector in a simple pattern
        if(cycle>0) a = ! a;

        // show time and inputs
        cout << "t" << cycle << ": ";
        cout << "  |" << a << "|" << b << "|";

        // inner loop over all components, check all inputs
        bool old_w = false; 
        while(true) {
            // assume no changes on this pass
            bool changed = false;

            // sumulate all gates in the circuit
            w = NOT(a);
            c = AND( w, b );

            // check all inputs for changes
            if(w != old_w) { 
                changed = true;
                old_w = w;          // for next pass
            }
            cout << " |" << w << "|" << c << "|";
            if(!changed) break;
            
        }
        cout << endl;
    }
}

