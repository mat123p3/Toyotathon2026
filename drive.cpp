#include "drive.h"
#include <Arduino.h>

//private functions, low level
void setLeftMotor(int speed, bool forward) {
  speed = constrain(speed, 0, 255);
  if (forward) {
    analogWrite (LEFT_PWM_FWD, speed);
    analogWrite (LEFT_PWM_REV, 0);
    digitalWrite(LEFT_EN_FWD, HIGH);
    digitalWrite(LEFT_EN_REV, HIGH);
  } else {
    analogWrite (LEFT_PWM_FWD, 0);
    analogWrite (LEFT_PWM_REV, speed);
    digitalWrite(LEFT_EN_FWD, HIGH);
    digitalWrite(LEFT_EN_REV, HIGH);
  }
}

void setRightMotor(int speed, bool forward) {
  speed = constrain(speed, 0, 255);
  if (forward) {
    analogWrite (RIGHT_PWM_FWD, 0);
    analogWrite (RIGHT_PWM_REV, speed);
    digitalWrite(RIGHT_EN_FWD, HIGH);
    digitalWrite(RIGHT_EN_REV, HIGH);
  } else {
    analogWrite (RIGHT_PWM_FWD, speed);
    analogWrite (RIGHT_PWM_REV, 0);
    digitalWrite(RIGHT_EN_FWD, HIGH);
    digitalWrite(RIGHT_EN_REV, HIGH);
  }
}

//public functions, high level
void motorsInit() {
  pinMode(LEFT_PWM_FWD, OUTPUT);
  pinMode(LEFT_PWM_REV, OUTPUT);
  pinMode(LEFT_EN_FWD, OUTPUT);
  pinMode(LEFT_EN_REV, OUTPUT);
  pinMode(RIGHT_PWM_FWD, OUTPUT);
  pinMode(RIGHT_PWM_REV, OUTPUT);
  pinMode(RIGHT_EN_FWD, OUTPUT);
  pinMode(RIGHT_EN_REV, OUTPUT);
  stopMotors();
}

void moveForward(int speed) {
  setLeftMotor (speed, true);
  setRightMotor(speed, true);
}

void moveBackward(int speed) {
  setLeftMotor (speed, false);
  setRightMotor(speed, false);
}

void spinCenter(int speed, bool clockwise) {
  //clockwise  = left fwd  + right rev
  //anti-clockwise = left rev  + right fwd
  setLeftMotor (speed, clockwise);
  setRightMotor(speed, !clockwise);
}

void spinSide(int speed, bool leftSide) {
  if (leftSide) {
    //pivot on left wheel: left motor stopped, right motor forward
    setLeftMotor (0, true);
    setRightMotor(speed, true);
  } else {
    //pivot on right wheel: right motor stopped, left motor forward
    setLeftMotor (speed, true);
    setRightMotor(0, true);
  }
}

void stopMotors() {
  analogWrite (LEFT_PWM_FWD, 0);
  analogWrite (LEFT_PWM_REV, 0);
  digitalWrite(LEFT_EN_FWD, LOW);
  digitalWrite(LEFT_EN_REV, LOW);
  analogWrite (RIGHT_PWM_FWD, 0);
  analogWrite (RIGHT_PWM_REV, 0);
  digitalWrite(RIGHT_EN_FWD, LOW);
  digitalWrite(RIGHT_EN_REV, LOW);
}
