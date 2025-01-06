'''
 * Filename    : Button
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin
import time 

button = Pin(14, Pin.IN, Pin.PULL_UP) # 定义按键的引脚，输入模式和输入上拉模式

while True: 
    if button.value() == 0: # 按下按键时，打印相应信息
        print("0  You pressed the button!")  
    else:  # 松开按键时，打印相应信息
        print("1  You loosen the button!")
    time.sleep(0.1)  # 延时0.1秒
