'''
 * Filename    : Home_Appliances
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin
import time

relay = Pin(12, Pin.OUT) # connect relay to pin 12, and set pin 12 to output mode                  
button = Pin(26, Pin.IN, Pin.PULL_UP) #connect button to pin 26, and set pin 26 to input pull-up mode

# define a function called reverseGPIO() to reverse the relay output level
def reverseGPIO():
    if relay.value():
        relay.value(0)     #LED off
    else:
        relay.value(1)     #LED on

try:
    while True:
        if not button.value():
            time.sleep_ms(20)
            if not button.value():
                reverseGPIO()
                while not button.value():
                    time.sleep_ms(20)
except:
    pass
