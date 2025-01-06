/*
 * 名称   : Stepper_Motor
 * 功能   : 步进电机转动
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
// 连接步进电机驱动板的IN1、IN2、IN3和IN4引脚分别是IO16、IO17、IO18和IO19
const int outPorts[] = {16, 17, 18, 19};

void setup() {
  // 设置步进电机驱动板的引脚为输出模式
  for (int i = 0; i < 4; i++) {
    pinMode(outPorts[i], OUTPUT);
  }
}

void loop(){
  // 步进电机旋转一圈
  moveSteps(true, 32 * 64, 3);
  delay(1000);
  // 向另一个方向旋转一圈
  moveSteps(false, 32 * 64, 3);
  delay(1000);
}

//建议: 电机转动精确时，毫秒的范围是3至20
void moveSteps(bool dir, int steps, byte ms) {
  for (unsigned long i = 0; i < steps; i++) {
    moveOneStep(dir); // 旋转一步
    delay(constrain(ms,3,20)); // 控制速度
  }
}

void moveOneStep(bool dir) {
  // 定义一个变量，使用四个低位来表示端口的状态
  static byte out = 0x01;
  // 根据转动方向确定换档方向
  if (dir) {  // 环向左移动
    out != 0x08 ? out = out << 1 : out = 0x01;
  }
  else {   // 环向右移动
    out != 0x01 ? out = out >> 1 : out = 0x08;
  }
  // 输出信号到每个端口
  for (int i = 0; i < 4; i++) {
    digitalWrite(outPorts[i], (out & (0x01 << i)) ? HIGH : LOW);
  }
}

void moveAround(bool dir, int turns, byte ms){
  for(int i=0;i<turns;i++)
    moveSteps(dir,32*64,ms);
}
void moveAngle(bool dir, int angle, byte ms){
  moveSteps(dir,(angle*32*64/360),ms);
}

