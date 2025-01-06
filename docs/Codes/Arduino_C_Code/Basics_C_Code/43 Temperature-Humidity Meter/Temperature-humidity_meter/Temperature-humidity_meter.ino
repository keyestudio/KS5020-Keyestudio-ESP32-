/*  
 * 名称   : Temperature-humidity meter
 * 功能   ：I2C 128×32 LCD显示屏显示温度和湿度模拟温湿度仪表
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
 */
#include "DHT.h" 
#include "lcd128_32_io.h"

#define DHTPIN 13  // Set the pin connected to the DHT11 data pin
#define DHTTYPE DHT11 // DHT 11 

DHT dht(DHTPIN, DHTTYPE);

lcd lcd(21, 22); // 创建IIC LCD 128*32引脚:SDA-->IO21, SCL-->IO22

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  dht.begin();
  lcd.Init();  // 初始化
  lcd.Clear(); // 清屏
}
char string[10];

//LCD显示湿度和温度值
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
  lcd.Cursor(0,0); // 设置显示的位置
  lcd.Display("Temper:"); //设置显示的内容
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

