/*  
 * Filename: Temperature-Humidity Meter
 * Function: I2C 128×32 LCD display temperature and humidity to simulate the temperature and humidity meter
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
 */
#include "DHT.h" 
#include "lcd128_32_io.h"

#define DHTPIN 13  // Set the pin connected to the DHT11 data pin
#define DHTTYPE DHT11 // DHT 11 

DHT dht(DHTPIN, DHTTYPE);

lcd lcd(21, 22); // create IIC LCD 128*32 pin: SDA-->IO21, SCL-->IO22

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  dht.begin();
  lcd.Init();  // initalize 
  lcd.Clear(); // clear display
}
char string[10];

//LCD display temperature and humidity
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
  lcd.Cursor(0,0); // set displayed position
  lcd.Display("Temper:"); //set displayed content
  lcd.Cursor(0,8);
  lcd.DisplayNum(temperature);
  lcd.Cursor(0,11);
  lcd.Display("C");
  lcd.Cursor(2,0); 
  lcd.Display("humid:");
  lcd.Cursor(2,8);
  lcd.DisplayNum(humidity);
  lcd.Cursor(2,11);
  lcd.Display("%");
  delay(200);
}

