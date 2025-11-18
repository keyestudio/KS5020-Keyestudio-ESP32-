/*  
 * Filename: Temperature_Detector
 * Function: OLED displays the voltage and temperature detected by the thermistor
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define PIN_ANALOG_IN 36 // connect thermistor pin to IO36

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // initialize with I2C addr 0x3C (specialize for 128x64)
  display.clearDisplay(); // clear display
}

void loop(){
  int AnalogValue = analogRead(PIN_ANALOG_IN);  // read IO36 pin analog value
  float Rt=0;      // NTC thermistor
  float R=10000;   // resistor with fixed resistance value of 10K
  float T2=273.15+25; // Convert to Kelvin temperature
  float B=3950;    // B value is an important parameter of thermistor
  float K=273.15;  // Fahrenheit (K°)
  float VR=0;
  VR = (float)(AnalogValue / 4095.0 * 3.3);  // Convert to a voltage value
  Rt = (3.3 - VR) / VR * 10000;    // Calculate the NTC thermistor
  float temp = 1/(1/T2+log(Rt/R)/B)-K+0.5;// Calculate temperature
  display.clearDisplay();  // clear display
  display.setTextSize(1);  // set text size
  display.setTextColor(WHITE);  // set text color
  display.setCursor(15,0);   // set text position
  display.println("Temperature Meter");  // set text content 
  display.setCursor(0,25);   // set text position
  display.println("Voltage:");  // set text content
  display.setCursor(50,25);
  display.println(VR);
  display.setCursor(80,25);
  display.println("V");
  display.setCursor(0,50);
  display.println("Temperature:");
  display.setCursor(75,50);
  display.println(temp);
  display.setCursor(110,50);
  display.println("C");
  display.display();
  delay(150);
}
