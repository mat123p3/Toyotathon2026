#include <Arduino.h>
#include "drive.h"
#include "pinouts.h"
#include "remote.h"
#include "sensors.h"
#include "toyotathon.h"


struct driver drv = {   (struct motor){ MOTOR0PWM0, MOTOR0EN0, MOTOR0PWM1, MOTOR0EN1 },
                        (struct motor){ MOTOR1PWM0, MOTOR1EN0, MOTOR1PWM1, MOTOR1EN1 } };


long next_target;

void setup() {
    drive_init( &drv );
    next_target = millis() + 1000;
}

void loop() {
    drive_move( &drv, 200, 1 );
    delay(1000);
    drive_move( &drv, 200, -1 );
    delay(1000);
    drive_spin( &drv, 200, 1);
    delay(1000);
    drive_spin( &drv, 200, -1 );
    delay(1000);
    drive_move( &drv, 200, 1, 0.5 , 1 );
    delay(1000);
    drive_move( &drv, 200, 1, 0.5, -1 );
    delay(1000);
    drive_move( &drv, 200, -1, 0.5, -1 );
    delay(1000);
    drive_move( &drv, 200, -1, 0.5, 1 );
}
