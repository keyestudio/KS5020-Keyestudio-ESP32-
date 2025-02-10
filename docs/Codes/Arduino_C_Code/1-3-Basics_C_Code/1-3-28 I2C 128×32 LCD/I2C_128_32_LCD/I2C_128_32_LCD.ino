/*
 * Filename: LCD 128*32
 * Function: LCD 128*32 shows character strings
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
#include "lcd128_32_io.h"

lcd lcd(21, 22); // Create IIC LCD 128*32 pin: SDA-->IO21, SCL-->IO22

void setup() {
  lcd.Init();  // initialize
  lcd.Clear(); // clear
}

void loop() {
  lcd.Cursor(0, 4); // Set the location of the display
  lcd.Display("KEYESTUDIO"); // Sets the string to be displayed
  lcd.Cursor(1, 0);
  lcd.Display("ABCDEFGHIJKLMNOPQR");
  lcd.Cursor(2, 0);
  lcd.Display("123456789+-*/<>=$@");
  lcd.Cursor(3, 0);
  lcd.Display("%^&(){}:;'|?,.~\\[]");
}

