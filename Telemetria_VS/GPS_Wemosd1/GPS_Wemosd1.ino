#include <TinyGPS++.h>
#include <SoftwareSerial.h>

const int RX_PIN = 13, TX_PIN = 15;
const uint32_t GPS_BAUD = 9600; // Default baud of NEO-6M is 9600

TinyGPSPlus gps; // The tinyGPS object
SoftwareSerial gpsSerial(RX_PIN, TX_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  gpsSerial.begin(GPS_BAUD);

  Serial.println(F("ESP8266 - GPS Module"));
}

void loop() {
  // put your main code here, to run repeatedly:
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
      else {
        Serial.println("Loading");
      }

      
      delay(5000);
  }  
    }
    

  if (millis() > 30000 && gps.charsProcessed() < 10) {
    Serial.println(F("No GPS data received: check wiring"));
  }
}
