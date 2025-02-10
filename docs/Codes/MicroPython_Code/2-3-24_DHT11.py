'''
 * Filename    : DHT11
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# import machine, time and dht library
import machine
import time
import dht

# connect DHT11 to pin(13).
DHT = dht.DHT11(machine.Pin(13))

# Obtain temperature and humidity values per second and print it out. 
while True:
    DHT.measure() # Start the DHT11 once to measure the data.
   # Call DHT built-in functions to get temperature and humidity values and print them on "Shell".
    print('temperature:',DHT.temperature(),'℃','humidity:',DHT.humidity(),'%')
    time.sleep_ms(1000)