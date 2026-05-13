#ifndef __TOYOTATHON_H__
#define __TOYOTATHON_H__

inline float toVoltage( int a ) { return a * ( 5.0 / 1023 ); }

inline float fap( float x, float fromLow, float fromHigh, float toLow, float toHigh )
{ return ( x - fromLow ) * ( toHigh - toLow ) / ( fromHigh - fromLow ) + toLow; }

#endif
