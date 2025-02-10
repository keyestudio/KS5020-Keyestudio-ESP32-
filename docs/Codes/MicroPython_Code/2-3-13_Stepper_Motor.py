'''
 * Filename    : Stepper_Motor
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin
import time 
 
# initialize pins
in1 = Pin(16, Pin.OUT)
in2 = Pin(17, Pin.OUT)
in3 = Pin(18, Pin.OUT)
in4 = Pin(19, Pin.OUT)
 
# delay
delay = 1
 
# The number of steps required for the motor to rotate one turn, (about 360°), may vary slightly.
ROUND_VALUE = 509
 
# 4-phase 8-beat stepper motor sequence value: A-AB-B-BC-C-CD-D-DA-A.
STEP_VALUE = [
    [1, 0, 0, 0],
    [1, 1, 0, 0],
    [0, 1, 0, 0],
    [0, 1, 1, 0],
    [0, 0, 1, 0],
    [0, 0, 1, 1],
    [0, 0, 0, 1],
    [1, 0, 0, 1],
]
 
# pins output low
def reset():
    in1(0)
    in2(0)
    in3(0)
    in4(0)
 
# If count is a positive integer, it rotates clockwise;
# if count is a negative integer, it rotates counterclockwise.
def step_run(count):
    direction = 1     # rotate clockwise
    if count < 0:
        direction = -1  # rotate counterclockwise
        count = -count
    for x in range(count):
        for bit in STEP_VALUE[::direction]:
            in1(bit[0])
            in2(bit[1])
            in3(bit[2])
            in4(bit[3])
            time.sleep_ms(delay)
    reset()
 
# If a is a positive integer, it rotates clockwise;
# if a is a negative integer, it rotates counterclockwise.
def step_angle(a):
    step_run(int(ROUND_VALUE * a / 360))
 
# Loop: turn clockwise once, then counterclockwise once.
while True:
    step_run(509)
    step_run(-509)
    step_angle(360)
    step_angle(-360)