'''
 * Filename    : IR_Receiver
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# 导入红外解码器的库.
from irrecvdata import irGetCMD 

# 将红外接收器与GPIO5关联.
recvPin = irGetCMD(5)

# 当获得红外遥控的键值时，在“Shell”中打印出来. 
try:
    while True:
        irValue = recvPin.ir_read() # 调用ir_read()来读取遥控器上按键的值并将其赋值给irValue.
        if irValue:
            print(irValue)
except: 
    pass