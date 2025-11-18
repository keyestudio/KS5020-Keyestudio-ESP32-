/*  
 * Filename: Corridor_Induction_Lamp
 * Function: Control LED with light sensor and PIR motion sensor
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int photoresistorPin = 36;  // set photoresistor pin to IO36
const int pirPin = 12;  // set PIR motion sensor pin to IO12
const int ledPin = 25;  // set LEDpin to IO25
byte pirStat = 0;   // PIR motion sensor state

void setup() {
  Serial.begin(9600);  // set baud rate to 9600
  pinMode(ledPin, OUTPUT);  // set LED pin to output
  pinMode(photoresistorPin, INPUT);  // set photoresistor pin to input
  pinMode(pirPin, INPUT);  // set PIR motion sensor pin to input
}

void loop() {
  int adcVal = analogRead(photoresistorPin); // read photoresistor analog value，and assign to adcVal
  Serial.println(adcVal); //print analog value 
  pirStat = digitalRead(pirPin); // read PIR motion sensor value
  if (adcVal >= 3500) { // if photoresistor analog value is greater than or equal to 3500
    if (pirStat == HIGH){  // if PIR motion sensor detects human motion
      digitalWrite(ledPin, HIGH); // Turn on the external LED
      delay(5000);
    } 
    else{ // or else, PIR motion sensor does not detect human motion
      digitalWrite(ledPin, LOW); // Turn off the external LED   
    }
  }
  else{  // or else, photoresistor analog value is smaller than 3500
    digitalWrite(ledPin, LOW); // Turn off the external LED
  }
}

