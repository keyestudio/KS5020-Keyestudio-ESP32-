/*
 * Filename: Web Plotter
 * Function: Draw multiple line plots in the Web server
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
// Import required libraries
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <WebSocketsServer.h>
#include "index.h"

/*REPLACE WITH YOUR NETWORK CREDENTIALS(Put your SSID & Password)*/
const char* ssid = "REPLACE_WITH_YOUR_SSID";  //Enter SSID here
const char* password = "REPLACE_WITH_YOUR_PASSWORD"; //Enter Password here

AsyncWebServer server(80);
WebSocketsServer webSocket = WebSocketsServer(81);  // WebSocket server on port 81

int last_update = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize WebSocket server
  webSocket.begin();
  //webSocket.onEvent(webSocketEvent);

  // Serve a basic HTML page with JavaScript to create the WebSocket connection
  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    Serial.println("Web Server: received a web page request");
    String html = HTML_CONTENT;  // Use the HTML content from the index.h file
    request->send(200, "text/html", html);
  });

  server.begin();
  Serial.print("ESP32 Web Server's IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  webSocket.loop();

  if (millis() - last_update > 500) {
    last_update = millis();
    String variable_1 = String(random(0, 100));
    String variable_2 = String(random(0, 100));
    String variable_3 = String(random(0, 100));
    String variable_4 = String(random(0, 100));

    // TO SERIAL PLOTTER
 // Serial.print(variable_1);
 // Serial.print(" ");  // a tab '\t' or space ' ' character is printed between the two values.
 // Serial.print(variable_2);
 // Serial.print(" ");  // a tab '\t' or space ' ' character is printed between the two values.
 // Serial.print(variable_3);
 // Serial.print(" ");           // a tab '\t' or space ' ' character is printed between the two values.
 // Serial.println(variable_4);  // the last value is terminated by a carriage return and a newline characters.

    // TO WEB PLOTTER
    webSocket.broadcastTXT(variable_1);
    webSocket.broadcastTXT(" ");  // a tab '\t' or space ' ' character is printed between the two values.
    webSocket.broadcastTXT(variable_2);
    webSocket.broadcastTXT(" ");  // a tab '\t' or space ' ' character is printed between the two values.
    webSocket.broadcastTXT(variable_3);
    webSocket.broadcastTXT(" ");  // a tab '\t' or space ' ' character is printed between the two values.
    webSocket.broadcastTXT(variable_4);
    webSocket.broadcastTXT("\r\n");  // the last value is terminated by a carriage return and a newline characters.
  }
}
