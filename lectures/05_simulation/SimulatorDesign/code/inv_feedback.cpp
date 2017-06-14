#include <iostream>
#include <iomanip>
using namespace std;
int s_time = 0;       // nanoseconds

bool inverter(bool input) {
    s_time += 2;
    return !input;
}

int main(void) {
    cout << "Inverter Feedback Simulator" << endl;

    bool wire = true;   // initial value on the wire

    // simulation loop
    for (int c = 0; c < 10; c++) {
        cout << "t" << setw(3) << setfill('0') << s_time << ": " << wire << endl;
        wire = inverter(wire);
    }
}

        
