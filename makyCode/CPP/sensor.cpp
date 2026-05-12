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
    pinMode(R_MZ80, INPUT); //pull up?
    pinMode(L_MZ80, INPUT); //pull up?
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
