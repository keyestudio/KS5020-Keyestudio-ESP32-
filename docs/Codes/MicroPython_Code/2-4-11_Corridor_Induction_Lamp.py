'''
 * Filename    : Corridor_Induction_Lamp
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin, ADC
import time
 
# PIR motion sensor pin
human = Pin(12, Pin.IN)
 
# set photoresistor pin to GP36 (ADC function)
adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

# set LED to pin 25 and set it to output 
led = Pin(25, Pin.OUT)

def detect_someone(): # the function of "if PIR motion sensor detects a motion"
    if human.value() == 1:
        return True
    return False
 
abc = 0
 
while True:
    adcVal=adc.read() # read the ADC value of the photoresistor
    if adcVal > 3500: # when the ADC value of the photoresistor is greater than 3500
        if detect_someone() == True: # if PIR motion sensor detects a motion
            abc += 1 # adc adds 1
            led.value(1) # LED on
            print("value=", abc)
            time.sleep(1)
        else:
            if abc != 0:
                abc = 0
                led.value(0)
    else:
        led.value(0)
 
    time.sleep(0.1)