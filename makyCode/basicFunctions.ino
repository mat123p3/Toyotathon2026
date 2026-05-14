#include "/Users/maky/School/Project/Sumobots26/Toyotathon2026/makyCode/H/motorDriver.h"
#include "/Users/maky/School/Project/Sumobots26/Toyotathon2026/makyCode/H/sensor.h"
#include <atomic>
#include <ios>

//This file is to test the bot's basic functional
// it contains a demo movement function that demoes the different movements of the bot
// a handlingEdge funciton which tests the QT1RC sensors for edge detection and how the bot should react
// and a handleBadgiy funciton which will test the MZ80, JS200 and Sharp sensors on enemy detection
//
// THIS CODE DOES NOT INCORPERATE THE REMOTE START

QT1RC qt1rc;
MZ80 mz80;
JS200 js200;
//add sharp

BTS7960 leftMotor(LR_PWM,LL_PWM,LR_EN,LL_EN);
BTS7960 rightMotor(RR_PWM,RL_PWM,RR_EN,RL_EN);
Drive drive(leftMotor,rightMotor);

//tuning values
const int reverseMS = 300;
const int forwardMS = 300;
const int turnMS = 250;

//BASIC MOVEMENTS
//this will just be one fucntion that will demo the movement of the bot
void demoMove(){
    //drive forward
    drive.forward(FULLSPEED);
    delay(500);
   //turn left
   drive.turnLeft(TURNSPEED);
   delay(500);
   //turn right
   drive.turnRight(TURNSPEED);
   delay(500);
   //reverse
   drive.reverse(FULLSPEED);
   delay(500);
   //pivoting
   drive.pivotLeft(SLOWSPEED);
   delay(400);
   drive.pivotRight(SLOWSPEED);
   delay(400);
   //break
   drive.breakBot()
   delay(300);
   //stop
   drive.stopBot()
   delay(500);
}

void handleEdge(){
    bool leftEdge = qt1rc.isLeftEdge();
    bool rightEdge = qt1rc.isRightEdge();
    bool backEdge = qt1rc.isBackEdge();

    if (!leftEdge && !rightEdge && !backEdge){
        return; //if there is no edge detection, continue
    }
    //if the bot is basically on top of the white line in the arena
    if (leftEdge && rightEdge){
        drive.reverse(FULLSPEED);
        delay(reverseMS);
        drive.pivotRight(SLOWSPEED);
        delay(turnMS * 2);
    //if the QT1RC on the back of the bot detects the white line, the bot should move forward
    }else if (backEdge){
        drive.forward(FULLSPEED);
        delay(forwardMS);
    //if the left QT1RC detects the white line, then the bot should reverse and turn right
    }else if (leftEdge){
        drive.reverse(FULLSPEED);
        delay(reverseMS);
        drive.turnRight(TURNSPEED);
        delay(turnMS);
    //vice versa for the right sensor
    }else{
        drive.reverse(FULLSPEED);
        delay(reverseMS);
        drive.turnLeft(TURNSPEED);
        delay(turnMS);
    }
}

void handleBadGuy(){
    bool mzLeft = mz80.isObjectLeft();
    bool mzRight = mz80.isObjectRight();
    bool jsFront = js200.isObjectFront();
    //add the sharp stuff

    //if there is no reading, the bot will spin to scan
    drive.pivotRight(SLOWSPEED);
    delay(turnMS);
    drive.pivotLeft(SLOWSPEED);
    delay(turnMS);

    //now if there is a bot
    // bot is right in front
    if (mzLeft && mzRight) {
        drive.forward(FULLSPEED);
        return;
    }
    //bad guy on left
    if (mzLeft){
        drive.pivotLeft(TURNSPEED);
        return;
    }
    //bad guy on right
    if (mzRight){
        drive.pivotRight(TURNSPEED);
        return;
    }
    //if the enemy is straight ahead
    if(jsFront){
        drive.forward(FULLSPEED);
        return;
    }

    //missing the sharp function, should be similar to MZ80
    // but instead of pivoting, turn
}

void setup(){
    Serial.begin(9600);

    qt1rc.initSensor();
    mz80.initSensor();
    js200.initSensor();
    drive.begin();
    //put the demo in the setup so it only runs once
    demoMove();
}

void loop(){
    if (qt1rc.isAnyEdge()){
        handleEdge();
        return;
    }
    handleBadGuy();
    delay(50);
}
