/*  
 * Filename: Guess_Numbers
 * Function: Infrared remote control a digital tube displays numbers and leds to simulate guessing numbers
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t recvPin = 18;  // set IR receiver pin to IO18
IRrecv irrecv(recvPin);      // create class object for the receiver
decode_results results;       // create class object for decoded results
// set each segment IO pins
const int a = 16;  // set a-segment digital pin to IO16
const int b = 17;  // set b-segment digital pin to IO17
const int c = 14;  // set c-segment digital pin to IO14
const int d = 12;  // set d-segment digital pin to IO12
const int e = 13;  // set e-segment digital pin to IO13
const int f = 5;  // set f-segment digital pin to IO5
const int g = 23;  // set g-segment digital pin to IO23
const int dp = 27;  // set dp-segment digital pin to IO27
const int ledPin = 26;  //set external LED pin to IO26

boolean flag = true;  //LED flag

void setup() {
  Serial.begin(9600);       // set baud rate to 9600
  irrecv.enableIRIn();        // Start receiver
  Serial.print("IRrecvDemo is now running and waiting for IR message on Pin ");
  Serial.println(recvPin);   //print the received signals
  pinMode(a, OUTPUT);  // set digital tube a-segment pin to output mode
  pinMode(b, OUTPUT);  // set digital tube b-segment pin to output mode
  pinMode(c, OUTPUT);  // set digital tube c-segment pin to output mode
  pinMode(d, OUTPUT);  // set digital tube d-segment pin to output mode
  pinMode(e, OUTPUT);  // set digital tube e-segment pin to output mode
  pinMode(f, OUTPUT);  // set digital tube f-segment pin to output mode
  pinMode(g, OUTPUT);  // set digital tube g-segment pin to output mode
  pinMode(dp, OUTPUT);  // set digital tube dp-segment pin to output mode
  pinMode(ledPin, OUTPUT);  // set LED pin to output mode
}

void loop() {
  if(irrecv.decode(&results)) {        // Wait for decoding
    serialPrintUint64(results.value, HEX);// Output decoding result
    Serial.println("");
    handleControl(results.value);      // Handle commands from remote control
    irrecv.resume();                   // Receive the next value
  }
}

void handleControl(unsigned long value){
  if (value == 0xFF02FD && flag == true){ // press key “OK” on the remote control and receive “OK” 
    digitalWrite(ledPin, HIGH);
    flag = false;
  } 
  else if (value == 0xFF02FD && flag == false){ // press key “OK” on the remote control and receive “OK”
    digitalWrite(ledPin, LOW);
    flag = true;
  } 
  else if(value == 0xFF6897){ // press key “1” on the remote control
    digital_1();// show number 1
  } 
  else if(value == 0xFF9867){ // press key “2” on the remote control
    digital_2();// show number  2
  } 
  else if(value == 0xFFB04F){ // press key “3” on the remote control
    digital_3();// show number  3
  }
  else if(value == 0xFF30CF){ // press key “4” on the remote control
    digital_4();// show number  4
  }
  else if(value == 0xFF18E7){ // press key “5” on the remote control
    digital_5();// show number  5
  }
  else if(value == 0xFF7A85){ // press key “6” on the remote control
    digital_6();// show number  6
  }
  else if(value == 0xFF10EF){ // press key “7” on the remote control
    digital_7();// show number  7
  }
  else if(value == 0xFF38C7){ // press key “8” on the remote control
    digital_8();// show number  8
  }
  else if(value == 0xFF5AA5){ // press key “9” on the remote control
    digital_9();// show number  9
  }
  else if(value == 0xFF4AB5){ // press key “0” on the remote control
    digital_0();// show number  0
  }
  else if(value == 0xFF42BD){ // press key “*” on the remote control
    // 1-bit digital tube segments a-dp are all off
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    digitalWrite(dp,LOW);
  }
}

void digital_0(void) { // show number 0
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  digitalWrite(dp,LOW);
}
void digital_1(void) { // show number  1
  unsigned char j;
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    digitalWrite(dp,LOW);
}
void digital_2(void) { // show number  2
  unsigned char j;
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
}
void digital_3(void) { // show number  3
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
}
void digital_4(void) { // show number  4
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
}
void digital_5(void) { // show number  5
  unsigned char j;
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
}
void digital_6(void) { // show number  6
  unsigned char j;
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
}
void digital_7(void) { // show number  7
  unsigned char j;
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    digitalWrite(dp,LOW);
}
void digital_8(void) { // show number  8
  unsigned char j;
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
}
void digital_9(void) { // show number  9
  unsigned char j;
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,LOW);
}