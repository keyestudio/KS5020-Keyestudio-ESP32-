/*
 * 名称   : PIR motion
 * 功能   : 读取人体红外传感器的数值
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
const int pirPin = 14;  // PIR运动传感器的引脚定义为IO14
int val = 0;

void setup() {
  Serial.begin(9600);   // 波特率设置为9600
  pinMode(pirPin, INPUT);   // 将传感器设置为输入模式
}

void loop() {
  val = digitalRead(pirPin);    // 读取传感器值
  Serial.print(val);    // 打印传感器值
  if (val == 1) {    // 附近有人移动，输出高电平
    Serial.print("        ");
    Serial.println("Some body is in this area!");
    delay(100);
  }
  else {    // 如果附近没有人移动，输出低电平
    Serial.print("        ");
    Serial.println("No one!");
    delay(100);
  }
}