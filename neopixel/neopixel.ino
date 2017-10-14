#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN_a 6
#define PIN_b 7
#define PIN_c 8
#define PIN_d 9

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip_a = Adafruit_NeoPixel(12, PIN_a, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_b = Adafruit_NeoPixel(12, PIN_b, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_c = Adafruit_NeoPixel(12, PIN_c, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_d = Adafruit_NeoPixel(12, PIN_d, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code


  strip_a.begin();
  strip_b.begin();
  strip_c.begin();
  strip_d.begin();
  strip_a.show(); // Initialize all pixels to 'off'
  strip_b.show(); // Initialize all pixels to 'off'
  strip_c.show(); // Initialize all pixels to 'off'
  strip_d.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip_a.Color(0, 255, 0), 80); // Green
  colorWipe(strip_a.Color(0, 0, 255), 80); // Blue
  colorWipe(strip_b.Color(0, 255, 0), 80); // Green
  colorWipe(strip_b.Color(0, 0, 255), 80); // Blue
  colorWipe(strip_c.Color(0, 255, 0), 80); // Green
  colorWipe(strip_c.Color(0, 0, 255), 80); // Blue
  colorWipe(strip_d.Color(0, 255, 0), 80); // Green
  colorWipe(strip_d.Color(0, 0, 255), 80); // Blue
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip_a.numPixels(); i++) {
    strip_a.setPixelColor(i, c);
    strip_a.show();
    delay(wait);
  }
  for(uint16_t i=0; i<strip_b.numPixels(); i++) {
    strip_b.setPixelColor(i, c);
    strip_b.show();
    delay(wait);
  }
for(uint16_t i=0; i<strip_c.numPixels(); i++) {
    strip_c.setPixelColor(i, c);
    strip_c.show();
    delay(wait);
  }
  for(uint16_t i=0; i<strip_d.numPixels(); i++) {
    strip_d.setPixelColor(i, c);
    strip_d.show();
    delay(wait);
  }
}


