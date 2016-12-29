/*
 * LIXIE Serial Parser
 * 
 * This code eats up numbers from Serial UART, 
 * (separated by any non-numeric char) and
 * converts them to Lixie output!
 * 
 * For example:
 * "1:888\n" would write "888" to the displays.
 * 
 * Command types:
 * 
 * "0\n"
 *    This clears all Lixie dsiplays
 * 
 * "1:[number]\n"
 *    This writes [number] to the Lixie displays
 *    
 * "2:[r]:[g]:[b]\n"
 *    This sets the Lixie on_color to [r],[g],[b].
 *    
 * "3:[r]:[g]:[b]\n"
 *    This sets the Lixie off_color to [r],[g],[b].
 *    
 * "4:[h]:[s]:[v]\n"
 *    This sets the Lixie on_color to [h],[s],[v].
 *    
 * "5:[h]:[s]:[v]\n"
 *    This sets the Lixie off_color to [h],[s],[v].
 */

#include "Lixie.h" // Include Lixie Library
Lixie lix;         // Set class nickname for faster coding

bool parsing = false;

void setup() {
  // initialize serial:
  Serial.begin(115200);
  lix.begin();
}

void loop() {
}

void serialEvent() {
  if (parsing == false) {
    parsing = true;

    uint8_t type = Serial.parseInt();
    if (type == 0) {
      lix.clear();
      lix.show();
    }
    else if (type == 1) {
      uint32_t number = Serial.parseInt();
      lix.write_int(number);
    }
    else if (type == 2) {
      uint8_t r = Serial.parseInt();
      uint8_t g = Serial.parseInt();
      uint8_t b = Serial.parseInt();
      lix.color_on_rgb(r, g, b);
    }
    else if (type == 3) {
      uint8_t r = Serial.parseInt();
      uint8_t g = Serial.parseInt();
      uint8_t b = Serial.parseInt();
      lix.color_off_rgb(r, g, b);
    }
    else if (type == 4) {
      uint8_t h = Serial.parseInt();
      uint8_t s = Serial.parseInt();
      uint8_t v = Serial.parseInt();
      lix.color_on_hsv(h, s, v);
    }
    else if (type == 5) {
      uint8_t h = Serial.parseInt();
      uint8_t s = Serial.parseInt();
      uint8_t v = Serial.parseInt();
      lix.color_off_hsv(h, s, v);
    }
    while (Serial.available()) {
      byte garbage = Serial.read();
    }
    parsing = false;
  }
}
