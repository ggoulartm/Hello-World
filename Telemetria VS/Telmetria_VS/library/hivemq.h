#ifndef HIVEMQTTBMS
#define HIVEMQTTBMS
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <time.h>
#include <TZ.h>
#include <FS.h>
#include <LittleFS.h>
#include <CertStoreBearSSL.h>
#define MSG_BUFFER_SIZE (500)
#endif

class HiveMQ{
    char msg[MSG_BUFFER_SIZE];
    int value = 0;
        public:
            void setup_wifi();
            void setDateTime();
            void callback(char* topic, byte* payload, unsigned int length);
            void reconnect();
            void hivemq_initialize();
            void clientPublish(int value);
};