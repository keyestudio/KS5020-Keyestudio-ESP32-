'''
 * Filename    : Tilt_Switch
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin
import time

TiltSensor = Pin(14, Pin.IN) # set tilt switch pin to input

while True:
    value = TiltSensor.value()  # assign the value read by the tilt switch to variable value
    print(value, end = " ")  # print the value read by the tilt switch
    if  value== 1: # if tilt switch tilts, the serial monitor shows relevant messages
        print("The switch is turned on")
    else:  # if tilt switch does not tilt, the serial monitor shows relevant messages
        print("The switch is turned off")
    time.sleep(0.1)