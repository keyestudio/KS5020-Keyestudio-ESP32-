/*
 * Filename: Control Relay Via Web Server
 * Function : Relay connecting and disconnecting are controlled through the Web server
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

#define relayPin 12  // ESP32 pin GPIO12 connected to Relay

/*REPLACE WITH YOUR NETWORK CREDENTIALS(Put your SSID & Password)*/
const char* ssid = "REPLACE_WITH_YOUR_SSID";  //Enter SSID here
const char* password = "REPLACE_WITH_YOUR_PASSWORD"; //Enter Password here

AsyncWebServer server(80);

int relay_state = LOW;

String getHTML() {
  String html = "<!DOCTYPE HTML>";
  html += "<html>";
  html += "<head>";
  html += "<link rel='icon' href='data:,'>";
  html += "</head>";
  html += "<p>Relay state: <span style='color: red;'>";

  if (relay_state == LOW)
    html += "OFF";
  else
    html += "ON";

  html += "</span></p>";
  html += "<a href='/relay1/on'>Turn ON</a>";
  html += "<br><br>";
  html += "<a href='/relay1/off'>Turn OFF</a>";
  html += "</html>";

  return html;
}

void setup() {
  Serial.begin(115200);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, relay_state);

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

  // home page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("ESP32 Web Server: New request received:");
    Serial.println("GET /");
    request->send(200, "text/html", getHTML());
  });

  // Route to control the Relay
  server.on("/relay1/on", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("ESP32 Web Server: New request received:");
    Serial.println("GET /relay1/on");
    relay_state = HIGH;
    digitalWrite(relayPin, relay_state);
    request->send(200, "text/html", getHTML());
  });
  server.on("/relay1/off", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("ESP32 Web Server: New request received:");
    Serial.println("GET /relay1/off");
    relay_state = LOW;
    digitalWrite(relayPin, relay_state);
    request->send(200, "text/html", getHTML());
  });

  // Start the server
  server.begin();
}

void loop() {
  // Your code here
}

