#line 1 "/home/cheese/code/Toyotathon2026/sensors.cpp"
#include <Arduino.h>
#include "sensors.h"
#include "QTRSensors.h"
#include "pinouts.h"
#include "sharp.h"

static QTRSensors q;

void init_sensors()
{
    pinMode( SHARP_L_PIN, INPUT );
    pinMode( SHARP_R_PIN, INPUT );

    pinMode( QTR_L_BUF, INPUT );
    pinMode( QTR_M_BUF, INPUT );
    pinMode( QTR_R_BUF, INPUT );

    pinMode( LINE_L_PIN, INPUT );
    pinMode( LINE_F_PIN, INPUT );
    pinMode( LINE_R_PIN, INPUT );
    pinMode( STARTER_PIN, INPUT );
    pinMode( FRONT_PIN, INPUT );
    pinMode( SIDE_L_PIN, INPUT );
    pinMode( SIDE_R_PIN, INPUT );
}

static uint16_t _qtr_raw[3];
static uint16_t _qtr_thresh = 300;
void read_sensors()
{
    _s_buf[FRONT_BUF] = digitalRead( FRONT_PIN );
    sharp_read( _s_buf + SHARP_L_BUF, (const uint8_t[]){ SHARP_L_PIN, SHARP_R_PIN }, 2 );
    _s_buf[SIDE_L_BUF] = digitalRead( SIDE_L_PIN );
    _s_buf[SIDE_R_BUF] = digitalRead( SIDE_R_PIN );

    _s_buf[QTR_L_BUF] = ( analogRead( LINE_L_PIN ) < _qtr_thresh ) ? 1 : 0;
    _s_buf[QTR_M_BUF] = ( analogRead( LINE_F_PIN ) < _qtr_thresh ) ? 1 : 0;
    _s_buf[QTR_R_BUF] = ( analogRead( LINE_R_PIN ) < _qtr_thresh ) ? 1 : 0;


    Serial.print( _s_buf[QTR_L_BUF] );
    Serial.print( "\t" );
    Serial.print( _s_buf[QTR_M_BUF] );
    Serial.print( "\t" );
    Serial.print( _s_buf[QTR_R_BUF] );
    Serial.println();


}
