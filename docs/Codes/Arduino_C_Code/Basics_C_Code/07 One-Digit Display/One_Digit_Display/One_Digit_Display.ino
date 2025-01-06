/*
 * 名称   : One_Digit_Display
 * 功能   : 一位数码管显示0-9数字
 * 编译IDE：ARDUINO 2.3.3
 * 作者   : https://www.keyestudio.com/ 
*/
const int rckPin = 23; //RCK
const int sckPin = 18; //SCK
const int siPin = 5; //SI 

int datArray[] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void setup (){
  //set pins to output
  pinMode(rckPin,OUTPUT);
  pinMode(sckPin,OUTPUT);
  pinMode(siPin,OUTPUT);
}

void loop(){
  for(int num = 0; num <10; num++){
    digitalWrite(rckPin,LOW); //ground RCK and hold low for as long as you are transmitting
    shiftOut(siPin,sckPin,MSBFIRST,datArray[num]);
    digitalWrite(rckPin,HIGH); //pull the RCK to save the data
    delay(1000);
  }
}
