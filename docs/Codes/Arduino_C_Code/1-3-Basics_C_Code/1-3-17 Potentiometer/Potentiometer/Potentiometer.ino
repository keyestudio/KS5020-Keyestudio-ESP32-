/*  
 * Filename: Poutentiometer
 * Function: read Potentiometer value
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int PIN_ANALOG_IN = 36;   //set Potentiometer pin to GPIO36

void setup() {
  Serial.begin(9600);   //set baud rate to 9600
  pinMode(PIN_ANALOG_IN, INPUT);    // set Potentiometer pin to input
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);    //read Potentiometer analog value
  int dacVal = map(adcVal, 0, 4095, 0, 255);
  double voltage = adcVal / 4095.0 * 3.3;
  Serial.print("ADC Val: ");    //Print ADC Val:
  Serial.print(adcVal);    //Print and show adcVal value
  Serial.print(" |DAC Val: ");    //Print  DAC Val:  
  Serial.print(adcVal);    //Print and show adcVal value
  Serial.print(" |Voltage: ");    //Print  Voltage:  
  Serial.println(voltage);    //Print and show voltage value
  delay(200);
}