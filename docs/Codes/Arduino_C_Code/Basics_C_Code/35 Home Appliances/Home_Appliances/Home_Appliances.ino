/*  
 * 名称   : Home_Appliances
 * 功能   : 继电器和按键开关来控制电机转动模拟小家电
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
const int relayPin = 12;          // 定义继电器的引脚接IO12
const int buttonPin = 26;         //定按键开关的引脚接IO26

int buttonState = HIGH;     // 记录按钮状态，并将状态初始化为高电平
int relayState = LOW;       //记录继电器状态，并将状态初始化为低电平
int lastButtonState = HIGH; // 记录上次检测的按键状态
long lastChangeTime = 0;    // 记录按键状态变化的时间点

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);   // 将按键引脚设置为输入模式
  pinMode(relayPin, OUTPUT);          // 将继电器引脚设置为输出模式
  digitalWrite(relayPin, relayState); // 将继电器的初始状态设置为“关闭”
}
void loop() {
  int nowButtonState = digitalRead(buttonPin);// 读取按键引脚的当前状态
  // 如果按键引脚状态发生变化，记录时间点
  if (nowButtonState != lastButtonState) {
    lastChangeTime = millis();
  }
  // 如果按键状态发生变化，并保持稳定一段时间，那么它应该跳过反弹区域
  if (millis() - lastChangeTime > 10) {
    if (buttonState != nowButtonState) {    // 确认按键状态已更改
      buttonState = nowButtonState;
      if (buttonState == LOW) {             // 低电平表示按键被按下
        relayState = !relayState;           // 反向继电器状态
        digitalWrite(relayPin, relayState); // 更新继电器状态
      }
    }
  }
  lastButtonState = nowButtonState; // 保存最后一个按钮的状态
}

