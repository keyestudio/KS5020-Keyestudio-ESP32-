/*
 * Filename: Human Nearby or Not
 * Fuunction: read PIR motion sensor value
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int pirPin = 14;  // set PIR motion sensor pin to IO14
int val = 0;

void setup() {
  Serial.begin(9600);   // set baud rate to 9600
  pinMode(pirPin, INPUT);   // set sensor to input 
}

void loop() {
  val = digitalRead(pirPin);    // read sensor value
  Serial.print(val);    // print sensor value
  if (val == 1) {    // Output high level when someone moves nearby
    Serial.print("        ");
    Serial.println("Some body is in this area!");
    delay(100);
  }
  else {    // If no one moves nearby, the output is low
    Serial.print("        ");
    Serial.println("No one!");
    delay(100);
  }
}