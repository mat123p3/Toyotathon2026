#include "pinouts.h"
#include "remote.h"
#include "drive.h"

void init_remote( int pin )
{
    pinMode( pin, INPUT );
    attachInterrupt( digitalPinToInterrupt( pin ), kill, LOW );
}

void kill()
{
    stopMotors();
    exit(0);
    //while(1);
}
