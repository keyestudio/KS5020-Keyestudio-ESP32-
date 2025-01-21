/*
 * Filename: RGB_LED
 * Function: RGB LED shines in different colors
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/ 
*/
const int ledPins[] = {27, 25, 26};    //Define the red, green, and blue pins
const byte chns[] = {0, 1, 2};      //define PWM channel
int red, green, blue;

void setup() {
  for (int i = 0; i < 3; i++) {   //Set pwm channel, 1KHz, 8bit
    ledcSetup(chns[i], 1000, 8);
    ledcAttachPin(ledPins[i], chns[i]);
  }
}

void loop() {
  setColor(255, 0, 0); // Red
  delay(1000);
  setColor(0, 255, 0); // Green
  delay(1000);
  setColor(0, 0, 255); // Blue
  delay(1000);
  setColor(255, 255, 0); // Yellow
  delay(1000);
  setColor(80, 0, 80); // Purple
  delay(1000);
  setColor(0, 255, 255); // Cyan
  delay(1000);
}

void setColor(int red, int green, int blue) {
  ledcWrite(chns[0], red); //Common cathode LED, high level on
  ledcWrite(chns[1], green);
  ledcWrite(chns[2], blue);
}
