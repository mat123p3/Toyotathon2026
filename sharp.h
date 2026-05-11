#ifndef __SHARP_H__
#define __SHARP_H__

#include "toyotathon.h"

static lookup_table lt;
const float d_calib[] = {
    15, 20, 25, 30, 35, 40, 45, 50, 55, 60,
    65, 70, 75, 80, 85, 90, 100, 110, 120, 130
};
const float v_calib[] = {
    2.6, 2.3, 2.39, 1.87, 1.54, 1.35, 1.25, 1.15, 1.07, 1.01,
    0.95, 0.88, 0.85, 0.78, 0.77, 0.78, 0.74, 0.72, 0.68, 0.6
};

int     sharp_init();
inline int sharp_lookup_v( float v )
{ return lookup_v( &lt, v ); }

#define AVERAGE_SIZE 4
float   sharp_read( int pin );

#endif
