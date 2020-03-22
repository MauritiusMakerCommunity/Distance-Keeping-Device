Date 22/03/2020
Version : 1.0 Beta 

Author : Yovan Fowdar


Reason  : Covid-19

Background info : It is widely accepted that the safe distance to keep from someone that is infected by COVID-19 Virus is 150cm 

Purpose of this device : Sound an alarm when an object is closer that 150 cm from the device

Where to place this device : on a belt , trouser , skirt (Should not be higher so as not to miss short people)

Powering the device : The device can be powered with commonly available battery power banks commonly used to charge phones



Current phase :  Prototyping 
Next phases :- 
(1)  3D Printed Enclosure
(2)  Field test 
(3)  Add PIR module to prevent the device from detecting objects

Electronic Components
1) Arduino Nano 
2) HC-SR04  Reference on Ultrasonic sensor  -- >https://www.itead.cc/wiki/Ultrasonic_Ranging_Module_HC-SR04
3) Buzzer 5V



Wiring on HC-SR04 to Arduino/ATMEGA

VCC  --> 5V

TRIG --> D2

ECHO --> D3

GND --> GND


Wiring to buzzer

GND --> GND

+VE --> D4

