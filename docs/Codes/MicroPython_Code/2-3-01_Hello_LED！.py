'''
 * Filename    : Hello_LED 
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# import Pin and time library
from machine import Pin
import time

led = Pin(26, Pin.OUT)   # Set LED pin to 26 and set it to output

try:
    while True:
        led.value(1)   # LED on
        time.sleep(1)  # Delay 1s
        led.value(0)   # LED off
        time.sleep(1)  # Delay 1s
except:
    pass