'''
 * Filename    : LM35
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import ADC, Pin 
import time

# 开启并配置ADC，量程为0-5.0V
adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)
conversion_factor = 5.0 / (4095) 

# 每0.5秒读取一次ADC值，将ADC值转换为温度值输出;
# 并将这些数据打印到“Shell”
while True:
    adcVal=adc.read()
    reading = adcVal * conversion_factor 
    temperature = reading * 102.4 
    print(temperature)
    time.sleep(0.5)