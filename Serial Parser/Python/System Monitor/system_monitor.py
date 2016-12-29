import lixie as lix
import psutil
import time
import commands

# VARIABLES -----------------

MODE_INTERVAL = 5 # How often to switch data types
TEMP_UNITS = "F"  # Can be "F" or "C"

# ---------------------------

modeIndex = 0
modes = ["TEMP","CPU","MEM","DISK"]
lastSwitch = 0

lix.begin() # Initialize Lixies

while True:
	tNow = int(time.time())
	if tNow % MODE_INTERVAL == 0:
		if tNow != lastSwitch: # makes it so we only advace the index once during this second
			lastSwitch = tNow
			modeIndex+=1
			if modeIndex == len(modes):
				modeIndex = 0

	mode = modes[modeIndex]

	if mode == "CPU":
		r = 255
		g = 255
		b = 0
		info = int(psutil.cpu_percent(interval=0.1))
	elif mode == "MEM":
		r = 0
		g = 255
		b = 255
		info = int(psutil.virtual_memory().percent)
		time.sleep(0.1)
	elif mode == "DISK":
		r = 255
		g = 0
		b = 255
		info = int(psutil.disk_usage('/').percent)
		time.sleep(0.1)
	elif mode == "TEMP":
		r = 255
		g = 255
		b = 255
		info = int(float(commands.getoutput("/opt/vc/bin/vcgencmd measure_temp").split("=")[1].split("'")[0]))
		if TEMP_UNITS == "F":
			info = ((info*9)/5)+32
		time.sleep(0.1)

	print mode+": "+str(info)

	lix.color_on_rgb(r,g,b) # Set Lixie to type color
	lix.write(info) # write info
