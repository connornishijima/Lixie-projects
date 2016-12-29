from serial import Serial
import time
import re

global ser

def begin():
	global ser
	ser = Serial("/dev/ttyAMA0", 115200, timeout=1)
	clear()

def write(message):
	global ser
	output = re.sub("[^0-9]", "", str(message))
	ser_print(
		"1:"+
		str(output)+"\n"
	)

def color_on_rgb(r,g,b):
	global ser
	ser_print(
		"2:"+
		str(r)+":"+
		str(g)+":"+
		str(b)+"\n"
	)

def color_off_rgb(r,g,b):
	global ser
	ser_print(
		"3:"+
		str(r)+":"+
		str(g)+":"+
		str(b)+"\n"
	)

def color_on_hsv(h,s,v):
	global ser
	ser_print(
		"4:"+
		str(h)+":"+
		str(s)+":"+
		str(v)+"\n"
	)

def color_off_hsv(h,s,v):
	global ser
	ser_print(
		"5:"+
		str(h)+":"+
		str(s)+":"+
		str(v)+"\n"
	)

def clear():
	global ser
	ser_print("0\n")
	
def ser_print(message):
	global ser
#	sys.stdout.write(message.replace("\n",'')+"\\n"+"\n")
#   ^ Uncomment this ^ for debug
	ser.write(message)
	time.sleep(0.005)
