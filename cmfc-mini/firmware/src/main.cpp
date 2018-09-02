#include <Arduino.h>

#include "Movement.h"
#include "WebSocket.h"
#include "GAM.h"

#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>


#define LEDPIN      2

// const char* ssid = "leonie";
const char* ssid = "CoworkingHN";
const char* password = "ilovecowohn";

Movement movement;
WebSocket socket;
GAM gyro;

WiFiClient client;

void blink(int count, int del) {
    pinMode(LEDPIN, OUTPUT);

    for (int i = 0; i < count; i++) {
        digitalWrite(LEDPIN, LOW);
        delay(del);
        digitalWrite(LEDPIN, HIGH);
        delay(del);
    }
}

void setup() {
    Serial.begin(9600);
    blink(10, 100);
    
    // setup WLAN
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        blink(1, 500);
        Serial.printf("\nWiFi connected.\nIP address:");
        Serial.println(WiFi.localIP());
    }


    blink(10, 100);

    gyro.I2Cscan();

    socket.Setup(client);
    // movement.Setup();
    gyro.Setup();

    blink(2, 500);
}


void loop() {
    static uint32_t prev_ms = millis();

    while (WiFi.status() != WL_CONNECTED) {
        blink(1, 500);
    }

    //server.handleClient();

    socket.Loop();
    //movement.Loop();


    if (millis() > 1000 + prev_ms) {
        prev_ms = millis();

        
        int16_t values_accel[3];
        int16_t values_temp[1];
        int16_t values_gyro[3];

        gyro.Loop(values_accel, values_temp, values_gyro);

        String message = String("accel_x:") + String(values_accel[0], DEC) + String(";accel_y:") + String(values_accel[1], DEC) + String(";accel_z:") + String(values_accel[2], DEC);
        char msg[message.length()];
        message.toCharArray(msg, message.length());
        socket.Message(msg);

    }

}
