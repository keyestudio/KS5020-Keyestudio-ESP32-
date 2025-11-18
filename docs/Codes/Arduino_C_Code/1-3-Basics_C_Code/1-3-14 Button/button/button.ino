/*
 * Filename: button
 * Function: read button value
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int button = 14;  // set button pin to IO14
int val = 0;       // store button value

void setup() {
  Serial.begin(9600);    // set baud rate to 9600
  pinMode(button, INPUT);  // Set the pin to input mode
}

void loop() {
  val = digitalRead(button);  // Read the button value and assign it to the variable val
  Serial.print(val);          // print val
  if (val == 0) {             // The low level is read when the button is pressed and the relevant message is printed out
    Serial.print("    ");  
    Serial.println("Press the botton"); // Print button released message
    delay(100);
  }
  else {               // release button
    Serial.print("    ");
    Serial.println("Loose the botton");
    delay(100);
  }
}
