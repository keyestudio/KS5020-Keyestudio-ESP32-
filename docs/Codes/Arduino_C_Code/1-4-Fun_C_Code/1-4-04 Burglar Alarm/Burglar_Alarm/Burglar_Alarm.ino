/*  
 * Filename: Burglar_Alarm
 * Function: The PIR controls the buzzer and LED to simulate the burglar alarm
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int ledPin = 26;  // define LED pin to IO26
const int PIR_PIN = 14;  // PIR motion sensor control pin to IO14
const int BUZZER_PIN = 19;  //define active buzzer control pin to IO19

int item = 0;  //define item initial value to 0

void setup() {
  Serial.begin(9600);//set baud rate to 9600
  pinMode(PIR_PIN, INPUT);  //set PIR motion sensor pin to input
  pinMode(BUZZER_PIN, OUTPUT); //set active buzzer pin to output
  pinMode(ledPin, OUTPUT);// set led pin to output
}

void loop() {
  item = digitalRead(PIR_PIN); //Read the digital signal output of PIR motion sensor
  Serial.println(item);    //Print the value of the item
  if (item == 1) {  //Motion detection, output high level signal
    digitalWrite(BUZZER_PIN, HIGH); //Turn on the buzzer
    digitalWrite(ledPin, HIGH); // LED on
    delay(200);//delay 200ms
    digitalWrite(BUZZER_PIN, LOW); //Turn off the buzzer
    digitalWrite(ledPin, LOW); // LED off
    delay(200);//delay 200ms
  } else {  //No signals or data were detected
    digitalWrite(BUZZER_PIN, LOW); //Turn off the buzzer
    digitalWrite(ledPin, LOW); // LED off
  }
}