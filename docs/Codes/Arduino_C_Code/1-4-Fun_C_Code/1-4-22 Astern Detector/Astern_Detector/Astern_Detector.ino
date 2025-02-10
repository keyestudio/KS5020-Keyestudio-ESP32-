/*  
 * Filename: Astern_Detector
 * Function: Ultrasonic control OLED and passive buzzer to simulate astern detector
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

const int BUZZER_PIN = 26;   //set passive buzzer pin to IO26

const int TrigPin = 18; //set Trig pin to IO18
const int EchoPin = 19; //set Echo pin to IO19
int distance;     // ultrasound to measure distance

float checkdistance() { //Get distance
  // Give a short low level beforehand to ensure a clean high pulse
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  // The sensor is triggered by a high pulse of 10 microseconds or more
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  // Read the signal from the sensor: a high level pulse
  // Its duration is the time (in microseconds) from sending the ping command to receiving the response from the object.
  float distance = pulseIn(EchoPin, HIGH) / 58.00;  //Convert to distance
  delay(300);
  return distance;
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);  // set buzzer to output mode
  ledcSetup(3, 660, 13);        //set pwm channel,660Hz,13bit
  ledcAttachPin(BUZZER_PIN, 3);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Initialization with I2C addr 0x3C (for 128x64)
  display.clearDisplay(); // clear display
  
  pinMode(TrigPin, OUTPUT);     //set Trig pin to output
  pinMode(EchoPin, INPUT);      //set Echo pin to input
}

void loop() {
  distance = checkdistance(); //Ultrasonic ranging
  display.clearDisplay();  // clear display
  display.setTextSize(1);  // set text size
  display.setTextColor(WHITE);  // set text color
  display.setCursor(0,0);   // set text position
  display.println("Astern Detector");  // set text content 
  display.setCursor(0,30);   // set text position
  display.println("Distance(cm):");  // set text content
  display.setCursor(80,30);
  display.println(distance);
  display.display();
  delay(50);
  if (distance <= 10) {   
    ledcWrite(3, 450);
    delay(500);

  } else if (distance > 10 && distance <= 20) {
    ledcWrite(3, 100);
    delay(100);
  } else {
    ledcWrite(3, 0);
  }
}

