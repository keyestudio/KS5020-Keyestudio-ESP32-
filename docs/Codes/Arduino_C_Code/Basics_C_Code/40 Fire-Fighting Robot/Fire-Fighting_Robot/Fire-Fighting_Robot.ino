/*  
 * 名称   : Fire-fighting robot
 * 功能   : 火焰传感器控制电机和LED模拟灭火机器人
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
const int flamePin = 36;   // 定义火焰传感器的引脚连接到IO36
const int motoraPin = 13;  // 定义电机的motor_IN+引脚连接到IO13
const int motorbPin = 12; // 定义电机的motor_IN-引脚连接到IO12
const int ledPin = 25;   // 定义led的引脚连接到IO25
int item = 0; // 定义变量item初始值为0

void setup() {
  Serial.begin(9600);  // 设置串口波特率为9600
  pinMode(flamePin, INPUT); // 设置火焰传感器的引脚为输入模式
  pinMode(motoraPin, OUTPUT); // 设置电机的motor_IN+引脚为输出模式
  pinMode(motorbPin, OUTPUT); // 设置电机的motor_IN-引脚为输出模式
  pinMode(ledPin, OUTPUT); // 设置led的引脚为输出模式
}

void loop() {
  item = analogRead(flamePin);  // 读取火焰传感器模拟值并赋值给变量item
  Serial.print(item);  // 串口打印模拟值
  if (item > 2000) {  // 模拟值在2000以上，打开风扇，LED闪烁  
    Serial.print("   "); 
    Serial.println("Put out a fire");
    digitalWrite(motoraPin, HIGH);  //电机转动
    digitalWrite(motorbPin, LOW);
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);  
  } 
  else {//否则，关闭风扇，LED不亮
    Serial.print("   "); 
    Serial.println("No flame detected");
    digitalWrite(motoraPin, LOW); 
    digitalWrite(motorbPin, LOW);
    digitalWrite(ledPin, LOW); 
  } 
}
