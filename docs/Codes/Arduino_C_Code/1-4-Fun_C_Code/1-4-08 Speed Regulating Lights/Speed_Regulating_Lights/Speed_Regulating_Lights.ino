/*
 * Filename: Speed_Regulating_Lights
 * Function: Variable speed light
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int ledPins[] = {12, 13, 14};  //set red yellow green LED pins
const int potPin = 36;  //set potentiometer pin to IO36  
int potValue = 0;  //potentiometer value  
int delayTime = 100;  //Default delay time
  
void setup() {  
  for (int i = 0; i < 3; i++) {  
    pinMode(ledPins[i], OUTPUT);  //set LED pin to input  
  }  
  pinMode(potPin, INPUT);  //set potentiometer pin to output  
}  
  
void loop() {  
  potValue = analogRead(potPin);  //read potentiometer value  
  delayTime = map(potValue, 0, 4095, 100, 1000);  //map potentiometer value to delay time  
  
  for (int i = 0; i < 3; i++) {  
    digitalWrite(ledPins[i], HIGH);  //current LED on
    delay(delayTime);  //delay  
    digitalWrite(ledPins[i], LOW);  //current LED off
  }  
}
