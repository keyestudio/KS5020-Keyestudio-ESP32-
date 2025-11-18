/*  
 * Filename: Joystick
 * Function: read joystick values
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/ 
*/
int VRx = 36;  //define X pin to IO36
int VRy = 39;  //define Y pin to IO39
int SW = 26;    //define B pin to IO26
int xPosition = 0;  //set variable xPosition initial value to 0
int yPosition = 0;  //set variable yPosition initial value to 0
int SW_state = 0;  //set variable SW_state initial value to 0

void setup() {
Serial.begin(9600); 
pinMode(VRx, INPUT);  //X axis pin to input mode
pinMode(VRy, INPUT);  //Y axis pin to input mode
pinMode(SW, INPUT_PULLUP);   //Z axis pin to input pull-up mode
}

// In loop(), use analogRead() to read the values for the X and Y axes
// And use digitalRead() to read the z-axis values and then display them.
void loop() {
  xPosition = analogRead(VRx); 
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  Serial.print("X: ");
  Serial.print(xPosition);
  Serial.print(" | Y: ");
  Serial.print(yPosition);
  Serial.print(" | Button: ");
  Serial.println(SW_state);
  delay(100);
}