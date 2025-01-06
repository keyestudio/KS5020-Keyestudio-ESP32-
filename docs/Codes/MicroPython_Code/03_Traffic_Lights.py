'''
 * Filename    : Traffic_Lights
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin 
import time

led_red = Pin(13, Pin.OUT)  # 创建引脚13为红色led对象，设置引脚13为输出模式
led_yellow = Pin(14, Pin.OUT)  # 创建引脚14为黄色led对象，设置引脚14为输出模式
led_green = Pin(16, Pin.OUT) # 创建引脚16为绿色led对象，设置引脚16为输出模式
 
while True:
    led_red.value(1)  # 红色LED点亮
    time.sleep(5)   # 延时 5s
    led_red.value(0) # 红色LED熄灭
    led_yellow.value(1)
    time.sleep(0.5)
    led_yellow.value(0)
    time.sleep(0.5)
    led_yellow.value(1)
    time.sleep(0.5)
    led_yellow.value(0)
    time.sleep(0.5)
    led_yellow.value(1)
    time.sleep(0.5)
    led_yellow.value(0)
    time.sleep(0.5)
    led_green.value(1)
    time.sleep(5) 
    led_green.value(0) 