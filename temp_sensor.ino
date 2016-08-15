#include<SoftwareSerial.h>
SoftwareSerial mySerial(9,10);//since we connecting arduino to gsm module via pin 9 and 10 not by rx and tx
int val;
int tempPin = 1;
int buzzer=11;
int t=0;
static int x=1;
float cel;
void setup()
{
 mySerial.begin(2400);   // Setting the baud rate of GSM Module  
Serial.begin(2400);//Starts serial communication with a baud rate of 9600
pinMode(buzzer,OUTPUT);
}
void SendMessage()
{
 mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(2000);  
   mySerial.println("AT+CMGS=\"+917078869316\"\r");
  delay(2000);
mySerial.println("Your house is on fire...");
  delay(200);
   mySerial.println((char)26);
  delay(2000);
 }

void loop()
{
  val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
cel = mv/10;
Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();
delay(500);
t++;
Serial.print(t);
check();
}
void check()
{
if(cel>25)
{
 noTone(11);
tone(6, 440, 200);
noTone(6);
tone(7, 494, 500);
noTone(7);
tone(11, 523, 300);
 while(x==1)
  {delay(2000);
    Serial.print("i am in");
    x++;
  SendMessage();
  } 
}
}
