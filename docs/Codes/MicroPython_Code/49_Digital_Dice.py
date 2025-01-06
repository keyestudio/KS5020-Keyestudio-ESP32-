'''
 * Filename    : Digital_Dice
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
import machine
import time
import random

# Define the segment code for a common anode 7-segment display
SEGCODE = [0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f]

# Initialize the pins for the 74HC595 shift register
si = machine.Pin(5, machine.Pin.OUT)  # SI of 74HC595
rck = machine.Pin(23, machine.Pin.OUT)  # RCK of 74HC595
sck = machine.Pin(18, machine.Pin.OUT)  # SCK of 74HC595

tilt = machine.Pin(26, machine.Pin.IN) # Tilt pin

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

# Initialize the random seed
random.seed(time.ticks_us())

num = 1
tilt_state = False

# Define the tilt callback function to toggle the tilt state
def tilt_callback(pin):
    global tilt_state
    tilt_state = not tilt_state 

# Attach the tilt callback function to the falling edge of the tilt pin
tilt.irq(trigger=machine.Pin.IRQ_FALLING, handler=tilt_callback)

# Continuously display the current digit on the 7-segment display, scrolling if tilt is not shaked
while True: 

    # Display the current digit on the 7-segment display
    hc595_shift(SEGCODE[num])

    # If the tilt is shaked and tilt state is True
    if tilt_state:
        pass

    # If the tilt is shaked again and tilt state is False, generate a new random digit
    if not tilt_state:
        num = random.randint(1, 6)
        time.sleep_ms(100) # Adjust this value to control the display refresh rate