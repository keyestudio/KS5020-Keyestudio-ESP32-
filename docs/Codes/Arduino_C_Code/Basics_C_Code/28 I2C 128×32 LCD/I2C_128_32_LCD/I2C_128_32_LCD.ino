/*
 * 文件名 : LCD 128*32
 * 描述   : LCD 128*32显示字符串
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
#include "lcd128_32_io.h"

lcd lcd(21, 22); // 创建IIC LCD 128*32引脚:SDA-->IO21, SCL-->IO22

void setup() {
  lcd.Init();  // 初始化
  lcd.Clear(); // 清屏
}

void loop() {
  lcd.Cursor(0, 4); // 设置显示的位置
  lcd.Display("KEYESTUDIO"); // 设置显示的字符串
  lcd.Cursor(1, 0);
  lcd.Display("ABCDEFGHIJKLMNOPQR");
  lcd.Cursor(2, 0);
  lcd.Display("123456789+-*/<>=$@");
  lcd.Cursor(3, 0);
  lcd.Display("%^&(){}:;'|?,.~\\[]");
}

