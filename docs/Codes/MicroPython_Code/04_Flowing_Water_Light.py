'''
 * Filename    : Flowing_Water_Light
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
''' 
from machine import Pin
import time

# 使用阵列定义5个连接LED的IO端口，便于操作.
pins = [18, 5, 14, 17, 26]
# 使用两个for循环分别从左到右打开led，然后从右到左打开led
def showLed():
    for pin in pins:
        print(pin)
        led = Pin(pin, Pin.OUT)
        led.value(1)
        time.sleep_ms(100)
        led.value(0)
        time.sleep_ms(100)        
    for pin in reversed(pins):
        print(pin)
        led = Pin(pin, Pin.OUT)
        led.value(1)
        time.sleep_ms(100)
        led.value(0)
        time.sleep_ms(100)
          
while True:
    showLed()