'''
 * Filename    : Ultrasonic
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin 
import time

# 定义超声波测距模块的控制引脚
Trig = Pin(13, Pin.OUT, 0) 
Echo = Pin(12, Pin.IN, 0)

distance = 0 # 将初始距离定义为0
soundVelocity = 340 #Set the speed of sound.

# getDistance()函数用于驱动超声波模块测量距离，
# Trig保持高电平10us以启动超声波模块
# Echo.value()用于读取超声波模块Echo引脚的状态，
# 然后使用时间模块的time.sleep_us()函数计算Echo的持续时间,
# Trig引脚的高电平，根据时间计算测量距离并返回值。
def getDistance():
    Trig.value(1)
    time.sleep_us(10)
    Trig.value(0)
    while not Echo.value():
        pass
    pingStart = time.ticks_us()
    while Echo.value():
        pass
    pingStop = time.ticks_us()
    pingTime = time.ticks_diff(pingStop, pingStart) // 2
    distance = int(soundVelocity * pingTime // 10000)
    return distance

# 延时2秒，等待超声波模块稳定
# 打印每500毫秒从超声波模块获得的数据
time.sleep(2)
while True:
    time.sleep_ms(500)
    distance = getDistance()
    print("Distance: ", distance, "cm")