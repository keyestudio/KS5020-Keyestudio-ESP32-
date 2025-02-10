'''
 * Filename    : Fire-fighting_robot
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# import pin and ADC module
from machine import ADC,Pin
import time

# Enable and configure ADC with a range of 0-3.3V
adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

# connect LED to pin 25 and set it to output
led = Pin(25, Pin.OUT)   

# motor pins
INA = Pin(13, Pin.OUT) # INA to IN+
INB = Pin(12, Pin.OUT) # INB to IN-

while True:
    adcVal=adc.read()  # read the ADC value of the flame sensor
    print(adcVal)  # show ADC value on “Shell”
    if adcVal > 2000:  # when the ADC value of the flame sensor is greater than 2000
        # turn on the motor
        INA.value(0)
        INB.value(1)
        # LED flashes
        led.value(1)   
        time.sleep(0.5)  
        led.value(0)   
        time.sleep(0.5)  
    else: # when the ADC value of the flame sensor is less than or equal to 2000
        # turn off the motor and LED
        INA.value(0)
        INB.value(0)
        led.value(0)
    time.sleep(0.1)