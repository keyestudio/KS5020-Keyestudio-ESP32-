'''
 * Filename    : 4-Digit_Digital_Tube
 * Thonny      : Thonny 4.1.7 
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin
import time

# each digit pin of the digital tube
a = Pin(19, Pin.OUT)
b = Pin(17, Pin.OUT)
c = Pin(14, Pin.OUT)
d = Pin(13, Pin.OUT)
e = Pin(5, Pin.OUT)
f = Pin(23, Pin.OUT)
g = Pin(27, Pin.OUT)
dp = Pin(12, Pin.OUT)

G1 = Pin(18, Pin.OUT)
G2 = Pin(26, Pin.OUT)
G3 = Pin(25, Pin.OUT)
G4 = Pin(16, Pin.OUT)
  
# corresponding pins of digital tube a-dp
d_Pins=[Pin(i,Pin.OUT)  for i in [19,17,14,13,5,23,27,12]]
# corresponding pins of digital tube segments G1, G2, G3, G4
w_Pins=[Pin(i,Pin.OUT)  for i in [18,26,25,16]]
 
number={
    '0':
    [1,1,1,1,1,1,0,0],#0
    '1':
    [0,1,1,0,0,0,0,0],#1
    '2':
    [1,1,0,1,1,0,1,0],#2
    '3':
    [1,1,1,1,0,0,1,0],#3
    '4':
    [0,1,1,0,0,1,1,0],#4
    '5':
    [1,0,1,1,0,1,1,0],#5
    '6':
    [1,0,1,1,1,1,1,0],#6
    '7':
    [1,1,1,0,0,0,0,0],#7
    '8':
    [1,1,1,1,1,1,1,0],#8
    '9':
    [1,1,1,1,0,1,1,0],#9
}
 
def display(num,dp):
    global number
    count=0
    for pin in d_Pins: # show num value
        pin.value(number[num][count])
        count+=1
    if dp==1:
        d_Pins[7].value(0)
def clear():
    for i in w_Pins:
        i.value(0)
    for i in d_Pins:
        i.value(1)
def showData(num):
   # numeric hundreds, thousands, units, and decimal places
    d_num=num
    location=d_num.find('.')
    if location>0:
        d_num=d_num.replace('.','')
        while len(d_num)<4:
            d_num='0'+d_num
        for i in range(0,4):
            time.sleep(2)
            clear()
            w_Pins[3-i].value(1)
            if i==location-1:
                display(d_num[i],1)
            else:
                display(d_num[i],0)
    if location<0:
        for i in range(0,4):
            time.sleep(2)
            clear()
            w_Pins[3-i].value(1)
            display(d_num[i],0)
while True:
 
    num='9016'
    showData(num)