/*
 * 名称   : Tilt_Switch
 * 功能   : 读倾斜开关的值
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/ 
*/
int SWITCH_PIN = 14; // 将倾斜开关连接到IO14
int val = 0;       // 用于存储倾斜开关的值

void setup(){
  Serial.begin(9600); // 启动串口监视器，设置波特率为9600
  pinMode(SWITCH_PIN, INPUT); // 设置倾斜开关的引脚为输入模式
} 

void loop(){
  val = digitalRead(SWITCH_PIN); // 读取倾斜开关的值并将其赋值给变量val
  Serial.print(val);  // 打印变量val的值
  if (val == 1) {  // 倾斜开关倾斜时读取到高电平，并打印出相关的信息
    Serial.print("    ");  
    Serial.println("Tilt"); // 打印倾斜开关的倾斜信息
    delay(100); 
  }
  else {  // 倾斜开关不倾斜时读取到低电平
    Serial.print("    ");
    Serial.println("No tilt");
    delay(100);
  }
}
