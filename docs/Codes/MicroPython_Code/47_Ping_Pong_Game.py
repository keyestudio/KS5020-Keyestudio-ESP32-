'''
 * Filename    : Ping Pong Game
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# Import Pin,SoftI2C,ssd1306,sleep,gfx libraries
from machine import Pin, SoftI2C
import ssd1306
from time import sleep

up_button = Pin(14, Pin.IN, Pin.PULL_UP) # Up_Button
down_button = Pin(25, Pin.IN, Pin.PULL_UP) # Down_Button

# ESP32 Pin assignment 
i2c = SoftI2C(scl=Pin(22), sda=Pin(21))

# Set the width, height and i2c of the OLED
oled_width = 128
oled_height = 64 
oled = ssd1306.SSD1306_I2C(oled_width, oled_height, i2c)

# 读取两个按键值，并且操作两个按键，OLED显示对应的信息.
while True:
    upbutton = up_button.value()
    downbutton = down_button.value()
    upbutton_string = str(upbutton)
    downbutton_string = str(downbutton)

    if upbutton == 0: # 按下up_button按键时
        oled.text('Ping Pong Game', 0, 0)
        oled.text('up_button:', 0, 25)
        oled.text(upbutton_string, 80, 25)
        oled.show()
    else:  # 松开按键时
        oled.fill(0)
    if downbutton == 0: # 按下down_button按键时
        oled.text('Ping Pong Game', 0, 0)
        oled.text('down_button:', 0, 25)
        oled.text(downbutton_string, 100, 25)
        oled.show()
    else:  # 松开down_button按键时
        oled.fill(0)