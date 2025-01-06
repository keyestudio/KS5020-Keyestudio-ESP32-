/*
 * 名称   : Traffic_Lights
 * 功能   : 模拟交通灯
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/ 
*/
const int PIN_LED_RED = 13;   //定义红色引脚
const int PIN_LED_YELLOW = 14;   //定义黄色引脚
const int PIN_LED_GREEN = 16;   //定义绿色引脚

void setup() {
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
}

void loop() {
   digitalWrite(PIN_LED_GREEN, HIGH);// 点亮绿色的灯
   delay(5000);// 延时 5 s
   digitalWrite(PIN_LED_GREEN, LOW);// 
   delay(500);// 延时 0.5 s
   for(int i=0;i<3;i++)// 闪烁 3 次.
   {
     digitalWrite(PIN_LED_YELLOW, HIGH);// 点亮黄色的灯
     delay(500);// 延时 0.5 s
     digitalWrite(PIN_LED_YELLOW, LOW);// 熄灭黄色的灯
     delay(500);// 延时 0.5 s
   } 
   digitalWrite(PIN_LED_RED, HIGH);// 点亮红色的灯
   delay(5000);// 延时 5 s
   digitalWrite(PIN_LED_RED, LOW); // 熄灭红色的灯
   delay(500);// 延时 0.5 s
}
