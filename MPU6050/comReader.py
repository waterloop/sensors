import serial, csv

mFile = open('output.cvs', 'wb')

writer = csv.writer(mFile, dialect=csv)
with serial.Serial('COM4', 19200, timeout=1) as mSerial:
    if mSerial.isOpen():
        while True:
            writer.writerow(str(mSerial.readline()).replace("b'", "").replace("\\r\\n'", "").split("/"))
