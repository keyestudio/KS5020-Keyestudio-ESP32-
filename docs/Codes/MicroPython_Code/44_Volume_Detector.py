'''
 * Filename    : Volume_Detector
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin, ADC
import machine
import time
import lcd128_32_fonts
from lcd128_32 import lcd128_32

# 开启并配置ADC，量程为0-3.3V
adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

# i2c配置引脚,地址和其他
clock_pin = 22
data_pin = 21
bus = 0
i2c_addr = 0x3f
use_i2c = True

# DHT11读取温湿度,LCD显示温湿度.
def scan_for_devices():
    i2c = machine.I2C(bus,sda=machine.Pin(data_pin),scl=machine.Pin(clock_pin))
    devices = i2c.scan()
    if devices:
        for d in devices: 
            print(hex(d))
    else:
        print('no i2c devices')
         
# 声音传感器检测声音并且读取音量ADC值,LCD显示ADC值.
try:
    while True:
        adcVal=adc.read()
        if use_i2c:
            scan_for_devices()
            lcd = lcd128_32(data_pin, clock_pin, bus, i2c_addr)         
        lcd.Cursor(0, 2)
        lcd.Display("Volume Detector")
        lcd.Cursor(2, 4)
        lcd.Display("Volume:")
        lcd.Cursor(2, 12)
        lcd.Display(str(adcVal))
        time.sleep(0.5)
except:
    pass