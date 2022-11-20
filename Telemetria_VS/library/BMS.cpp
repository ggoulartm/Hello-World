#ifndef BATTERYMANAGEMENTSYSTEM
#define BATTERYMANAGEMENTSYSTEM
#include <mcp_can.h>
#endif
#include "BMS.h"

extern MCP_CAN CANBMS(10);                               // Set CS to pin 10

BMS::BMS(){
    can_intialize();
    //sendConfig();
}

void BMS::can_intialize(void){
    // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
    if(CANBMS.begin(MCP_ANY, CAN_125KBPS, MCP_8MHZ) == CAN_OK)
    Serial.println("MCP2515 Initialized Successfully!");
    else Serial.println("Error Initializing MCP2515...");
    CANBMS.setMode(MCP_NORMAL);                     // Set operation mode to normal so the MCP2515 sends acks to received data.
    pinMode(CAN0_INT, INPUT);                            // Configuring pin for /INT input
    Serial.println("MCP2515 Library Receive Example...");
    delay(3000);
}

/*
void BMS::sendConfig(void){
    if(SENDCONFIG){
        //**************ENVIO DE CONFIG1***********
        byte data[8] = {0x00, 0x01, 0x02, 0xFF, 0x04, 0x05, 0x06, 0x07};
        data[0]=0xFF&NCH;
        data[1]=NCH>>8;
        data[2]=0xFF&NTH;
        data[3]=NTH>>8;
        data[4]=0xFF&OV;
        data[5]=OV>>8;
        data[6]=0xFF&UV;
        data[7]=UV>>8;
        //send data:  ID = 0x10000000, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
        byte sndStat = CAN0.sendMsgBuf(0x10000000, 1, 8, data);
       Serial.println("Envio configuracao 1");
        //*****************************************************
        delay(3000);
        data[0]=0xFF&SHORTCIRCUIT;
        data[1]=SHORTCIRCUIT>>8;
        data[2]=0xFF&OVERCURRENT;
        data[3]=OVERCURRENT>>8;
        data[4]=0xFF&OVERTEMPERATURE;
        data[5]=OVERTEMPERATURE>>8;
        data[6]=0xFF&GAIN_I_SENSE;
        data[7]=GAIN_I_SENSE>>8;
        //send data:  ID = 0x10000001, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
        sndStat = CAN0.sendMsgBuf(0x10000001, 1, 8, data);
        Serial.println("Envio configuracao 2");
        //*****************************************************
        delay(3000);
        data[0]=0xFF&DVOLT;
        data[1]=DVOLT>>8;
        data[2]=0xFF&LOWVOLT;
        data[3]=LOWVOLT>>8;
        data[4]=0xFF&HIGHVOLT;
        data[5]=HIGHVOLT>>8;
        data[6]=0xFF&CANCHARGEVOLT;
        data[7]=CANCHARGEVOLT>>8;
   
        sndStat = CAN0.sendMsgBuf(0x10000002, 1, 8, data);
        Serial.println("Envio configuracao 3");
        //*****************************************************
        
         delay(3000);
        data[0]=0xFF&CHARGEDVOLT;
        data[1]=CHARGEDVOLT>>8;
        data[2]=0xFF&OVERVOLT_HISTERESYS;
        data[3]=OVERVOLT_HISTERESYS>>8;
        data[4]=0xFF&DELAY_HISTERESYS;
        data[5]=DELAY_HISTERESYS>>8;
        data[6]=0xFF&BALANCE;
        data[7]=BALANCE>>8;

        sndStat = CAN0.sendMsgBuf(0x10000003, 1, 8, data);
        Serial.println("Envio configuracao 4");
        //*****************************************************
  }//sendconfig
}//sendConfig()
*/

int count=0;

void BMS::requestConfig(void){
    if(REQUEST_CONFIG){
    count++;
        if(count>=60)
        {
        byte data[8] = {0x00, 0x01, 0x02, 0xFF, 0x04, 0x05, 0x06, 0x07};
        byte sndStat = CANBMS.sendMsgBuf(0x11000000, 1, 8, data);
        if(sndStat == CAN_OK)
        {
            Serial.println("Message Sent Successfully!");
            } else 
            {
            Serial.println("Error Sending Message...");
            }
            count=0;
        }
    }
}

int* BMS::readCan(){
    int canRead[4]={};
    //*****************************************************
    if(readcan>=16){
        canRead[0]=Current1;
        canRead[1]=Current1;
        canRead[2]=Vpack;
        canRead[3]=SoC;
        char j=1;
        readcan=0;
    }

    while(!digitalRead(CAN0_INT)){
        readcan++;
        CANBMS.readMsgBuf(&rxId, &len, rxBuf);      // Read data: len = data length, buf = data byte(s)
            if((rxId & 0x1FFFFFFF)==0x186555F4){   
                Vpack= (int)rxBuf[0]|((int)rxBuf[1]<<8);   
                Current1= (int)rxBuf[2]|((int)rxBuf[3]<<8);
                Current2= (int)rxBuf[4]|((int)rxBuf[5]<<8);
                SoC= (int)rxBuf[6]|((int)rxBuf[7]<<8);
            }
    }

return canRead;
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/