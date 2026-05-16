#include <Arduino.h>
#include <stdint.h>

#include "drive.h"

void drive_init( struct driver *drv )
{
    pinMode( drv->l.pwm_f_pin, OUTPUT );
    pinMode( drv->l.pwm_f_en, OUTPUT );
    pinMode( drv->l.pwm_b_pin, OUTPUT );
    pinMode( drv->l.pwm_b_en, OUTPUT );
    pinMode( drv->r.pwm_f_pin, OUTPUT );
    pinMode( drv->r.pwm_f_en, OUTPUT );
    pinMode( drv->r.pwm_b_pin, OUTPUT );
    pinMode( drv->r.pwm_b_en, OUTPUT );
    analogWrite( drv->l.pwm_f_pin, 0 );
    digitalWrite( drv->l.pwm_f_en, HIGH );
    analogWrite( drv->l.pwm_b_pin, 0 );
    digitalWrite( drv->l.pwm_b_en, HIGH );
    analogWrite( drv->r.pwm_f_pin, 0 );
    digitalWrite( drv->r.pwm_f_en, HIGH );
    analogWrite( drv->r.pwm_b_pin, 0 );
    digitalWrite( drv->r.pwm_b_en, HIGH );
}

void drive_move( struct driver *drv, uint8_t p, int8_t d )
{
    drive_reset( drv );
    uint8_t pwm_tgt_l = ( !d ) ? drv->l.pwm_b_pin : drv->l.pwm_f_pin;
    uint8_t pwm_tgt_r = ( !d ) ? drv->r.pwm_b_pin : drv->r.pwm_f_pin;
    analogWrite( pwm_tgt_l, p );
    analogWrite( pwm_tgt_r, p );
}

void drive_move( struct driver *drv, uint8_t p, int8_t d, float r, int8_t c )
{
    r = constrain( r, 0.0, 1.0 );
    drive_reset( drv );
    uint8_t pwm_tgt_l = ( !d ) ? drv->l.pwm_b_pin : drv->l.pwm_f_pin;
    uint8_t pwm_tgt_r = ( !d ) ? drv->r.pwm_b_pin : drv->r.pwm_f_pin;
    if( !c )
    {
        analogWrite( pwm_tgt_l, p * c );
        analogWrite( pwm_tgt_r, p );
    }
    else
    {
        analogWrite( pwm_tgt_l, p );
        analogWrite( pwm_tgt_r, p * c );
    }
}

void drive_spin( struct driver *drv, uint8_t p, uint8_t c )
{
    drive_reset( drv );
    uint8_t pwm_tgt_l = ( c == 0 ) ? drv->l.pwm_b_pin : drv->l.pwm_f_pin;
    uint8_t pwm_tgt_r = ( c == 0 ) ? drv->r.pwm_f_pin : drv->r.pwm_b_pin;
    analogWrite( pwm_tgt_l, p );
    analogWrite( pwm_tgt_r, p );
}

void drive_lock( struct driver *drv )
{
    digitalWrite( drv->l.pwm_f_pin, HIGH );
    digitalWrite( drv->l.pwm_b_pin, HIGH );
    digitalWrite( drv->r.pwm_f_pin, HIGH );
    digitalWrite( drv->r.pwm_b_pin, HIGH );
}
