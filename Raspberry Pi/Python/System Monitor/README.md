# Raspberry Pi System Monitor

This is code for showing CPU/RAM/Disk usage and system temperature on a Raspberry Pi!

| DATA TYPE  |  COLOR  |
|------------|---------|
| CPU (%)    | Yellow  |
| RAM (%)    | Cyan    |
| Disk (%)   | Magenta |
| Temp (C/F) | White   |

# Setup

This requires the psutil Python library to work.
You can install it using pip:

    sudo apt-get install python-pip
    sudo pip install psutil
    
**This script relies on the [Lixie Python library](https://github.com/connornishijima/lixie_python)!**

# Variables

- **MODE_INTERVAL** How often, in seconds, to switch data types
- **TEMP_UNITS** Can be "C" or "F"
