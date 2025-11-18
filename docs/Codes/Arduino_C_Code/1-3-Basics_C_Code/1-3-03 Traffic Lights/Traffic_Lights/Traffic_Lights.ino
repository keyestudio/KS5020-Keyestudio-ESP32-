/*
 * Filename: Traffic_Lights
 * Function: traffic lights
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/ 
*/
const int PIN_LED_RED = 13;   //define red LED pin
const int PIN_LED_YELLOW = 14;   //define yellow LED pin
const int PIN_LED_GREEN = 16;   //define green LED pin

void setup() {
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
}

void loop() {
   digitalWrite(PIN_LED_GREEN, HIGH);// turn on green LED
   delay(5000);// Delay 5 s
   digitalWrite(PIN_LED_GREEN, LOW);// 
   delay(500);// Delay 0.5 s
   for(int i=0;i<3;i++)// Blink 3 times
   {
     digitalWrite(PIN_LED_YELLOW, HIGH);// Turn on yellow LED
     delay(500);// Delay 0.5 s
     digitalWrite(PIN_LED_YELLOW, LOW);//  Turn off yellow LED
     delay(500);// Delay 0.5 s
   } 
   digitalWrite(PIN_LED_RED, HIGH);// Turn on red LED
   delay(5000);// Delay 5 s
   digitalWrite(PIN_LED_RED, LOW); //  Turn off red LED
   delay(500);// Delay 0.5 s
}
