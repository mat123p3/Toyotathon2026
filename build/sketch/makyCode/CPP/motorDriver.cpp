#line 1 "/home/cheese/code/Toyotathon2026/makyCode/CPP/motorDriver.cpp"
#include "/Users/maky/School/Project/Sumobots26/Toyotathon2026/makyCode/H/motorDriver.h"
//#include <system_error>

//single motor
BTS7960::BTS7960(int rPWM, int lPWM, int rEN, int lEN)
: rPwm(rPWM),lPwm(lPWM), rEn(rEN), lEn(lEN){}

void BTS7960::init(){
    pinMode(rPwm, OUTPUT);
    pinMode(lPwm, OUTPUT);
    pinMode(rEn, OUTPUT);
    pinMode(lEn, OUTPUT);
    digitalWrite(rEn, HIGH);
    digitalWrite(lEn, HIGH);
    stopBot();
}
void BTS7960::forwardBot(int speed){
    speed = constrain(speed, 0, 255);
    analogWrite(lPwm, 0);
    analogWrite(rPwm, speed);
}
void BTS7960::reverseBot(int speed){
    speed = constrain(speed, 0, 255);
    analogWrite(rPwm, 0);
    analogWrite(lPwm, speed);
}
void BTS7960::stopBot(){
    analogWrite(rPwm, 0);
    analogWrtie(lPwm, 0);
}
void BTS7960::breakBot(){
    digitalWrite(rEn, LOW);
    digitalWrite(lEn, LOW);
}

//driver differential
Driver::Driver(BTS7960& left, BTS7960& right)
: l(left), r(right) {}

void Driver::begin(){
    l.init();
    r.init();
}
void Driver::forward(int speed){
    l.forwardBot(speed);
    r.forwardBot(speed);
}
void Driver::reverse(int speed){
    l.reverseBot(speed);
    r.reverseBot(speed);
}
void Driver::stopBot(){
    l.stopBot();
    r.stopBot();
}
void Driver::breakBot(){
    l.breakBot();
    r.breakBot();
}
void Driver::turnLeft(int speed){
    l.forwardBot(speed/2);
    r.forwardBot(speed);
}
void Driver::turnRight(int speed){
    l.forwardBot(speed);
    r.forwardBot(speed/2);
}
void Driver::pivotLeft(int speed){
    l.reverseBot(speed);
    r.forwardBot(speed);
}
void Driver::pivotRight(int speed){
    l.forwardBot(speed);
    r.reverseBot(speed);
}
