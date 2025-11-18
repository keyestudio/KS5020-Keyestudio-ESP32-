'''
 * Filename    : Temperature_Detector
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin, ADC, SoftI2C
import machine
import time
import math 
import ssd1306
from time import sleep

# Enable and configure ADC with a range of 0-3.3V
adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

# ESP32 Pin assignment 
i2c = SoftI2C(scl=Pin(22), sda=Pin(21))

# Set the width, height and i2c of the OLED
oled_width = 128
oled_height = 64
oled = ssd1306.SSD1306_I2C(oled_width, oled_height, i2c)

# OLED displays the voltage of the thermistor and the measured temperature value
try:
    while True: 
        adcValue = adc.read()
        voltage = adcValue / 4095 * 3.3
        Rt = 10 * voltage / (3.3-voltage)
        tempK = (1 / (1 / (273.15+25) + (math.log(Rt/10)) / 3950))
        tempC = int(tempK - 273.15)        
        voltage_string = str(voltage)
        tempC_string = str(tempC)
        oled.text('TemperatureMeter', 0, 0)
        oled.text('Volt:', 0, 25)
        oled.text(voltage_string, 40, 25)
        oled.text('V', 110, 25)
        oled.text('Temperature:', 0, 50)
        oled.text(tempC_string, 100, 50)
        oled.text('C', 120, 50) 
        oled.show()
        time.sleep(0.15)
        oled.fill(0)
except:
    pass