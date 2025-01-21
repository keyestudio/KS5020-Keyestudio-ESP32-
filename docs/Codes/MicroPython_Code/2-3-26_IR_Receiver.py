'''
 * Filename    : IR_Receiver
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# import infrared decoder library.
from irrecvdata import irGetCMD 

# connect IR receiver to pin GPIO5
recvPin = irGetCMD(5)

# When the key values of the infrared remote control are obtained, print on the "Shell".
try:
    while True:
        irValue = recvPin.ir_read() # Call ir_read() to read key values to assign to irValue
        if irValue:
            print(irValue)
except: 
    pass