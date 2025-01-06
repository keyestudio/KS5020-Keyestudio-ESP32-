'''
 * Filename    : Astern_Detector 
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin, ADC, PWM, SoftI2C
import machine 
import time  
import ssd1306
from time import sleep

# ESP32 Pin assignment 
i2c = SoftI2C(scl=Pin(22), sda=Pin(21))

# Set the width, height and i2c of the OLED
oled_width = 128
oled_height = 64
oled = ssd1306.SSD1306_I2C(oled_width, oled_height, i2c)

# Define the GPIO pin that is connected to the buzzer
buzzer = machine.PWM(machine.Pin(26))

# 定义无源蜂鸣器发声的playtone函数
def playtone(frequency):
    buzzer.duty_u16(1000)
    buzzer.freq(frequency)

# 定义超声波测距模块的控制引脚
Trig = Pin(18, Pin.OUT, 0) 
Echo = Pin(19, Pin.IN, 0)

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

# OLED显示超声波传感器检测的距离值，在不同的距离范围内，蜂鸣器发出不同的声音.
while True:
    distance = getDistance()
    distance_string = str(distance)
    oled.text('Astern Detector', 0, 0)
    oled.text('Distance(cm):', 0, 25)
    oled.text(distance_string, 0, 50) 
    oled.show()
    time.sleep(0.15)
    oled.fill(0)
    if distance <= 10:
        playtone(880)
        sleep(0.1)
    elif distance > 10 and distance <= 20:
        playtone(332)
        sleep(0.2)
    else:
        buzzer.duty_u16(0)      