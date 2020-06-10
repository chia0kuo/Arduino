#include <LWiFi.h>
#include <WiFiClient.h>
#include <Ultrasonic.h>
#include "MCS.h"
#include "DHT.h"
#define _SSID "Han"
#define _KEY  "0975818791"

#define TRIGGER_PIN 4
#define ECHO_PIN 3
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

MCSDevice mcs("D88njlra", "FQMHiFg56cJAxMHO");

MCSDisplayFloat Temp("2");

void setup() {
Serial.begin(9600);
while(WL_CONNECTED != WiFi.status())
  {
    Serial.print("WiFi.begin(");
    Serial.print(_SSID);
    Serial.print(",");
    Serial.print(_KEY);
    Serial.println(")...");
    WiFi.begin(_SSID, _KEY);
  }
  Serial.println("WiFi connected !!");

  mcs.addChannel(Temp);
  while(!mcs.connected())
  {
    Serial.println("MCS.connect()...");
    mcs.connect();
  }
  Serial.println("MCS connected !!");

}
void loop(){
float cmMsec;
cmMsec = ultrasonic.read(CM); // 計算距離，單位: 公分
Serial.print("CM: "); 
Serial.println(cmMsec);
mcs.process(100);
      if(!Temp.set(cmMsec))
    {
      Serial.print("Failed to update remote");
      Serial.println(Temp.value());
    }


delay(1000);

  while(!mcs.connected())
  {
    Serial.println("re-connect to MCS...");
    mcs.connect();
    if(mcs.connected())
      Serial.println("MCS connected !!");
  }

}
