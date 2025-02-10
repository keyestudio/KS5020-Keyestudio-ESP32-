'''
 * Filename    : Astern_Detector 
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin, ADC, PWM, SoftI2C
import machine 
import time  
import ssd1306
from time import sleep

# ESP32 Pin assignment 
i2c = SoftI2C(scl=Pin(22), sda=Pin(21))

# Set the width, height and i2c of the OLED
oled_width = 128
oled_height = 64
oled = ssd1306.SSD1306_I2C(oled_width, oled_height, i2c)

# Define the GPIO pin that is connected to the buzzer
buzzer = machine.PWM(machine.Pin(26))

# Define the playtone function for the sound of the passive buzzer
def playtone(frequency):
    buzzer.duty_u16(1000)
    buzzer.freq(frequency)

# set the ultrasonic sensor pins
Trig = Pin(18, Pin.OUT, 0) 
Echo = Pin(19, Pin.IN, 0)

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

# OLED displays the distance value detected by the ultrasonic sensor. At different distances, buzzers make different sounds.
while True:
    distance = getDistance()
    distance_string = str(distance)
    oled.text('Astern Detector', 0, 0)
    oled.text('Distance(cm):', 0, 25)
    oled.text(distance_string, 0, 50) 
    oled.show()
    time.sleep(0.15)
    oled.fill(0)
    if distance <= 10:
        playtone(880)
        sleep(0.1)
    elif distance > 10 and distance <= 20:
        playtone(332)
        sleep(0.2)
    else:
        buzzer.duty_u16(0)      