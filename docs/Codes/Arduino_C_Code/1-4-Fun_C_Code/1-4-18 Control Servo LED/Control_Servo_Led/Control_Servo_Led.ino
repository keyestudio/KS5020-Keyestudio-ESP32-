/*  
 * Filename: Control_Servo_Led
 * Function: control servo rotation and LED
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
#include <ESP32Servo.h>

const int servoPin = 4;  // set servo pin to IO4
Servo myservo;  //create servo object to control servo 

const int ledPin = 25; // set LED pin to IO25

const int buttonPin = 14; // set button pin to IO14
const int potentiometerPin = 36;  // set potentiometer pin to IO36

int val1 = 0;   // Store button values
int val2 = 0;   // set val2 to 0

void setup() {
  pinMode(potentiometerPin, INPUT);    // set potentiometer pin to input
  pinMode(buttonPin, INPUT);    // set button pin to input
  pinMode(ledPin, OUTPUT); // set ledpin to output
  myservo.attach(servoPin);  // set servo pin to IO4
  myservo.write(0); // servo roattes 0°
  delay(200); // delay 200ms
}

void loop() {
  val1 = digitalRead(buttonPin);  //read button value and assign it to val1
  if (val1 == 0) {       //when the button is pressed, read low
    digitalWrite(ledPin, HIGH); // LED on
    delay(5000);  // delay 5000ms
  }
  else {
    digitalWrite(ledPin, LOW); // LED off
  }  
  val2 = analogRead(potentiometerPin);    //read potentiometer analog values
  myservo.write((map(val2, 0, 4095, 0, 180)));   // map potentiometer analog values to servo position
  delay(5);   // delay 5ms to allow the servo rotates to the set position
}
