import lixie as lix
import commands
import time
import traceback

lix.begin()

# Nest account information for API Access
NEST_EMAIL = ""
NEST_PASSWORD = ""

# Index of Nest Thermostat for users with multiple Nests (default = 0)
NEST_INDEX = 0

# Can be "F" or "C"
TEMP_UNITS = "F"

while True:
	try:
		print "-----------------------------"
		print "Getting data from Nest API..."
		resp = commands.getoutput('nest.py --user "'+NEST_EMAIL+'" --password "'+NEST_PASSWORD+'" --index '+str(NEST_INDEX)$
		resp = resp.split("\n")
		heat_state = False
		cool_state = False
		color = [255,255,255]
		for item in resp:
			item = item.split(":")
			try:
				key = item[0].replace(".",'')
				val = item[1].replace(" ",'')
			except:
				pass

			if key == "hvac_heater_state":
				heat_state = val
			if key == "hvac_fan_state":
				cool_state = val

			if key == "current_temperature":
				if TEMP_UNITS == "F":
					temp = ((float(val)*9)/5)+32
				elif TEMP_UNITS == "C":
					temp = float(val)

		if heat_state == "True" and cool_state == "False":
			color = [255,127,0]   # Orange
		elif heat_state == "False" and cool_state == "True":
			color = [0,127,255]   # Cyan
		else:
			color = [255,255,255] # White

		print "TEMP: "+str(int(temp))
		print "HEAT STATE: "+str(heat_state)
		print "COOL STATE: "+str(cool_state)

		lix.color_on_rgb(color[0],color[1],color[2])
		lix.write(int(temp))
		time.sleep(20)

	except:
		traceback.print_exc()
