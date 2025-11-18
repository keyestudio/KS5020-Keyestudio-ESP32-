/*
 * Filename: Breathing_LED
 * Function: Make led light fade in and out, just like breathing.
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int ledPin = 26;  // The GPIO pin for the LED
int CHN = 0;   // define the pwm channel
int FRQ = 1000;   // define the pwm frequency
int PWM_BIT = 8;   // define the pwm resolution for ledc channel

void setup() {
  ledcSetup(CHN, FRQ, PWM_BIT); // setup pwm channel，frequency and resolution for ledc channel.
  ledcAttachPin(ledPin, CHN);  // attach the led pin to pwm channel
}

void loop() {
  for (int i = 0; i < 255; i++) { //make light fade in
    ledcWrite(CHN, i);
    delay(5);
  }
  for (int i = 255; i > -1; i--) {  //make light fade out
    ledcWrite(CHN, i);
    delay(5);
  }
}
