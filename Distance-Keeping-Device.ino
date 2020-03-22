/*
Date 22/03/2020
Reason  : Covid-19
Background info : It is widely accepted that the safe distance to keep from someone that is infected by COVID-19 Virus is 150cm 
Purpose of this device : Sound an alarm when an object is closer that 150 cm from the device
Where to place tis device : on a belt , trouser , skirt (Should not be higher to as not to miss short people) 
Version : 1.0 Beta 
Author : Yovan Fowdar

Reference on Ultrasonic sensor  -- >https://www.itead.cc/wiki/Ultrasonic_Ranging_Module_HC-SR04

Wiring on HC-SR04 to Arduino/ATMEGA
VCC  --> 5V
TRIG --> D2
ECHO --> D3
GND --> GND

Wiring to buzzer 
GND --> GND
+VE --> D4                         
*/

const int TrigerPin = 2;
const int EchoPin = 3;
const int BuzzerPin = 4;
const int MinDistanceTrigger = 150; // (in cm)
const int StateDuration = 4000; //(time in milliseconds that the triggered distance will need to be in that state for an alarm to be triggered)
boolean Triggered = 0;
long  TriggeredMillis; 
long Duration;
int Distance;
void setup() {
pinMode(TrigerPin, OUTPUT); // Sets the trigPin as an Output
pinMode(EchoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(115200); // Starts the serial communication
pinMode(BuzzerPin,OUTPUT);
// this is a startup beep beepppp beeppppppppppp
digitalWrite(BuzzerPin,HIGH);
delay(100);
digitalWrite(BuzzerPin,LOW);
delay(100);
digitalWrite(BuzzerPin,HIGH);
delay(200);
digitalWrite(BuzzerPin,LOW);
delay(100);
digitalWrite(BuzzerPin,HIGH);
delay(500);
digitalWrite(BuzzerPin,LOW);
}
void loop() {
  
  digitalWrite(TrigerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigerPin, LOW);
  Duration = pulseIn(EchoPin, HIGH);
  // Calculate distance
  
  Distance = Duration*0.034/2;
  Serial.print("Distance = ");
  Serial.println(Distance);
  if (Distance <=MinDistanceTrigger) {
    if (Triggered == 0){
      TriggeredMillis = (millis()+StateDuration);
    }
    Triggered = 1;
    if (millis() > TriggeredMillis) {
      digitalWrite(BuzzerPin,HIGH);  // Activate buzzer
    }
  }
  
  if (Distance >MinDistanceTrigger) {
    digitalWrite(BuzzerPin,LOW);
    Triggered = 0;
  }
  
}
