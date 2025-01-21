/*  
 * Filename: IR Receiver
 * Function: Decode infrared remote control, print it out through serial port
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t recvPin = 5;  // set ir receiver to pin IO5
IRrecv irrecv(recvPin);      // Creates a class object for the receiver
decode_results results;       // Create the decoded result class object

void setup() {
  Serial.begin(9600);       // set baud rate to 9600
  irrecv.enableIRIn();        // start receiver
  Serial.print("IRrecvDemo is now running and waiting for IR message on Pin ");
  Serial.println(recvPin);   //Print the signal received by the infrared receiving pin
}

void loop() {
  if (irrecv.decode(&results)) {          // Wait for decoding
    serialPrintUint64(results.value, HEX);// Print out the decoded result
    Serial.println("");
    irrecv.resume();                      // Release the IRremote. Receive the next value
  }
  delay(100);
}