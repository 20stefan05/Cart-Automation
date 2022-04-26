#ifndef THRUST_H
#define THRUST_H

#include "Arduino.h"
#define PWMPIN 9
#define ENPIN 8
#define DIRPIN 7
void mvForward(int speed);
void mvBackward(int speed);
void stop();
#endif
