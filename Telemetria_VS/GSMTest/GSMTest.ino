#define TINY_GSM_MODEM_SIM800 //Tipo de modem que estamos usando
#include <TinyGsmClient.h>
#include <SPI.h>

HardwareSerial SerialGSM(1);
TinyGsm modemGSM(SerialGSM);
TinyGsmClient gsmClient(modemGSM);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setupGSM(); //Inicializa e configura o modem GSM

  //Espera 2 segundos e limpamos o display
  delay(2000);
}

void setupGSM()
{
  Serial.println("Setup GSM...");
  //Inicializamos a serial onde está o modem
  SerialGSM.begin(9600, SERIAL_8N1, 4, 2, false);
  delay(3000);

  //Mostra informação sobre o modem
  Serial.println(modemGSM.getModemInfo());

  //Inicializa o modem
  if (!modemGSM.restart())
  {
    Serial.println("Restarting GSM Modem failed");
    delay(10000);
    ESP.restart();
    return;
  }

  //Espera pela rede
  if (!modemGSM.waitForNetwork()) 
  {
    Serial.println("Failed to connect to network");
    delay(10000);
    ESP.restart();
    return;
  }

  //Conecta à rede gprs (APN, usuário, senha)
  if (!modemGSM.gprsConnect("zap.vivo.com.br", "vivo", "vivo")) {
    Serial.println("GPRS Connection Failed");
    delay(10000);
    ESP.restart();
    return;
  }

  Serial.println("Setup GSM Success");
}

void loop() {
  // put your main code here, to run repeatedly:

}
