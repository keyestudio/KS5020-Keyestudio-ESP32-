/*  
 * Filename: Thermistor
 * Function: detect temperature with Thermistor
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int PIN_ANALOG_IN = 36; // set sensor pin to analog IO36

void setup() {
  Serial.begin(9600);
}

void loop() {
  int AnalogValue = analogRead(PIN_ANALOG_IN);    //read IO36 pin analog value
  float Rt=0;      //NTC Thermistor
  float R=10000;   // resistor with fixed resistance value of 10K
  float B=3950;    //B value is an important parameter of thermistor
  float K=273.15;  //Degree Kelvin (K°)
  float VR=0;
  VR = (float)(AnalogValue / 4095.0 * 3.3);  //convert to voltage value
  Rt = (3.3 - VR) / VR * 10000;    //calculate NTC Thermistor resistance
  float temp = 1/(1/(273.15+25)+log(Rt/R)/B)-K+0.5;//calcualte temperature
  Serial.print("ADC value:");
  Serial.print(AnalogValue);
  Serial.print("  |  Voltage:");
  Serial.print(VR);
  Serial.print("V");
  Serial.print("  |  Temperature:");
  Serial.print(temp);
  Serial.println("℃");
  delay(200);
}
