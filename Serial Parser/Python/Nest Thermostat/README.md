# Nest Temperature/Status Display

This is code for showing the current temperature reading from a Nest Thermostat, colored with the heating/cooling state!

For example, if your Nest is heating the house, and the current temp is 72F, the Lixies will show an orange "72"!
This mimics the Nest display & app.

# Setup

This requires the [python-nest-thermostat](https://github.com/FiloSottile/nest_thermostat) package by [Filippo Valsorda](https://github.com/FiloSottile) to work.
You can install it using pip:

    sudo apt-get install python-pip
    sudo pip install nest-thermostat
    
**This script relies on the [lixie.py library](https://github.com/connornishijima/Lixie-projects/tree/master/Serial%20Parser)!**

# Variables

- **NEST_EMAIL** Your Nest account email address - the script uses the online API to access information
- **NEST_PASSWORD** Password for your Nest account
- **NEST_INDEX** This allows you to read from a specific Nest you own, if you have more than one. (default = 0)
- **TEMP_UNITS** Can be "F" or "C".
