#include<SoftwareSerial.h>

int fire = A0;
int value = 0;
void setup() {
  pinMode(fire, INPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(fire);
  Serial.println(value);
  delay(2000);
}
