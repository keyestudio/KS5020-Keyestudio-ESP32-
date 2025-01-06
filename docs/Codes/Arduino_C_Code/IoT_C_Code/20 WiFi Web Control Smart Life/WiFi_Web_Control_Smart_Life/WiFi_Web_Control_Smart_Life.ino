/*
 * 名称    : WiFi_Web_Control_Smart_Life  
 * 功能    : WIFI 网页控制多个元器件和模块模拟WiFi智能生活
 * 编译 IDE: ARDUINO 2.3.3
 * 作者    : https://www.keyestudio.com/
*/
#include <Arduino.h>
#include <WiFi.h>
#include <ESP32Servo.h>

/*REPLACE WITH YOUR NETWORK CREDENTIALS(Put your SSID & Password)*/
const char* ssid = "REPLACE_WITH_YOUR_SSID";  //Enter SSID here
const char* password = "REPLACE_WITH_YOUR_PASSWORD"; //Enter Password here

// 用于存储 HTTP 请求的变量
String header;

const int ledPins[] = {27, 16, 17};  // 依次定义红、绿、蓝的引脚
const byte chns[] = {1, 2, 3};     // 定义PWM通道
int red, green, blue;

const int buzzerPin = 18;   // 定义有源蜂鸣器引脚为IO18
const int motoraPin = 13;   // 定义直流电机IN+的数字控制引脚为IO13
const int motorbPin = 12;   // 定义直流电机IN-的数字控制引脚为IO12
const int relayPin = 25;  // 定义继电器引脚为IO25
const int servoPin = 4;  // 定义舵机引脚为IO4
Servo myservo;  // 创建舵机对象来控制舵机
// Define the minimum and maximum pulse widths for the servo
const int minPulseWidth = 500; // 0.5 ms
const int maxPulseWidth = 2500; // 2.5 ms

int status = WL_IDLE_STATUS;
WiFiServer server(80);

unsigned long currentTime = millis(); // 当前时间
unsigned long previousTime = 0;  // 前一时刻
const long timeoutTime = 2000; // 定义超时时间（以毫秒为单位）(示例：2000ms = 2s）

