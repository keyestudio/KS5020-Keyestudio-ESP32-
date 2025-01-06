/*  
 * 名称   : Astern_Detector
 * 功能   : 超声波控制OLED和无源蜂鸣器，模拟倒车检测仪
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

const int BUZZER_PIN = 26;   //定义无源蜂鸣器引脚为IO26

const int TrigPin = 18; //设置Trig引脚为IO18
const int EchoPin = 19; //设置Echo引脚为IO19
int distance;     //超声波测量距离

float checkdistance() { //得到的距离
  // 事先给一个短的低电平，以确保一个干净的高脉冲;
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  // 传感器由10微秒或更长时间的高脉冲触发
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  // 从传感器读取信号:一个高电平脉冲
  // 它的持续时间是从发送ping命令到从对象接收回显的时间(以微秒为单位)
  float distance = pulseIn(EchoPin, HIGH) / 58.00;  //转换成距离
  delay(300);
  return distance;
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);  // 设置蜂鸣器为输出模式
  ledcSetup(3, 660, 13);        //设置pwm通道，660Hz,13bit
  ledcAttachPin(BUZZER_PIN, 3);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // 使用 I2C addr 0x3C 进行初始化(针对128x64)
  display.clearDisplay(); // 清屏
  
  pinMode(TrigPin, OUTPUT);     //设置Trig引脚作为输出
  pinMode(EchoPin, INPUT);      //设置Echo引脚作为输入
}

void loop() {
  distance = checkdistance(); //超声波测距
  display.clearDisplay();  // 清屏
  display.setTextSize(1);  // 设置显示字体的大小
  display.setTextColor(WHITE);  // 设置显示字体的颜色
  display.setCursor(0,0);   // 设置显示字体的位置
  display.println("Astern Detector");  // 设置显示的内容 
  display.setCursor(0,30);   // 设置显示字体的位置
  display.println("Distance(cm):");  // 设置显示的内容
  display.setCursor(80,30);
  display.println(distance);
  display.display();
  delay(50);
  if (distance <= 10) {   
    ledcWrite(3, 450);
    delay(500);

  } else if (distance > 10 && distance <= 20) {
    ledcWrite(3, 100);
    delay(100);
  } else {
    ledcWrite(3, 0);
  }
}

