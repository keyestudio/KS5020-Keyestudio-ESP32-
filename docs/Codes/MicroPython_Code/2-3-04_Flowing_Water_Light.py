'''
 * Filename    : Flowing_Water_Light
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
''' 
from machine import Pin
import time

# Use the array to define five IO ports connected to leds
pins = [18, 5, 14, 17, 26]
# Use two for loops to turn on the led from left to right, and then from right to left
def showLed():
    for pin in pins:
        print(pin)
        led = Pin(pin, Pin.OUT)
        led.value(1)
        time.sleep_ms(100)
        led.value(0)
        time.sleep_ms(100)        
    for pin in reversed(pins):
        print(pin)
        led = Pin(pin, Pin.OUT)
        led.value(1)
        time.sleep_ms(100)
        led.value(0)
        time.sleep_ms(100)
          
while True:
    showLed()