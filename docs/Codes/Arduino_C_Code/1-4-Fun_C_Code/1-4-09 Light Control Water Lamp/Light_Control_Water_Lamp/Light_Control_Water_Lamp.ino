/*
 * Filename: Light control water lamp
 * Function: Light intensity control 8 LED like water flow
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
const int NbrLEDs = 8; // 8 leds
const int ledPins[] = {17, 16, 27, 14, 12, 13, 5, 23}; // 8 leds attach to 8 pins respectively
const int photocellPin = 36;  //photoresistor attach to IO36
int sensorValue = 0;  // value read from the sensor
int ledLevel = 0;   // sensor value converted into LED 'bars'

void setup(){
  Serial.begin(9600);  // start serial port at 9600 bps:
  for (int led = 0; led < NbrLEDs; led++){
    pinMode(ledPins[led], OUTPUT);  // make all the LED pins outputs
  }
}

void loop(){
  sensorValue = analogRead(photocellPin); // read the value of IO36
  Serial.print("SensorValue: ");
  Serial.println(sensorValue);  // Print the analog value of the photoresistor
  ledLevel = map(sensorValue, 0, 4095, 0, NbrLEDs);  // map to the number of LEDs
  Serial.print("ledLevel: ");
  Serial.println(ledLevel);
  for (int led = 0; led < NbrLEDs; led++){
    if (led <= ledLevel ){  // When led is smaller than ledLevel, run the following code.
      digitalWrite(ledPins[led], HIGH);     // turn on pins less than the level
    }
    else{
      digitalWrite(ledPins[led], LOW);     // turn off pins higher than
    }
  }
}
