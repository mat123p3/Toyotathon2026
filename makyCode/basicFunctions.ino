#include "/Users/maky/School/Project/Sumobots26/Toyotathon2026/makyCode/H/motorDriver.h"
#include "/Users/maky/School/Project/Sumobots26/Toyotathon2026/makyCode/H/sensor.h"
#include <atomic>
#include <ios>

QT1RC qt1rc;
MZ80 mz80;
JS200 js200;
//add sharp

BTS7960 leftMotor(LR_PWM,LL_PWM,LR_EN,LL_EN);
BTS7960 rightMotor(RR_PWM,RL_PWM,RR_EN,RL_EN);
Drive drive(leftMotor,rightMotor);

//tuning values
const int reverseMS = 300;
const int turnMS = 250;

//BASIC MOVEMENTS
//this will just be one fucntion that will demo the movement of the bot
void demoMove(){
    //drive forward
    drive.forward(FULLSPEED);
    delay(500);
   //turn left
   drive.turnLeft();
   delay(500);
   //turn right
   drive.turnRight();
   delay(500);
   //reverse
   drive.reverse(FULLSPEED);
   delay(500);
   //pivoting
   drive.pivotLeft();
   delay(400);
   drive.pivotRight();
   delay(400);
   //break
   drive.breakBot()
   delay(300);
   //stop
   drive.stopBot()
   delay(500);
}
