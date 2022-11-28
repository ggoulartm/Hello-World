#include <iostream>
#include <chrono>
#include <thread>
#include <queue>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cctype>
#include "canmsg.cpp"
#include "relatorios.cpp"

using namespace std;

void menu(){
cout<<"==============================//===================================="<<endl;
    print("Menu:");
    print("0) Conectar");
    print("1) Visualizar Dados de Tensão");
    print("2) Visualizar Dados de Temperatura");
    print("3) Visualizar Dados Genéricos");
    print("4) Imprimir log de Eventos");
    print("5) Sair");
    print("Digite o código correspondente a opção desejada:");
}

int main(){
        Relatorio eventos;
        int Buff{};
        int Buff1{}, Buff2{};
        CanMsg CAN(4);
cout<<"==============================//===================================="<<endl;
        print("Instanciação do BMS - Bateria de Lítio");
        BMS LIFEPO4(Buff);
        print("Instanciação dos Dados de Tensão");
        BMS_Voltage Volt(Buff1, Buff2);
        print("Instanciação dos Dados de Temperatura");
        BMS_Temperature Temp(Buff);
        print("Instanciação dos Dados Genéricos (Tensão do Pack, Estado de Carga e Correntes de Entrada/Saída)");
        BMS_Generic Generic(Buff);
cout<<"==============================//===================================="<<endl;
    print("Seja bem-vindo ao Sistema de Telemetria da Equipe Vento Sul");
    print("Assim que a conexão estiver feita, iremos começar a plotar os dados");
cout<<"==============================//===================================="<<endl;
int num=0;
while(num!=5){
        Date hoje(returnTime()[0]);
        menu();
        cin>>num;
        switch(num){
        case 0: 
                //wifi connect
                cout<<"==============================//===================================="<<endl;
                cout<<endl<<endl<<endl<<endl;
                displayTime();
                        this_thread::sleep_for(1s);
                cout<<"==============================//===================================="<<endl;
                        cout<<endl<<endl<<endl<<endl<<endl;
                hoje.setDate(returnTime()[1],"Connect",0);
                eventos.make(hoje);
                break;
        case 1:
                Volt.readMsg(&Buff1, &Buff2);
                displayTime();
                        this_thread::sleep_for(1s);
                        cout<<endl<<endl<<endl<<endl<<endl;
                Volt.saveMsg();
                hoje.setDate(returnTime()[1],"Volt",(Buff1+Buff2)/2);
                eventos.make(hoje);
                break;
        case 2:
                Temp.readMsg(&Buff);
                displayTime();
                        this_thread::sleep_for(1s);
                        cout<<endl<<endl<<endl<<endl<<endl;
                Temp.setHistory(&Buff, 8);
                hoje.setDate(returnTime()[1],"Temp",Buff);
                eventos.make(hoje);
                break;
        case 3:
                Generic.readMsg(&Buff);
                displayTime();
                        this_thread::sleep_for(1s);
                        cout<<endl<<endl<<endl<<endl<<endl;
                Generic.setHistory(&Buff, 8);
                hoje.setDate(returnTime()[1],"Generic",Buff);
                eventos.make(hoje);
                break;
        case 4:
                eventos.display();
                break;
    }
}       

return 0;
}