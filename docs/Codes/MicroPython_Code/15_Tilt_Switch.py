'''
 * Filename    : Tilt_Switch
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin
import time

TiltSensor = Pin(14, Pin.IN) # 定义倾斜开关的引脚，输入模式

while True:
    value = TiltSensor.value()  # 将倾斜开关读取的值赋给与变量value
    print(value, end = " ")  # 打印倾斜开关读取的值
    if  value== 1: # 倾斜开关倾斜时，串口打印相关信息
        print("The switch is turned on")
    else:  # 倾斜开关未倾斜时，串口打印相关信息
        print("The switch is turned off")
    time.sleep(0.1)