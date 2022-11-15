#include <mcp_can_dfs.h>
#include <mcp_can.h>
#include <can_receive.h>
#include <hivemq.h>


String message=0;


void setup() {
  delay(500);
  Serial.begin(500000);
  Can can();
  delay(500);
  HiveMQ.hivemq_initialize();
}

void loop() {
  //CAN
  Can.requestConfig();
  int canRead[] = Can.readCan();
  for(int i: canRead){
    message = String(i);
    HiveMQ.clientPublish(message);
  }
}
