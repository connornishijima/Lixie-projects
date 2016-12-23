#include "ArduinoJson.h" // JSON Parser
#include "Lixie.h"       // Include Lixie Library
Lixie lix;               // Set class nickname for faster coding

String inputString = "";         // a string to hold incoming data
bool parsing = false;            // Keeps track of when we're currently parsing data

void setup() {
  Serial.begin(115200); // initialize serial
  lix.begin();
}

void loop() {
  // Anything you want here
}

void serialEvent() {
  if (parsing == false) { // If we're not parsing
    while (Serial.available()) { // Read in all serial data
      // get the new byte:
      char inChar = (char)Serial.read();
      // add it to the inputString:
      // if the incoming character is a newline, set a flag
      // so the main loop can do something about it:
      if (inChar == '\n') { // If command is done sending
        parseCommand(inputString); // Parse command
        inputString = ""; // Empty input String
      }
      else {
        inputString += inChar;
      }
    }
  }
}

void parseCommand(String com) {
  parsing = true;
  StaticJsonBuffer<400> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(com); // Parse JSON String to object

  // Test if parsing succeeds.
  if (!root.success()) {
    // clear the string:
    parsing = false;
    return;
  }
  
  // Use JSON data to write to Lixie Displays:
  uint32_t number = root["number"];
  String color_type = root["color_type"];

  if (color_type == "RGB") {
    int on_r = root["on_color"][0];
    int on_g = root["on_color"][1];
    int on_b = root["on_color"][2];
    int off_r = root["off_color"][0];
    int off_g = root["off_color"][1];
    int off_b = root["off_color"][2];

    lix.color_on_rgb(on_r, on_g, on_b);
    lix.color_off_rgb(off_r, off_g, off_b);
  }
  else if (color_type == "HSV") {
    int on_h = root["on_color"][0];
    int on_s = root["on_color"][1];
    int on_v = root["on_color"][2];
    int off_h = root["off_color"][0];
    int off_s = root["off_color"][1];
    int off_v = root["off_color"][2];
    lix.color_on_hsv(on_h, on_s, on_v);
    lix.color_off_hsv(off_h, off_s, off_v);
  }

  lix.write_int(number);
  parsing = false;
}
