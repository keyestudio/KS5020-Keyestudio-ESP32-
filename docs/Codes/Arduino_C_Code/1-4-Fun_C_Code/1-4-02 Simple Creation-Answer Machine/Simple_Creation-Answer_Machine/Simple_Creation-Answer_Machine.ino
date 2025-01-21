/*  
 * Filename: Simple Creation-Answer Machine
 * Function: Simple creation Answer Machine
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int button1 = 5;  // the pin of the button1 to IO5
const int button2 = 13;  // button2 attach to IO13
const int button3 = 12;  // button3 attach to IO12
const int button4 = 14;  // button4 attach to IO14
const int buzzerPin = 19;  // the buzzer attach to IO18    
const int LED_R = 16;  // LED_R attach to IO16    
const int LED_G = 17;  // LED_G attach to IO17   
const int LED_B = 25;  // LED_Battach to IO25
const int LED_Y = 26;  // LED_Y attach to IO26
#define uint8 unsigned char
uint8 flag = 0;  // used to indicate the state of button4 key
uint8 b1State,b2State,b3State,b4State = 0;

void setup(){
  //initialize buzzer,LED_R, LED_G, LED_B and LED_Y as output
  pinMode(buzzerPin, OUTPUT);     
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);     
  pinMode(LED_B, OUTPUT); 
  pinMode(LED_Y, OUTPUT);
  //initialize button1,button2,button3 and button4 as input,combined with pullup
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);    
  pinMode(button4, INPUT_PULLUP);
  //turn all the led off
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);  
  digitalWrite(LED_B, LOW); 
  digitalWrite(LED_Y, LOW);
}
void loop(){
  //turn all the led off
  digitalWrite(LED_R, LOW);
  digitalWrite(LED_G, LOW);  
  digitalWrite(LED_B, LOW);  
  digitalWrite(LED_Y, LOW);
  //read the state of the button4
  b4State = digitalRead(button4);
  //when button4 pressed
  if(b4State == 0){
    if(b4State == 0){  //confirm that the button4 is pressed
      flag = 1;  //if so,flag is 1
      digitalWrite(LED_Y, HIGH);  //turn the host LED_Y on
      delay(200);  
    }
  }
  if(flag == 1){
    //read the state of the button of buttons
    b1State = digitalRead(button1);  
    b2State = digitalRead(button2);
    b3State = digitalRead(button3);
    //If the button1 press the first
    if(b1State == 0){
      flag = 0;
      digitalWrite(LED_Y, LOW);
      Alarm();  //buzzer sound
      digitalWrite(LED_R,HIGH);  //turn the LED_R on only
      digitalWrite(LED_G,LOW); 
      digitalWrite(LED_B,LOW); 
      while(digitalRead(button4));  //detect the button4,if pressed,out of the while loop
    }
    //If the button2 press the first
    if(b2State == 0){
      flag = 0;
      digitalWrite(LED_Y, LOW);
      Alarm();
      digitalWrite(LED_R,LOW);
      digitalWrite(LED_G,HIGH); 
      digitalWrite(LED_B,LOW); 
      while(digitalRead(button4));
    }
    //If the button3 press the first
    if(b3State == 0){
      flag = 0;
      digitalWrite(LED_Y, LOW);
      Alarm();
      digitalWrite(LED_R,LOW);
      digitalWrite(LED_G,LOW); 
      digitalWrite(LED_B,HIGH); 
      while(digitalRead(button4));
    }
  }
}
//buzzer sound
void Alarm()         {
  for(int i=0;i<100;i++){
    digitalWrite(buzzerPin,HIGH); //the buzzer sound
    delay(2);
    digitalWrite(buzzerPin,LOW);  //without sound
    delay(2);                     //when delay time changed,the frequency changed
  }
} 
