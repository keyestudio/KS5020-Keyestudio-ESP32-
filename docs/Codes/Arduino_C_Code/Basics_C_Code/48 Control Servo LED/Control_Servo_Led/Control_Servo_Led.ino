/*  
 * 名称   : Control_Servo_Led
 * 功能   : 控制舵机转动和LED
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
#include <ESP32Servo.h>

const int servoPin = 4;  // 定义舵机引脚IO4
Servo myservo;  //创建舵机对象来控制舵机

const int ledPin = 25; // 定义LED的引脚为IO25

const int buttonPin = 14; // 将按键开关的引脚连接到IO14
const int potentiometerPin = 36;  // 电位器的引脚定义为IO36

int val1 = 0;   // 用于存储按键值
int val2 = 0;   // 设置val2为0

void setup() {
  pinMode(potentiometerPin, INPUT);    // 将电位器的引脚设置为输入模式
  pinMode(buttonPin, INPUT);    // 将按键开关的引脚设置为输入模式
  pinMode(ledPin, OUTPUT); // 设置led引脚为输出模式
  myservo.attach(servoPin);  // 选择舵机引脚IO4
  myservo.write(0); // 舵机转动0°
  delay(200); // 等待200ms
}

void loop() {
  val1 = digitalRead(buttonPin);  //读取按键开关的值并将其赋值给变量val1
  if (val1 == 0) {       //按下按键开关时读取到低电平
    digitalWrite(ledPin, HIGH); // 点亮LED
    delay(5000);  // 等待5000ms
  }
  else {
    digitalWrite(ledPin, LOW); // 熄灭LED
  }  
  val2 = analogRead(potentiometerPin);    //读取电位器的模拟信号
  myservo.write((map(val2, 0, 4095, 0, 180)));   // 电位器的模拟值映射到舵机的位置
  delay(5);   // 等待5ms让舵机到达对应的位置
}
