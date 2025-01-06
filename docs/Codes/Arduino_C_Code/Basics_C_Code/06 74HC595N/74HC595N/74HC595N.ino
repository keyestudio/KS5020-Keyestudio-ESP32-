/*
 * 名称   : 74HC595N
 * 功能   : 74HC595N控制8个LED实现流水一样的效果
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/
*/
const int rckPin = 23; //RCK
const int sckPin = 18; //SCK
const int siPin = 5; //SI 

int datArray[] = {B00000000, B00000001, B00000011, B00000111, B00001111, B00011111, B00111111, B01111111, B11111111};

void setup (){
  //set pins to output
  pinMode(rckPin,OUTPUT);
  pinMode(sckPin,OUTPUT);
  pinMode(siPin,OUTPUT);
}

void loop(){
  for(int num = 0; num < 9; num++){
    digitalWrite(rckPin,LOW); //ground RCK and hold low for as long as you are transmitting
    shiftOut(siPin,sckPin,MSBFIRST,datArray[num]);
    digitalWrite(rckPin,HIGH); //pull the RCK to save the data
    delay(1000);
  }
}
