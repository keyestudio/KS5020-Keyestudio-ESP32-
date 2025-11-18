'''
 * Filename    : Buzzer_Beep 
 * Thonny      : Thonny 4.1.7 
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin
import time

buzzer = Pin(13, Pin.OUT)   # set buzzer pin to 13, and set it to output

try:
    while True:
        buzzer.value(1)    # the buzzer buzzes
        time.sleep(0.5) # delay 0.5s
        buzzer.value(0)    # the buzzer keeps quiet
        time.sleep(0.5) # delay 0.5s
except:
    pass