#include<SoftwareSerial.h>
SoftwareSerial mySerial(9,10);//since we connecting arduino to gsm module via pin 9 and 10 not by rx and tx
int val;
int tempPin = 1;
int buzzer=11;
int t=0;
static int x=1;
float cel;
char phone_no[]="7078869316";
void setup()
{
 mySerial.begin(9600);   // Setting the baud rate of GSM Module  
Serial.begin(9600);//Starts serial communication with a baud rate of 9600
pinMode(buzzer,OUTPUT);

}
void Call()
{
 mySerial.print("AT");
 mySerial.print("ATD");
 mySerial.print(phone_no);
 mySerial.println(";");
 delay(20000);
 mySerial.print("ATH");
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
  Call();
  } 
}
}
