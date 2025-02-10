'''
 * Filename    : Smart_Access_Control_System
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin, PWM
import time
from mfrc522_i2c import mfrc522

# define the output frequency of IO4 as 50Hz and assign it to PWM.
servoPin = PWM(Pin(4)) 
servoPin.freq(50)
servoPin.duty(256)

# i2c config.
addr = 0x28
scl = 22
sda = 21

# initialize the pins and addresses of mfrc522
rc522 = mfrc522(scl, sda, addr)
rc522.PCD_Init()
rc522.ShowReaderDetails()  # display details of the PCD-MFRC522 card reader

# UID code values of the white card and green key chain
uid1 = [180, 180, 170, 219]
uid2 = [231, 185, 101, 101]

# initial Angle of the servo
servoPin.duty_u16(1638)
time.sleep(1)

# Read the UID code values for the white card and the green key chain. If the value is correct, the servo rotates.
while True:
    if rc522.PICC_IsNewCardPresent():
        #print("Is new card present!")
        if rc522.PICC_ReadCardSerial() == True:
            print("Card UID:", end=' ')
            print(rc522.uid.uidByte[0 : rc522.uid.size])
            if rc522.uid.uidByte[0 : rc522.uid.size] == uid1 or rc522.uid.uidByte[0 : rc522.uid.size] == uid2:
                servoPin.duty_u16(8100)
                time.sleep(1)
            else :
                servoPin.duty_u16(1638)
                time.sleep(1)
                