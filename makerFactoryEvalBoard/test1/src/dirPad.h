#include <Arduino.h>
#define DIRPAD


#define DPAD_PIN_DOWN   25
#define DPAD_PIN_UP     34
#define DPAD_PIN_LEFT   26
#define DPAD_PIN_RIGHT  32
#define DPAD_PIN_MIDDLE 27

#define DEBOUNCE_TIME   5

uint8_t buttonPins[] = {
    DPAD_PIN_MIDDLE,
    DPAD_PIN_UP,
    DPAD_PIN_DOWN,
    DPAD_PIN_LEFT,
    DPAD_PIN_RIGHT,
};
const uint8_t buttonPinsSize = sizeof(buttonPins)/sizeof(buttonPins[0]);

bool buttonState[buttonPinsSize], lastButtonState[buttonPinsSize];
uint32_t lastButtonPress = 0;

void handleButtonPress(uint8_t buttonId) {
    Serial.println("Button " + String(buttonId) + " pressed.");
}

void dirPadSetup() {
    for(uint8_t i = 0; i < buttonPinsSize; i++) {
        pinMode(buttonPins[i], INPUT);
    }
}

void dirPadLoop() {
    uint32_t now = millis();
    for(uint8_t i = 0; i < buttonPinsSize; i++) {
        bool pinState = digitalRead(buttonPins[i]);
        if(!pinState && lastButtonState[i] && lastButtonPress + DEBOUNCE_TIME < now) {
            lastButtonPress = now;
            handleButtonPress(i);
        }
        lastButtonState[i] = pinState;
    }
}