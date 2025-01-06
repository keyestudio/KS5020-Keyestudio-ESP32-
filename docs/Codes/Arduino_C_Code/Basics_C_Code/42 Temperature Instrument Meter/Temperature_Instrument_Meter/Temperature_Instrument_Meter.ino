/*  
 * 名称   : Temperature_Detector
 * 功能   : OLED显示屏显示热敏电阻检测的电压和温度
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define PIN_ANALOG_IN 36 // 热敏电阻的引脚连接到IO36

#define SCREEN_WIDTH 128 // 显示宽度，以像素为单位
#define SCREEN_HEIGHT 64 // OLED 显示高度，以像素为单位

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // 使用 I2C addr 0x3C 进行初始化(针对128x64)
  display.clearDisplay(); // 清屏
}

void loop(){
  int AnalogValue = analogRead(PIN_ANALOG_IN);  // 读IO36引脚的模拟值
  float Rt=0;      // NTC 热敏电阻
  float R=10000;   // 具有固定电阻值的10K电阻
  float T2=273.15+25; // 转换成开尔文温度
  float B=3950;    // B值是热敏电阻的一个重要参数
  float K=273.15;  // 华氏度 (K°)
  float VR=0;
  VR = (float)(AnalogValue / 4095.0 * 3.3);  // 转换成电压值
  Rt = (3.3 - VR) / VR * 10000;    // 计算NTC热敏电阻
  float temp = 1/(1/T2+log(Rt/R)/B)-K+0.5;// 计算温度
  display.clearDisplay();  // 清屏
  display.setTextSize(1);  // 设置显示字体的大小
  display.setTextColor(WHITE);  // 设置显示字体的颜色
  display.setCursor(15,0);   // 设置显示字体的位置
  display.println("Temperature Meter");  // 设置显示的内容 
  display.setCursor(0,25);   // 设置显示字体的位置
  display.println("Voltage:");  // 设置显示的内容
  display.setCursor(50,25);
  display.println(VR);
  display.setCursor(80,25);
  display.println("V");
  display.setCursor(0,50);
  display.println("Temperature:");
  display.setCursor(75,50);
  display.println(temp);
  display.setCursor(110,50);
  display.println("C");
  display.display();
  delay(150);
}
