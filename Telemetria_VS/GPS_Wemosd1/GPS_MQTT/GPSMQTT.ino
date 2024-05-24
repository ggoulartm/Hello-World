#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <time.h>
#include <TZ.h>
#include <FS.h>
#include <LittleFS.h>
#include <CertStoreBearSSL.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

// GPS Headers
const int RX_PIN = 13, TX_PIN = 15;
const uint32_t GPS_BAUD = 9600; // Default baud of NEO-6M is 9600

TinyGPSPlus gps; // The tinyGPS object
SoftwareSerial gpsSerial(RX_PIN, TX_PIN);


/* MQTT Headers
Host: mqtt.tago.io
TCP/IP port: 1883
TCP/IP port over SSL: 8883
Username: Token
Password: <Your_Device-Token> (Replace with your actual device token)
Client ID: Can be set to any unique identifier 
*/

// Update these with values suitable for your network.
const char* ssid = "Eletro_europa";
const char* password = "NoYas150632";
const char* mqtt_server = "mqtt.tago.io";
const int mqtt_port = 1883
const char* UserMQTT = "93670e80-8aa6-4191-8977-4ad8b278711e";
const char* PasswrodMQTT = "93670e80-8aa6-4191-8977-4ad8b278711e";

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
  time_t now = time(nullptr);
  while (now < 8 * 3600 * 2) {
    delay(100);
    Serial.print(".");
    now = time(nullptr);
  }
  Serial.println();

  struct tm timeinfo;
  gmtime_r(&now, &timeinfo);
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
  // Loop until we’re reconnected
  while (!client->connected()) {
    Serial.print("Attempting MQTT connection…");
    String clientId = "ESP8266Client - MyClient";
    // Attempt to connect
    // Insert your password
    if (client->connect(clientId.c_str(), UserMQTT, PasswrodMQTT)) {
      Serial.println("connected");
      // Once connected, publish an announcement…
      client->publish("testTopic", "hello world");
      // … and resubscribe
      client->subscribe("testTopic");
    } else {
      Serial.print("failed, rc = ");
      Serial.print(client->state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

String CatchGPS() {
      if (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      double latdb = gps.location.lat();
      double longdb = gps.location.lng();
      Serial.println(latdb);
      Serial.println(longdb);
      String latStr = String(latdb,10);
      String longStr = String(longdb,10);
      String msg = "lat: "+latStr+", long: "+longStr;
      
      if (gps.location.isValid()){
        Serial.print(F("- latitude:"));
        Serial.println(gps.location.lat());

        Serial.print(F("- longitude:"));
        Serial.println(gps.location.lng());

        if (gps.altitude.isValid()) {         
           Serial.print(F("- altitude:"));
           Serial.println(gps.altitude.meters());
        }
        
        if (gps.speed.isValid()) {         
           Serial.print(F("- speed:"));
           Serial.println(gps.speed.kmph());
        }

        if (gps.date.isValid() && gps.time.isValid()){
          Serial.print(F("- GPS date&time: "));
          Serial.print(gps.date.year());
          Serial.print(F("-"));
          Serial.print(gps.date.month());
          Serial.print(F("-"));
          Serial.print(gps.date.day());
          Serial.print(F(" "));
          Serial.print(gps.time.hour());
          Serial.print(F(":"));
          Serial.print(gps.time.minute());
          Serial.print(F(":"));
          Serial.print(gps.time.second());
          Serial.print(F(":"));
        }
      }
      return msg;
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

void loop() {

    String msg = CatchGPS();

  if (!client->connected()) {
    reconnect();
  }
  client->loop();
    Serial.print("Publish message: ");
    Serial.println(msg);
    client->publish("testTopic", msg);
    
  }
}
