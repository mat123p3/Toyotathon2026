#include "sensors.h"
#include "pinouts.h"

void read_sensors()
{
    _sense_buffer[L_SENSE] = readDigital( SIDEL );
    _sense_buffer[R_SENSE] = readDigital( SIDER );
    _sense_buffer[M_SENSE] = readDigital( SIDEM );
}

void parse_sharp( struct sensor_info *sens )
{
    float d = lookup_v( toVoltage( readAnalog( pin ) ) );
    if( d < 50 )
    {
        sense_buffer[mem] = DISTANCE.CLOSE;
        close_front = 1;
    }
    else if( d < 100 )
    {
    }
}

int init_lookup( struct LOOKUP_TABLE *lt, float *d, float *v, size_t s )
{
    lt->size = s;
    lt->d = (float *) malloc( s * sizeof( float ) );
    lt->v = (float *) malloc( s * sizeof( float ) );
    if( lt->d == NULL || lt->v == NULL )
    {
        return -1;
    }
    memcpy( lt->d, d, s * sizeof(float) );
    memcpy( lt->v, v, s * sizeof(float) );
    return lt->size;
}

float lookup_v( struct LOOKUP_TABLE *lt, float v )
{
    if( v < lt->v[lt->size - 1] ) return -1;
    for( int i = 0; i < lt->size; i++ )
    {
        if( v >= lt->v[i+1] )
        {
            return fap( v, lt->v[i], lt->v[i+1], lt->d[i], lt->d[i+1] );
        }
    }
    return lt->d[0];
}
