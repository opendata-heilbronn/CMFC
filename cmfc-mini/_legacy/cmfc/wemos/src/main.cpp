
#include <Arduino.h>
#include <Servo.h>

Servo servos[4];
int degrees[4];

void setup() {
    for (int i = 0; i < 4; i++) {
        servos[i].attach(10 + i);
        degrees[i] = 90;
    }
}

void loop() {
    servos[0].write(170);
    servos[1].write(170);
    servos[2].write(170);
    servos[3].write(170);

    delay(20);
}

