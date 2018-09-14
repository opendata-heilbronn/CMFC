#include <Arduino.h>
#include <Servo.h>

#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

const char* ssid = "CoworkingHN";
const char* password = "ilovecowohn";
WiFiClient client;

ESP8266WebServer server(80);

Servo servos[4];
int sensor_pin = 5;
int detectWalls = 1;

int led_millis = 0;
bool led_status = false;

void handleRoot() {
    String message = "";

    for (int i = 0; i < server.args(); i++) {
        if (server.argName(i).equals("s1")) { servos[0].write(server.arg(i).toInt()); }
        if (server.argName(i).equals("s2")) { servos[1].write(server.arg(i).toInt()); }
        if (server.argName(i).equals("s3")) { servos[2].write(server.arg(i).toInt()); }
        if (server.argName(i).equals("s4")) { servos[3].write(server.arg(i).toInt()); }
        if (server.argName(i).equals("wall")) { detectWalls = server.arg(i).toInt(); }
    } 
    server.send(200, "text/plain", message);

}

void handleNotFound(){
    String message = "File Not Found\n\n";
    message += "URI: ";
    message += server.uri();
    message += "\nMethod: ";
    message += (server.method() == HTTP_GET)?"GET":"POST";
    message += "\nArguments: ";
    message += server.args();
    message += "\n";
    for (uint8_t i=0; i<server.args(); i++){
        message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
    }
    server.send(404, "text/plain", message);
}


void setup() {
    Serial.begin(9600);
    Serial.println("");

    Wire.begin();
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/", handleRoot);
    server.onNotFound(handleNotFound);
    server.begin();


    pinMode(2, OUTPUT);

    servos[0].attach(15);
    servos[1].attach(13);
    servos[2].attach(12);
    servos[3].attach(14);

    pinMode(sensor_pin, INPUT);
}


void loop() {
    server.handleClient();

    if (detectWalls > 0 && digitalRead(sensor_pin) == 0) {
        servos[0].write(90);
        servos[1].write(90);
        servos[2].write(90);
        servos[3].write(90);
    }
}
