'''
 * Filename    : LM35
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import ADC, Pin 
import time

# Enable and configure ADC with a range of 0-5.0V
adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)
conversion_factor = 5.0 / (4095) 

# Read the ADC value every 0.5 seconds, and convert the ADC value to temperature value to output;
# show these values on “Shell”
while True:
    adcVal=adc.read()
    reading = adcVal * conversion_factor 
    temperature = reading * 102.4 
    print(temperature)
    time.sleep(0.5)