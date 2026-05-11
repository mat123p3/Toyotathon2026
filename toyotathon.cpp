#include "toyotathon.h"
#include <Arduino.h>

//initializes lookup table. Copies n distance and voltage values from d and v.
int init_lookup( struct lookup_table *lt, float *d, float *v, size_t s )
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

//Returns an interpolated value for the voltage v
float lookup_v( struct lookup_table *lt, float v )
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
