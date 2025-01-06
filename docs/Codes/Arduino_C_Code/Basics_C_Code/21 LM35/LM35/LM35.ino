/*  
 * 名称   : LM35
 * 功能   : 用LM35检测温度
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
const int lm35Pin = 36;  //定义lm35的引脚GPIO36
float temperature = 0; //定义变量temperature初始值为0
long value = 0; //定义变量value初始值为0

void setup() {
  Serial.begin(9600); //设置串口波特率9600
  pinMode(lm35Pin, INPUT);  //设置lm35Pin为输入模式
}

void loop() {
  value = analogRead(lm35Pin); //读取模拟输入

  //电压与摄氏度转换：
  //0.0012210012210012 = 5.0/4095，0~5.0V对应模拟口读数0~4095，每10毫伏对应1℃
  temperature = (value * 0.0012210012210012 * 100);
  
  Serial.print("Temper =  ");
  Serial.print(temperature);
  Serial.println("℃");
  delay(100);
}

