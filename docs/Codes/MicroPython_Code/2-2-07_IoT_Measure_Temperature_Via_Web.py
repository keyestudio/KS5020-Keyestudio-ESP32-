'''
 * Filename    : IoT_Measure_Temperature_Via_Web 
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
''' 
import machine
import network
import socket
import time
from machine import ADC, Pin

# Configure Wi-Fi
# REPLACE WITH YOUR NETWORK CREDENTIALS(Put your SSID & Password)
ssid = 'REPLACE_WITH_YOUR_SSID'         # Enter router name
password = 'REPLACE_WITH_YOUR_PASSWORD' # Enter router password

def connect_wifi():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    wlan.connect(ssid, password)
    while not wlan.isconnected():
        print('Connecting to WiFi...')
        time.sleep(1)
    print('WiFi connected:', wlan.ifconfig())

# Connect to Wi-Fi
connect_wifi()

# Configure ADC pins
adc = machine.ADC(machine.Pin(36))
adc.atten(machine.ADC.ATTN_11DB)  # Set attenuation factor
adc.width(ADC.WIDTH_12BIT)

def read_temperature():
    raw_value = adc.read()
    voltage = raw_value / 4095 * 5.0
    temperature = voltage / 0.01  # The LM35 output is 0.01V/°C
    return temperature

def web_page():
  temperature = read_temperature()
  html = """<!DOCTYPE HTML><html><head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
  <style> html { font-family: Arial; display: inline-block; margin: 0px auto; text-align: center; }
    h2 { font-size: 3.0rem; } p { font-size: 3.0rem; } .units { font-size: 1.2rem; } 
    .ds-labels{ font-size: 1.5rem; vertical-align:middle; padding-bottom: 15px; }
  </style></head><body><h2>ESP with LM35</h2>
  <p>
    <i class="fas fa-thermometer-half" style="color:#059e8a;"></i> 
    <span class="lm-labels">Temperature</span> 
    <span>""" + str(round(temperature, 2))+"""</span>
    <sup class="units">&deg;C</sup>
  </p>
    <p><i class="fas fa-thermometer-half" style="color:#059e8a;"></i> 
    <span class="lm-labels">Temperature</span>
    <span id="temperature">""" + str(round(temperature * (9/5) + 32.0, 2)) + """</span>
    <sup class="units">&deg;F</sup>
  </p></body></html>"""
  return html

# Creating a Web Server
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(('', 80))
s.listen(5)

while True:
    conn, addr = s.accept()
    print('Got a connection from %s' % str(addr))
    request = conn.recv(1024)
    print('Content = %s' % str(request))
    
    response = web_page()
    conn.send('HTTP/1.1 200 OK\n')
    conn.send('Content-Type: text/html\n')
    conn.send('Connection: close\n\n')
    conn.sendall(response)
    conn.close()