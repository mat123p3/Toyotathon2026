#ifndef __SENSORS_H__
#define __SENSORS_H__

#include <stdint.h>
#include <stdlib.h>
#include "pinouts.h"

//-------------SENSOR FUNCTIONS------------------

#define     SHARP_COUNT 2
#define     QTR_COUNT   3
#define     SIDE_COUNT  2
#define     FRONT_COUNT 1

#define L_SHARP_BUF 0
#define R_SHARP_BUF 1
static float _analog_senses[ SHARP_COUNT + QTR_COUNT ];

#define SIDE_L_BUF  0
#define SIDE_R_BUF  1
#define FRONT_BUF   2
#define QTR_L_BUF   3
#define QTR_F_BUF   4
#define QTR_R_BUF   5
static float _digital_sense[ SIDE_COUNT + FRONT_COUNT + QTR_COUNT ];

//
int init_sensors();
//Reads all sensors into internal buffer
void read_sensors();

static bool close;
inline bool is_close() { return close; }

#endif