void setup() {
  Serial.begin(115200);  // 初始化硬件串口
  for (int i = 0; i < 3; i++) {   //设置pwm通道，1KHz,8bit
    ledcSetup(chns[i], 1000, 8);
    ledcAttachPin(ledPins[i], chns[i]);
  }
  pinMode(motoraPin, OUTPUT);  // 设置直流电机的IN+引脚为输出模式
  pinMode(motorbPin, OUTPUT);  // 设置直流电机的IN-引脚为输出模式
  pinMode(relayPin, OUTPUT);   // 设置继电器引脚为输出模式
  pinMode(buzzerPin, OUTPUT);  // 设置有源蜂鸣器引脚为输出模式

  myservo.attach(servoPin);  //设置舵机引脚为IO4
  myservo.write(0); //旋转到0度
  delay(1000); //延迟1s

  // 使用 SSID 和密码连接到 Wi-Fi 网络
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // 打印本地IP地址并启动Web服务器
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();   // 监听数据

  if (client) {                             // 如果有新客户端连接，
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");          // 在串行端口中打印一条消息
    String currentLine = "";                // 创建一个字符串来保存来自客户端的传入数据
    while (client.connected() && currentTime - previousTime <= timeoutTime) {  // 当客户端连接时循环
      currentTime = millis();
      if (client.available()) {             // 如果有字节要从客户端读取，
        char c = client.read();             // 读取一个字节
        Serial.write(c);                    // 将其打印出串行监视器
        header += c;
        if (c == '\n') {                    // 如果该字节是换行符
           // 如果当前行为空，则连续有两个换行符。
           // 这就是客户端 HTTP 请求的结束，因此发送响应：
          if (currentLine.length() == 0) {
             // HTTP 标头始终以响应代码开头（例如 HTTP/1.1 200 OK）
             // 一个内容类型，以便客户端知道接下来会发生什么，然后是一个空行：
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            // 网页标题
            client.println("<body><h1>ESP32 Web Server</h1>");
            // HTTP响应的内容跟在首部之后:
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/A\">here</a> turn on Relay<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/B\">here</a> turn off Relay<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/C\">here</a> turn on RGB<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/D\">here</a> turn off RGB<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/E\">here</a> turn on fan<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/F\">here</a> turn off fan<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/G\">here</a> turn on buzzer<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/H\">here</a> turn off buzzer<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/I\">here</a> <br>servo turn to 180</p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/J\">here</a> <br>servo turn to 0</p>");
           
            // HTTP响应以另一个空行结束:
            client.println();
            // 跳出while循环:
            break;
          } else {    // 如果有换行符，清除currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // 如果你有除回车字符以外的其他字符,
          currentLine += c;      // 并且将其添加到currentLine的末尾
        }

        // 检查客户端请求是否存在 "GET /A"or"GET /B"or"GET /C"or"GET /D"or"GET /E"or"GET /F"or"GET /G"or"GET /H"or"GET /I"or"GET /J":
        if (currentLine.endsWith("GET /A")) {    // GET /A 打开继电器
          digitalWrite(relayPin, HIGH);       
        }
        if (currentLine.endsWith("GET /B")) {    // GET /B 关闭继电器
          digitalWrite(relayPin, LOW); 
        }
        if (currentLine.endsWith("GET /C")) {    // GET /C 打开RGB
            // Cycle through basic colors
          setColor(255, 0, 0);  // Red
          delay(1000);       // Wait for 1 second
          setColor(0, 255, 0);  // Green
          delay(1000);       // Wait for 1 second
          setColor(0, 0, 255);  // Blue
          delay(1000);       // Wait for 1 second

            // Cycle through blended colors
          setColor(255, 0, 252);  // Magenta
          delay(1000);         // Wait for 1 second
          setColor(237, 109, 0);  // Orange
          delay(1000);         // Wait for 1 second
          setColor(255, 215, 0);  // Yellow
          delay(1000);         // Wait for 1 second
          setColor(34, 139, 34);  // Forest Green
          delay(1000);         // Wait for 1 second
          setColor(0, 112, 255);  // Light Blue
          delay(1000);         // Wait for 1 second
          setColor(0, 46, 90);    // Indigo
          delay(1000);         // Wait for 1 second
          setColor(128, 0, 128);  // Purple
          delay(1000);         // Wait for 1 second       
        }
        if (currentLine.endsWith("GET /D")) {    // GET /D 关闭RGB
          setColor(0, 0, 0);  // Black
        }
        if (currentLine.endsWith("GET /E")) {  // GET /E 直流电机转动
          digitalWrite(motoraPin, LOW);  
          digitalWrite(motorbPin, HIGH);               
        }
        if (currentLine.endsWith("GET /F")) {  // GET /F 直流电机不转
          digitalWrite(motoraPin, LOW);  
          digitalWrite(motorbPin, LOW);                 
        }
        if (currentLine.endsWith("GET /G")) {  // GET /G 打开有源蜂鸣器
          digitalWrite(buzzerPin, HIGH);                              
        }
        if (currentLine.endsWith("GET /H")) {  // GET /H 关闭无源蜂鸣器
          digitalWrite(buzzerPin, LOW);                              
        }
        if (currentLine.endsWith("GET /I")) {  // GET /J 舵机转到180°
          myservo.write(180); //旋转到180度
          delay(1000); //延迟1s
        }
        if (currentLine.endsWith("GET /J")) {  // GET /K 舵机转到0°
          myservo.write(0); //旋转到0度
          delay(1000); //延迟1s
        }
      } 
    }
    // 清除头变量
    header = "";
    // 断开连接:
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}

// Function to set the RGB LED color
void setColor(int red, int green, int blue) {
  ledcWrite(chns[1], red); //共阴极LED，高电平开启LED.
  ledcWrite(chns[2], green);
  ledcWrite(chns[3], blue);
}
