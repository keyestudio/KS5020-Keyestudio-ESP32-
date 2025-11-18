/*  
 * Filename: Magic_Color_Music_Box
 * Function: Ultrasound measures distance, controls a buzzer and 7 leds to simulate the Magic color music box
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int trig = 33;  //Set ultrasonic sensor Trig pin to IO33
const int echo = 32;  //Set ultrasonic sensor Echo pin to IO32
const int LED1 = 13;   //Set LED1 pin to IO13
const int LED2 = 12;   //Set LED2 pin to IO12
const int LED3 = 14;   //Set LED3 pin to IO14
const int LED4 = 27;   //Set LED4 pin to IO27
const int LED5 = 16;   //Set LED5 pin to IO16
const int LED6 = 17;   //Set LED6 pin to IO17
const int LED7 = 25;   //Set LED7 pin to IO25
const int beeppin = 18;  //Set passive buzzer pin to IO18

int duration = 0;  //Set duration initial value to 0
int distance = 0;  //Set distance initial value to 0

void setup() {
  Serial.begin(9600);     //Set baud rate to 9600
  pinMode(trig, OUTPUT);  //Set ultrasonic sensor Trig digital pin to output mode
  pinMode(echo, INPUT);   //Set ultrasonic sensor Echo digital pin to output mode
  pinMode(LED1, OUTPUT);  //Set LED1 digital pin to output mode
  pinMode(LED2, OUTPUT);  //Set LED2 digital pin to output mode
  pinMode(LED3, OUTPUT);  //Set LED3 digital pin to output mode
  pinMode(LED4, OUTPUT);  //Set LED4 digital pin to output mode
  pinMode(LED5, OUTPUT);  //Set LED5 digital pin to output mode
  pinMode(LED6, OUTPUT);  //Set LED6 digital pin to output mode
  pinMode(LED7, OUTPUT);  //Set LED7 digital pin to output mode
  pinMode(beeppin, OUTPUT); //Set passive buzzer digital pin to output mode 
  ledcSetup(3, 2000, 8);  // Set passive buzzer channel to 3, frequency 2000, PWM resolution 8.
  ledcAttachPin(beeppin, 3);  // bind LEDC channel to passive buzzer IO port to output
  ledcWrite(3, 0); // stop playing
}
void loop(){
  //Keep trigPin output high for 10μs to trigger HC_SR04
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  //Wait for HC-SR04 to return to high and measure this wait time
  duration = pulseIn(echo, HIGH);
  //Calculate distance based on time
  distance = (duration / 2) / 28.5;
  Serial.println(distance);  // print distance value
  if (distance > 0 && distance <= 5){  // If ultrasonic sensor detection distance ranges from 0~5cm
    digitalWrite(LED1, HIGH);  //LED1 on
    ledcSetup(3, 2000, 8);   
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 262);  // passive buzzer plays tone do
    delay(1000);  //Delay 1000ms
  }
  else{  //Otherwise，ultrasonic sensor detection distance does not range from 0~5cm
    digitalWrite(LED1, LOW);  //LED1 off
    ledcSetup(3, 2000, 8);    // stop playing
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 0); 
  }
  if (distance > 5 && distance <= 10){  //If ultrasonic sensor detection distance ranges from 5~10cm
    digitalWrite(LED2, HIGH);  //LED2 on
    ledcSetup(3, 2000, 8);   
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 294);  //passive buzzer plays tone re
    delay(750);
  }
  else{  //Otherwise，ultrasonic sensor detection distance does not range from 5~10cm
    digitalWrite(LED2, LOW);  //LED2 off
    ledcSetup(3, 2000, 8);    // stop playing
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 0); 
  }
  if (distance > 10 && distance <= 15){  //If ultrasonic sensor detection distance ranges from 10~15cm
    digitalWrite(LED3, HIGH);  //LED3 on
    ledcSetup(3, 2000, 8);   
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 330);  //passive buzzer plays tone mi
    delay(625);
  }
  else{  //Otherwise，ultrasonic sensor detection distance does not range from 10~15cm
    digitalWrite(LED3, LOW);  //LED3 off
    ledcSetup(3, 2000, 8);    // stop playing
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 0); 
  }
    if (distance > 15 && distance <= 20){  //If ultrasonic sensor detection distance ranges from 15~20cm
    digitalWrite(LED4, HIGH);  //LED4 on
    ledcSetup(3, 2000, 8);   
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 349);  //passive buzzer plays tone fa
    delay(500);
  }
  else{  //Otherwise，ultrasonic sensor detection distance does not range from 15~20cm
    digitalWrite(LED4, LOW);  //LED4 off
    ledcSetup(3, 2000, 8);    // stop playing
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 0); 
  }
  if (distance > 20 && distance <= 25){  //If ultrasonic sensor detection distance ranges from 20~25cm
    digitalWrite(LED5, HIGH);  //LED5 on
    ledcSetup(3, 2000, 8);   
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 392);  //无源鸣器 plays tone so
    delay(375);
  }
  else{  //Otherwise，ultrasonic sensor detection distance does not range from 20~25cm
    digitalWrite(LED5, LOW);  //LED5 off
    ledcSetup(3, 2000, 8);    // stop playing
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 0); 
  }
  if (distance > 25 && distance <= 30){  //If ultrasonic sensor detection distance ranges from 25~30cm
    digitalWrite(LED6, HIGH);  //LED6 on
    ledcSetup(3, 2000, 8);   
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 440);   //passive buzzer plays tone la
    delay(250);
  }
  else{  //Otherwise，ultrasonic sensor detection distance does not range from 25~30cm
    digitalWrite(LED6, LOW);  //LED6 off
    ledcSetup(3, 2000, 8);    // stop playing
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 0); 
  }
  if (distance > 30 && distance <= 35){  //If ultrasonic sensor detection distance ranges from 30~35cm
    digitalWrite(LED7, HIGH);  //LED7 on
    ledcSetup(3, 2000, 8);   
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 494);  //passive buzzer plays tone si
    delay(125);
  }
  else{  //Otherwise，ultrasonic sensor detection distance does not range from 30~35cm
    digitalWrite(LED7, LOW);  //LED7 off
    ledcSetup(3, 2000, 8);    // stop playing
    ledcAttachPin(beeppin, 3);  
    ledcWrite(3, 0); 
  }
}     
