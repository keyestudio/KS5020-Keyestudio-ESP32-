'''
 * Filename    : Human Nearby or Not 
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin
import time

PIR = Pin(14, Pin.IN)  # set PIR motion sensor pin to input
 
while True:
    value = PIR.value()  # aggign the value read by PIR motion sensor to the variable value
    print(value, end = " ")  # show the value read by the PIR motion sensor
    if value == 1:  # if PIR motion sensor detects motion, the serial monitor prints relevant messages
        print("Some body is in this area!")
    else:  # if PIR motion sensor does not detect motion, the serial monitor prints relevant messages
        print("No one!")
    time.sleep(0.1)