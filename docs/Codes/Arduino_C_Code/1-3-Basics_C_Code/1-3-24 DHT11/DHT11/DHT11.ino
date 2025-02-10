/*  
 * Filename: Dht11
 * Function: detect temperature and humidity with DHT11
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/ 
*/
#include "DHT.h"

#define DHTPIN 13  // Set the IO13 connected to the DHT11 data pin
#define DHTTYPE DHT11 // DHT 11 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);  // Set the baud rate of the serial port
  Serial.println("DHT11 test!");  // Print string "DHT11 test!"
  dht.begin();  // Initialize DHT11
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (it's a very slow sensor)
  float humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // Print the humidity and temperature
  Serial.print("Humidity: "); 
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(temperature);
  Serial.println(" ℃");
  // Wait a few seconds between measurements.
  delay(200);
}
