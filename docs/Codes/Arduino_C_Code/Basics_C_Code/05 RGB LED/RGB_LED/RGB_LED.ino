/*
 * 名称   : RGB_LED
 * 功能   : RGB LED发出不同的颜色光
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/ 
*/
const int ledPins[] = {27, 25, 26};    //依次定义红、绿、蓝的引脚
const byte chns[] = {0, 1, 2};      //定义PWM通道
int red, green, blue;

void setup() {
  for (int i = 0; i < 3; i++) {   //设置pwm通道，1KHz,8bit
    ledcSetup(chns[i], 1000, 8);
    ledcAttachPin(ledPins[i], chns[i]);
  }
}

void loop() {
  setColor(255, 0, 0); // Red
  delay(1000);
  setColor(0, 255, 0); // Green
  delay(1000);
  setColor(0, 0, 255); // Blue
  delay(1000);
  setColor(255, 255, 0); // Yellow
  delay(1000);
  setColor(80, 0, 80); // Purple
  delay(1000);
  setColor(0, 255, 255); // Cyan
  delay(1000);
}

void setColor(int red, int green, int blue) {
  ledcWrite(chns[0], red); //共阴极LED，高电平开启LED.
  ledcWrite(chns[1], green);
  ledcWrite(chns[2], blue);
}
