/*
 * Filename: Blynk-based_Intrusion_Notification_System
 * Function: Intrusion notification system based on Blynk
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPxxxxxxx"
#define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
#define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxx"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

/*REPLACE WITH YOUR NETWORK CREDENTIALS(Put your SSID & Password)*/
const char* ssid = "REPLACE_WITH_YOUR_SSID";  //Enter SSID here
const char* password = "REPLACE_WITH_YOUR_PASSWORD"; //Enter Password here

// Define the PIR sensor pin and related variables
const int sensorPin = 14;
int state = 0;
int awayHomeMode = 0;

const int ledPin = 26; // Define LED pin to IO26.
const int buzzerPin = 19; // the buzzer pin

// Create Blynk Timer object
BlynkTimer timer;

void setup() {
  Serial.begin(115200);  // Start serial communication at 115200 baud rate for debugging
  pinMode(sensorPin, INPUT);  // Set PIR sensor pin as input
  pinMode(ledPin, OUTPUT); // Set LED pin to output
  pinMode(buzzerPin, OUTPUT); // Set as output

  // Configure Blynk and connect to WiFi
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);

  timer.setInterval(1000L, myTimerEvent);  // Setup a function to be called every second
}

void loop() {
  Blynk.run();  // Run Blynk
  timer.run();  // Run BlynkTimer
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED() {
  Blynk.syncVirtual(V0);
}

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0) {
  awayHomeMode = param.asInt();  // Set incoming value from pin V0 to a variable

  if (awayHomeMode == 1) {
    Serial.println("The switch on Blynk has been turned on.");
    Blynk.virtualWrite(V1, "Detecting signs of intrusion...");
  } else {
    Serial.println("The switch on Blynk has been turned off.");
    Blynk.virtualWrite(V1, "Away home mode close");
  }
}

void myTimerEvent() {
  // Please don't send more that 10 values per second.
  sendData();  // Call function to send sensor data to Blynk app
}

// Function to send sensor data to Blynk app
void sendData() {
  if (awayHomeMode == 1) {
    state = digitalRead(sensorPin);  // Read the state of the PIR sensor

    Serial.print("state:");
    Serial.println(state);

    // If the sensor detects movement, send an alert to the Blynk app
    if (state == HIGH) {
      Serial.println("Somebody here!");
      Blynk.virtualWrite(V1, "Somebody in your house! Please check!");
      Blynk.logEvent("intrusion_detected");
      digitalWrite(ledPin, HIGH); // LED on.
      digitalWrite(buzzerPin, HIGH); // Set to HIGH to make the buzzer sound
      delay(500); // Delay 1s.
      digitalWrite(ledPin, LOW); // LED off.
      digitalWrite(buzzerPin, LOW); // LOW to turn off the buzzer
      delay(500); // Delay 1s.
    }
  }
}