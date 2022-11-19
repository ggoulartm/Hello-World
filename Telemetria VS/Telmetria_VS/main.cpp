#include <iostream>
#include "canmsg.cpp"

int main(){
    CanMsg CAN(4);
    
    int Buff{};
    int Buff1{}, Buff2{};

    BMS LIFEPO4(Buff);
    print("Seja bem-vindo ao Sistema de Telemetria da Equipe Vento Sul");
    print("Assim que a conexão estiver feita, iremos começar a plotar os dados");

while(1){
    //menu
    print("Menu:");
    print("0) Conectar");
    print("1) Visualizar Dados de Tensão");
    print("2) Visualizar Dados de Temperatura");
    print("4) Visualizar Dados Genéricos");
    print("Digite o código correspondente a opção desejada:");
    unsigned char num;
    cin>>num;
    switch(num){
        case 0: 
                //wifi connect
                break;
        case 1:
                CAN.readMsg(&Buff1, &Buff2);
                BMS_Voltage Volt(Buff1, Buff2);
                break;
        case 2:
                CAN.readMsg(&Buff);
                BMS_Temperature Temp(Buff);
                break;
        case 3:
                CAN.readMsg(&Buff);
                BMS_Generic Generic(Buff);
                break;
    }
}
return 0;
}