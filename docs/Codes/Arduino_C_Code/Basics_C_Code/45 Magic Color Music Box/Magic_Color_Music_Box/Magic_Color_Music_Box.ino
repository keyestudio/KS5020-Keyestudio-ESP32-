/*  
 * 名称   : Magic_Color_Music_Box
 * 功能   : 超声波测量距离控制蜂鸣器和7个LED模拟魔幻色彩音乐盒
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
const int trig = 33;  //定义超声波传感器的Trig引脚为IO33
const int echo = 32;  //定义超声波传感器的Echo引脚为IO32
const int LED1 = 13;   //定义LED1引脚为IO13
const int LED2 = 12;   //定义LED2引脚为IO12
const int LED3 = 14;   //定义LED3引脚为IO14
const int LED4 = 27;   //定义LED4引脚为IO27
const int LED5 = 16;   //定义LED5引脚为IO16
const int LED6 = 17;   //定义LED6引脚为IO17
const int LED7 = 25;   //定义LED7引脚为IO25
const int beeppin = 18;  //定义无源蜂鸣器引脚为IO18

int duration = 0;  //定义变量duration初始值为0
int distance = 0;  //定义变量distance初始值为0

void setup() {
  Serial.begin(9600);     //设置串口波特率为9600
  pinMode(trig, OUTPUT);  //设置超声波Trig数字口为输出模式
  pinMode(echo, INPUT);   //设置超声波Echo数字口为输出模式
  pinMode(LED1, OUTPUT);  //设置LED1数字口为输出模式
  pinMode(LED2, OUTPUT);  //设置LED2数字口为输出模式
  pinMode(LED3, OUTPUT);  //设置LED3数字口为输出模式
  pinMode(LED4, OUTPUT);  //设置LED4数字口为输出模式
  pinMode(LED5, OUTPUT);  //设置LED5数字口为输出模式
  pinMode(LED6, OUTPUT);  //设置LED6数字口为输出模式
  pinMode(LED7, OUTPUT);  //设置LED7数字口为输出模式
  pinMode(beeppin, OUTPUT); //设置无源蜂鸣器数字口为输出模式 
  ledcSetup(3, 2000, 8);  // 设置无源蜂鸣器通道为3,频率为2000,PWM分辨率为8.
  ledcAttachPin(beeppin, 3);  // 将 LEDC 通道绑定到无源蜂鸣器 IO 口上以实现输出.
  ledcWrite(3, 0); // 停止播放
}
void loop(){
  //使trigPin输出高电平持续10μs触发HC_SR04
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  //等待HC-SR04回到高电平并测量这个等待时间
  duration = pulseIn(echo, HIGH);
  //根据时间计算距离
  distance = (duration / 2) / 28.5;
  Serial.println(distance);  // 串口打印距离值
  if (distance > 0 && distance <= 5){  // 如果超声波检测的距离值在0~5cm范围内
    digitalWrite(LED1, HIGH);  //LED1点亮
    ledcSetup(3, 2000, 8);   
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 262);  // 无源蜂鸣器播放音调do
    delay(1000);  //延时1000ms
  }
  else{  //否则，超声波检测的距离值不在0~5cm范围内
    digitalWrite(LED1, LOW);  //LED1不亮
    ledcSetup(3, 2000, 8);    // 停止播放
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 0); 
  }
  if (distance > 5 && distance <= 10){  //如果超声波检测的距离值在5~10cm范围内
    digitalWrite(LED2, HIGH);  //LED2点亮
    ledcSetup(3, 2000, 8);   
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 294);  //无源蜂鸣器播放音调re
    delay(750);
  }
  else{  //否则，超声波检测的距离值不在5~10cm范围内
    digitalWrite(LED2, LOW);  //LED2不亮
    ledcSetup(3, 2000, 8);    // 停止播放
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 0); 
  }
  if (distance > 10 && distance <= 15){  //如果超声波检测的距离值在10~15cm范围内
    digitalWrite(LED3, HIGH);  //LED3点亮
    ledcSetup(3, 2000, 8);   
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 330);  //无源蜂鸣器播放音调mi
    delay(625);
  }
  else{  //否则，超声波检测的距离值不在10~15cm范围内
    digitalWrite(LED3, LOW);  //LED3不亮
    ledcSetup(3, 2000, 8);    // 停止播放
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 0); 
  }
    if (distance > 15 && distance <= 20){  //如果超声波检测的距离值在15~20cm范围内
    digitalWrite(LED4, HIGH);  //LED4点亮
    ledcSetup(3, 2000, 8);   
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 349);  //无源蜂鸣器播放音调fa
    delay(500);
  }
  else{  //否则，超声波检测的距离值不在15~20cm范围内
    digitalWrite(LED4, LOW);  //LED4不亮
    ledcSetup(3, 2000, 8);    // 停止播放
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 0); 
  }
  if (distance > 20 && distance <= 25){  //如果超声波检测的距离值在20~25cm范围内
    digitalWrite(LED5, HIGH);  //LED5点亮
    ledcSetup(3, 2000, 8);   
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 392);  //无源鸣器播放音调so
    delay(375);
  }
  else{  //否则，超声波检测的距离值不在20~25cm范围内
    digitalWrite(LED5, LOW);  //LED5不亮
    ledcSetup(3, 2000, 8);    // 停止播放
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 0); 
  }
  if (distance > 25 && distance <= 30){  //如果超声波检测的距离值在25~30cm范围内
    digitalWrite(LED6, HIGH);  //LED6点亮
    ledcSetup(3, 2000, 8);   
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 440);   //无源蜂鸣器播放音调la
    delay(250);
  }
  else{  //否则，超声波检测的距离值不在25~30cm范围内
    digitalWrite(LED6, LOW);  //LED6不亮
    ledcSetup(3, 2000, 8);    // 停止播放
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 0); 
  }
  if (distance > 30 && distance <= 35){  //如果超声波检测的距离值在30~35cm范围内
    digitalWrite(LED7, HIGH);  //LED7点亮
    ledcSetup(3, 2000, 8);   
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 494);  //无源蜂鸣器播放音调si
    delay(125);
  }
  else{  //否则，超声波检测的距离值不在30~35cm范围内
    digitalWrite(LED7, LOW);  //LED7不亮
    ledcSetup(3, 2000, 8);    // 停止播放
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 0); 
  }
}     
