/*  
 * Filename: LM35
 * Function: detect temperature with LM35
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int lm35Pin = 36;  //set lm35 pin to GPIO36
float temperature = 0; //set variable temperature initial value to 0
long value = 0; //set variable value initial value to 0

void setup() {
  Serial.begin(9600); //set baud rate to 9600
  pinMode(lm35Pin, INPUT);  //set lm35Pin to input
}

void loop() {
  value = analogRead(lm35Pin); //read analog intput

  //Voltage and Celsius conversion:
  //0.0012210012210012 = 5.0/4095，0~5. 0V corresponds to the analog port reading of 0~4095, every 10 millivolts corresponds to 1 °C.
  temperature = (value * 0.0012210012210012 * 100);
  
  Serial.print("Temper =  ");
  Serial.print(temperature);
  Serial.println("℃");
  delay(100);
}

