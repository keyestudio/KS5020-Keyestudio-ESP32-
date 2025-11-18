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

# Enable and configure ADC with a range of 0-3.3V
adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

# Configure i2c, pins, addresses, etc.
clock_pin = 22
data_pin = 21
bus = 0
i2c_addr = 0x3f
use_i2c = True

# DHT11 reads temperature and humidity values and the LCD reveals them
def scan_for_devices():
    i2c = machine.I2C(bus,sda=machine.Pin(data_pin),scl=machine.Pin(clock_pin))
    devices = i2c.scan()
    if devices:
        for d in devices: 
            print(hex(d))
    else:
        print('no i2c devices')
         
# The sound sensor detects the sound and reads the ADC value of the volume, and the LCD displays it.
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