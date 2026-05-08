#ifndef __SENSORS_H__
#define __SENSORS_H__

#include <cstdint>
#include <stdlib.h>
#include "pinouts.h"

struct LOOKUP_TABLE
{
    float *d;
    float *v;
    size_t size;
};

static struct LOOKUP_TABLE sharp_lt;
//----------------LOOKUP TABLE FUNCTIONS
//initializes lookup table. Copies n distance and voltage values from d and v.
int init_lookup( struct LOOKUP_TABLE *lt, float *d, float *v, size_t n );
//Returns an interpolated value for the voltage v
float lookup_v( struct LOOKUP_TABLE *lt, float v );
//init the sharp lookup table
int init_sharp( float *d, float *v, size_t n );

//-------------SENSOR FUNCTIONS------------------

#define SENSOR_COUNT = 8
static uint8_t _sense_buffer[SENSOR_COUNT];

enum DISTANCE{
    VCLOSE = 0,
    CLOSE = 1,
    MID = 2,
    FAR = 3,
    VFAR = 4
};

struct sensor_info
{
    int         pin;
    uint8_t     buf_pos;
};

#define M_SENSE             0
#define L_SENSE             1
#define R_SENSE             2
#define L_ANGLE_SENSE       3
#define R_ANGLE_SENSE       4
#define L_LINE_SENSE        5
#define F_LINE_SENSE        6
#define R_LINE_SENSE        7

static struct sensor_info l_angle_info = { .pin = SHARPL, .buf_pos = L_ANGLE_SENSE };
static struct sensor_info r_angle_info = { .pin = SHARPR, .buf_pos = R_ANGLE_SENSE };
static struct sensor_info l_line_info = { .pin = LINEL, .buf_pos = L_LINE_SENSE };
static struct sensor_info f_line_info = { .pin = LINEF, .buf_pos = F_LINE_SENSE };
static struct sensor_info r_line_info = { .pin = LINER, .buf_pos = R_LINE_SENSE };

static uint8_t _close_front = 0;
//Reads all sensors into internal buffer
void read_sensors();

//Parse sharp sensors
void parse_sharp( struct sensor_info *sens )

#endif
