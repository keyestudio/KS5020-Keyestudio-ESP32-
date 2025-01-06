/*  
 * 名称   : Potentiometer
 * 功能   : 读取声音传感器的值
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
const int PIN_ANALOG_IN = 36;   //定义声音传感器的引脚连接到IO36

void setup() {
  Serial.begin(9600);   // 波特率设置为9600
  pinMode(PIN_ANALOG_IN, INPUT);  // 将声音传感器的引脚设置为输入模式
}

void loop() {
  int adcVal = analogRead(PIN_ANALOG_IN);    // 读取声音传感器的模拟信号
  int dacVal = map(adcVal, 0, 4095, 0, 255);
  double voltage = adcVal / 4095.0 * 3.3;
  Serial.print("ADC Val: ");    // 打印字符串ADC Val:
  Serial.print(adcVal);    // 打印且显示adcVal值
  Serial.print(" |DAC Val: ");    // 打印字符串  DAC Val:  
  Serial.print(adcVal);    // 打印且显示adcVal值
  Serial.print(" |Voltage: ");    // 打印字符串  Voltage:  
  Serial.println(voltage);    // 打印且显示voltage值
  delay(200);
}