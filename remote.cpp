#include "pinouts.h"
#include "remote.h"

void init_remote( int pin )
{
    pinMode( pin, INPUT );
    attachInterrupt( digitalPinToInterrupt( pin ), kill, FALLING );
}

void kill()
{
    exit(0);
}
