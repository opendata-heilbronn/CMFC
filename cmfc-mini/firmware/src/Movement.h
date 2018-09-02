#include <Arduino.h>
#include <Servo.h>

class Movement {
    public:
        void SetServo(int servo, int value);
        void SetServos(int s1, int s2, int s3, int s4);
        void Setup();
        void Loop();
};