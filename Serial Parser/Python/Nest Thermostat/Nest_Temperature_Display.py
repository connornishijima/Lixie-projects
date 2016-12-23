import lixie
import commands
import time
import traceback

lixie.begin()

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
		resp = commands.getoutput('nest.py --user "'+NEST_EMAIL+'" --password "'+NEST_PASSWORD+'" --index '+str(NEST_INDEX)+' show')
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
			color = [255,127,0]
		elif heat_state == "False" and cool_state == "True":
			color = [0,127,255]
		else:
			color = [255,255,255]

		print "TEMP: "+str(int(temp))
		print "HEAT STATE: "+str(heat_state)
		print "COOL STATE: "+str(cool_state)

		data = {
			"number":int(temp),
			"color_type":"RGB",
			"on_color":color,
			"off_color":[0,0,0]
		}
		lixie.write(data)
		time.sleep(20)

	except:
		traceback.print_exc()
