/*  
 * 名称   : Night_Lamp
 * 功能   : 光敏电阻控制LED
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
const int PIN_ANALOG_IN = 36;  // 光敏电阻的引脚
const int PIN_LED = 12;  // LED的引脚
int CHAN = 0;  // 使用led通道0

void setup() {
  ledcSetup(CHAN, 1000, 12); // PWM取值范围为0 ~ 4095
  ledcAttachPin(PIN_LED, CHAN); // PIN_LED引脚定义通道0为输出引脚
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN); //读adc
  int pwmVal = adcVal;        // adcVal映射到pwmVal
  ledcWrite(CHAN, pwmVal);    // 设置脉冲宽度.
  delay(10);
}