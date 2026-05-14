#include "/Users/maky/School/Project/Sumobots26/Toyotathon2026/makyCode/H/sensor.h"

//QT1RC
void QT1RC::initSensor(){
    pinMode(LF_QT1RC, INPUT);
    pinMode(RF_QT1RC, INPUT);
    pinMode(B_QT1RC, INPUT);
}
int QT1RC::readLeft(){
   return analogRead(LF_QT1RC);
}
int QT1RC::readRight(){
   return analogRead(RF_QT1RC);
}
int QT1RC::readBack(){
    return analogRead(B_QT1RC);
}
bool QT1RC::isLeftEdge(){
    return readLeft() < threshold;
}
bool QT1RC::isRightEdge(){
    return readRight() < threshold;
}
bool QT1RC::isBackEdge(){
    return readBack() < threshold;
}
bool QT1RC::isAnyEdge(){
    return isLeftEdge() || isRightEdge() || isBackEdge();
}

//MZ80
void MZ80::initSensor(){
    pinMode(R_MZ80, INPUT_PULLUP);
    pinMode(L_MZ80, INPUT_PULLUP);
    //using pullup, when the sensor are inactive, the internal resistor will pull the pins
    // to HIGH. When an object is detected, it will pull the pin to active LOW.
    // Object -> 0
    // No Object -> 1
    // without the pullup, it will give floating and garbage readings causing bad outputs
}
int MZ80::readLeft(){
    return digitalRead(L_MZ80);
}
int MZ80::readRight(){
    return digitalRead(R_MZ80);
}
bool MZ80::isObjectLeft(){
    return readLeft() == LOW;
}
bool MZ80::isObjectRight(){
    return readRight() == LOW;
}
bool MZ80::isAnyObject(){
    return isObjectLeft() || isObjectRight();
}

//JS200
void JS200::initSensor(){
    pinMode(FR_JS200, INPUT_PULLUP);
}
int JS200::readFront(){
    return digitalRead(FR_JS200);
}
bool JS200::isObjectFront(){
    return readFront() == LOW;
}
