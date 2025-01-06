/*  
 * 名称   : Cooling_Device
 * 功能   : LM35温度传感器控制OLED和电机模拟散热装置
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // 显示宽度，以像素为单位
#define SCREEN_HEIGHT 64 // OLED 显示高度，以像素为单位

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int lm35Pin = 36;  // 定义LM35引脚连接到IO36
const int motoraPin = 16;  // 定义电机的motor_IN+引脚连接到IO16
const int motorbPin = 17; // 定义电机的motor_IN-引脚连接到IO17


void setup() {
  Serial.begin(9600);  // 设置硬件串口为9600
  pinMode(lm35Pin, INPUT); // 设置lm35Pin为输入模式
  pinMode(motoraPin, OUTPUT); // 设置电机的motor_IN+引脚为输出模式
  pinMode(motorbPin, OUTPUT); // 设置电机的motor_IN-引脚为输出模式

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // 使用 I2C addr 0x3C 进行初始化(针对128x64)
  display.clearDisplay(); // 清屏
}

void loop() {
  int reading = analogRead(lm35Pin);  // 读LM35引脚的模拟值
  int temperC = (reading * 0.0012210012210012 * 100); //电压与摄氏度转换:0.0012210012210012 = 5.0/4095，0~5.0V对应模拟口读数0~4095，每10毫伏对应1℃,计算摄氏温度.
  display.clearDisplay();  // 清屏
  display.setTextSize(1);  // 设置显示字体的大小
  display.setTextColor(WHITE);  // 设置显示字体的颜色
  display.setCursor(0,0);   // 设置显示字体的位置
  display.println("Cooling Device");  // 设置显示的内容 
  display.setCursor(0,30);   // 设置显示字体的位置
  display.println("Temper(C):");  // 设置显示的内容
  display.setCursor(60,30);
  display.println(temperC);
  display.display();
  delay(200);
  if (temperC > 30) { // 当温度超过30℃时，风扇打开
    digitalWrite(motoraPin, HIGH);  //电机转动
    digitalWrite(motorbPin, LOW);
  } 
  else { // 否则，风扇关闭
    digitalWrite(motoraPin, LOW); 
    digitalWrite(motorbPin, LOW);
  }
}