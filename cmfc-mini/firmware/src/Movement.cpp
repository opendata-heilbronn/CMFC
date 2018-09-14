#include <Arduino.h>
#include <Servo.h>
#include "Movement.h"

#ifndef SERVO_COUNT
#define SERVO_COUNT     4
#endif

#ifndef SENSOR_PIN
#define SENSOR_PIN     5
#endif

const int servoPins[SERVO_COUNT] = {15, 13, 12, 14};
int detectWalls = 1;
Servo servos[SERVO_COUNT];


void Movement::Setup() {
    for (int i = 0; i < SERVO_COUNT; i++) {
        servos[i].attach(servoPins[i]);
    }
}

void Movement::Loop() {
    if (detectWalls > 0 && digitalRead(SENSOR_PIN) == 0) {
        servos[0].write(90);
        servos[1].write(90);
        servos[2].write(90);
        servos[3].write(90);
    }
}

void Movement::SetServo(int servo, int value) {
    servos[servo].write(value);
}

void Movement::SetServos(int s1, int s2, int s3, int s4) {
    servos[0].write(s1);
    servos[1].write(s2);
    servos[2].write(s3);
    servos[3].write(s4);
}
