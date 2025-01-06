'''
 * Filename    : Magic_Color_Music_Box 
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin, ADC, PWM 
import machine 
import time  
from time import sleep 

# 7个led的数字引脚
led1 = Pin(13, Pin.OUT)
led2 = Pin(12, Pin.OUT)
led3 = Pin(14, Pin.OUT)
led4 = Pin(27, Pin.OUT)
led5 = Pin(16, Pin.OUT)
led6 = Pin(17, Pin.OUT) 
led7 = Pin(25, Pin.OUT)

# Define the GPIO pin that is connected to the buzzer
buzzer = machine.PWM(machine.Pin(18))

# 定义无源蜂鸣器发声的playtone函数
def playtone(frequency):
    buzzer.duty_u16(1000)
    buzzer.freq(frequency)

# 定义超声波测距模块的控制引脚
Trig = Pin(33, Pin.OUT, 0) 
Echo = Pin(32, Pin.IN, 0)

distance = 0 # 将初始距离定义为0
soundVelocity = 340 # Set the speed of sound.
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

# 让人隔空在超声波传感器前挥动手掌，超声波传感器检测距离，在不同的距离范围内，
# 无源蜂鸣器演奏不同音符，7个LED相互点亮.
while True:
    distance = getDistance()
    if distance > 0 and distance <= 5:
        led1.value(1)
        playtone(262)
        sleep(1)
    else:
        led1.value(0)
        buzzer.duty_u16(0)
        
    if distance > 5 and distance <= 10:
        led2.value(1)
        playtone(294)
        sleep(0.75)
    else:
        led2.value(0)
        buzzer.duty_u16(0)
    if distance > 10 and distance <= 15:
        led3.value(1)
        playtone(330)
        sleep(0.625)
    else:
        led3.value(0)
        buzzer.duty_u16(0)        
    if distance > 15 and distance <= 20:
        led4.value(1)
        playtone(349)
        sleep(0.5)
    else:
        led4.value(0)
        buzzer.duty_u16(0)
    if distance > 20 and distance <= 25:
        led5.value(1)
        playtone(392)
        sleep(0.375)
    else:
        led5.value(0)
        buzzer.duty_u16(0)        
    if distance > 25 and distance <= 30:
        led6.value(1)
        playtone(440)
        sleep(0.25)
    else:
        led6.value(0)
        buzzer.duty_u16(0)
    if distance > 35 and distance <= 40:
        led7.value(1)
        playtone(494)
        sleep(0.125)
    else:
        led7.value(0)
        buzzer.duty_u16(0)