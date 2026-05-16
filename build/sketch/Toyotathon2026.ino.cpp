#line 1 "/home/cheese/code/Toyotathon2026/Toyotathon2026.ino"
#include <Arduino.h>
#include "drive.h"
#include "pinouts.h"
#include "remote.h"
#include "sensors.h"
#include "toyotathon.h"

STATE r_st = SEARCHING;

#define DRIVE_SPEED 100

struct scheduler sch;

struct driver drv = {   (struct motor){ MOTOR0PWM1, MOTOR0EN1, MOTOR0PWM0, MOTOR0EN0 },
                        (struct motor){ MOTOR1PWM0, MOTOR1EN0, MOTOR1PWM1, MOTOR1EN1 } };

void sweep_left();
void sweep_right();

#line 32 "/home/cheese/code/Toyotathon2026/Toyotathon2026.ino"
void kill_switch();
#line 38 "/home/cheese/code/Toyotathon2026/Toyotathon2026.ino"
void setup();
#line 52 "/home/cheese/code/Toyotathon2026/Toyotathon2026.ino"
void loop();
#line 20 "/home/cheese/code/Toyotathon2026/Toyotathon2026.ino"
void sweep_left()
{
    drive_move( &drv, 255, 1, 0.8, 0 );
    sch = (struct scheduler){ .f = sweep_right, .t = millis() + 500 };
}

void sweep_right()
{
    drive_move( &drv, 255, 1, 0.8, 1 );
    sch = (struct scheduler){ .f = sweep_left, .t = millis() + 500 };
}

void kill_switch()
{
    drive_lock( &drv );
    exit(0);
}

void setup() {
    drive_init( &drv );
    while( !digitalRead( STARTER_PIN ) );
    init_remote( STARTER_PIN , kill_switch );
    init_sensors();
    drive_move( &drv, DRIVE_SPEED, 1 );
    r_st = TRACKING;
}

static uint8_t line;
static uint8_t radar;
static uint8_t lsd;
static uint8_t agro;

void loop() {
    read_sensors();
    line = on_line();
    radar = find_enemy();
    if( radar & 0b01110 )
    {
        if( radar & 0b00100 ) lsd = 0;
        else if( radar & 0b01000 ) lsd = 1;
        else lsd = 2;
    }
    if( r_st != REPO && ( line & 0b101 ) ){
        r_st = ON_LINE;
    }
    switch( r_st )
    {
        case ON_LINE:
            r_st = REPO;
            drive_move( &drv, 200, 0 );
            delay(200);
            if( line & 0b001 )
            {
                drive_spin( &drv, 60, 0 );
            }
            else
            {
                drive_spin( &drv, 60, 1 );
            }
            break;
        case REPO:
            if( radar & 0b01110 || line & 0b010 )
            {
                r_st = TRACKING;
                drive_lock( &drv );
                delay(25);
            }
            break;
        case TRACKING:
            if( !( radar & 0b01110 ) )
            {
                r_st = TRACKING_ADJUST;
                agro = 0;
            }
            break;
        case TRACKING_ADJUST:
            if( lsd == 0 )
            {
                drive_move( &drv, DRIVE_SPEED, 1 );
                r_st = TRACKING;
            }
            else if( radar & 0b01010 )
            {
                constrain( ++agro, 0, 200 );
                drive_move( &drv, DRIVE_SPEED, 1, 1 - fap( agro, 0, 200, 0.4, 1 ), ( lsd == 1 ) ? 1 : 0 );
            }
            break;
        default:
            break;

        /*
        case SEARCHING:
            sweep_left();
            if( !radar ) break;
            else if( radar & 0b10001 )
            {
                sch.f = NULL;
                drive_spin( &drv, 200, ( radar & 0b1 ) ? 0 : 1 );
            }
            r_st = PRE_TRACKING;
            break;
        case PRE_TRACKING:
            if( radar & 0b1110 )
            {
                r_st = TRACKING;
                drive_move( &drv, 255, 1 );
            }
            break;
        case TRACKING:
            if( millis() - 300 > lst )
            {
                r_st = SEARCHING;
                break;
            }
            if( !(radar & 0b00100) )
            {
                r_st = TRACKING_ADJUST;
                break;
            }
        case TRACKING_ADJUST:
            if( lsd == 0 )
            {
                drive_move( &drv, 255, 1 );
                r_st = TRACKING;
                break;
            }
            else if( lsd == 1 )
            {
                drive_move( &drv, 200, 1, 0.8, 0 );
                break;
            }
            else
            {
                drive_move( &drv, 200, 1, 0.8, 1 );
                break;
            }
        */
    }
}

