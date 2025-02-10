'''
 * Filename    : IoT_ESP32_WiFi_Station_Mode 
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com 
'''
import time
import network # Importing network library.

# REPLACE WITH YOUR NETWORK CREDENTIALS(Put your SSID & Password)
ssidRouter     = 'REPLACE_WITH_YOUR_SSID'     # Enter router name
passwordRouter = 'REPLACE_WITH_YOUR_PASSWORD' # Enter router password

def STA_Setup(ssidRouter,passwordRouter):
    print("Setup start")
    sta_if = network.WLAN(network.STA_IF) # Set the ESP32 to Station mode.
    if not sta_if.isconnected():
        print('connecting to',ssidRouter)
  # Activate the station mode of the ESP32, initiate a connection request to the router and enter the connection password.      
        sta_if.active(True)
        sta_if.connect(ssidRouter,passwordRouter)
  # Wait for the ESP32 to connect to the router successfully.      
        while not sta_if.isconnected():
            pass
  # Print the IP address assigned to the ESP32 MPU in the Shell. 
    print('Connected, IP address:', sta_if.ifconfig())
    print("Setup End")

try:
    STA_Setup(ssidRouter,passwordRouter)
except:
    sta_if.disconnect()