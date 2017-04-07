#include<SoftwareSerial.h>
float sensor = A0;
float value;

void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(sensor);
  Serial.println(value);
  delay(2000);
}
