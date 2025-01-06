'''
 * Filename    : PIR_Motion
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin
import time

PIR = Pin(14, Pin.IN)  # 定义人体红外传感器的引脚，输入模式
 
while True:
    value = PIR.value()  # 将人体红外传感器读取的值赋给与变量value
    print(value, end = " ")  # 打印人体红外传感器读取的值
    if value == 1:  # 人体红外传感器检测的移动时，串口打印相关信息
        print("Some body is in this area!")
    else:  # 人体红外传感器未检测的移动时，串口打印相关信息
        print("No one!")
    time.sleep(0.1)