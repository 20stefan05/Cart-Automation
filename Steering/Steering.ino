#include "Steer.h"
#include <SPI.h>
#include "mcp2515_can.h"



const int SPI_CS_PIN = 53; // set SPI pins for the CAN communication
const int CAN_INT_PIN = 2;

mcp2515_can CAN(SPI_CS_PIN); // Set CS pin  

void setup() {
  // put your setup code here, to run once:
  pinMode(EN, OUTPUT);
  digitalWrite(EN, HIGH);
  Serial.begin(9600);
    
    while(!Serial){};

    while (CAN_OK != CAN.begin(CAN_500KBPS)) {             // init can bus : baudrate = 500k
        Serial.println("CAN init fail, retry...");
        delay(100);
    }
    Serial.println("CAN init ok!");
    delay(100);
}
int time0 = millis();
void loop() {
  // put your main code here, to run repeatedly:
    unsigned char len = 0;
    unsigned char buf[3];
  if (CAN_MSGAVAIL == CAN.checkReceive()) {
     // check if data coming
      CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf
      if(buf[0]=='L'){
        digitalWrite(EN, LOW);
        while(millis() - time0 < 100){
                  steerLeft(buf[1]);
        }
        time0 = millis();
      }
      
      else if(buf[0]=='R'){
        digitalWrite(EN, LOW);
         while(millis() - time0 < 100){
         steerRight(buf[1]);
        }
        time0 = millis();
      }
        
      
      else if(buf[0] == 'P'){
        digitalWrite(EN, LOW);
        int pos = 200/360*buf[2];
        steer(buf[1], buf[2]); 
      }
  }
  else
      digitalWrite(EN, HIGH);      

}
