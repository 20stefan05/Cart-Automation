#include "Thrust.h"
int DIR = 1;
void mvForward(int speed){
  //digitalWrite(ENPIN, LOW);
  delay(100);
  int speedToMotor = map(speed, 0, 10, 0, 255);
  if(DIR==1)
      analogWrite(PWMPIN, abs(speedToMotor));
  else{
    DIR=1;
    analogWrite(PWMPIN, 0);
    digitalWrite(DIRPIN, LOW);\
    delay(100);
    analogWrite(PWMPIN, abs(speedToMotor));

  }
      Serial.println(speed);  
}
void mvBackward(int speed){
    //digitalWrite(ENPIN, LOW);
    delay(100);
  int speedToMotor = map(speed, 0, 10, 0, 255);
//      analogWrite(PWMPIN, abs(speedToMotor)); 
//      Serial.println(speed); 
        if(DIR==0)
      analogWrite(PWMPIN, abs(speedToMotor));
  else{
    DIR=0;
    analogWrite(PWMPIN, 0);
    digitalWrite(DIRPIN, HIGH);
    delay(100);
    analogWrite(PWMPIN, abs(speedToMotor));

  }
}
void stop(){
  analogWrite(PWMPIN, 0);
  delay(100);
  //digitalWrite(ENPIN, HIGH);

}
//de lucrat la schimbarea directiei!
