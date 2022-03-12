#ifndef STEER_H
#define STEER_H
#endif

#include "Arduino.h"
#include <AccelStepper.h>

#define PUL 7
#define DIR 6
#define EN 8

void steerRight(int speed);
void steerLeft(int speed);
void steer(int speed, int pos);
