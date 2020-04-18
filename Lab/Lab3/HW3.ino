double sensorValue,sensorVoltage,R1=0;

void setup() {
  
  Serial.begin(9600);
  
}


void loop() {
  for (int i=0;i<=5;i++) {
  sensorValue = 0.7* sensorValue + 0.3* analogRead(14);
  }
  sensorVoltage = sensorValue * 2.5 / 4095;
  Serial.print(analogRead(14));
  Serial.print(",");
  Serial.println(sensorVoltage);
  delay(500);       
}
