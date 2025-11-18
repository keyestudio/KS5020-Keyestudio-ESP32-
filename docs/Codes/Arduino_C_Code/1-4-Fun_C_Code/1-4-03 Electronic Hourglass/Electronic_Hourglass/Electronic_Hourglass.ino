/*  
 * Filename: Electronic_Hourglass
 * Function: Control 4 LED analog electronic hourglass with tilt switch
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const byte SWITCH_PIN = 26; // connect tilt sensor pin to IO26
const int led1 = 16;  //connect led1 pin to IO16
const int led2 = 17;  //connect led2 pin to IO17
const int led3 = 18;  //connect led3 pin to IO18
const int led4 = 19;  //connect led4 pin to IO18

byte switch_state = 0; //set switch_state initial value to 0

void setup(){
  Serial.begin(9600); //set baud rate to 9600
  pinMode(SWITCH_PIN, INPUT); //set tilt sensor pin to input
  for(int i=16;i<20;i++){  //set 4 LED pin to output
    pinMode(i, OUTPUT);
  } 
  for(int i=16;i<20;i++){ //set 4 LED to off
    digitalWrite(i,0);
  } 
}

void loop(){
  switch_state = digitalRead(SWITCH_PIN); //read tilt sensor value and assign to switch_state
  Serial.println(switch_state); //print tilt sensor value 
  if (switch_state == 1) {  //if tilt sensor tilts（value = 1）
    for(int i=16;i<20;i++){  //4 LED gradually on
      digitalWrite(i,1);
      delay(500);
    } 
  }
  if (switch_state == 0) {  //if tilt sensor does not tilt（value = 0）
    for(int i=19;i>15;i--){  //4 LED gradually off
      digitalWrite(i,0);
      delay(500);
    }
  }
}
