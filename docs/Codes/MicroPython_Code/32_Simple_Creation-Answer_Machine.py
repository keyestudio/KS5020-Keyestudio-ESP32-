'''
 * Filename    : Simple_Creation-Answer_Machine
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com 
'''
from machine import Pin, PWM 
import machine
from time import sleep

led_R = Pin(16, Pin.OUT) # 创建引脚16为LED对象，设置引脚16为输出模式
led_R.value(0) 
led_G = Pin(17, Pin.OUT) # 创建引脚17为LED对象，设置引脚17为输出模式
led_G.value(0) 
led_B = Pin(25, Pin.OUT) # 创建引脚25为LED对象，设置引脚25为输出模式
led_B.value(0) 

# Define the GPIO pin that is connected to the buzzer
buzzer = machine.PWM(machine.Pin(19))
buzzer.duty_u16(0)

# 定义无源蜂鸣器发声的playtone函数
def playtone(frequency):
    buzzer.duty_u16(10000)
    buzzer.freq(frequency)
    
button1 = Pin(5, Pin.IN, Pin.PULL_UP) # 创建引脚5为按键对象,设置IO5为输入模式
flag = 0
Key = 0

def fun(button1):
    global flag
    if flag == 0:
      led_R.value(0)
      led_G.value(1)
      led_B.value(1)
      playtone(392)
      sleep(0.375)
    elif flag == 1:
      led_R.value(1)
      led_G.value(0)
      led_B.value(1)
      playtone(440)
      sleep(0.25)
    elif flag == 2:
      led_R.value(1)
      led_G.value(1)
      led_B.value(0)
      playtone(494) 
      sleep(0.125)
    elif flag == 3:
      led_R.value(0)
      led_G.value(0)
      led_B.value(1)
      playtone(349)
      sleep(0.5)
    elif flag == 4:
      led_R.value(1)
      led_G.value(0)
      led_B.value(0)
      playtone(330)
      sleep(0.625)
    elif flag == 5:
      led_R.value(0)
      led_G.value(1)
      led_B.value(0)
      playtone(294)
      sleep(0.75)
    elif flag == 6:
      led_R.value(1)
      led_G.value(1)
      led_B.value(1)
      playtone(262)
      sleep(1)
    else:
      led_R.value(0)
      led_G.value(0)
      led_B.value(0)
      buzzer.duty_u16(0)
    if flag < 7:
      flag = flag + 1
    else:
      flag = 0
button1.irq(fun,Pin.IRQ_FALLING)
