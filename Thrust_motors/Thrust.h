#ifndef THRUST_H
#define THRUST_H

#include "Arduino.h"
#define PWMPIN 8
#define ENPIN 9
#define DIRPIN 10
void mvForward(int speed);
void mvBackward(int speed);
void stop();
#endif
