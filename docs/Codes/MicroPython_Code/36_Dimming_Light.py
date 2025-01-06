'''
 * Filename    : Dimming_Light
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin,PWM,ADC  
import time 

# 定义IO12的输出频率为1000Hz，并将其分配给PWM.
pwm =PWM(Pin(12,Pin.OUT),1000)

# 开启并配置ADC，量程为0-3.3V
adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_10BIT)

# 每0.1秒读取一次ADC值，将ADC值转换为pwm值输出;
# 并将ADC值打印到“Shell”
try:
    while True:
        adcValue=adc.read()
        pwm.duty(adcValue)
        print(adc.read())
        time.sleep_ms(100)
except:
    pwm.deinit()