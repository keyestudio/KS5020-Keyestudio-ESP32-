/*  
 * Filename: RFID_RC522
 * Function: RFID read UID
 * Compiling IDE：ARDUINO 2.3.3
 * Author: https://www.keyestudio.com/
*/
#include <Wire.h>
#include "MFRC522_I2C.h"

// IIC pins default to GPIO21(SDA) and GPIO22(SCL) of the ESP32
// 0x28 is the i2c address on the SDA. If it doesn't match, check your address with i2cscanner
MFRC522 mfrc522(0x28);   // Create an instance of MFRC522

void setup() {
  Serial.begin(115200);           // Initialize serial communication with the PC
  Wire.begin();                   // Initialize I2C
  mfrc522.PCD_Init();             // Initialize MFRC522
  ShowReaderDetails();            // Display detailed PCD-MFRC522 card reader details
  Serial.println(F("Scan PICC to see UID, type, and data blocks..."));
}

void loop() {
  // Look for new cards and choose one if available
  if ( ! mfrc522.PICC_IsNewCardPresent() || ! mfrc522.PICC_ReadCardSerial() ) {
    delay(50);
    return;
  }
  
  // Select a key card with the UID and SAK as mfrc522.uid and save the UID
  Serial.print(F("Card UID:"));
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  } 
  Serial.println();
}

void ShowReaderDetails() {
  // Obtain MFRC522 software
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
  // The communication signal may not be transmitted when it returns to 0x00 or 0xFF
  if ((v == 0x00) || (v == 0xFF)) {
    Serial.println(F("WARNING: Communication failure, is the MFRC522 properly connected?"));
  }
}
