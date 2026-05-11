#ifndef __TOYOTATHON_H__
#define __TOYOTATHON_H__

#include <stdlib.h>
#include <string.h>

inline float toVoltage( int a ) { return a * ( 5.0 / 1023 ); }

inline float fap( float x, float fromLow, float fromHigh, float toLow, float toHigh )
{ return ( x - fromLow ) * ( toHigh - toLow ) / ( fromHigh - fromLow ) + toLow; }

struct lookup_table
{
    float *d;
    float *v;
    size_t size;
};

//initializes lookup table. Copies n distance and voltage values from d and v.
int init_lookup( struct lookup_table *lt, float *d, float *v, size_t s );

//Returns an interpolated value for the voltage v
float lookup_v( struct lookup_table *lt, float v );

#endif
