#include <Arduino.h>
//#include "led.h"
#include "dirPad.h"

void setup() {
    Serial.begin(115200);

    #ifdef LED
        ledSetup();
    #endif

    #ifdef DIRPAD
        dirPadSetup();
    #endif
}

void loop() {
    #ifdef LED
        ledLoop();
    #endif

    #ifdef DIRPAD
        dirPadLoop();
    #endif
}