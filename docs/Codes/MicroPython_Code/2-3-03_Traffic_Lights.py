'''
 * Filename    : Traffic_Lights
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin 
import time

led_red = Pin(13, Pin.OUT)  # Connect red LED to pin 13, and set it to output mode
led_yellow = Pin(14, Pin.OUT)  # Connect yellow LED to pin 14, and set it to output mode
led_green = Pin(16, Pin.OUT) # Connect green LED to pin 16, and set it to output mode
 
while True:
    led_red.value(1)  # red LED on
    time.sleep(5)   # delay 5s
    led_red.value(0) # red LED off
    led_yellow.value(1)
    time.sleep(0.5)
    led_yellow.value(0)
    time.sleep(0.5)
    led_yellow.value(1)
    time.sleep(0.5)
    led_yellow.value(0)
    time.sleep(0.5)
    led_yellow.value(1)
    time.sleep(0.5)
    led_yellow.value(0)
    time.sleep(0.5)
    led_green.value(1)
    time.sleep(5) 
    led_green.value(0) 