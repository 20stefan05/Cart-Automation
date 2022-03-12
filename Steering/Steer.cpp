#include "Steer.h"


AccelStepper stepper(1, PUL, DIR);



void steerRight(int speed){
  stepper.setMaxSpeed(speed);
  stepper.setSpeed(speed);
  stepper.runSpeed();
}
void steerLeft(int speed){
  stepper.setMaxSpeed(-1*speed);
  stepper.setSpeed(-1*speed);
  stepper.runSpeed();
}
void steer(int speed, int pos){
  stepper.setMaxSpeed(speed);
  stepper.setAcceleration(speed);
  stepper.moveTo(pos);
  stepper.run();
}
