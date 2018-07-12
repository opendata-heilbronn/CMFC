#include <NeoPixelBus.h>
#define LED

#define NUM_LEDS 4
#define DATA_PIN 33
#define BUS_ENABLE_PIN 2

uint8_t colorSaturation = 16;

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(NUM_LEDS, DATA_PIN);

RgbColor red = RgbColor(colorSaturation, 0, 0);
RgbColor green = RgbColor(0, colorSaturation, 0);
RgbColor blue = RgbColor(0, 0, colorSaturation);
RgbColor white = RgbColor(colorSaturation);
RgbColor black = RgbColor(0);



void ledSetup() {
    pinMode(BUS_ENABLE_PIN, OUTPUT);
    digitalWrite(BUS_ENABLE_PIN, LOW);

    strip.Begin();
    strip.Show();
}

void ledLoop() {
    strip.SetPixelColor(0, red);
    strip.SetPixelColor(1, green);
    strip.SetPixelColor(2, blue);
    strip.SetPixelColor(3, white);
    strip.Show();
}
