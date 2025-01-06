'''
 * Filename    : Hello_LED 
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# 导入 Pin 和 time 库
from machine import Pin
import time

led = Pin(26, Pin.OUT)   # 创建引脚26为LED对象，设置引脚26为输出

try:
    while True:
        led.value(1)   # LED点亮
        time.sleep(1)  # 延时 1s
        led.value(0)   # LED熄灭
        time.sleep(1)  # 延时 1s
except:
    pass