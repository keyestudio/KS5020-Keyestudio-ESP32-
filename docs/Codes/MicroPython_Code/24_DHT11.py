'''
 * Filename    : DHT11
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# 导入 machine, time 和 dht 库. 
import machine
import time
import dht

# 关联DHT11引脚(13).
DHT = dht.DHT11(machine.Pin(13))

# 每1秒获取一次温湿度数据，并打印出来. 
while True:
    DHT.measure() # 启动DHT11一次测量数据.
   # 调用DHT的内置函数来获取温度
   # 和湿度数据并打印在“Shell”中.
    print('temperature:',DHT.temperature(),'℃','humidity:',DHT.humidity(),'%')
    time.sleep_ms(1000)