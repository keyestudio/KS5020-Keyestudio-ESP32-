/*  
 * Filename: Home_Appliances
 * Function: Use relays and button to control motor rotation to simulate small household appliances
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int relayPin = 12;          // set relay pin to IO12
const int buttonPin = 26;         //set button pin to IO26

int buttonState = HIGH;     // record button state, and set state to high
int relayState = LOW;       //record relay state, and set state to low
int lastButtonState = HIGH; // record last button state 
long lastChangeTime = 0;    // record button state changing time

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);   // set button pin to input
  pinMode(relayPin, OUTPUT);          // set relay pin to output
  digitalWrite(relayPin, relayState); // set relay inital state to “off”
}
void loop() {
  int nowButtonState = digitalRead(buttonPin);// read button pin current state 
  // if button pin state changes, record time point
  if (nowButtonState != lastButtonState) {
    lastChangeTime = millis();
  }
  // if button state changes, and remain stable for a while, then it should skip the rebound area
  if (millis() - lastChangeTime > 10) {
    if (buttonState != nowButtonState) {    // ensure button state is changed
      buttonState = nowButtonState;
      if (buttonState == LOW) {             // low means button is pressed
        relayState = !relayState;           // reverse relay state 
        digitalWrite(relayPin, relayState); // update relay state 
      }
    }
  }
  lastButtonState = nowButtonState; // store the last button state 
}

