#include <Arduino.h>

class GAM {
    public:
        void I2Cscan();
        void Setup();
        void Loop(int16_t* accel, int16_t* temp, int16_t* gyro);
};