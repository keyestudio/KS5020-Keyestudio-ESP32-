/*  
 * 名称   : Thermistor
 * 功能   : 用热敏电阻检测温度
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
const int PIN_ANALOG_IN = 36; // 热敏电阻接到模拟引脚IO36

void setup() {
  Serial.begin(9600);
}

void loop() {
  int AnalogValue = analogRead(PIN_ANALOG_IN);    //读IO36引脚的模拟值
  float Rt=0;      //NTC 热敏电阻
  float R=10000;   //具有固定电阻值的10K电阻
  float B=3950;    //B值是热敏电阻的一个重要参数
  float K=273.15;  //开氏度 (K°)
  float VR=0;
  VR = (float)(AnalogValue / 4095.0 * 3.3);  //转换成电压值
  Rt = (3.3 - VR) / VR * 10000;    //计算NTC热敏电阻
  float temp = 1/(1/(273.15+25)+log(Rt/R)/B)-K+0.5;//计算温度
  Serial.print("ADC value:");
  Serial.print(AnalogValue);
  Serial.print("  |  Voltage:");
  Serial.print(VR);
  Serial.print("V");
  Serial.print("  |  Temperature:");
  Serial.print(temp);
  Serial.println("℃");
  delay(200);
}
