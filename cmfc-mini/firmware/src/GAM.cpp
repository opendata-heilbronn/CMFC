#include <Arduino.h>
#include <Wire.h>

#include "GAM.h"

#define MPU9250_ADDRESS     0x68

#define ACCEL_ADDRESS         0x3B
#define GYRO_ADDRESS        0x43

void I2Cread(uint8_t Address, uint8_t Register, uint8_t Nbytes, uint8_t* Data)
{
    Wire.beginTransmission(Address);
    Wire.write(Register);
    Wire.endTransmission();
    
    Wire.requestFrom(Address, Nbytes); 
    uint8_t index=0;

    while (Wire.available())
        Data[index++]=Wire.read();
}


void I2CwriteByte(uint8_t Address, uint8_t Register, uint8_t Data)
{
    Wire.beginTransmission(Address);
    Wire.write(Register);
    Wire.write(Data);
    Wire.endTransmission();
}


void GAM::I2Cscan() {
    Wire.begin();
    // scan for i2c devices
    byte error, address;
    int nDevices;

    Serial.println("Scanning...");

    nDevices = 0;
    for(address = 1; address < 127; address++ ) 
    {
        // The i2c_scanner uses the return value of
        // the Write.endTransmisstion to see if
        // a device did acknowledge to the address.
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0)
        {
            Serial.print("I2C device found at address 0x");
            if (address<16) 
                Serial.print("0");
            Serial.print(address,HEX);
            Serial.println("  !");

            nDevices++;
        }
        else if (error==4) 
        {
            Serial.print("Unknow error at address 0x");
            if (address<16) 
                Serial.print("0");
            Serial.println(address,HEX);
        }    
    }

    if (nDevices == 0)
        Serial.println("No I2C devices found\n");
    else
        Serial.println("done\n");
}

void GAM::Setup() {
    // Arduino initializations
    Wire.begin();
    // Set accelerometers low pass filter at 5Hz
    I2CwriteByte(MPU9250_ADDRESS,29,0x06);
    // Set gyroscope low pass filter at 5Hz
    I2CwriteByte(MPU9250_ADDRESS,26,0x06);


    // Configure gyroscope range
    // I2CwriteByte(MPU9250_ADDRESS,27,GYRO_FULL_SCALE_1000_DPS);
    // Configure accelerometers range
    // I2CwriteByte(MPU9250_ADDRESS,28,ACC_FULL_SCALE_4_G);
    // Set by pass mode for the magnetometers
    // I2CwriteByte(MPU9250_ADDRESS,0x37,0x02);

    // Request continuous magnetometer measurements in 16 bits
    // I2CwriteByte(MAG_ADDRESS,0x0A,0x16);

    // pinMode(13, OUTPUT);
    // Timer1.initialize(10000);         // initialize timer1, and set a 1/2 second period
    // Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt


    // Store initial time
    // ti=millis();
}


void GAM::Loop(int16_t* accel, int16_t* temp, int16_t* gyro) {
    uint8_t Buf[14];

    I2Cread(MPU9250_ADDRESS, ACCEL_ADDRESS, 14, Buf);

    accel[0] = -(Buf[0]<<8 | Buf[1]);
    accel[1] = -(Buf[2]<<8 | Buf[3]);
    accel[2] = Buf[4]<<8 | Buf[5];

    temp[2] = Buf[6]<<8 | Buf[7];

    gyro[0] = Buf[8]<<8 | Buf[9];
    gyro[1] = Buf[10]<<8 | Buf[11];
    gyro[2] = Buf[12]<<8 | Buf[13];
}