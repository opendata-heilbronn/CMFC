#include <Arduino.h>
#include <ESP8266WiFi.h>

class WebSocket {
    public:
        void Setup(WiFiClient client);
        void Loop();
        void Message(String msg);
        void Send(char *event, char *payload);
};