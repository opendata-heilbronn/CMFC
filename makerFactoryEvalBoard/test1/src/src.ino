#include <Arduino.h>
#include "led.h"

void setup() {
    Serial.begin(115200);

    #ifdef LED
    ledSetup();
    #endif
}

void loop() {
    #ifdef LED
    ledLoop();
    #endif
}