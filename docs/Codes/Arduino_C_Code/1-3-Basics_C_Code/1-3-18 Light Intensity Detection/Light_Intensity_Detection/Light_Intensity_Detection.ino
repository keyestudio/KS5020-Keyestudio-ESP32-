/*  
 * Filename: Light Intensity Detection
 * Function: read Photoresistor light intensity value
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int PIN_ANALOG_IN = 36;   //set Photoresistor pin to GPIO36

void setup() {
  Serial.begin(9600);   //set baud rate to 9600
  pinMode(PIN_ANALOG_IN, INPUT);    //set pin to input
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);    //read Photoresistor analog value
  int dacVal = map(adcVal, 0, 4095, 0, 255);
  double voltage = adcVal / 4095.0 * 3.3;
  Serial.print("ADC Val: ");    //print ADC Val:
  Serial.print(adcVal);    //print and display adcVal value
  Serial.print(" |DAC Val: ");    //print   DAC Val:  
  Serial.print(dacVal);    //print and display adcVal value
  Serial.print(" |Voltage: ");    //print   Voltage:  
  Serial.println(voltage);    //print and display voltage value
  delay(200);
}