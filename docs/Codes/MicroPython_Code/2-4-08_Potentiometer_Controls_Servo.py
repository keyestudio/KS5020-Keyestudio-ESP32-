'''
 * Filename    : Potentiometer_Controls_Servo
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
from machine import Pin,PWM,ADC 
import time

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

# Enable and configure ADC with a range of 0-3.3V
adc=ADC(Pin(36))
adc.atten(ADC.ATTN_11DB)
adc.width(ADC.WIDTH_12BIT)

try:
    while True:
        adcValue=adc.read() # Read the ADC value of the potentiometer
        angle=(adcValue*180)/4096 # Convert the ADC value of the potentiometer to the Angle of the servo
        servo_write(servo, int(angle)) # servo rotation Angle
        time.sleep_ms(50)
except:
    servo.deinit()