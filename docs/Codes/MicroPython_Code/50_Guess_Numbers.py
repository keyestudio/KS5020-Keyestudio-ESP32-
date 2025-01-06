'''
 * Filename    : Guess_Numbers
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# 导入irGetCMD,Pin的库.
from irrecvdata import irGetCMD
from machine import Pin

# 将红外接收器与GPIO18关联.
recvPin = irGetCMD(18)
 
# 配置七段数码管引脚（这里以共阴极为例）
a = Pin(16, Pin.OUT)
b = Pin(17, Pin.OUT)
c = Pin(14, Pin.OUT)
d = Pin(12, Pin.OUT)
e = Pin(13, Pin.OUT)
f = Pin(5, Pin.OUT) 
g = Pin(23, Pin.OUT)
dp = Pin(27, Pin.OUT)

# 定义LED灯引脚连接到IO26
led = Pin(26, Pin.OUT)

flag = 1          
 
try:
    while True:
         irValue = recvPin.ir_read() # 调用ir_read()来读取按键的值并将其赋值给irValue.
         if irValue:
            print(irValue)
            if irValue == '0xff02fd' and flag == 1: # 按下遥控器的“OK”键并且接收数字“OK”
              led.value(1)   
              flag = 0 
            elif irValue == '0xff02fd' and flag == 0: # 按下遥控器的“OK”键并且接收数字“OK”
              led.value(0)   
              flag = 1            
            elif irValue == '0xff6897': # 按下遥控器的“1”键
                a.value(0)   # 显示数字1
                b.value(1)
                c.value(1)
                d.value(0)
                e.value(0)
                f.value(0)
                g.value(0)
                dp.value(0)  
            elif irValue == '0xff9867': # 按下遥控器的“2”键
                a.value(1)  # 显示数字2 
                b.value(1)
                c.value(0)
                d.value(1)
                e.value(1)
                f.value(0)
                g.value(1)
                dp.value(0) 
            elif irValue == '0xffb04f': # 按下遥控器的“3”键
                a.value(1) # 显示数字3  
                b.value(1)
                c.value(1)
                d.value(1)
                e.value(0)
                f.value(0)
                g.value(1)
                dp.value(0) 
            elif irValue == '0xff30cf': # 按下遥控器的“4”键
                a.value(0)  # 显示数字4 
                b.value(1)
                c.value(1)
                d.value(0)
                e.value(0)
                f.value(1)
                g.value(1)
                dp.value(0) 
            elif irValue == '0xff18e7': # 按下遥控器的“5”键
                a.value(1)  # 显示数字5 
                b.value(0)
                c.value(1)
                d.value(1)
                e.value(0)
                f.value(1)
                g.value(1)
                dp.value(0) 
            elif irValue == '0xff7a85': # 按下遥控器的“6”键
                a.value(1)  # 显示数字6 
                b.value(0)
                c.value(1)
                d.value(1)
                e.value(1)
                f.value(1)
                g.value(1)
                dp.value(0) 
            elif irValue == '0xff10ef': # 按下遥控器的“7”键            
                a.value(1) # 显示数字7  
                b.value(1)
                c.value(1)
                d.value(0)
                e.value(0)
                f.value(0)
                g.value(0)
                dp.value(0)    
            elif irValue == '0xff38c7': # 按下遥控器的“8”键
                a.value(1)  # 显示数字8 
                b.value(1)
                c.value(1)
                d.value(1)
                e.value(1)
                f.value(1)
                g.value(1)
                dp.value(0) 
            elif irValue == '0xff5aa5': # 按下遥控器的“9”键
                a.value(1)  # 显示数字9 
                b.value(1)
                c.value(1)
                d.value(1)
                e.value(0) 
                f.value(1)
                g.value(1)
                dp.value(0) 
            elif irValue == '0xff4ab5': # 按下遥控器的“0”键
                a.value(1) # 显示数字0  
                b.value(1)
                c.value(1)
                d.value(1) 
                e.value(1)
                f.value(1)
                g.value(0)
                dp.value(0) 
            elif irValue == '0xff42bd': # 按下遥控器的“*”键
                a.value(0)  # 不显示 
                b.value(0)
                c.value(0)
                d.value(0)
                e.value(0)
                f.value(0)
                g.value(0)
                dp.value(0)
except:
    pass