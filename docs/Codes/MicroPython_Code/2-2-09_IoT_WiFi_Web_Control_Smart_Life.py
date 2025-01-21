'''
 * Filename    : IoT_WiFi_Web_Control_Smart_Life 
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
import machine 
import network 
import socket
import time
from machine import Pin,PWM

# REPLACE WITH YOUR NETWORK CREDENTIALS(Put your SSID & Password)
ssid = 'REPLACE_WITH_YOUR_SSID'         # Enter router name
password = 'REPLACE_WITH_YOUR_PASSWORD' # Enter router password

buzzer = machine.Pin(18, machine.Pin.OUT) # Set the GPIO pin to output (assuming the active buzzer is connected to GPIO18)
motora = machine.Pin(13, machine.Pin.OUT) # Set GPIO pin to output (assuming DC motor IN+ is connected to GPIO13)
motorb = machine.Pin(12, machine.Pin.OUT) # Set GPIO pin to output (assuming DC motor IN-connected IN GPIO12)
relay = machine.Pin(25, machine.Pin.OUT) # Set the GPIO pin to output (assuming the relay is connected to GPIO25)

# Define the GPIO pins for the RGB LED
RED_PIN = 27
GREEN_PIN = 16
BLUE_PIN = 17
# Set up the PWM channels
red = PWM(Pin(RED_PIN))
green = PWM(Pin(GREEN_PIN))
blue = PWM(Pin(BLUE_PIN))

# Set the PWM frequency
red.freq(1000)
green.freq(1000)
blue.freq(1000)

# Map input values from one range to another
def interval_mapping(x, in_min, in_max, out_min, out_max):
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

# Convert color values (0-255) to duty cycle values (0-1023)
def color_to_duty(rgb_value):
    rgb_value = int(interval_mapping(rgb_value,0,255,0,1023))
    return rgb_value 

def set_color(red_value,green_value,blue_value):
    red.duty(color_to_duty(red_value))
    green.duty(color_to_duty(green_value))
    blue.duty(color_to_duty(blue_value))

# Create a PWM (Pulse Width Modulation) object on Pin 4
servo = machine.PWM(machine.Pin(4))

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

def connect_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(ssid, password)
    while not wlan.isconnected():
        time.sleep(1)
    print('Connected to WiFi, IP:', wlan.ifconfig()[0])

connect_wifi()

# Create a simple Web server
def web_page():
    html = """
    <html>
    <body>
    <h1>ESP32 Web Server</h1>
    <p style=\"font-size:7vw;\">Click <a href=\"/A\">here</a> turn on Relay<br></p>
    <p style=\"font-size:7vw;\">Click <a href=\"/B\">here</a> turn off Relay<br></p>
    <p style=\"font-size:7vw;\">Click <a href=\"/C\">here</a> turn on RGB<br></p>
    <p style=\"font-size:7vw;\">Click <a href=\"/D\">here</a> turn off RGB<br></p>
    <p style=\"font-size:7vw;\">Click <a href=\"/E\">here</a> turn on fan<br></p>
    <p style=\"font-size:7vw;\">Click <a href=\"/F\">here</a> turn off fan<br></p>
    <p style=\"font-size:7vw;\">Click <a href=\"/G\">here</a> turn on buzzer<br></p>
    <p style=\"font-size:7vw;\">Click <a href=\"/H\">here</a> turn off buzzer<br></p>
    <p style=\"font-size:7vw;\">Click <a href=\"/I\">here</a> <br>servo turn to 180</p>
    <p style=\"font-size:7vw;\">Click <a href=\"/J\">here</a> <br>servo turn to 0</p>
    </body>
    </html>
    """
    return html

# Start a TCP server
addr = socket.getaddrinfo('0.0.0.0', 80)[0][-1]
s = socket.socket()
s.bind(addr)
s.listen(1)
print('Listening on', addr)

set_color(0, 0, 0)
servo_write(servo, 0)

while True:
    cl, addr = s.accept()
    print('Client connected from', addr)
    request = cl.recv(1024)
    request = str(request)

    if 'GET /A' in request:
        relay.value(1)  # Relay pull
    if 'GET /B' in request:
        relay.value(0)  # Relay off
    if 'GET /C' in request:
        # basic colors
        set_color(255, 0, 0)  # Red
        time.sleep(1)     # Wait for 1 second
        set_color(0, 255, 0)  # Green
        time.sleep(1)     # Wait for 1 second
        set_color(0, 0, 255)  # Blue
        time.sleep(1)      # Wait for 1 second
        # blended colors
        set_color(255, 0, 252)  # Magenta
        time.sleep(1)        # Wait for 1 second
        set_color(237, 109, 0)  # Orange
        time.sleep(1)       # Wait for 1 second
        set_color(255, 215, 0) # Yellow
        time.sleep(1)         # Wait for 1 second
        set_color(34, 139, 34)  # Forest Green
        time.sleep(1)         # Wait for 1 second
        set_color(0, 112, 255)  # Light Blue
        time.sleep(1)         # Wait for 1 second
        set_color(0, 46, 90)   # Indigo
        time.sleep(1)      # Wait for 1 second
        set_color(128, 0, 128)  # Purple
        time.sleep(1)        # Wait for 1 second
    if 'GET /D' in request:
        set_color(0, 0, 0)  # Black
    if 'GET /E' in request:
        motora.value(1)  # Turn on the motor
        motorb.value(0)
    if 'GET /F' in request:
        motora.value(0)  # Turn off the motor
        motorb.value(0)
    if 'GET /G' in request:
        buzzer.value(1)  # The buzzer buzzes
    if 'GET /H' in request:
        buzzer.value(0)  # The buzzer does not sound
    if 'GET /I' in request:
        servo_write(servo, 180)  # the Servo turns to 180°
    if 'GET /J' in request:
        servo_write(servo, 0)  # the Servo turns to 0° 
    cl.send('HTTP/1.1 200 OK\r\n')
    cl.send('Content-Type: text/html\r\n\r\n')
    cl.send(web_page())
    cl.close()