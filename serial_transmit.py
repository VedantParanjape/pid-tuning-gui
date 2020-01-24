import serial
import time
import sys

def serial_write(data, serial_port = '/dev/ttyUSB0'):

    ser = serial.Serial(serial_port,115200,timeout=0)

    while True:
        time.sleep(0.1)  
        print(ser.write(data))

def main():
    # data= b'\x1f\xaa\x88'
    if len(sys.argv) < 3:
        print("usage: python3 rf_transmit.py [data] [port]")
    
    else:
        data = sys.argv[1].encode()
        port = sys.argv[2]

        serial_write(data, port)        

if __name__ == "__main__":
    main()