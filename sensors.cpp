#include "sensors.h"
#include "pinouts.h"
#include "sharp.h"
#include <Arduino.h>

int init_sensors()
{
    if( sharp_init() < 0 )
    {
        return -1;
    }
    return 0;
}

void read_sensors()
{
    _analog_senses[ L_SHARP_BUF ] = sharp_read( SHARPL );
    _analog_senses[ R_SHARP_BUF ] = sharp_read( SHARPR );

    _digital_sense[ SIDE_L_BUF ] = digitalRead( SIDEL );
    _digital_sense[ SIDE_R_BUF ] = digitalRead( SIDER );
    _digital_sense[ FRONT_BUF ] = digitalRead( LONG );
}
