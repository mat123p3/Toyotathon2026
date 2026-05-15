#line 1 "/home/cheese/code/Toyotathon2026/sensors.h"
#ifndef __SENSORS_H__
#define __SENSORS_H__

#include <stdint.h>
#include <Arduino.h>

#define     SENSOR_COUNT 9

#define FRONT_BUF   0
#define SHARP_L_BUF 1
#define SHARP_R_BUF 2
#define SIDE_L_BUF  3
#define SIDE_R_BUF  4
#define QTR_L_BUF   5
#define QTR_M_BUF   6
#define QTR_R_BUF   7
inline uint8_t _s_buf[ 8 ];

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
 * @brief Checks if enemy is front.
 * @return uint8_t. Starting from smallest endian, bit 0 is left, bit 1 is middle
 * bit 2 is right.
 */
inline uint8_t find_enemy()
{
    return _s_buf[SIDE_L_BUF] | _s_buf[SHARP_L_BUF] << 1 | _s_buf[FRONT_BUF] << 2 | _s_buf[SHARP_R_BUF] << 3 | _s_buf[SIDE_R_BUF] << 4;
}

/*
 * @brief Checks is sensors are on line.
 * @return uint8_t. Starting from smallest endian, bit 0 is back left sensor, bit 1
 * is middle sensor, bit 2 is back right.
 */
inline uint8_t on_line()
{
    return _s_buf[QTR_R_BUF] | _s_buf[QTR_M_BUF] << 1 | _s_buf[QTR_L_BUF] << 2;
}

#endif
