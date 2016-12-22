# Live Wordpress Visitor Display
Connor Nishijima (2016)

This is code for a live count of your Wordpress visitors, based on the [WP Live Statistics](https://wordpress.org/plugins/wp-live-statistics/) plugin by [Paratheme](https://paratheme.com/)!

# Requirements

- WordPress self-hosted installation
- [WP Live Statistics](https://wordpress.org/plugins/wp-live-statistics/) plugin
- ESP8266 Microcontroller
- Lixie Display (1 or more)

# Variables

- **WIFI_SSID** Your WIFi SSID
- **WIFI PASS** Your WiFi password
- **WORDPRESS_URL** The root of your WordPress site - for example: "http://connor-n.com"

# Setup

To get your counter working, just install and activate the stats plugin above, modify this code with your own variables, and flash it to an ESP8266 using the Arduino IDE. Unless you've changed it, the default pin for Lixie DIN control is Pin 13. :)
