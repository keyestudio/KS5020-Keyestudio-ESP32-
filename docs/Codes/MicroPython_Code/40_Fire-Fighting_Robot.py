'''
 * Filename    : Fire-fighting_robot
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# 导入引脚和ADC模块
from machine import ADC,Pin
import time

# 开启并配置ADC，量程为0-3.3V 
adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

# 创建引脚25为LED对象，设置引脚25为输出模式
led = Pin(25, Pin.OUT)   

# 电机的两个引脚
INA = Pin(13, Pin.OUT) # INA对应IN+
INB = Pin(12, Pin.OUT) # INB对应IN-

while True:
    adcVal=adc.read()  # 读取火焰传感器的ADC值
    print(adcVal)  # 将ADC值打印到“Shell”
    if adcVal > 2000:  # 当火焰传感器的ADC值大于2000时
        # 开启电机
        INA.value(0)
        INB.value(1)
        # LED闪烁
        led.value(1)   
        time.sleep(0.5)  
        led.value(0)   
        time.sleep(0.5)  
    else: # 当火焰传感器的ADC值小于等于2000时
        # 关闭电机和LED
        INA.value(0)
        INB.value(0)
        led.value(0)
    time.sleep(0.1)