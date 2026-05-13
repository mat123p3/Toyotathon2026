#ifndef __SENSORS_H__
#define __SENSORS_H__

#include <stdint.h>

#define     SENSOR_COUNT 9

#define FRONT_BUF   0
#define SHARP_L_BUF 1
#define SHARP_R_BUF 2
#define SIDE_L_BUF  3
#define SIDE_R_BUF  4
#define QTR_L_BUF   5
#define QTR_F_BUF   6
#define QTR_R_BUF   7
static uint8_t _s_buf[ 8 ];

#define CALIBRATION_COUNT 200
/*
 * @brief Initialize all sensor pins.
 */
void init_sensors();

/*
 * @brief Read all sensors.
 */
void read_sensors();

/*
 * @brief Returns 1 if enemy in front, 0 otherwise.
 */
inline static uint8_t is_front(){ return _s_buf[ FRONT_BUF ]; }

/*
 * @brief I dont know lil bro
 */
inline static uint8_t last_seen(){
    if( _s_buf[FRONT_BUF] )         return 0;
    else if( _s_buf[SHARP_L_BUF] )  return 1;
    else if( _s_buf[SHARP_R_BUF] )  return 2;
    else if( _s_buf[SIDE_L_BUF] )   return 3;
    else if( _s_buf[SIDE_R_BUF] )   return 4;
}

#endif
