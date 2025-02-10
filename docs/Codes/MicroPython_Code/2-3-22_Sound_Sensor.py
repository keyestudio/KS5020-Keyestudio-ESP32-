'''
 * Filename    : Sound_Sensor
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# import Pin, ADC and DAC library
from machine import ADC,Pin,DAC
import time

# Enable and configure ADC with a range of 0-3.3V
adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT) 

# Read the ADC value every 0.1 seconds, and convert the ADC value to DAC value and voltage to output;
# show these values on “Shell”
try:
    while True:
        adcVal=adc.read()
        dacVal=adcVal//16
        voltage = adcVal / 4095.0 * 3.3
        print("ADC Val:",adcVal,"DACVal:",dacVal,"Voltage:",voltage,"V")
        time.sleep(0.1)
except:
    pass