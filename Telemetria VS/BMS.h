#ifndef BATTERYMANAGEMENTSYSTEM
#define BATTERYMANAGEMENTSYSTEM
#include <mcp_can.h>
#include <SPI.cpp>
#endif
#define SENDCONFIG 0
#define REQUEST_CONFIG 0
#define CAN0_INT 2                              // Set INT to pin 2
MCP_CAN CAN0(10);                               // Set CS to pin 10

class BMS{
int NCH=8;                // [numero de celulas]
int NTH=4;                // [numero de termistores]   
int OV=3650;              // [Sobretensão - mV]
int UV=2850;              // [Subtensão - mV]
int SHORTCIRCUIT=50000;   //[corrente de curto - mA]
int OVERCURRENT=40000;    //[sobrecorrente - mA]
int OVERTEMPERATURE=45;   //[sobretemperatura - ºC]
int GAIN_I_SENSE=2083;    //[sensibilidade do sensor de corrente - uV/A]
int DVOLT=8;              //[delta de tensão de balanceamento - mV]
int LOWVOLT=3000;         //[tensão de alerta de baixa tensão mV]
int HIGHVOLT=3500;        //[tensão de alerta de alta tensão mV]
int CANCHARGEVOLT=3200;   //[não utilizado] 
int CHARGEDVOLT=3600;       //[tensão que define que bateria está carregada mV]
int OVERVOLT_HISTERESYS=4;  //[NÃO UTILIZADO]
int DELAY_HISTERESYS=60;    //[tempo maximo de balanceamento - minutos]
int BALANCE=1;              //[define se é permitido balanceamento - binario]
long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];
char msgString[128];                        // Array to store serial string
int readcan=0;
int Vpack,Current1,Current2,SoC;
    public:
        BMS();
        void can_intialize();
        //void sendConfig();
        void requestConfig();
        int *readCan();
};