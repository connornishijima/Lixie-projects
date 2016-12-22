# data.sparkfun.com Streamer
Connor Nishijima (2016)

This is code for streaming numeric values from a data.sparkfun.com stream!

# Requirements

- data.sparkfun.com stream of your own
- ESP8266 Microcontroller
- Lixie Display (1 or more)

# Variables

- **WIFI_SSID** Your WIFi SSID
- **WIFI PASS** Your WiFi password
- **SPARKFUN_PUBLIC_KEY** The public key of your Sparkfun stream
- **SPARKFUN_DATA_FIELD** The field of your stream to parse (eg: "temp")

# Setup

To get your streamer working, just modify this code with your own variables, and flash it to an ESP8266 using the Arduino IDE. Unless you've changed it, the default pin for Lixie DIN control is Pin 13. :)
