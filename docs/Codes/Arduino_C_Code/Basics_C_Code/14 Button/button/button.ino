/*
 * 名称   : button
 * 功能   : 读按键的值
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
const int button = 14;  // 将按键的引脚连接到IO14
int val = 0;       // 用于存储按键的键值

void setup() {
  Serial.begin(9600);    // 启动串口监视器，设置波特率为9600
  pinMode(button, INPUT);  // 设置按键的引脚为输入模式
}

void loop() {
  val = digitalRead(button);  // 读取按键的值并将其赋值给变量val
  Serial.print(val);          // 打印变量val的值
  if (val == 0) {             // 按下按键时读取到低电平，并打印出相关的信息
    Serial.print("    ");  
    Serial.println("Press the botton"); // 打印按键的释放信息
    delay(100);
  }
  else {               // 按起按键
    Serial.print("    ");
    Serial.println("Loose the botton");
    delay(100);
  }
}
