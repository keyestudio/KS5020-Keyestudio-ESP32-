'''
 * Filename    : Joystick_Display 
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com 
'''
from machine import Pin, ADC, SoftI2C
import machine  
import time  
import ssd1306
from time import sleep

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

# ESP32 Pin assignment 
i2c = SoftI2C(scl=Pin(22), sda=Pin(21))

# Set the width, height and i2c of the OLED
oled_width = 128
oled_height = 64
oled = ssd1306.SSD1306_I2C(oled_width, oled_height, i2c)

while True:
    # read the values of axes X, Y, Z of the joystick
    xValue = rocker_x.read()
    yValue = rocker_y.read()
    zValue = button_z.value()
    xValue_string = str(xValue)
    yValue_string = str(yValue)
    zValue_string = str(zValue)

    # show the values of axes X, Y, Z
    oled.text('X: ', 0, 0)
    oled.text(xValue_string, 20, 0)
    oled.text('Y: ', 0, 10)
    oled.text(yValue_string, 20, 10)
    oled.text('Z: ', 0, 20)
    oled.text(zValue_string, 20, 20)
    oled.show()
    time.sleep(0.15)
    oled.fill(0)
    
    # Determine the orientation of the joystick based on the values of the X and Y axes
    if yValue < 1000:
       oled.text('Direction:Down', 0, 35)
       oled.show()
    elif yValue > 3000:
       oled.text('Direction:Up', 0, 35)
       oled.show()
    elif xValue < 1000:
       oled.text('Direction:Left', 0, 35)
       oled.show()
    elif xValue > 3000:
       oled.text('Direction:Right', 0, 35)
       oled.show()
    else:
       oled.text('Direction:Center', 0, 35)
       oled.show()
    
    # show button(z axis) state
    if zValue == 1:
       oled.text('Button:Pressed', 0, 50)
       oled.show()
    else:
       oled.text('Button:Released', 0, 50)
       oled.show()