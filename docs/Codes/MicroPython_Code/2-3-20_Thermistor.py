'''
 * Filename    : Thermistor
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin, ADC
import time
import math

# Enable and configure ADC with a range of 0-3.3V
adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

# Read the ADC value every 0.5 seconds, and convert the ADC value to voltage and temperature value to output;
# show these values on “Shell”
try: 
    while True:  
        adcValue = adc.read()  # read pin IO36 adc value
        voltage = adcValue / 4095 * 3.3  # convert to voltage value
        Rt =(3.3-voltage) / voltage * 10000  # calculate NTC thermistor risistance
        tempK = (1 / (1 / (273.15+25) + (math.log(Rt/10000)) / 3950))  # calculate the temperature in Fahrenheit
        tempC = (tempK - 273.15)+0.5  # calculate the temperature in Celsius
        print("ADC value:",adcValue,"  Voltage:",voltage,"V","  Temperature: ",tempC,"C");
        time.sleep(0.5)
except:
    pass