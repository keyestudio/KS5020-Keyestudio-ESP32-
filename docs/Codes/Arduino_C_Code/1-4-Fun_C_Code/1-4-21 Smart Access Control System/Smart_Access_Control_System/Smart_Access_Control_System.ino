/* 
 * Filename: Smart Access Control System
 * Function: RFID control the servo to open the "door"
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
#include <Wire.h>
#include "MFRC522_I2C.h"
// The IIC pins default to IO21 and IO22 of the ESP32,SDA-->IO21,SCL-->IO22
// 0x28 is the i2c address of SDA, if it does not match, please check your address with i2c.
MFRC522 mfrc522(0x28);   // Create the address of MFRC522

#include <ESP32Servo.h>
Servo myservo;  // Create a servo object to control the servo
const int servoPin = 4; // Connect the servo pin to IO4

String rfid_str = "";

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mfrc522.PCD_Init();
  ShowReaderDetails();            // Display the PCD-MFRC522 card reader
  Serial.println(F("Scan PICC to see UID, type, and data blocks..."));
  
  myservo.setPeriodHertz(50);           // Standard 50 Hz click
  myservo.attach(servoPin, 500, 2500);  // Attach the servo on the servoPin to the servo object
  myservo.write(0); 
  delay(500);
}

void loop() {
   if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }
  
  // Select a card. UID and SAK are mfrc522.uid.
  
  // save UID
  rfid_str = ""; //Empty string
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    rfid_str = rfid_str + String(mfrc522.uid.uidByte[i], HEX);  //Convert to string
    //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    //Serial.print(mfrc522.uid.uidByte[i], HEX);
  } 
  Serial.println(rfid_str);
  
  if (rfid_str == "d963d3b3" || rfid_str == "d4e8e5e9") {
    myservo.write(180);
    delay(500);
    Serial.println("  open the door!");
    }
}

void ShowReaderDetails() {
  //  Run or invoke the MFRC522 software
  byte v = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
  Serial.print(F("MFRC522 Software Version: 0x"));
  Serial.print(v, HEX);
  if (v == 0x91)
    Serial.print(F(" = v1.0"));
  else if (v == 0x92)
    Serial.print(F(" = v2.0"));
  else
    Serial.print(F(" (unknown)"));
  Serial.println("");
  // When returned to 0x00 or 0xFF, the communication signal may not be transmitted
  if ((v == 0x00) || (v == 0xFF)) {
    Serial.println(F("WARNING: Communication failure, is the MFRC522 properly connected?"));
  }
}
