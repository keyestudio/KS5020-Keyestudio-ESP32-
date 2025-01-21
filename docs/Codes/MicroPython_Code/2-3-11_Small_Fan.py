'''
 * Filename    : Small_Fan
 * Thonny      : Thonny 4.1.7 
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin
import time 

motor1a = Pin(13, Pin.OUT) # set motor1a pin to 13, and set it to output
motor1b = Pin(12, Pin.OUT) # set motor1b pin to 12, and set it to output

def forward():
    motor1a.value(1) # set motor1a to high
    motor1b.value(0) # set motor1b to low
def backward():
    motor1a.value(0)
    motor1b.value(1)
def stop():
    motor1a.value(0)
    motor1b.value(0)

def test():
    forward() # the motor rotates forwards
    time.sleep(5) # delay
    stop() # the motor stops
    time.sleep(2)
    backward()# the motor rotates backwards
    time.sleep(5)
    stop()
    time.sleep(2)
    
for i in range(5):
    test() 