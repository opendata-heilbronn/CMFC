
#include <Arduino.h>
#include <Servo.h>
#include <SoftwareSerial.h>

Servo servos[4];
int degrees[4];

SoftwareSerial mySerial(5, 4);

void setup() {
    for (int i = 0; i < 4; i++) {
        servos[i].attach(10 + i);
        servos[i].write(90);
    }

    Serial.begin(9600);
    mySerial.begin(9600);

    Serial.write("starting up");
}

bool turn = false;
String received = "";


void SetSpeed(int servo, int speed) {
    servos[servo].write(speed);
}

void loop() {


    if (mySerial.available()) {
        char input = mySerial.read();
        received += input;

        if (input != '\n')
            return;


        if (received.startsWith("s1:")) {
            String speed = received.substring(3);
            speed = speed.substring(speed.length() - 1);
            Serial.println(speed);
        }
        
        // Serial.println(received);
        received = "";
        return;
    }
}

