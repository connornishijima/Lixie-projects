# Live PHP Visitor Display
Connor Nishijima (2016)

This is code for a live count of your PHP website visitors, based on the [Live PHP Visitor Counter](https://thomas.vanhoutte.be/miniblog/visitor-counter/) by [Thomas Vanhoutte](https://plus.google.com/+ThomasVanhoutte).

# Requirements

- Webserver with PHP and file/permissions access
- ESP8266 Microcontroller
- Lixie Display (1 or more)

# Variables

- **WIFI_SSID** Your WIFi SSID
- **WIFI PASS** Your WiFi password
- **WEBSITE_URL** Directory of your visitors.php script - For example: "http://connor-n.com/lixie"

# Setup

To use your Lixie Displays / ESP8266 as a live PHP active visitor counter, you need to place visitors.php into your web directory, and create an empty file named "visitors.db" with file permissions 666. Then you can just modify the .ino code with your own variables, and flash it to an ESP8266 using the Arduino IDE. Unless you've changed it, the default pin for Lixie DIN control is Pin 13. :)
