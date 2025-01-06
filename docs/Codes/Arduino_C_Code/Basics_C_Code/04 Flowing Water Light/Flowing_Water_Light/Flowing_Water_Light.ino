/*
 * 名称   : Flowing_Water_Light
 * 功能   : 流水灯
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/ 
*/
byte ledPins[] = {18, 5, 14, 17, 26}; //LED的引脚
int ledCounts; //定义LED的数量

void setup() {
//将5个LED设置为输出模式
  ledCounts = sizeof(ledPins); 
  for (int i = 0; i < ledCounts; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < ledCounts; i++) { //5个LED将从右到左依次点亮再熄灭
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
  for (int i = ledCounts - 1; i > -1; i--) { //5个LED将从左到右依次点亮再熄灭
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  }
}

