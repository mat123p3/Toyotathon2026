#line 1 "/home/cheese/code/Toyotathon2026/remote.h"
#ifndef __REMOTE_H__
#define __REMOTE_H__

#include <Arduino.h>
#include <stdint.h>

inline void init_remote( uint8_t pin, void (*isr)(void) )
{
    pinMode( pin, INPUT );
    attachInterrupt( digitalPinToInterrupt( pin ), isr, LOW );
}

#endif
