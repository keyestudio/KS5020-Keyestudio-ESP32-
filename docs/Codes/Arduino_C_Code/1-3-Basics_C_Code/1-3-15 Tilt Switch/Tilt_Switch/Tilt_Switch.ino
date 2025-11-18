/*
 * Filename: Tilt_Switch
 * Function: read tilt sensor value
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/ 
*/
int SWITCH_PIN = 14; // set tilt sensor pin to IO14
int val = 0;       // store tilt sensor value

void setup(){
  Serial.begin(9600); // set baud rate to 9600
  pinMode(SWITCH_PIN, INPUT); // set tilt sensor pin to input
} 

void loop(){
  val = digitalRead(SWITCH_PIN); // read tilt sensor value and assign it to val
  Serial.print(val);  // print val value
  if (val == 1) {  // tilt sensor tilts, read high and print relavent message
    Serial.print("    ");  
    Serial.println("Tilt"); // print tilt sensor "tilt"
    delay(100); 
  }
  else {  // tilt sensor does not tilt, read low
    Serial.print("    ");
    Serial.println("No tilt");
    delay(100);
  }
}
