/*  
 * Filename: Temperature from LM35 on Web Server
 * Function: The LM35 detected temperature is displayed on the Web server
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
// Import required libraries
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <WebSocketsServer.h>
#include "index.h"

const int lm35Pin = 36;   // ESP32 pin GPIO36 connected to LM35 sensor's DATA pin

/*REPLACE WITH YOUR NETWORK CREDENTIALS(Put your SSID & Password)*/
const char* ssid = "REPLACE_WITH_YOUR_SSID";  //Enter SSID here
const char* password = "REPLACE_WITH_YOUR_PASSWORD"; //Enter Password here

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  pinMode(lm35Pin, INPUT);  //Set the lm35Pin to the input mode
  
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Print the ESP32's IP address
  Serial.print("ESP32 Web Server's IP address: ");
  Serial.println(WiFi.localIP());

   // Serve the HTML page from the file
  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    Serial.println("ESP32 Web Server: New request received:");  // for debugging
    Serial.println("GET /");                                    // for debugging

    request->send(200, "text/html", webpage); // webpage is from index.h file
  });                                    // for debugging


  // Define a route to get the temperature data
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest* request) {
    Serial.println("ESP32 Web Server: New request received:");  // for debugging
    Serial.println("GET /temperature");

    long value = analogRead(lm35Pin); //Read analog input
    // get temperature from sensor
    // Voltage and Celsius conversion:
    // 0.0012210012210012 = 5.0/4095, 0~5.0V corresponds to the analog port reading 0~4095, and every 10 millivolts corresponds to 1℃
    float temperature = (value * 0.0012210012210012 * 100);
    // Format the temperature with two decimal places
    String temperatureStr = String(temperature, 2);
    request->send(200, "text/plain", temperatureStr);
  });

  // Start the server
  server.begin();
}

void loop() {
  // Your code here
}
