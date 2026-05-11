#include <Arduino.h>
#include "pinouts.h"

// Motor control pins To be revised based on actual wiring
const int leftMotorPin1 = 2;
const int leftMotorPin2 = 3;
const int rightMotorPin1 = 4;
const int rightMotorPin2 = 5;
const int leftEnable = 9;
const int rightEnable = 10;

void setup() {
  // Set motor pins as outputs 
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(leftEnable, OUTPUT);
  pinMode(rightEnable, OUTPUT);
}

        void loop() {
        // Example usage
        moveForward(255);
        delay(1000);
        stopMotors();
        delay(500);
        moveBackward(255);
        delay(1000);
        stopMotors();
        delay(500);
        spinCenter(200, true); // clockwise
        delay(1000);
        stopMotors();
        delay(500);
        spinSide(200, true); // spin on left side
        delay(1000);
        stopMotors();
        delay(500);
        }

// Driver functions for basic movement

void moveForward(int speed) {
  analogWrite(leftEnable, speed);
  analogWrite(rightEnable, speed);
  digitalWrite(leftMotorPin1, HIGH);
  digitalWrite(leftMotorPin2, LOW);
  digitalWrite(rightMotorPin1, HIGH);
  digitalWrite(rightMotorPin2, LOW);
}

void moveBackward(int speed) {
  analogWrite(leftEnable, speed);
  analogWrite(rightEnable, speed);
  digitalWrite(leftMotorPin1, LOW);
  digitalWrite(leftMotorPin2, HIGH);
  digitalWrite(rightMotorPin1, LOW);
  digitalWrite(rightMotorPin2, HIGH);
}

void spinCenter(int speed, bool clockwise) {
  analogWrite(leftEnable, speed);
  analogWrite(rightEnable, speed);
  if (clockwise) {
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, HIGH);
  } else {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, HIGH);
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  }
}

void spinSide(int speed, bool leftSide) {
  if (leftSide) {
    // Spin on left side: right motor forward, left motor stop
    analogWrite(leftEnable, 0);
    analogWrite(rightEnable, speed);
    digitalWrite(rightMotorPin1, HIGH);
    digitalWrite(rightMotorPin2, LOW);
  } else {
    // Spin on right side: left motor forward, right motor stop
    analogWrite(leftEnable, speed);
    analogWrite(rightEnable, 0);
    digitalWrite(leftMotorPin1, HIGH);
    digitalWrite(leftMotorPin2, LOW);
  }
}

void stopMotors() {
  analogWrite(leftEnable, 0);
  analogWrite(rightEnable, 0);
}