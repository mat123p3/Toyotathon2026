#ifndef __MOTORDRIVER_H_
#define __MOTORDRIVER_H_

#include "pinDeclarations.h"

//speed presets (0-255)
// could always add more ,or make a function that can alter the speed
#define FULLSPEED 255
#define SLOWSPEED 120
#define TURNSPEED 180

//motor driver BTS7960 with driver functions
//Motor driver class
class BTS7960{
    public:
        BTS7960(int rPWM, int lPWM, int rEN, int lEN);
        void init();
        void forwardBot(int speed);
        void reverseBot(int speed);
        void breakBot();
        void stopBot();

    private:
        int rPwm;
        int lPwm;
        int rEn;
        int lEn;
};

//Driver functions
class Driver{
    public:
        Driver(BTS7960& left, BTS7960& right);
        void begin();
        //all these speeds are preset, could change
        void forward(int speed = FULLSPEED);
        void reverse(int speed = FULLSPEED);
        void turnLeft(int speed = SLOWSPEED);
        void turnRight(int speed = SLOWSPEED);
        void pivotLeft(int speed = SLOWSPEED);
        void pivotRight(int speed = SLOWSPEED);
        void stopBot();
        void breakBot();
    private:
        BTS7960& l;
        BTS7960& r;
};
#endif
