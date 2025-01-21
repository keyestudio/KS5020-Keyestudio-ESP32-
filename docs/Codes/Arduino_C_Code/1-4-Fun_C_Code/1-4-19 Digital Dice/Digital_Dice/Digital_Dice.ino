/*
 * Filename: Digital_Dice
 * Function: Digital Dice
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int siPin = 5;   // SI of 74HC595
const int rckPin = 23;  // RCK of 74HC595
const int sckPin = 18;  // SCK of 74HC595
const int tiltPin = 26;    // The pin where the tilt switch is connected

// Byte representation for numbers in a common-cathode 7-segment display
byte numbers[] = {
  // 0b00111111,  // 0
  0b00000110,  // 1
  0b01011011,  // 2
  0b01001111,  // 3
  0b01100110,  // 4
  0b01101101,  // 5
  0b01111101,  // 6
  //... Add the values for the rest of the numbers
};

// State and timing variables
volatile bool rolling = false;
unsigned long lastShakeTime = 0;

void setup() {
  // Initialize pins
  pinMode(siPin, OUTPUT);
  pinMode(sckPin, OUTPUT);
  pinMode(rckPin, OUTPUT);
  pinMode(tiltPin, INPUT_PULLUP);  // Enable internal pull-up resistor

  // Attach an interrupt to the tiltPin. When the tilt switch is activated, the shakeDetected function will be called
  attachInterrupt(digitalPinToInterrupt(tiltPin), rollDice, CHANGE);
}

void loop() {
  // Check if it's rolling
  if (rolling) {
    byte number = random(1, 7);  // Generate a random number between 1 and 6
    displayNumber(number);
    delay(100);  // Delay to make the rolling effect visible

    // Stop rolling after 1 second
    if ((millis() - lastShakeTime) > 1000) {
      rolling = false;
    }
  }
}

// Interrupt handler for shake detection
void rollDice() {
  if (digitalRead(tiltPin) == LOW) {
    lastShakeTime = millis();  // Record the time of shake
    rolling = true;            // Start rolling
  }
}

// Function to display a number on the 7-segment display
void displayNumber(byte number) {
  digitalWrite(rckPin, LOW);
  shiftOut(siPin, sckPin, MSBFIRST, numbers[number - 1]);
  digitalWrite(rckPin, HIGH);
}
