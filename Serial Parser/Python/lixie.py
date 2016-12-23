from serial import Serial
import json
import time

def begin():
	global ser
	connected = False
	port = 0
	while connected == False: # Iterate through USB Serial until we find a microcontroller
		try:
			ser = Serial('/dev/ttyACM'+str(port), 115200, timeout=1)
			connected = True
		except:
			port+=1

	for x in range(10): # Clears out all Serial/JSON Parsing buffers
		clear()
		time.sleep(0.1)

def write(data):
	global ser
	output = json.dumps(data)
	ser.write(output+"\n")

def clear():
	data = {
		"number":0,
		"color_type":"HSV",
		"on_color":[0,0,0],
		"off_color":[0,0,0]
	}
	output = json.dumps(data)
	ser.write(output+"\n")
