/*  
 * Filename: Joystick Display
 * Function: Joystick control OLED display
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// set Joystick pins
#define JOYSTICK_X_PIN 36 // VRx
#define JOYSTICK_Y_PIN 39 // VRy
#define JOYSTICK_SW_PIN 26 // SW(B)

void setup() {
  // initialize baud rate
  Serial.begin(115200);

  // initialize  OLED display
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) 
  {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // initialize Joystick pin
  pinMode(JOYSTICK_X_PIN, INPUT);
  pinMode(JOYSTICK_Y_PIN, INPUT);
  pinMode(JOYSTICK_SW_PIN, INPUT_PULLUP);

  //  clear display, and show initial message
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Joystick Test");
  display.display();
}

void loop() {
  // read Joystick X axis, Y axis and Z axis values
  int xValue = analogRead(JOYSTICK_X_PIN);
  int yValue = analogRead(JOYSTICK_Y_PIN);
  bool swValue = digitalRead(JOYSTICK_SW_PIN);

  //  clear display
  display.clearDisplay();
  display.setCursor(0, 0);

  // show X axis, Y axis and Z axis values
  display.print("X: ");
  display.println(xValue);
  display.print("Y: ");
  display.println(yValue);
  display.print("Z: ");
  display.println(swValue);

  // according to X axis and Y axis values, determine Joystick direction
  if (yValue < 1000) {
    display.println("Direction: Down");
  } else if (yValue > 3000) {
    display.println("Direction: Up");
  } else if (xValue < 1000) {
    display.println("Direction: Left");
  } else if (xValue > 3000) {
    display.println("Direction: Right");
  } else {
    display.println("Direction: Center");
  }

  // show button state
  if (swValue == HIGH) {
    display.println("Button: Pressed");
  } else {
    display.println("Button: Released");
  }

  // update display
  display.display();

  // delay to avoid flashes
  delay(100);
}