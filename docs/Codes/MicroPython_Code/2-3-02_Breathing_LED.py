'''
 * Filename    : Breathing_LED 
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# import Pin, PWM and time
import time 
from machine import Pin,PWM

# ESP32 PWM pin output mode is different from the traditional controller.
# It can change the frequency and duty cycle by configuring the parameters of PWM during the initialization phase.
# set GPIO26 output frequency to 10000Hz, assign it to PWM.

pwm =PWM(Pin(26,Pin.OUT),10000)

try:
    while True:
# the duty cyclr ranges from 0-1023.
# Therefore, we use the first for loop to control the PWM and change the duty cycle to make the PWM output 0-100%;
# and use the second for loop to make PWM output 100%-0%.
        for i in range(0,1023): 
            pwm.duty(i)
            time.sleep_ms(1)
            
        for i in range(0,1023):
            pwm.duty(1023-i)
            time.sleep_ms(1)  
except:
# Each time PWM is used, the hardware timer will turn on to match it.
# Therefore, after each use of PWM, deinit() needs to be called to turn off the timer. Otherwise, the next time PWM may not work.
    pwm.deinit()