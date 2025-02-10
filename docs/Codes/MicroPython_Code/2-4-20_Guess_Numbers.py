'''
 * Filename    : Guess_Numbers
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# import irGetCMD, Pin library
from irrecvdata import irGetCMD
from machine import Pin

# connect IR receiver to pin GPIO18
recvPin = irGetCMD(18)
 
# Set the pins of the digital tube (here is common cathode)
a = Pin(16, Pin.OUT)
b = Pin(17, Pin.OUT)
c = Pin(14, Pin.OUT)
d = Pin(12, Pin.OUT)
e = Pin(13, Pin.OUT)
f = Pin(5, Pin.OUT) 
g = Pin(23, Pin.OUT)
dp = Pin(27, Pin.OUT)

# connect LED to pin IO26
led = Pin(26, Pin.OUT)

flag = 1          
 
try:
    while True:
         irValue = recvPin.ir_read() # Call ir_read() to read key values to assign to irValue.
         if irValue:
            print(irValue)
            if irValue == '0xff02fd' and flag == 1: # press the key “OK” on the remote control, and receive “OK”
              led.value(1)   
              flag = 0 
            elif irValue == '0xff02fd' and flag == 0: # press the key “OK” on the remote control, and receive “OK”
              led.value(0)   
              flag = 1            
            elif irValue == '0xff6897': # press the key “1” on the remote control
                a.value(0)   # show number 1
                b.value(1)
                c.value(1)
                d.value(0)
                e.value(0)
                f.value(0)
                g.value(0)
                dp.value(0)  
            elif irValue == '0xff9867': # press the key “2” on the remote control
                a.value(1)  # show number 2 
                b.value(1)
                c.value(0)
                d.value(1)
                e.value(1)
                f.value(0)
                g.value(1)
                dp.value(0) 
            elif irValue == '0xffb04f': # press the key “3” on the remote control
                a.value(1) # show number 3  
                b.value(1)
                c.value(1)
                d.value(1)
                e.value(0)
                f.value(0)
                g.value(1)
                dp.value(0) 
            elif irValue == '0xff30cf': # press the key “4” on the remote control
                a.value(0)  # show number 4 
                b.value(1)
                c.value(1)
                d.value(0)
                e.value(0)
                f.value(1)
                g.value(1)
                dp.value(0) 
            elif irValue == '0xff18e7': # press the key “5” on the remote control
                a.value(1)  # show number 5 
                b.value(0)
                c.value(1)
                d.value(1)
                e.value(0)
                f.value(1)
                g.value(1)
                dp.value(0) 
            elif irValue == '0xff7a85': # press the key “6” on the remote control
                a.value(1)  # show number 6 
                b.value(0)
                c.value(1)
                d.value(1)
                e.value(1)
                f.value(1)
                g.value(1)
                dp.value(0) 
            elif irValue == '0xff10ef': # press the key “7” on the remote control            
                a.value(1) # show number 7  
                b.value(1)
                c.value(1)
                d.value(0)
                e.value(0)
                f.value(0)
                g.value(0)
                dp.value(0)    
            elif irValue == '0xff38c7': # press the key “8” on the remote control
                a.value(1)  # show number 8 
                b.value(1)
                c.value(1)
                d.value(1)
                e.value(1)
                f.value(1)
                g.value(1)
                dp.value(0) 
            elif irValue == '0xff5aa5': # press the key “9” on the remote control
                a.value(1)  # show number 9 
                b.value(1)
                c.value(1)
                d.value(1)
                e.value(0) 
                f.value(1)
                g.value(1)
                dp.value(0) 
            elif irValue == '0xff4ab5': # press the key “0” on the remote control
                a.value(1) # show number 0  
                b.value(1)
                c.value(1)
                d.value(1) 
                e.value(1)
                f.value(1)
                g.value(0)
                dp.value(0) 
            elif irValue == '0xff42bd': # press the key “*” on the remote control
                a.value(0)  # show nothing 
                b.value(0)
                c.value(0)
                d.value(0)
                e.value(0)
                f.value(0)
                g.value(0)
                dp.value(0)
except:
    pass