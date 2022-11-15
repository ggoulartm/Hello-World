#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <time.h>
#include <TZ.h>
#include <FS.h>
#include <LittleFS.h>
#include <CertStoreBearSSL.h>


class HiveMQ{
// Update these with values suitable for your network.
const char* ssid = "Eletro_europa";
const char* password = "NoYas150632";
const char* mqtt_server = "e4d5a4758d51407596b46faed971e5e5.s2.eu.hivemq.cloud";
// A single, global CertStore which can be used by all connections.
// Needs to stay live the entire time any of the WiFiClientBearSSLs
// are present.
BearSSL::CertStore certStore;
//WiFi
WiFiClientSecure espClient;
PubSubClient * client;
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (500)
char msg[MSG_BUFFER_SIZE];
int value = 0;
    public:
    void hivemq_initialize();
    void clientPublish(String message);
};