//pins used on the Arduino nano

#ifndef __PINDECLARATIONS_H_
#define __PINDECLARATIONS_H_

//SENSORS
//MZ80 sensors
#define R_MZ80 D7
#define L_MZ80 D8
//QT1RC sensors
#define LF_QT1RC A2
#define RF_QT1RC A3
#define B_QT1RC A4
//JS200 front sensor
#define FR_JS200 D13
//sharp IR sensor
#define SIR_R A0
#define SIR_L A1

//MOTOR DRIVER
//LEFT BTS7960
#define LL_PWM D3
#define LR_PWM D6
#define LL_EN D4
#define LR_EN D6
//RIGHT BTS7960
#define RL_PWM D9
#define RR_PWM D11
#define RL_EN D10
#define RR_EN D12

#endif
