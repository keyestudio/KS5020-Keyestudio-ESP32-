/*  
 * Filename: Night_Lamp
 * Function: Photoresistor controls LED
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int PIN_ANALOG_IN = 36;  // Photoresistor pin
const int PIN_LED = 12;  // LED pin
int CHAN = 0;  // enable led channel 0 

void setup() {
  ledcSetup(CHAN, 1000, 12); // PWM ranges from 0 ~ 4095
  ledcAttachPin(PIN_LED, CHAN); // set PIN_LED pin channel 0 to output
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN); // read adc
  int pwmVal = adcVal;        // map adcVal to pwmVal
  ledcWrite(CHAN, pwmVal);    // Set pulse width
  delay(10);
}