'''
 * Filename    : Electronic_Hourglass
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin 
import time

led1 = Pin(16, Pin.OUT) # connect LED to pin 16, and set pin 16 to output mode
led2 = Pin(17, Pin.OUT) # connect LED to pin 17, and set pin 17 to output mode
led3 = Pin(18, Pin.OUT) # connect LED to pin 18, and set pin 18 to output mode
led4 = Pin(19, Pin.OUT) # connect LED to pin 19, and set pin 19 to output mode
Tilt_Sensor = Pin(26,Pin.IN) # connect tilt sensor to pin 26, and set pin IO26 to input mode
 
while True:
    if(Tilt_Sensor.value() == 1) : # if the tilt sensor value equals to 1
        led1.value(1) # led1 on
        time.sleep_ms(200) #delay
        led2.value(1) # led2 on
        time.sleep_ms(200) #delay
        led3.value(1) # led3 on
        time.sleep_ms(200) #delay
        led4.value(1) # led4 on
        time.sleep_ms(200) #delay
    else :  # if the tilt sensor value equals to 0
        led4.value(0) # led4 off
        time.sleep_ms(200) #delay
        led3.value(0) # led3 off
        time.sleep_ms(200) #delay
        led2.value(0) # led2 off
        time.sleep_ms(200) #delay
        led1.value(0) # led1 off
        time.sleep_ms(200) #delay
