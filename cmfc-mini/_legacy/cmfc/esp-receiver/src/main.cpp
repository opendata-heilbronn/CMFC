#include <Arduino.h>

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() {
    Serial.write(1);
    Serial.write(10);
    delay(1000);
    // put your main code here, to run repeatedly:
}