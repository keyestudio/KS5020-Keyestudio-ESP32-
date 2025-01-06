'''
 * Filename    : Cooling_Device
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

# 开启并配置ADC，量程为0-3.3V
adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)
conversion_factor = 5.0 / (4095)

# 电机的两个引脚
INA = Pin(16, Pin.OUT) # INA对应IN+
INB = Pin(17, Pin.OUT) # INB对应IN-

# OLED显示LM35检测到环境中的温度，当温度高于30℃时，开启电机.
while True:
    adcVal=adc.read()
    reading = adcVal * conversion_factor 
    temperature = reading * 102.4 
    temperature_string = str(temperature)
    oled.text('Cooling Device', 0, 0)
    oled.text('Temper(C):', 0, 20)
    oled.text(temperature_string, 0, 40) 
    oled.show()
    time.sleep(0.2)
    oled.fill(0) 
    if temperature > 30: # 当温度高于30℃时
        # 开启电机
        INA.value(0)
        INB.value(1)
    else: # 当温度不高于30℃时
        # 关闭电机
        INA.value(0)
        INB.value(0)