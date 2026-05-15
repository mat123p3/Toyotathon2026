#line 1 "/home/cheese/code/Toyotathon2026/drive.h"
#ifndef __DRIVE_H__
#define __DRIVE_H__

#include "pinouts.h"
#include <stdint.h>

struct motor{
    uint8_t     pwm_f_pin;
    uint8_t     pwm_f_en;
    uint8_t     pwm_b_pin;
    uint8_t     pwm_b_en;
};

//TODO IMPLEMENT WEAK/STRONG MOTOR
struct driver
{
    struct motor l;
    struct motor r;
};

//left motor
#define LEFT_PWM_FWD MOTOR0PWM0   // PWM forward
#define LEFT_PWM_REV MOTOR0PWM1   // PWM reverse
#define LEFT_EN_FWD MOTOR0EN0    // Enable/dir A
#define LEFT_EN_REV MOTOR0EN1    // Enable/dir B

//right motor
#define RIGHT_PWM_FWD MOTOR1PWM0   // PWM forward
#define RIGHT_PWM_REV MOTOR1PWM1   // PWM reverse
#define RIGHT_EN_FWD MOTOR1EN0    // Enable/dir A
#define RIGHT_EN_REV MOTOR1EN1    // Enable/dir B

/*
 * @brief               Unlock all motors, set pwm to 0.
 * @param[in] *drv      A pointer to the drive structure.
 */
void drive_init( struct driver *d );

/*
 * @brief               Drive in a straight line.
 * @param[in] *drv      A pointer to the drive structure.
 * @param[in] p         PWM value to write. Value is between 0 and 255.
 * @param[in] d         The direction to drive in. If d is less than 0, the robot will reverse
 */
void drive_move( struct driver *drv, uint8_t p, int8_t d );

/*
 * @brief               Drive while turning.
 * @param[in] *drv      A pointer to the drive structure.
 * @param[in] p         PWM value to write. Value is between 0 and 255.
 * @param[in] d         The direction to drive in. A value less than 0 represents backwards.
 * @param[in] r         The power ratio between both motors. Value is between 0 and 1. The ratio is
 *                      applied such that p is applied to one motor, and p * r to the other.
 * @param[in] c         The direction to turn in. If c is less than 0, the robot will turn ccw. Otherwise
 *                      it will turn cw.
 */
void drive_move( struct driver *drv, uint8_t p, int8_t d, float r, int8_t c );

/*
 * @brief               Spin on self.
 * @param[in] *drv      A pointer to the drive structure.
 * @param[in] p         PWM value to write. Value is between 0 and 255.
 * @param[in] c         The direction to turn in. 0 for ccw, 1 for cw.
 */
void drive_spin( struct driver *drv, uint8_t p, uint8_t c );

/*
 * @brief               Lock all motors.
 * @param[in] *drv      A pointer to the drive structure.
 */
void drive_lock( struct driver *drv );

/*
 * @brief               Reset all motors to 0.
 * @param[in] *drv      A pointer to the drive structure.
 */
inline static void drive_reset( struct driver *drv ){
    analogWrite( drv->l.pwm_f_pin, 0 );
    analogWrite( drv->l.pwm_b_pin, 0 );
    analogWrite( drv->r.pwm_f_pin, 0 );
    analogWrite( drv->r.pwm_b_pin, 0 );
}

#endif
