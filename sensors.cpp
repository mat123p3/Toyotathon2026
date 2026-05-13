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

    q.setTypeAnalog();
    q.setSensorPins( (const uint8_t[]){LINE_L_PIN, LINE_F_PIN, LINE_R_PIN }, 3 );
    pinMode( LED_BUILTIN, OUTPUT );
    digitalWrite( LED_BUILTIN, HIGH );
    for( int i = 0; i < CALIBRATION_COUNT; i++ )
    {
        q.calibrate();
    }
    digitalWrite( LED_BUILTIN, LOW );

    pinMode( LINE_L_PIN, INPUT );
    pinMode( LINE_F_PIN, INPUT );
    pinMode( LINE_R_PIN, INPUT );
    pinMode( STARTER_PIN, INPUT );
    pinMode( FRONT_PIN, INPUT );
    pinMode( SIDE_L_PIN, INPUT );
    pinMode( SIDE_R_PIN, INPUT );
}

static uint16_t _qtr_raw[3];
static uint16_t _qtr_thresh = 100;
void read_sensors()
{
    _s_buf[FRONT_BUF] = digitalRead( FRONT_PIN );
    sharp_read( _s_buf + SHARP_L_BUF, (const uint8_t[]){ SHARP_L_PIN, SHARP_R_PIN }, 2 );
    _s_buf[SIDE_L_BUF] = digitalRead( SIDE_L_PIN );
    _s_buf[SIDE_R_BUF] = digitalRead( SIDE_R_PIN );
    q.readCalibrated( _qtr_raw );
    for( int i = 0; i < 3; i++ )
    {
        _s_buf[i + QTR_L_BUF] = ( _qtr_raw[i] < _qtr_thresh ) ? 1 : 0;
    }
}
