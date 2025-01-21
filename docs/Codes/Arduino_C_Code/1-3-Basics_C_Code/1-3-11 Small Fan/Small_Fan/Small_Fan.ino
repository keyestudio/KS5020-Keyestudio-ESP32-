/*
 * Filename: Small_Fan
 * Function: fan rotates
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int Motorla = 13;  // motor Motor_IN+ pin
const int Motorlb = 12;  // motor Motor_IN- pin

void setup(){
  pinMode(Motorla, OUTPUT);// set Motorla to OUTPUT
  pinMode(Motorlb, OUTPUT);// set Motorlb to OUTPUT
}
void loop(){
// set to rotate clockwise for 5s
  digitalWrite(Motorla,HIGH);
  digitalWrite(Motorlb,LOW);
  delay(5000);
// set to stop rotating for 2s 
  digitalWrite(Motorla,LOW);
  digitalWrite(Motorlb,LOW);
  delay(2000);
// set to rotate counterclockwise for 5s
  digitalWrite(Motorla,LOW);
  digitalWrite(Motorlb,HIGH);
  delay(5000);
// set to stop rotating for 2s 
  digitalWrite(Motorla,LOW);
  digitalWrite(Motorlb,LOW);
  delay(2000);
}
