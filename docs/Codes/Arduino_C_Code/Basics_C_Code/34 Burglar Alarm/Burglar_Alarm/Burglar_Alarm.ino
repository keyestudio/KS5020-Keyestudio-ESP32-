/*  
 * 名称   : Burglar_Alarm
 * 功能   : PIR控制蜂鸣器和LED模拟防盗报警器
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
const int ledPin = 26;  // 定义LED的引脚为IO26
const int PIR_PIN = 14;  // PIR运动传感器控制引脚为IO14
const int BUZZER_PIN = 19;  //定义有源蜂鸣器控制引脚为IO19

int item = 0;  //定义变量item初始值为0

void setup() {
  Serial.begin(9600);//启动串口监视器，设置波特率为9600
  pinMode(PIR_PIN, INPUT);  //设置PIR运动传感器的引脚为输入模式
  pinMode(BUZZER_PIN, OUTPUT); //设置有源蜂鸣器的引脚为输出模式
  pinMode(ledPin, OUTPUT);// 设置led引脚为输出模式
}

void loop() {
  item = digitalRead(PIR_PIN); //读取人体红外热释传感器输出的数字信号
  Serial.println(item);    //打印变量item的值
  if (item == 1) {  //运动检测，输出的高电平信号
    digitalWrite(BUZZER_PIN, HIGH); //打开蜂鸣器
    digitalWrite(ledPin, HIGH); // 点亮LED
    delay(200);//延迟 200ms
    digitalWrite(BUZZER_PIN, LOW); //关掉蜂鸣器
    digitalWrite(ledPin, LOW); // 熄灭LED
    delay(200);//延迟 200ms
  } else {  //没有检测到任何信号或数据
    digitalWrite(BUZZER_PIN, LOW); //关掉蜂鸣器
    digitalWrite(ledPin, LOW); // 熄灭LED
  }
}