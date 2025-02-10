/*
 * Filename: Flowing_Water_Light
 * Function: Flowing water light
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/ 
*/
byte ledPins[] = {18, 5, 14, 17, 26}; //set LED pins
int ledCounts; //define the number of LED

void setup() {
//Set 5 LEDs to output mode
  ledCounts = sizeof(ledPins); 
  for (int i = 0; i < ledCounts; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < ledCounts; i++) { //The five leds will turn on and off from right to left
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = ledCounts - 1; i > -1; i--) { //The five leds will turn on and off from left to right
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}

