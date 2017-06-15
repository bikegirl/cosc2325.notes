#pragma once
#include "Component.h"

class Wire {
    public: // not  good design
        // attributes
        int state;
        Component *in;  
        Component *out;
        
        //accessors
        int read(void);

        // mutators
        void write(int value);
};
