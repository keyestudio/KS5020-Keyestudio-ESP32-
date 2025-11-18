'''
 * Filename    : Magic_Color_Music_Box 
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin, ADC, PWM 
import machine 
import time  
from time import sleep 

# Digital pins for 7 leds
led1 = Pin(13, Pin.OUT)
led2 = Pin(12, Pin.OUT)
led3 = Pin(14, Pin.OUT)
led4 = Pin(27, Pin.OUT)
led5 = Pin(16, Pin.OUT)
led6 = Pin(17, Pin.OUT) 
led7 = Pin(25, Pin.OUT)

# Define the GPIO pin that is connected to the buzzer
buzzer = machine.PWM(machine.Pin(18))

# Define the playtone function for the sound of the passive buzzer
def playtone(frequency):
    buzzer.duty_u16(1000)
    buzzer.freq(frequency)

# Define the control pins of the ultrasonic ranging module
Trig = Pin(33, Pin.OUT, 0) 
Echo = Pin(32, Pin.IN, 0)

distance = 0 # set initial distance value to 0
soundVelocity = 340 # Set the speed of sound.
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

# Wave your hand in front of an ultrasonic sensor to detect distance,
# At different distance ranges, the passive buzzer plays different notes and corresponding LED lights up.
while True:
    distance = getDistance()
    if distance > 0 and distance <= 5:
        led1.value(1)
        playtone(262)
        sleep(1)
    else:
        led1.value(0)
        buzzer.duty_u16(0)
        
    if distance > 5 and distance <= 10:
        led2.value(1)
        playtone(294)
        sleep(0.75)
    else:
        led2.value(0)
        buzzer.duty_u16(0)
    if distance > 10 and distance <= 15:
        led3.value(1)
        playtone(330)
        sleep(0.625)
    else:
        led3.value(0)
        buzzer.duty_u16(0)        
    if distance > 15 and distance <= 20:
        led4.value(1)
        playtone(349)
        sleep(0.5)
    else:
        led4.value(0)
        buzzer.duty_u16(0)
    if distance > 20 and distance <= 25:
        led5.value(1)
        playtone(392)
        sleep(0.375)
    else:
        led5.value(0)
        buzzer.duty_u16(0)        
    if distance > 25 and distance <= 30:
        led6.value(1)
        playtone(440)
        sleep(0.25)
    else:
        led6.value(0)
        buzzer.duty_u16(0)
    if distance > 35 and distance <= 40:
        led7.value(1)
        playtone(494)
        sleep(0.125)
    else:
        led7.value(0)
        buzzer.duty_u16(0)