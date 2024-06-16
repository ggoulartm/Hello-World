#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <time.h>
#include <TZ.h>
#include <FS.h>
#include <LittleFS.h>
#include <CertStoreBearSSL.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

// GPS Headers
const int RX_PIN = 4, TX_PIN = 3;
const uint32_t GPS_BAUD = 9600; // Default baud of NEO-6M is 9600

// GPS Data
double llat,llng;
time_t Now;

TinyGPSPlus gps; // The tinyGPS object
SoftwareSerial gpsSerial(RX_PIN, TX_PIN);


// Update these with values suitable for your network.
const char* ssid = "Eletro_europa";
const char* password = "NoYas150632";
const char* mqtt_server = "ClusterLink.cloud/mqtt";
const int mqtt_port = 8883;
const char* UserMQTT = "YourUser";
const char* PasswrodMQTT = "YourPassword";

// A single, global CertStore which can be used by all connections.
// Needs to stay live the entire time any of the WiFiClientBearSSLs
// are present.
BearSSL::CertStore certStore;

WiFiClientSecure espClient;
PubSubClient * client;
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (500)
char msg[MSG_BUFFER_SIZE];
int value = 0;

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void setDateTime() {
  // You can use your own timezone, but the exact time is not used at all.
  // Only the date is needed for validating the certificates.
  configTime(TZ_Europe_Berlin, "pool.ntp.org", "time.nist.gov");

  Serial.print("Waiting for NTP time sync: ");
  time_t nowe = time(nullptr);
  while (nowe < 8 * 3600 * 2) {
    delay(100);
    Serial.print(".");
    nowe = time(nullptr);
  }
  Serial.println();

  struct tm timeinfo;
  gmtime_r(&nowe, &timeinfo);
  Serial.printf("%s %s", tzname[0], asctime(&timeinfo));
}


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if the first character is present
  if ((char)payload[0] != NULL) {
    digitalWrite(LED_BUILTIN, LOW); // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is active low on the ESP-01)
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH); // Turn the LED off by making the voltage HIGH
  } else {
    digitalWrite(LED_BUILTIN, HIGH); // Turn the LED off by making the voltage HIGH
  }
}


void reconnect() {
  while (!client->connected()) {
    Serial.print("Attempting MQTT connection…");
    String clientId = "8a98b30641db4c189db544da86fc63e0";
    // Attempt to connect
    // Insert your password
    if (client->connect(clientId.c_str(), UserMQTT, PasswrodMQTT)) {
      Serial.println("connected");
      // Once connected, publish an announcement…
      client->publish("test", "ACRDA");
      // … and resubscribe
      client->subscribe("RemoteServer");
    } else {
      Serial.print("failed, rc = ");
      Serial.print(client->state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void setup() {
  delay(500);
  // When opening the Serial Monitor, select 9600 Baud
  Serial.begin(9600);
   //GPS Begin
    gpsSerial.begin(GPS_BAUD);

  delay(500);

  LittleFS.begin();
  setup_wifi();
  setDateTime(); // SET DATE AND TIME FROM NTP SERVER

  pinMode(LED_BUILTIN, OUTPUT); // Initialize the LED_BUILTIN pin as an output

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
  client->setServer(mqtt_server, mqtt_port);
  client->setCallback(callback);
  Serial.println("MQTT Server Started Successfully");
  Now=millis();
}

void loop() {
  if (!client->connected()) {
        Serial.println("Connecting to MQTT Server");
        reconnect();
  }
  client->loop();

  
  while (gpsSerial.available() > 0) {
   char gpsData = gpsSerial.read();
   gps.encode(gpsData); 
   delay(1);
  }
  
  if (millis() > 5000 && gps.charsProcessed() < 10) {
        Serial.println(F("No GPS data received"));
        char msg[100];
        snprintf(msg,100,"No data from GPS"); 
        client->publish("Problem", msg); 
  }

  JsonDocument JSONencode;
  
    char latitude[14];
    snprintf(latitude, 14, "%.10f",gps.location.lat());
    
    char longitude[14];
    snprintf(longitude, 14, "%.10f",gps.location.lng());
  
  JSONencode["variable"]="location";
  JSONencode["value"]="VentoSulDevice";
  JSONencode["location"]["type"]="Point";
  JSONencode["location"]["coordinates"][0]=longitude;
  JSONencode["location"]["coordinates"][1]=latitude;

  String JSONmessageBuffer;
  serializeJson(JSONencode,JSONmessageBuffer);
   Serial.println(JSONmessageBuffer);
  
  if (gps.location.isValid() && llat != gps.location.lat() && llng != gps.location.lng()) {
    Serial.println("Publishing message");
    char Buffer[250];
    JSONmessageBuffer.toCharArray(Buffer,250);
    client->publish("GPS_Topic", Buffer); 
    
    llat=gps.location.lat();
    llng=gps.location.lng();
    Now=millis();
  }

  
    digitalWrite(LED_BUILTIN, HIGH);// Turn the LED off by making the voltage HIGH
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW); 
}
