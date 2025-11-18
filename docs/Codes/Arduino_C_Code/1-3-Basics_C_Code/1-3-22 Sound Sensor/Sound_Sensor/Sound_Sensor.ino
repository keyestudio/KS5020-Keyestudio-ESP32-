/*  
 * Filename: Potentiometer
 * Function: read sound sensor value
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int PIN_ANALOG_IN = 36;   //set sensor pin to IO36

void setup() {
  Serial.begin(9600);   // set baud rate to 9600
  pinMode(PIN_ANALOG_IN, INPUT);  // set sensor pin to input
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);    // read sensor analog value
  int dacVal = map(adcVal, 0, 4095, 0, 255);
  double voltage = adcVal / 4095.0 * 3.3;
  Serial.print("ADC Val: ");    // print ADC Val:
  Serial.print(adcVal);    // print adcVal value
  Serial.print(" |DAC Val: ");    // print   DAC Val:  
  Serial.print(adcVal);    // print adcVal value
  Serial.print(" |Voltage: ");    // print   Voltage:  
  Serial.println(voltage);    // print voltage value
  delay(200);
}