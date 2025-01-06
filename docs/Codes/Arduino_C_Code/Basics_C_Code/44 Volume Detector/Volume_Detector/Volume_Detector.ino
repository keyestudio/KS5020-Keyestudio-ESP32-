/*  
 * 名称   : Volume Detector
 * 功能   : I2C 128×32 LCD显示屏显示声音传感器检测的音量
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
#include "lcd128_32_io.h"

#define PIN_ANALOG_IN 36 // 声音传感器的引脚连接到IO36

lcd lcd(21, 22); // 创建IIC LCD 128*32引脚:SDA-->IO21, SCL-->IO22

void setup() {
  lcd.Init();  // 初始化
  lcd.Clear(); // 清屏
}
char string[10];

//LCD显示音量值
void loop() {
  int Value = analogRead(PIN_ANALOG_IN);    //读IO36引脚的模拟值
  lcd.Cursor(0,2); // 设置显示的位置
  lcd.Display("Volume Detector"); //设置显示的内容
  lcd.Cursor(2,4); 
  lcd.Display("Volume:");
  lcd.Cursor(2,12);
  lcd.DisplayNum(Value);
  delay(200);
}
