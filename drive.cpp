#include <Arduino.h>
#include <stdint.h>

#include "drive.h"

void drive_init( struct driver *drv )
{
    analogWrite( drv->l.pwm_f_pin, 0 );
    digitalWrite( drv->l.pwm_f_en, HIGH );
    analogWrite( drv->l.pwm_b_pin, 0 );
    digitalWrite( drv->l.pwm_b_en, HIGH );
}

void drive_move( struct driver *drv, uint8_t p, int8_t d )
{
    uint8_t pwm_tgt_l = ( d < 0 ) ? drv->l.pwm_b_pin : drv->l.pwm_f_pin;
    uint8_t pwm_tgt_r = ( d < 0 ) ? drv->r.pwm_b_pin : drv->r.pwm_f_pin;
    analogWrite( pwm_tgt_l, p );
    analogWrite( pwm_tgt_r, p );
}

void drive_move( struct driver *drv, uint8_t p, int8_t d, float r, int8_t c )
{
    r = constrain( c, 0.0, 1.0 );
    uint8_t pwm_tgt_l = ( d < 0 ) ? drv->l.pwm_b_pin : drv->l.pwm_f_pin;
    uint8_t pwm_tgt_r = ( d < 0 ) ? drv->r.pwm_b_pin : drv->r.pwm_f_pin;
    if( c < 0 )
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
    uint8_t pwm_tgt_l = ( c < 0 ) ? drv->l.pwm_b_pin : drv->l.pwm_f_pin;
    uint8_t pwm_tgt_r = ( c < 0 ) ? drv->r.pwm_f_pin : drv->r.pwm_b_pin;
    analogWrite( pwm_tgt_l, p );
    analogWrite( pwm_tgt_r, p );
}

void drive_lock( struct driver *drv )
{
    digitalWrite( drv->l.pwm_f_pin, LOW );
    digitalWrite( drv->l.pwm_b_pin, LOW );
    digitalWrite( drv->r.pwm_f_pin, LOW );
    digitalWrite( drv->r.pwm_b_pin, LOW );
}
