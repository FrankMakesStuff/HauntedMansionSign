<<<<<<< HEAD
import serial
import time

ser = serial.Serial('COM3', 9600, timeout=5)
isRunning = True
while isRunning:
	try:
		getData = ser.readline()
		if getData:
			print getData ,
		
		if getData.find("input") > 0:
			revs = raw_input("How many slots? ")
			if revs.upper() == "EXIT":
				isRunning = False

			ser.write(revs + '\n')

		#time.sleep(0.1)
	except ser.SerialTimeoutException:
		print 'Serial port error: data could not be read!'
		time.sleep(1)

ser.close()
=======
import serial
import time

ser = serial.Serial('COM3', 9600, timeout=5)
isRunning = True
while isRunning:
	try:
		getData = ser.readline()
		if getData:
			print getData ,
		
		if getData.find("input") > 0:
			revs = raw_input("How many slots? ")
			if revs.upper() == "EXIT":
				isRunning = False

			ser.write(revs + '\n')

		#time.sleep(0.1)
	except ser.SerialTimeoutException:
		print 'Serial port error: data could not be read!'
		time.sleep(1)

ser.close()
>>>>>>> 70437755a8b59ef5d1e050f19d45bd515eb1c222
