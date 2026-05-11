#include "sharp.h"
#include "toyotathon.h"
#include <Arduino.h>

int sharp_init( int pin )
{
    return init_lookup( &lt , d_calib, v_calib, sizeof(d_calib) );
}

float sharp_read( int pin )
{
    return lookup_v( &lt , toVoltage( analogRead( pin ) ) );
}
