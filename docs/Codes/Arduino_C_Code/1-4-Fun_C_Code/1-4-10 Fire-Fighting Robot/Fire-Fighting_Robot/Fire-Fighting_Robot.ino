/*  
 * Filename: Fire-fighting robot
 * Function: Flame sensors control motors and leds to simulate fire fighting robots
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int flamePin = 36;   // set flame sensor pin to IO36
const int motoraPin = 13;  // set motor motor_IN+ pin to IO13
const int motorbPin = 12; // set motor motor_IN- pin to IO12
const int ledPin = 25;   // set led pin to IO25
int item = 0; // set item to 0

void setup() {
  Serial.begin(9600);  // set baud rate to 9600
  pinMode(flamePin, INPUT); // set flame sensor pin to input
  pinMode(motoraPin, OUTPUT); // set motor motor_IN+ pin to output
  pinMode(motorbPin, OUTPUT); // set motor motor_IN- pin to output
  pinMode(ledPin, OUTPUT); // set led pin to output
}

void loop() {
  item = analogRead(flamePin);  // read flame sensor analog value, and assign it to item
  Serial.print(item);  // print the analog value
  if (item > 2000) {  // When the analog value is above 2000, turn on the fan and the LED flashes 
    Serial.print("   "); 
    Serial.println("Put out a fire");
    digitalWrite(motoraPin, HIGH);  //motor rotates
    digitalWrite(motorbPin, LOW);
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);  
  } 
  else {//Otherwise, turn off the fan and the LED
    Serial.print("   "); 
    Serial.println("No flame detected");
    digitalWrite(motoraPin, LOW); 
    digitalWrite(motorbPin, LOW);
    digitalWrite(ledPin, LOW); 
  } 
}
