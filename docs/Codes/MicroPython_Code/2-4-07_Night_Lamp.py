'''
 * Filename    : Night_Lamp
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin,PWM,ADC
import time

# define the output frequency of IO12 as 1000Hz and assign it to PWM.
pwm =PWM(Pin(12,Pin.OUT),1000) 

# Enable and configure ADC with a range of 0-3.3V
adc=ADC(Pin(36))  
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_10BIT) 

# Read the ADC value every 0.1 seconds, and convert the ADC value to the pum value to output;
# show these values on “Shell”
try:
    while True:
        adcValue=adc.read()
        pwm.duty(adcValue)
        print(adcValue)
        time.sleep_ms(100)
except:
    pwm.deinit()