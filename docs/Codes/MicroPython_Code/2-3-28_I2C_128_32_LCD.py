'''
 * Filename    : I2C_128_32_LCD
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# import machine, time, lcd128_32_fonts, lcd128_32 library
import machine
import time
import lcd128_32_fonts
from lcd128_32 import lcd128_32

# configure i2c, pins and addresses, etc.
clock_pin = 22
data_pin = 21
bus = 0
i2c_addr = 0x3f
use_i2c = True

def scan_for_devices():
    i2c = machine.I2C(bus,sda=machine.Pin(data_pin),scl=machine.Pin(clock_pin))
    devices = i2c.scan()
    if devices:
        for d in devices:
            print(hex(d))
    else:
        print('no i2c devices')

if use_i2c:
    scan_for_devices()
    lcd = lcd128_32(data_pin, clock_pin, bus, i2c_addr)


lcd.Clear()

lcd.Cursor(0, 4)
lcd.Display("KEYESTUDIO")
lcd.Cursor(1, 0)
lcd.Display("ABCDEFGHIJKLMNOPQR")
lcd.Cursor(2, 0)
lcd.Display("123456789+-*/<>=$@")
lcd.Cursor(3, 0)
lcd.Display("%^&(){}:;'|?,.~\\[]")
'''
while True:
    # scan_for_devices()
    time.sleep(0.5)
'''
