#include <BMS.h>
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
  bms.requestConfig();
  int* canRead = {bms.readCan()};
  for(int* i=canRead; i<4+canRead; i++){
    //0:C1,1:C2,2:Vp,3:SoC
    hivemq.clientPublish(*i);
  }
}
