'''
 * Filename    : Corridor_Induction_Lamp
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin, ADC
import time
 
# 人体红外传感器引脚
human = Pin(12, Pin.IN)
 
# 初始化光敏电阻引脚到GP36 (ADC函数)
adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

# 创建引脚25为LED对象，设置引脚25为输出模式 
led = Pin(25, Pin.OUT)

def detect_someone(): # 创建人体红外传感器检测到有人移动的函数
    if human.value() == 1:
        return True
    return False
 
abc = 0
 
while True:
    adcVal=adc.read() # 读取光敏电阻的ADC值
    if adcVal > 3500: # 当光敏电阻的ADC值大于3500时
        if detect_someone() == True: # 当人体红外传感器检测到有人移动时
            abc += 1 # adc值加1
            led.value(1) # LED点亮
            print("value=", abc)
            time.sleep(1)
        else:
            if abc != 0:
                abc = 0
                led.value(0)
    else:
        led.value(0)
 
    time.sleep(0.1)