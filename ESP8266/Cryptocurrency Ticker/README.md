# Live Cryptocurrency Ticker
Connor Nishijima (2017)

This is code for a live ticker of your favorite cryptocurrency, valued in your local "real" currency!
For example, right now one "Ether" (ETH) is worth 260.59 USD. A set of Lixie displays would show "26059" with the decimal values marked in red or green, depending on decay or growth since we last checked.

# Requirements

- ESP8266 Microcontroller
- Lixie Display (3-6 ...or more. We'll see!)

# Variables

- **WIFI_SSID** Your WIFi SSID
- **WIFI PASS** Your WiFi password
- **INTERVAL** How many seconds we wait before fetching new values. (Default: 15)
- **COIN** The symbol for the cyrpto you'd like to monitor. A few examples are:
   Bitcoin    = BTC
   Ethereum   = ETH
   Ripple     = XRP
   NEM        = XEM
   Ethereum C = ETC
   Litecoin   = LTC   
- **CURRENCY** The "real" money you'd like to display the coin's current value in. For example:
  Australia Dollar    = AUD
  Great Britain Pound = GBP
  Euro                = EUR
  Japan Yen           = JPY
  USA Dollar          = USD

# Setup

To use your Lixie Displays / ESP8266 as a live crypto ticker, you need to modify the variables above to match your specific needs, and that'll be it! You now have a live cryptocurrency value on your desk, and now you don't have to check Coinbase every 30 seconds. You can check the Lixies every 15! ;)
