'''
 * Filename    : One_Digit_Display
 * Thonny      : Thonny 4.1.7 
 * Auther      : http//www.keyestudio.com
'''
import machine
import time

# Define the segment code for a common anode 7-segment display
SEGCODE = [0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f]

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

# Continuously loop through the numbers 0 to 9 and display them on the 7-segment display
while True:
    for num in range(10):
        hc595_shift(SEGCODE[num])  # Shift the segment code for the current number into the 74HC595
        time.sleep_ms(500)  # Wait 500 milliseconds before displaying the next number