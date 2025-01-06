/*
 * 名称   : Speed_Regulating_Lights
 * 功能   : 变速灯
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
const int ledPins[] = {12, 13, 14};  //定义红、黄、绿LED灯的引脚  
const int potPin = 36;  //定义电位器的引脚接到IO36  
int potValue = 0;  //电位器的值  
int delayTime = 100;  //默认的延迟时间  
  
void setup() {  
  for (int i = 0; i < 3; i++) {  
    pinMode(ledPins[i], OUTPUT);  //设置LED灯的引脚为输出模式  
  }  
  pinMode(potPin, INPUT);  //设置电位器的引脚为输入模式  
}  
  
void loop() {  
  potValue = analogRead(potPin);  //读取电位器的值  
  delayTime = map(potValue, 0, 4095, 100, 1000);  //将电位器的值映射到延迟时间  
  
  for (int i = 0; i < 3; i++) {  
    digitalWrite(ledPins[i], HIGH);  //点亮当前LED灯  
    delay(delayTime);  //等待一段时间  
    digitalWrite(ledPins[i], LOW);  //熄灭当前LED灯  
  }  
}
