/*  
 * Filename: Cooling_Device
 * Function: The LM35 temperature sensor controls the OLED and motor to simulate the cooling unit
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int lm35Pin = 36;  //set LM35 pin to IO36
const int motoraPin = 16;  //set motor motor_IN+ pin to IO16
const int motorbPin = 17; //set motor motor_IN- pin to IO17


void setup() {
  Serial.begin(9600);  // set baud rate to 9600
  pinMode(lm35Pin, INPUT); // set lm35Pin to input
  pinMode(motoraPin, OUTPUT); // set motor motor_IN+ pin to output
  pinMode(motorbPin, OUTPUT); // set motor motor_IN- pin to output

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Initialization with I2C addr 0x3C (for 128x64)
  display.clearDisplay(); // clear display
}

void loop() {
  int reading = analogRead(lm35Pin);  // read LM35 pin analog value
  int temperC = (reading * 0.0012210012210012 * 100); //Voltage and Celsius conversion:0.0012210012210012 = 5.0/4095，0~5. 0V corresponds to analog port reading 0~4095, every 10 millivolts corresponds to 1℃; Calculate the Celsius temperature.
  display.clearDisplay();  // clear display
  display.setTextSize(1);  // set text size
  display.setTextColor(WHITE);  // set text color
  display.setCursor(0,0);   // set text position
  display.println("Cooling Device");  // set text content 
  display.setCursor(0,30);   // set text position
  display.println("Temper(C):");  // set text content
  display.setCursor(60,30);
  display.println(temperC);
  display.display();
  delay(200);
  if (temperC > 30) { // When the temperature exceeds 30 ° C, the fan turns on
    digitalWrite(motoraPin, HIGH);  //motor rotates
    digitalWrite(motorbPin, LOW);
  } 
  else { // otherwise, the fan turns off
    digitalWrite(motoraPin, LOW); 
    digitalWrite(motorbPin, LOW);
  }
}