'''
 * Filename    : Thermistor
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin, ADC
import time
import math

# 开启并配置ADC，量程为0-3.3V
adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

# 每0.5秒读取一次ADC值，将ADC值转换为电压值和温度值输出
# 并将这些数据打印到“Shell”
try: 
    while True:  
        adcValue = adc.read()  # 读IO36引脚的adc值
        voltage = adcValue / 4095 * 3.3  # 转换成电压值
        Rt =(3.3-voltage) / voltage * 10000  # 计算NTC热敏电阻
        tempK = (1 / (1 / (273.15+25) + (math.log(Rt/10000)) / 3950))  # 计算华氏温度
        tempC = (tempK - 273.15)+0.5  # 计算摄氏温度
        print("ADC value:",adcValue,"  Voltage:",voltage,"V","  Temperature: ",tempC,"C");
        time.sleep(0.5)
except:
    pass