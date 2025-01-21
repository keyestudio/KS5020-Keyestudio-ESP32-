/*
 * Filename: WiFi_Web_Control_Smart_Life  
 * Function: WIFI web controls multiple components and modules to simulate WiFi smart life
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
#include <Arduino.h>
#include <WiFi.h>
#include <ESP32Servo.h>

/*REPLACE WITH YOUR NETWORK CREDENTIALS(Put your SSID & Password)*/
const char* ssid = "REPLACE_WITH_YOUR_SSID";  //Enter SSID here
const char* password = "REPLACE_WITH_YOUR_PASSWORD"; //Enter Password here

// A variable used to store HTTP requests
String header;

const int ledPins[] = {27, 16, 17};  // Define the red, green, and blue pins in order
const byte chns[] = {1, 2, 3};     // Define PWM channel
int red, green, blue;

const int buzzerPin = 18;   // set active buzzer pin to IO18
const int motoraPin = 13;   // set motor IN+ digital pin to IO13
const int motorbPin = 12;   // set motor IN- digital pin to IO12
const int relayPin = 25;  // set relay pin to IO25
const int servoPin = 4;  // set servo pin to IO4
Servo myservo;  // Create servo objects to control servo
// Define the minimum and maximum pulse widths for the servo
const int minPulseWidth = 500; // 0.5 ms
const int maxPulseWidth = 2500; // 2.5 ms

int status = WL_IDLE_STATUS;
WiFiServer server(80);

unsigned long currentTime = millis(); // Current time
unsigned long previousTime = 0;  // Previous time
const long timeoutTime = 2000; // set timeout period in milliseconds (example: 2000ms = 2s)

void setup() {
  Serial.begin(115200);  // set baud rate
  for (int i = 0; i < 3; i++) {   //set pwm channel，1KHz,8bit
    ledcSetup(chns[i], 1000, 8);
    ledcAttachPin(ledPins[i], chns[i]);
  }
  pinMode(motoraPin, OUTPUT);  // set motor 的IN+ pin to output
  pinMode(motorbPin, OUTPUT);  // set motor 的IN- pin to output
  pinMode(relayPin, OUTPUT);   // set relay pin to output
  pinMode(buzzerPin, OUTPUT);  // set active buzzer pin to output

  myservo.attach(servoPin);  //set servo pin to IO4
  myservo.write(0); //rotate to 0°
  delay(1000); //delay 1s

  // Connect to a Wi-Fi network through the SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print the local IP address and start the Web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();   // Monitor data

  if (client) {                             // If a new client connects,
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // Print a message in the serial monitor
    String currentLine = "";                // Create a string to store incoming data from the client
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // Loop when the client connects
      currentTime = millis();
      if (client.available()) {             // If there are bytes to be read from the client,
        char c = client.read();             // Read a byte
        Serial.write(c);                    // Print it out to the serial monitor
        header += c;
        if (c == '\n') {                    // If the byte is a line-break
           // If the current line is empty, there are two newlines in a row.
           // This is the end of the client HTTP request, so send the response:
          if (currentLine.length() == 0) {
             // HTTP header always starts with a response code (e.g. HTTP/1.1 200 OK)
             // A content type so that the client knows what to expect next, followed by a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            // web page title
            client.println("<body><h1>ESP32 Web Server</h1>");
            // The content of the HTTP response follows the header:
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/A\">here</a> turn on Relay<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/B\">here</a> turn off Relay<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/C\">here</a> turn on RGB<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/D\">here</a> turn off RGB<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/E\">here</a> turn on fan<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/F\">here</a> turn off fan<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/G\">here</a> turn on buzzer<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/H\">here</a> turn off buzzer<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/I\">here</a> <br>servo turn to 180</p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/J\">here</a> <br>servo turn to 0</p>");
           
            // The HTTP response ends with another blank line:
            client.println();
            // exit while loop:
            break;
          } else {    // If line break, clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // If there are any characters other than the carriage return,
          currentLine += c;      // And add it to the end of currentLine
        }

        // Check whether the client request exists "GET /A"or"GET /B"or"GET /C"or"GET /D"or"GET /E"or"GET /F"or"GET /G"or"GET /H"or"GET /I"or"GET /J":
        if (currentLine.endsWith("GET /A")) {    // GET /A turn off relay
          digitalWrite(relayPin, HIGH);       
        }
        if (currentLine.endsWith("GET /B")) {    // GET /B turn off relay
          digitalWrite(relayPin, LOW); 
        }
        if (currentLine.endsWith("GET /C")) {    // GET /C turn off RGB
            // Cycle through basic colors
          setColor(255, 0, 0);  // Red
          delay(1000);       // Wait for 1 second
          setColor(0, 255, 0);  // Green
          delay(1000);       // Wait for 1 second
          setColor(0, 0, 255);  // Blue
          delay(1000);       // Wait for 1 second

            // Cycle through blended colors
          setColor(255, 0, 252);  // Magenta
          delay(1000);         // Wait for 1 second
          setColor(237, 109, 0);  // Orange
          delay(1000);         // Wait for 1 second
          setColor(255, 215, 0);  // Yellow
          delay(1000);         // Wait for 1 second
          setColor(34, 139, 34);  // Forest Green
          delay(1000);         // Wait for 1 second
          setColor(0, 112, 255);  // Light Blue
          delay(1000);         // Wait for 1 second
          setColor(0, 46, 90);    // Indigo
          delay(1000);         // Wait for 1 second
          setColor(128, 0, 128);  // Purple
          delay(1000);         // Wait for 1 second       
        }
        if (currentLine.endsWith("GET /D")) {    // GET /D turn off RGB
          setColor(0, 0, 0);  // Black
        }
        if (currentLine.endsWith("GET /E")) {  // GET /E motor rotate
          digitalWrite(motoraPin, LOW);  
          digitalWrite(motorbPin, HIGH);               
        }
        if (currentLine.endsWith("GET /F")) {  // GET /F motor does not rotate
          digitalWrite(motoraPin, LOW);  
          digitalWrite(motorbPin, LOW);                 
        }
        if (currentLine.endsWith("GET /G")) {  // GET /G turn off active buzzer
          digitalWrite(buzzerPin, HIGH);                              
        }
        if (currentLine.endsWith("GET /H")) {  // GET /H turn off passive buzzer
          digitalWrite(buzzerPin, LOW);                              
        }
        if (currentLine.endsWith("GET /I")) {  // GET /J servorotates to 180°
          myservo.write(180); //rotate to 180°
          delay(1000); //delay 1s
        }
        if (currentLine.endsWith("GET /J")) {  // GET /K servorotates to 0°
          myservo.write(0); //rotate to 0°
          delay(1000); //delay 1s
        }
      } 
    }
    // clear header
    header = "";
    // disconnect:
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}

// Function to set the RGB LED color
void setColor(int red, int green, int blue) {
  ledcWrite(chns[1], red); //Common cathode LED, is on at high level
  ledcWrite(chns[2], green);
  ledcWrite(chns[3], blue);
}
