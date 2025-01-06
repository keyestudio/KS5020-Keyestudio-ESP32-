/*  
 * 名称   : Guess Numbers
 * 功能   : 红外遥控控制一位数码管显示数字和LED模拟猜数字
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t recvPin = 18;  // 定义红外接收器的引脚连接到IO18
IRrecv irrecv(recvPin);      // 创建用于接收器的类对象
decode_results results;       // 创建解码结果类对象
// 设置每个段的IO引脚
const int a = 16;  // 设置a段为数字引脚连接到IO16
const int b = 17;  // 设置b段为数字引脚连接到IO17
const int c = 14;  // 设置c段为数字引脚连接到IO14
const int d = 12;  // 设置d段为数字引脚连接到IO12
const int e = 13;  // 设置e段为数字引脚连接到IO13
const int f = 5;  // 设置f段为数字引脚连接到IO5
const int g = 23;  // 设置g段为数字引脚连接到IO23
const int dp = 27;  // 设置dp段为数字引脚连接到IO27
const int ledPin = 26;  //定义外接LED灯引脚连接到IO26

boolean flag = true;  //LED标志钻头

void setup() {
  Serial.begin(9600);       // 初始化串口，波特率设置为9600
  irrecv.enableIRIn();        // 启动接收器
  Serial.print("IRrecvDemo is now running and waiting for IR message on Pin ");
  Serial.println(recvPin);   //打印红外接收引脚接收到的信号
  pinMode(a, OUTPUT);  // 设置数码管a段引脚为“输出”模式
  pinMode(b, OUTPUT);  // 设置数码管b段引脚为“输出”模式
  pinMode(c, OUTPUT);  // 设置数码管c段引脚为“输出”模式
  pinMode(d, OUTPUT);  // 设置数码管d段引脚为“输出”模式
  pinMode(e, OUTPUT);  // 设置数码管e段引脚为“输出”模式
  pinMode(f, OUTPUT);  // 设置数码管f段引脚为“输出”模式
  pinMode(g, OUTPUT);  // 设置数码管g段引脚为“输出”模式
  pinMode(dp, OUTPUT);  // 设置数码管dp段引脚为“输出”模式
  pinMode(ledPin, OUTPUT);  // 设置LED灯引脚为“输出”模式
}

void loop() {
  if(irrecv.decode(&results)) {        // 等待解码
    serialPrintUint64(results.value, HEX);// 输出解码结果
    Serial.println("");
    handleControl(results.value);      // 处理来自远程控制的命令
    irrecv.resume();                   // 接收下一个值
  }
}

void handleControl(unsigned long value){
  if (value == 0xFF02FD && flag == true){ // 按下遥控器的“OK”键并且接收数字“OK” 
    digitalWrite(ledPin, HIGH);
    flag = false;
  } 
  else if (value == 0xFF02FD && flag == false){ // 按下遥控器的“OK”键并且接收数字“OK”
    digitalWrite(ledPin, LOW);
    flag = true;
  } 
  else if(value == 0xFF6897){ // 按下遥控器的“1”键
    digital_1();// 显示数字1
  } 
  else if(value == 0xFF9867){ // 按下遥控器的“2”键
    digital_2();// 显示数字 2
  } 
  else if(value == 0xFFB04F){ // 按下遥控器的“3”键
    digital_3();// 显示数字 3
  }
  else if(value == 0xFF30CF){ // 按下遥控器的“4”键
    digital_4();// 显示数字 4
  }
  else if(value == 0xFF18E7){ // 按下遥控器的“5”键
    digital_5();// 显示数字 5
  }
  else if(value == 0xFF7A85){ // 按下遥控器的“6”键
    digital_6();// 显示数字 6
  }
  else if(value == 0xFF10EF){ // 按下遥控器的“7”键
    digital_7();// 显示数字 7
  }
  else if(value == 0xFF38C7){ // 按下遥控器的“8”键
    digital_8();// 显示数字 8
  }
  else if(value == 0xFF5AA5){ // 按下遥控器的“9”键
    digital_9();// 显示数字 9
  }
  else if(value == 0xFF4AB5){ // 按下遥控器的“0”键
    digital_0();// 显示数字 0
  }
  else if(value == 0xFF42BD){ // 按下遥控器的“*”键
    // 一位数码管段a-dp都不点亮
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    digitalWrite(dp,LOW);
  }
}

void digital_0(void) { // 显示数字0
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  digitalWrite(dp,LOW);
}
void digital_1(void) { // 显示数字 1
  unsigned char j;
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    digitalWrite(dp,LOW);
}
void digital_2(void) { // 显示数字 2
  unsigned char j;
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
}
void digital_3(void) { // 显示数字 3
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
}
void digital_4(void) { // 显示数字 4
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
}
void digital_5(void) { // 显示数字 5
  unsigned char j;
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,LOW);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
}
void digital_6(void) { // 显示数字 6
  unsigned char j;
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
}
void digital_7(void) { // 显示数字 7
  unsigned char j;
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,LOW);
    digitalWrite(e,LOW);
    digitalWrite(f,LOW);
    digitalWrite(g,LOW);
    digitalWrite(dp,LOW);
}
void digital_8(void) { // 显示数字 8
  unsigned char j;
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    digitalWrite(d,HIGH);
    digitalWrite(e,HIGH);
    digitalWrite(f,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(dp,LOW);
}
void digital_9(void) { // 显示数字 9
  unsigned char j;
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  digitalWrite(dp,LOW);
}