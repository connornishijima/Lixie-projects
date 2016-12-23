# OpenWeatherMap Display
Connor Nishijima (2016)

This is code for a live count of your PHP website visitors, based on the [Live PHP Visitor Counter](https://thomas.vanhoutte.be/miniblog/visitor-counter/) by [Thomas Vanhoutte](https://plus.google.com/+ThomasVanhoutte).

# Requirements

- OpenWeatherMap API Key
- OpenWeatherMap City ID
- ESP8266 Microcontroller
- Lixie Display (1 or more)

# Variables

- **WIFI_SSID** Your WIFi SSID
- **WIFI PASS** Your WiFi password
- **OWM_API_KEY** OpenWeatherMap API Key
- **OWM_CITY_ID** OpenWeatherMap City ID
- **OWM_FIELD** Type of data to display
- **OWM_UNITS** Imperial, Metric, or Kelvin

# Setup

To use your Lixie Displays / ESP8266 as a live OpenWeatherMap Display, you need to obtain two things from OWM:

- API Key
- City ID

To get an API Key, go here and create an account: [http://openweathermap.org/appid](http://openweathermap.org/appid)
To get your City ID, search for your local weather on the site, and fetch it from the URL:
http://openweathermap.org/city/5368361
          This is your City ID ^
          
Next, let's configure the sketch to show the data we want.

**OWM_FIELD** is the type of data displayed - it can be "temp","humidity","pressure","temp_min", or "temp_max"
**OWM_UNITS** can be "imperial", "metric", or "kelvin"

Once you've gathered all of this, you can just modify the .ino code with your own variables, and flash it to an ESP8266 
using the Arduino IDE. Unless you've changed it, the default pin for Lixie DIN control is Pin 13. :)

Another feature of this code is that it changes the color of your Lixies based on the current state of weather!

| COLOR           | STATE                        |
|-----------------|------------------------------|
|(Very Pale) Blue | Thunderstorm                 |
|(Pale) Blue      | Drizzle                      |
|Cyan             | Rain                         |
|White            | Snow                         |
|Gray             | Atmospheric (fog, pollution) |
|Yellow           | Clear                        |
|(Pale) Yellow    | Clouds / Calm                |
|Red              | Extreme (tornado, lightning) |
