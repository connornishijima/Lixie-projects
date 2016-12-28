# Ping Speedometer
Connor Nishijima (2016)

This is code for a live network latency monitor! (This relies on the [ESP8266Ping library](https://github.com/dancol90/ESP8266Ping) by [Daniele Colanardi](https://github.com/dancol90))
# Requirements

- ESP8266 Microcontroller
- Lixie Display (1 or more)

# Variables

- **WIFI_SSID** Your WIFi SSID
- **WIFI PASS** Your WiFi password
- **PING_SITE** The webpage you'd like to ping
- **PING_COUNT** The number of pings to send to the server
- **PING_INTERVAL** The time to wait between pings
- **PING_GOOD** A user-defined "good" ping time (milliseconds)
- **PING_BAD** A user-defined "bad" ping time (milliseconds)

# Setup

To use your Lixie Displays / ESP8266 as a ping speedometer, modify the .ino code with your own variables, and flash it to an ESP8266 using the Arduino IDE. Unless you've changed it, the default pin for Lixie DIN control is Pin 13. :)

By default, it pings www.google.com, and 35ms is considered a good ping, 100ms is considered a bad ping. The code also colors your Lixies according to the level of network latency! Green = great, Yellow = good, Red = bad!

# Caveats

  - The WiFi of the ESP8266 will always be slower of
    that in your Playstation/PC/Etc. It's more of a
    relative measurement of latency, take it with a
    grain of salt.

  - By default, it's measuring latency from Google,
    which is a very ideal server. If you're using this
    to measure speed for GTA Online (or another
    game/service) you may want to ping the servers
    of that company instead.
