'''
 * Filename    : Ultrasonic
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin 
import time

# set the ultrasonic sensor pins
Trig = Pin(13, Pin.OUT, 0) 
Echo = Pin(12, Pin.IN, 0)

distance = 0 # set initial distance value to 0
soundVelocity = 340 #Set the speed of sound.

# getDistance() is used to drive the ultrasonic module to measure distance
# Trig holds a high level of 10us to activate the ultrasonic module
# Echo.value() is used to read the status of the Echo pin of the ultrasonic module
# time.sleep_us() function of the time module calculates the duration of the Echo
# Trig pin high level calculates the measured distance based on time and returns the value
def getDistance():
    Trig.value(1)
    time.sleep_us(10)
    Trig.value(0)
    while not Echo.value():
        pass
    pingStart = time.ticks_us()
    while Echo.value():
        pass
    pingStop = time.ticks_us()
    pingTime = time.ticks_diff(pingStop, pingStart) // 2
    distance = int(soundVelocity * pingTime // 10000)
    return distance

# delay 2 seconds, wait for the ultrasonic module to stabilize
# print values obtained from the ultrasonic module every 500 milliseconds
time.sleep(2)
while True:
    time.sleep_ms(500)
    distance = getDistance()
    print("Distance: ", distance, "cm")