#ifndef __DRIVE_H__
#define __DRIVE_H__

#include "pinouts.h"

//left motor
#define LEFT_PWM_FWD MOTOR0PWM0   // PWM forward
#define LEFT_PWM_REV MOTOR0PWM1   // PWM reverse
#define LEFT_EN_FWD MOTOR0EN0    // Enable/dir A
#define LEFT_EN_REV MOTOR0EN1    // Enable/dir B

//right motor
#define RIGHT_PWM_FWD MOTOR1PWM0   // PWM forward
#define RIGHT_PWM_REV MOTOR1PWM1   // PWM reverse
#define RIGHT_EN_FWD MOTOR1EN0    // Enable/dir A
#define RIGHT_EN_REV MOTOR1EN1    // Enable/dir B

//high level functions
void motorsInit();
//both motors going forwards
void moveForward(int speed);
//both motors going backwards
void moveBackward(int speed);
//spin in place: clockwise = right motor back / left motor fwd
void spinCenter(int speed, bool clockwise);
//pivot on one side: leftSide=true pivots on the left wheel
void spinSide(int speed, bool leftSide);
//break
void stopMotors();

//low level functions
void setLeftMotor(int speed, bool forward);
void setRightMotor(int speed, bool forward);

#endif
