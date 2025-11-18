'''
 * Filename    : Two_Kinds_of_Transistors
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
import machine

button = machine.Pin(14, machine.Pin.IN)   # Button
led = machine.Pin(26, machine.Pin.OUT)  # LED

# Start an infinite loop
while True:
    # Read the current value of the 'button' object (0 or 1) and store it in the 'button_status' variable
    button_status = button.value()
    # If the button is pressed (value is 0)
    if button_status == 0: 
        led.value(1) # Turn the LED on
    # If the button is not pressed (value is 1) 
    else:
        led.value(0)  # turn the LED off