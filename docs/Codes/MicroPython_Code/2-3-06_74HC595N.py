'''
 * Filename    : 74HC595N
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# Import the machine and time libraries
import machine
import time

# Initialize the pins for the 74HC595 shift register
si = machine.Pin(5, machine.Pin.OUT)  # SI
rck = machine.Pin(23, machine.Pin.OUT)  # RCK
sck = machine.Pin(18, machine.Pin.OUT)  # SCK

# Define the hc595_shift function to shift data into the 74HC595 shift register
def hc595_shift(dat):
    # Set the RCLK pin to low
    rck.off()

    # Iterate through each bit (from 7 to 0)
    for bit in range(7, -1, -1):
        # Extract the current bit from the input data
        value = 1 & (dat >> bit)

        # Set the SRCLK pin to low
        sck.off()

        # Set the value of the SDI pin
        si.value(value)

        # Clock the current bit into the shift register by setting the SRCLK pin to high
        sck.on()

    # Latch the data into the storage register by setting the RCLK pin to high
    rck.on()

num = 0

# Shift data into the 74HC595 to create a moving LED pattern
for i in range(16):
    if i < 8:
        num = (num << 1) + 1  # Shift left and set the least significant bit to 1
    elif i >= 8:
        num = (num & 0b01111111) << 1  # Mask the most significant bit and shift left
    hc595_shift(num)  # Shift the current value into the 74HC595
    print("{:0>8b}".format(num))  # Print the current value in binary format
    time.sleep_ms(200)  # Wait 200 milliseconds before shifting the next value