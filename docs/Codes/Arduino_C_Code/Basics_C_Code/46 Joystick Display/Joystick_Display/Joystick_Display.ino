/*  
 * 名称   : Joystick Display
 * 功能   : 摇杆控制OLED屏显示
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// 定义摇杆引脚
#define JOYSTICK_X_PIN 36 // VRx
#define JOYSTICK_Y_PIN 39 // VRy
#define JOYSTICK_SW_PIN 26 // SW(B)

void setup() {
  // 初始化串口
  Serial.begin(115200);

  // 初始化 OLED 显示屏
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) 
  {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // 初始化摇杆引脚
  pinMode(JOYSTICK_X_PIN, INPUT);
  pinMode(JOYSTICK_Y_PIN, INPUT);
  pinMode(JOYSTICK_SW_PIN, INPUT_PULLUP);

  // 清空显示屏并显示初始信息
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.println("Joystick Test");
  display.display();
}

void loop() {
  // 读取摇杆的X轴、Y轴和Z轴的数据
  int xValue = analogRead(JOYSTICK_X_PIN);
  int yValue = analogRead(JOYSTICK_Y_PIN);
  bool swValue = digitalRead(JOYSTICK_SW_PIN);

  // 清空显示屏
  display.clearDisplay();
  display.setCursor(0, 0);

  // 显示X轴、Y轴和Z轴的值
  display.print("X: ");
  display.println(xValue);
  display.print("Y: ");
  display.println(yValue);
  display.print("Z: ");
  display.println(swValue);

  // 根据X轴和Y轴的值判断摇杆的方向
  if (yValue < 1000) {
    display.println("Direction: Down");
  } else if (yValue > 3000) {
    display.println("Direction: Up");
  } else if (xValue < 1000) {
    display.println("Direction: Left");
  } else if (xValue > 3000) {
    display.println("Direction: Right");
  } else {
    display.println("Direction: Center");
  }

  // 显示按钮状态
  if (swValue == HIGH) {
    display.println("Button: Pressed");
  } else {
    display.println("Button: Released");
  }

  // 更新显示屏
  display.display();

  // 延迟一段时间以避免闪烁
  delay(100);
}