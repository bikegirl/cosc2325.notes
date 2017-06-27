#include <iostream>
using namespace std;
#include "Controller.h"
#Include <string>

string fname;
bool DEBUG = false;

// process the command line looking for the debug flag and code file name
void process_options(int argc, char *argv[]) {
    // check command line
    if(argc == 1 || argc > 3) {
        cout << "Usage: cpusim [-d] codefile" << endl;
        exit(EXIT_FAILURE);
    } else if(argc == 2) {
        if(argv[1][0] == '-') {
            cout << "file name required" << endl;
            exit(EXIT_FAILURE);
        } else
            fname = argv[1];
    } else {
        if(strcmp(argv[1],"-d")==0) {
            fname = argv[2];
            DEBUG = true;
            cout << "\tDebugging enabled" << endl;
        }
    }
}

int main(int argc, char *argv[]) {
    cout << "CPUsim v3 CPU running" <<  endl;
    process_options(argc, argv);
    Machine cycsi(DEBUG);                      // create the machine
    cycsi.load_code("test.code"); 
    cycsi.load_data("test.data");
    int ticks = cycsi.run();

    cout << "\...processing finished: (" << ticks << " ticks)" << endl;
}
