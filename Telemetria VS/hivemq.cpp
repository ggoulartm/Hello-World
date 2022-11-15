#include "hivemq.h"


void HiveMQ::hivemq_initialize(){
  LittleFS.begin();
  setup_wifi();
  setDateTime();
  pinMode(LED_BUILTIN, OUTPUT); // Initialize the LED_BUILTIN pin as an output
  // you can use the insecure mode, when you want to avoid the certificates
  //espclient->setInsecure();
  int numCerts = certStore.initCertStore(LittleFS, PSTR("/certs.idx"), PSTR("/certs.ar"));
  Serial.printf("Number of CA certs read: %d\n", numCerts);
  if (numCerts == 0) {
    Serial.printf("No certs found. Did you run certs-from-mozilla.py and upload the LittleFS directory before running?\n");
    return; // Can't connect to anything w/o certs!
  }
  BearSSL::WiFiClientSecure *bear = new BearSSL::WiFiClientSecure();
  // Integrate the cert store with this connection
  bear->setCertStore(&certStore);
  client = new PubSubClient(*bear);
  client->setServer(mqtt_server, 8883);
  client->setCallback(callback);
}

void HiveMQ::clientPublish(String message){
  if (!client->connected()) {
    reconnect();
  }
  client->loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
    snprintf (msg, MSG_BUFFER_SIZE, message, value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client->publish("testTopic", msg);
  }
}