#include <SevSeg.h>
SevSeg sevseg;
int Hour=0,Min=0;
byte Pin6;
void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2,3,4,5};
  byte segmentPins[] = {7,8,9,10,11,12,13,14};
  pinMode(6,INPUT);
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins,
  segmentPins);
  sevseg.setBrightness(100);
}

void loop() {
  static unsigned long timer = millis();
  Pin6= digitalRead (6);
  if (Pin6 == HIGH){
    Min = Hour = 0;
    sevseg.setNumber(Hour*100+Min,0);
  }

  
  if(millis()>timer){
    timer+=300;
    Min = Min + 1;
    if( Min == 60) 
    {
      Min = 0;
      if (Hour == 23)
        Hour=0;
      else
        Hour++;
    }
    sevseg.setNumber(Hour*100+Min,0);
  }
  sevseg.refreshDisplay();
 
  }
