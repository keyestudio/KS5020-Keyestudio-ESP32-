'''
 * Filename    : Joystick
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin, ADC
import time 

# initialize joystick module (ADC function)
rocker_x=ADC(Pin(36)) 
rocker_y=ADC(Pin(39))
button_z=Pin(26,Pin.IN,Pin.PULL_UP)

# Set the voltage acquisition range of the two ADC channels to 0-3.3V
# Set the data acquisition width to 0-4095.
rocker_x.atten(ADC.ATTN_11DB)
rocker_y.atten(ADC.ATTN_11DB)
rocker_x.width(ADC.WIDTH_12BIT)
rocker_y.width(ADC.WIDTH_12BIT)
 
# In the code, configure the Z_Pin to pull-up input mode.
# In while True, read values of X and Y-axis by Read() and the values of z-axis by value(), and display them.
while True:
    print("X,Y,Z:",rocker_x.read(),",",rocker_y.read(),",",button_z.value())
    time.sleep(0.5)