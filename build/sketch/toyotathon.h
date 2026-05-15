#line 1 "/home/cheese/code/Toyotathon2026/toyotathon.h"
#ifndef __TOYOTATHON_H__
#define __TOYOTATHON_H__

#include <stdlib.h>


inline float toVoltage( int a ) { return a * ( 5.0 / 1023 ); }

inline float fap( float x, float fromLow, float fromHigh, float toLow, float toHigh )
{ return ( x - fromLow ) * ( toHigh - toLow ) / ( fromHigh - fromLow ) + toLow; }

struct scheduler{
  void (*f)(void);
  unsigned long     t;
};

enum STATE{
    ON_LINE,
    REPO,
    SEARCHING,
    PRE_TRACKING,
    TRACKING,
    TRACKING_ADJUST
};

#endif
