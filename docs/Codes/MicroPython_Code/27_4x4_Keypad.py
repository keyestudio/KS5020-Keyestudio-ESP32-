'''
 * Filename    : 4x4_Keypad
 * Thonny      : Thonny 4.1.7
 * Auther      : http//www.keyestudio.com
'''
# 导入 keypad 库.
from keypad import KeyPad
import time

# 将键盘模块与ESP32引脚关联. 
keyPad = KeyPad(26, 25, 17, 16, 27, 14, 12, 13)

# 调用keyPad.scan()函数来获取所按键的值。一旦得到，就在“Shell”窗口打印出来. 
def key():
    keyvalue = keyPad.scan()
    if keyvalue != None:
        print(keyvalue, end="\t")
        time.sleep_ms(300)
        return keyvalue
            
while True: 
    key()
