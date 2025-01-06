/*  
 * 名称   : Electronic_Hourglass
 * 功能   : 倾斜开关控制4个LED模拟电子沙漏
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
const byte SWITCH_PIN = 26; // 将倾斜开关引脚连接到IO26
const int led1 = 16;  //将led1引脚连接到IO16
const int led2 = 17;  //将led2引脚连接到IO17
const int led3 = 18;  //将led3引脚连接到IO18
const int led4 = 19;  //将led4引脚连接到IO18

byte switch_state = 0; //定义变量switch_state初始值为0

void setup(){
  Serial.begin(9600); //串口波特率为9600
  pinMode(SWITCH_PIN, INPUT); //设置倾斜开关的引脚为输入模式
  for(int i=16;i<20;i++){  //设置4个LED的引脚为输出模式
    pinMode(i, OUTPUT);
  } 
  for(int i=16;i<20;i++){ //设置4个LED初始为熄灭
    digitalWrite(i,0);
  } 
}

void loop(){
  switch_state = digitalRead(SWITCH_PIN); //读取倾斜开关的值并赋值于变量switch_state
  Serial.println(switch_state); //串口打印倾斜开关的值
  if (switch_state == 1) {  //如果倾斜开关倾斜一定角度（即：其值为1）时
    for(int i=16;i<20;i++){  //4个LED逐渐点亮
      digitalWrite(i,1);
      delay(500);
    } 
  }
  if (switch_state == 0) {  //如果倾斜开关未倾斜（即：其值为0）时
    for(int i=19;i>15;i--){  //4个LED逐渐熄灭
      digitalWrite(i,0);
      delay(500);
    }
  }
}
