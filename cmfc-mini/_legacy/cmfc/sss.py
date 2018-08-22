import time
import serial

ser = serial.Serial(

    port='/dev/ttyS0',
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
)
counter = "60"
ser.write("hallo welt\n".encode())
time.sleep(5)
ser.close
