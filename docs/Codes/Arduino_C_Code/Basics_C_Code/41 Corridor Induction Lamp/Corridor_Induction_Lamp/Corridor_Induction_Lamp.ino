/*  
 * 文件名 : Corridor_Induction_Lamp
 * 描述 : 采用光敏传感器和人体红外传感器控制LED.
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
const int photoresistorPin = 36;  // 定义光敏电阻的引脚连接到IO36
const int pirPin = 12;  // 定义人体红外传感器的引脚连接到IO12
const int ledPin = 25;  // 定义LED的引脚连接到IO25
byte pirStat = 0;   // 人体红外传感器的状态

void setup() {
  Serial.begin(9600);  // 设置串口波特率为9600
  pinMode(ledPin, OUTPUT);  // 设置LED引脚为输出模式
  pinMode(photoresistorPin, INPUT);  // 设置光敏电阻的引脚为输入模式
  pinMode(pirPin, INPUT);  // 设置人体红外传感器的引脚为输入模式
}

void loop() {
  int adcVal = analogRead(photoresistorPin); // 读取光敏电阻的模拟信号，赋给于变量adcVal
  Serial.println(adcVal); //串口打印模拟值
  pirStat = digitalRead(pirPin); // 读取人体红外传感器的值
  if (adcVal >= 3500) { // 如果光敏电阻的模拟值大于等于3500时
    if (pirStat == HIGH){  // 如果人体红外传感器检测到人移动时
      digitalWrite(ledPin, HIGH); // 点亮外接LED
      delay(5000);
    } 
    else{ // 否则人体红外传感器未检测到人移动时
      digitalWrite(ledPin, LOW); // 熄灭外接LED灯   
    }
  }
  else{  // 否则光敏电阻的模拟值小于3500时
    digitalWrite(ledPin, LOW); // 熄灭外接LED灯
  }
}

