import serial
import time
from subprocess import Popen

port = '/dev/cu.usbmodem441'
baud = 9600
ser = serial.Serial(port, baud)

while True:    
    response = ser.read()
    if response is '1':
        response = '0'
        proc = Popen(['/usr/bin/afplay', 'bell.wav'])
        # print 'Success'
    time.sleep(0.1)
