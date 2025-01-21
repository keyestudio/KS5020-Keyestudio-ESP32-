/*  
 * Filename: Volume Detector
 * Function: I2C 128×32 LCD displays the volume detected by the sound sensor
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
#include "lcd128_32_io.h"

#define PIN_ANALOG_IN 36 // set sound sensor pin to IO36

lcd lcd(21, 22); // create IIC LCD 128*32 pin: SDA-->IO21, SCL-->IO22

void setup() {
  lcd.Init();  // initalize 
  lcd.Clear(); // clear display
}
char string[10];

//LCD displays the volume
void loop() {
  int Value = analogRead(PIN_ANALOG_IN);    //read pin IO36 analog value
  lcd.Cursor(0,2); // set displayed position
  lcd.Display("Volume Detector"); //set displayed content
  lcd.Cursor(2,4); 
  lcd.Display("Volume:");
  lcd.Cursor(2,12);
  lcd.DisplayNum(Value);
  delay(200);
}
