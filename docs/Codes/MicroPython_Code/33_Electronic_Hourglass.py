'''
 * Filename    : Electronic_Hourglass
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin 
import time

led1 = Pin(16, Pin.OUT) # 创建引脚16为LED对象，设置引脚16为输出模式
led2 = Pin(17, Pin.OUT) # 创建引脚17为LED对象，设置引脚17为输出模式
led3 = Pin(18, Pin.OUT) # 创建引脚18为LED对象，设置引脚18为输出模式
led4 = Pin(19, Pin.OUT) # 创建引脚19为LED对象，设置引脚19为输出模式
Tilt_Sensor = Pin(26,Pin.IN) # 创建引脚26为倾斜传感器对象，设置IO26为输入模式
 
while True:
    if(Tilt_Sensor.value() == 1) : # 如果倾斜传感器的值为1时
        led1.value(1) # led1 点亮
        time.sleep_ms(200) #延时
        led2.value(1) # led2 点亮
        time.sleep_ms(200) #延时
        led3.value(1) # led3 点亮
        time.sleep_ms(200) #延时
        led4.value(1) # led4 点亮
        time.sleep_ms(200) #延时
    else :  # 如果倾斜传感器的值为0时
        led4.value(0) # led4 熄灭
        time.sleep_ms(200) #延时
        led3.value(0) # led3 熄灭
        time.sleep_ms(200) #延时
        led2.value(0) # led2 熄灭
        time.sleep_ms(200) #延时
        led1.value(0) # led1 熄灭
        time.sleep_ms(200) #延时
