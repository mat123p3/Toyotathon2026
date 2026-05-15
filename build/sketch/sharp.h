#line 1 "/home/cheese/code/Toyotathon2026/sharp.h"
#ifndef __SHARP_H__
#define __SHARP_H__

#include <Arduino.h>
#include <stdint.h>

#include "toyotathon.h"

//use this for distance
/*
const float d_calib[] = {
    15, 20, 25, 30, 35, 40, 45, 50, 55, 60,
    65, 70, 75, 80, 85, 90, 100, 110, 120, 130
};
const float v_calib[] = {
    2.6, 2.3, 2.39, 1.87, 1.54, 1.35, 1.25, 1.15, 1.07, 1.01,
    0.95, 0.88, 0.85, 0.78, 0.77, 0.78, 0.74, 0.72, 0.68, 0.6
};
*/

/*
 * @brief           Read n sharp sensors. Output values to p.
 *                  Output is 2 if very close, 0 if too far, 1 otherwise.
 * @param[out]  d   Pointer to the buffer where data is outputted.
 * @param[in]   p   Pointer to the buffer where pins to read are located.
 * @param[in]   n   Amount of sensors to read.
 */
inline void sharp_read( uint8_t *d, const uint8_t *p, size_t n )
{
    for( int i = 0; i < n; i++ )
    {
        float v = toVoltage( analogRead( p[i] ) );
        if( v > 2.2 ){ d[i] = 2; }
        else if( v > 0.6 ){ d[i] = 1; }
        else { d[i] = 0; }
    }
}

#endif
