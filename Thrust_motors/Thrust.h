#ifndef THRUST_H
#define THRUST_H

#include "Arduino.h"
#define PWMPIN 6
#define ENPIN 10
#define DIRPIN 11
void mvForward(int speed);
void mvBackward(int speed);
void stop();
#endif
