'''
 * Filename    : Home_Appliances
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin
import time

relay = Pin(12, Pin.OUT) # 创建引脚12为relay对象，设置引脚12为输出模式                  
button = Pin(26, Pin.IN, Pin.PULL_UP) #创建引脚26为button对象，设置引脚26为输入上拉模式

#定义一个函数并将其命名为reverseGPIO()，用于反转继电器输出电平
def reverseGPIO():
    if relay.value():
        relay.value(0)     #LED熄灭
    else:
        relay.value(1)     #LED点亮

try:
    while True:
        if not button.value():
            time.sleep_ms(20)
            if not button.value():
                reverseGPIO()
                while not button.value():
                    time.sleep_ms(20)
except:
    pass
