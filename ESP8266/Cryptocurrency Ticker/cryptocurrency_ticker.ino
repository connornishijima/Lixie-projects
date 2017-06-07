/* -------------------------------------------------
   Cryptocurrency Ticker
   using ESP8266 and Lixie Displays!

   by Connor Nishijima - 6/7/2017
   -------------------------------------------------

   To use your Lixie Displays / ESP8266 as a live
   cryptocurrency ticker via CryptoCompare, you'll need
   a few things:

   - WIFI_SSID
   - WIFI_PASSWORD
   - COIN
   - CURRENCY
   - INTERVAL
   
   "INTERVAL" is how many seconds we wait before fetching new values. (Default: 15)
   
   "COIN" is the symbol for the cyrpto you'd like to monitor.
   A few examples are:
   
   Bitcoin    = BTC
   Ethereum   = ETH
   Ripple     = XRP
   NEM        = XEM
   Ethereum C = ETC
   Litecoin   = LTC
   
  "CURRENCY" is the "real" money you'd like to display the coin's
  current value in. For example:
  
  Australia Dollar    = AUD
  Great Britain Pound = GBP
  Euro                = EUR
  Japan Yen           = JPY
  USA Dollar          = USD
  
  and so forth. :)
  
  The decimals are displayed in a separate color from the whole units, 
  which will be green or red depending on growth or decay in value in
  the last INTERVAL.

   -------------------------------------------------
*/

#include "Lixie.h" // Include Lixie Library
#define DATA_PIN   5
#define NUM_LIXIES 6
Lixie lix(DATA_PIN, NUM_LIXIES);

#include <ESP8266WiFi.h>        // ESP8266 WIFI Lib
#include <ESP8266WiFiMulti.h>   // WifiMulti Lib for connection handling
#include <WiFiClientSecure.h>   // Allows HTTPS (SSL) connection to CryptoCompare
#include <ArduinoJson.h>        // JSON Parser
ESP8266WiFiMulti WiFiMulti;

char* WIFI_SSID    = "";
char* WIFI_PASS    = "";

String COIN     = "ETH"; // WHAT CRYPTO ARE WE WATCHING THE VALUE OF?
String CURRENCY = "USD"; // WHAT CURRENCY IS THE COIN VALUE REPRESENTED IN?
uint16_t INTERVAL = 15; // HOW MANY SECONDS BETWEEN PRICE CHECKS?

const char* host = "min-api.cryptocompare.com";
const int httpsPort = 443;
uint16_t last_value = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("BOOT");
  WiFiMulti.addAP(WIFI_SSID, WIFI_PASS); // Your WIFI credentials
  lix.begin(); // Initialize LEDs

  // This sets all lights to yellow while we're connecting to WIFI
  while ((WiFiMulti.run() != WL_CONNECTED)) {
    lix.color(255, 255, 0);
    lix.write(888888);
    delay(100);
  }

  Serial.println("CONNECTED");
  // Green on connection success
  lix.color(0, 255, 0);
  lix.write(888888);
  delay(500);

  // Reset colors to default
  lix.color(255, 255, 255);
  lix.clear();
}

void loop() {
  Serial.println("CHECKING VALUE");
  checkCoin();
  delay(INTERVAL*1000);
}

// FUNCTIONS ----------------------------------------

// Check latest coin value on CryptoCompare API
void checkCoin() {
  StaticJsonBuffer<200> jsonBuffer;      // JSON Parser setup
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    JsonObject& coin_data = jsonBuffer.parseObject(get_value());
    if (!coin_data.success()) {
      Serial.println("Parsing failed");
      return;
    }
    float value = coin_data[CURRENCY];
    value*=100;
    Serial.println(value);
    lix.write(uint16_t(value));
    if (uint16_t(value) > last_value) {
      flash_color(0, 255, 0);
    }
    if (uint16_t(value) < last_value) {
      flash_color(255, 0, 0);
    }
    last_value = value;
  }
}

// Set custom color, fade whole numbers back to default
void flash_color(byte r, byte g, byte b) {
  lix.color(r, g, b);
  lix.show();
  delay(500);
  for (float progress = 0; progress < 1; progress += 0.01) {
    lix.color(
      255 * progress + r * (1 - progress),
      255 * progress + g * (1 - progress),
      255 * progress + b * (1 - progress),
      2
    );
    lix.color(
      255 * progress + r * (1 - progress),
      255 * progress + g * (1 - progress),
      255 * progress + b * (1 - progress),
      3
    );
    lix.color(
      255 * progress + r * (1 - progress),
      255 * progress + g * (1 - progress),
      255 * progress + b * (1 - progress),
      4
    );
    lix.show();
    delay(1);
  }
}

// Fetches coin value from CryptoCompare API
String get_value() {
  // Use WiFiClientSecure class to create TLS connection
  WiFiClientSecure client;
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return "CANNOT CONNECT";
  }

  String url = "/data/price?fsym="+COIN+"&tsyms="+CURRENCY;
  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: BuildFailureDetectorESP8266\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    Serial.println(line);
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n'); // Used to skip first line of result
  line = client.readStringUntil('\n');  // This is the one we want
  Serial.println("reply was:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");
  return line;
}
