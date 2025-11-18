'''
 * Filename    : 4x4_Keypad
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# import keypad library
from keypad import KeyPad
import time

# connect keypad midule to ESP32 pins
keyPad = KeyPad(26, 25, 17, 16, 27, 14, 12, 13)

# Call the keyPad.scan() function to get key values. Once you get them, print on Shell.
def key():
    keyvalue = keyPad.scan()
    if keyvalue != None:
        print(keyvalue, end="\t")
        time.sleep_ms(300)
        return keyvalue
            
while True: 
    key()
