#include <SPI.h> 
#include "mcp2515_can.h"
#include "Thrust.h"


// Set SPI CS Pin according to your hardware

const int SPI_CS_PIN = 10;
const int CAN_INT_PIN = 2;

mcp2515_can CAN(SPI_CS_PIN); // Set CS pin  

void setup() {
  //Declaring LED pin as output
  pinMode(PWMPIN, OUTPUT);
  pinMode(ENPIN, OUTPUT);
  pinMode(DIRPIN, OUTPUT);
  Serial.begin(9600);
    
    while(!Serial){};

    while (CAN_OK != CAN.begin(CAN_500KBPS)) {             // init can bus : baudrate = 500k
        Serial.println("CAN init fail, retry...");
        delay(100);
    }
    Serial.println("CAN init ok!");
    delay(100);
}
int time = millis();
void loop() {
  digitalWrite(ENPIN, LOW);
    unsigned char len = 0;
    unsigned char buf[2];
  if (CAN_MSGAVAIL == CAN.checkReceive()) {         // check if data coming
      CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
      if(buf[0]=='F'){
        if(buf[1]=='M')mvForward(10);
        else mvForward(buf[1]);
        time = millis();
      }
      else if(buf[0]=='B'){
        if(buf[1]=='M')mvBackward(10);
        else mvBackward(buf[1]);
        time = millis();
      }

  }
  else if(millis()-time>100){
    stop();
    time = millis();
  }
  //else stop();
}
