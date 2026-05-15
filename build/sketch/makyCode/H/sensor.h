#line 1 "/home/cheese/code/Toyotathon2026/makyCode/H/sensor.h"
#ifndef __SENSOR_H_
#define __SENSOR_H_

#include "pinDeclarations.h"

//classes for the sensors
//QT1RC sensor
class QT1RC{
    public:
        void initSensor();
        //void calibrateSensor();
        int readLeft();
        int readRight();
        int readBack();
        //these functions will be resposible to see if the bot has reached the edges
        bool isLeftEdge();
        bool isRightEdge();
        bool isBackEdge();
        bool isAnyEdge();
        //int getThreshold();
    private :
        int threshold = 400; //defaulted value, used when testing the sensor
        int darkVal = 0; //overwritten when calibrated
        int lightVal = 0;
        int avgRead(int pin, int samples);
};
//MZ80
class MZ80{
    public:
        void initSensor();
        int readLeft();
        int readRight();
        //if there is a bot on the sides
        bool isObjectLeft();
        bool isObjectRight();
        bool isAnyObject();

};

class JS200{
    public:
        void initSensor();
        int readFront();
        bool isObjectFront();
};

#endif
