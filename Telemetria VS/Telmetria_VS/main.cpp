#include <iostream>
#include "canmsg.cpp"

void main(){
    CanMsg CAN(4);
    
    int Buff;
    int Buff1, Buff2;

    BMS LIFEPO4(Buff);
    print("Seja bem-vindo ao Sistema de Telemetria da Equipe Vento Sul");
    print("Assim que a conexão estiver feita, iremos começar a plotar os dados");


    //menu
    print("Menu:");
    print("1) Conectar");
    print("2) Visualizar Dados de Temperatura");
    print("3) Visualizar Dados de Tensão");
    print("4) Visualizar Dados Genéricos");
    print("Digite o código correspondente a opção desejada:");
    unsigned char num;
    cin>>num;
    switch(num){
        case 1:
                BMS_Voltage(Buff1, Buff2);
                break;
        case 2:
                BMS_Temperature(Buff1, Buff2);
                break;
        case 3:
                BMS_Generic(Buff);
                break;
    }

}