#pragma once

class Component {
    public:
        Component(string cn);
        string name;
        int reg;
        void tick();    // microtick function 
        void setReg(int val);
        int getReg(void);
};
      
