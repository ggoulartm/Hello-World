#include <BMS.h>
#include <mcp_can.h>
#include <hivemq.h>

BMS bms;
HiveMQ hivemq;

void setup() {
  delay(500);
  Serial.begin(500000);
  bms.can_intialize();
//  bms.sendConfig();
  delay(500);
  hivemq.hivemq_initialize();
}

void loop() {
  char message[]="";
  bms.requestConfig();
  int* canRead = {bms.readCan()};
  for(int* i=canRead; i<4+canRead; i++){
    message = {String(*i)};
    hivemq.clientPublish(message);
  }
}
