/*
 * 名称   : Internet Clock using ESP32 and OLED Display
 * 功能   : 使用 ESP32 和 OLED 显示屏的互联网时钟 
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
#include <WiFi.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

/*REPLACE WITH YOUR NETWORK CREDENTIALS(Put your SSID & Password)*/
const char* ssid = "REPLACE_WITH_YOUR_SSID";  //Enter SSID here
const char* password = "REPLACE_WITH_YOUR_PASSWORD"; //Enter Password here

#define NTP_OFFSET  19800        // In seconds 
#define NTP_INTERVAL 60 * 1000  // In miliseconds
#define NTP_ADDRESS  "1.asia.pool.ntp.org"
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, NTP_ADDRESS, NTP_OFFSET, NTP_INTERVAL);

#define SCREEN_WIDTH 128 // 显示宽度，以像素为单位
#define SCREEN_HEIGHT 64 // OLED 显示高度，以像素为单位

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup(){
  display.begin();
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  timeClient.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // 使用 I2C addr 0x3C 进行初始化(针对128x64)
  display.clearDisplay(); // 清屏
  display.setTextColor(WHITE);
  //display.startscrollright(0x00, 0x0F);
  display.setTextSize(2);
  //display.setCursor(0,0);
  //display.print("  Internet ");
  //display.println("  Clock ");
  //display.display();
  //delay(3000);
}

void loop(){
  timeClient.update();
  String formattedTime = timeClient.getFormattedTime();
  // Serial.println(formattedTime);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println(formattedTime);
  display.display();   // write the buffer to the display
  delay(10);
  delay(100);
}

