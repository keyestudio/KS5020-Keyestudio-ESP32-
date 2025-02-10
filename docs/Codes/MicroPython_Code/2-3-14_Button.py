'''
 * Filename    : Button
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin
import time 

button = Pin(14, Pin.IN, Pin.PULL_UP) # set the button pin to input and pull-up mode

while True: 
    if button.value() == 0: # press the button, print related messages
        print("0  You pressed the button!")  
    else:  # release the button, print related messages
        print("1  You loosen the button!")
    time.sleep(0.1)  # delay 0.1s
