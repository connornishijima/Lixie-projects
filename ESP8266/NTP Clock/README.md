# NTP Clock
Connor Nishijima (2016)

This is code for an NTP Clock!
# Requirements

- ESP8266 Microcontroller
- Lixie Display (4 or more)

# Variables

- **WIFI_SSID** Your WIFi SSID
- **WIFI PASS** Your WiFi password
- **SIX_DIGIT** True/false for 6 or 4 digit clocks
- **TIME_COLOR_RGB** 8-bit RGB value to color the displays with
- **TIME_OFFSET** Your local UTC offset for time zones

# Setup

To use your Lixie Displays / ESP8266 as an NTP Clock, modify the .ino code with your own variables, and flash it to an ESP8266 using the Arduino IDE. Unless you've changed it, the default pin for Lixie DIN control is Pin 13. :)

**PLEASE NOTE** - By default, the Lixie library is only configured to drive 4 digits. If you want a 6-digit clock, you'll need to modify the NUM_LIXIES valiable to use 6 digits.
