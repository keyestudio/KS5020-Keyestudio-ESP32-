/*
 * File name: Hello,LED
 * Function: LED blinks 1s
 * Compiling IDE: ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int ledPin = 26; // Define LED pin to IO26.

void setup(){
  pinMode(ledPin, OUTPUT); // Set LED pin to output
}

void loop(){
  digitalWrite(ledPin, HIGH); // LED on.
  delay(1000); // Delay 1s.
  digitalWrite(ledPin, LOW); // LED off.
  delay(1000); // Delay 1s.
}
