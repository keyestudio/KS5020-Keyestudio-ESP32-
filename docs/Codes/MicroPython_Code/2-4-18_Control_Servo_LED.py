'''
 * Filename    : Control_Servo_LED
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin,PWM,ADC
import time 

# connect LED to pin 25 and set it to output
led = Pin(25, Pin.OUT)

# Create a PWM (Pulse Width Modulation) object on Pin 4
servo = PWM(Pin(4,Pin.OUT),10000)

# Set the frequency of the PWM signal to 50 Hz, common for servos
servo.freq(50)

# Define a function for interval mapping
def interval_mapping(x, in_min, in_max, out_min, out_max):
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

# Define a function to write an angle to the servo
def servo_write(pin, angle):

    pulse_width = interval_mapping(angle, 0, 180, 0.5, 2.5) # Calculate the pulse width
    duty = int(interval_mapping(pulse_width, 0, 20, 0, 1023))     # Calculate the duty cycle
    pin.duty(duty) # Set the duty cycle of the PWM signal
    
button = Pin(14, Pin.IN, Pin.PULL_UP) # Button

# Enable and configure ADC with a range of 0-3.3V
adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)  

while True:
    # Read the current value of the 'button' object (0 or 1) and store it in the 'button_status' variable
    button_status = button.value()
    # If the button is pressed (value is 0)
    if button_status == 0: 
        led.value(1) # Turn the LED on
    # If the button is not pressed (value is 1) 
    else:
        led.value(0)  # turn the LED off
    adcValue=adc.read() # read the ADC value of the potentiometer
    angle=(adcValue*180)/4096 # Convert the ADC value of the potentiometer to the Angle of the servo
    servo_write(servo, int(angle)) # servo rotation Angle
    time.sleep_ms(50)
