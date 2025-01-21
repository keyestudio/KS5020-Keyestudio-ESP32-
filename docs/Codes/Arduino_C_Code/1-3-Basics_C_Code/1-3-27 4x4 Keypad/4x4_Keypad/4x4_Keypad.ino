/*  
 * Filename: 4x4_Keypad
 * Function: read 4*4 matrix keypad key values
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
#include <Keypad.h> // include Keypad 

//Defines symbols on keyboard buttons
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {26, 25, 17, 16}; // Connect the pins to the keypad rows
byte colPins[COLS] = {27, 14, 12, 13};   // Connect the pins to the keypad columns

// Initialize an instance of the myKeypad class
Keypad myKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // set baud rate to 115200
  Serial.println("ESP32 is ready!");  // print “ESP32 is ready!”
}

void loop() {
  // Get character input
  char keyPressed = myKeypad.getKey();
  // If there is any character input, it is sent to the serial port
  if (keyPressed) {
    Serial.println(keyPressed);
  }
}
