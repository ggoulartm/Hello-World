#include <iostream>
#include <chrono>
#include <thread>
#include "canmsg.cpp"

using namespace std;

void displayTime(){
        cout<<endl<<endl<<endl;
    auto now = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(now);
 
    cout << "Relógio: " << ctime(&end_time) << endl;
}

int main(){
    CanMsg CAN(4);
    
    int Buff{};
    int Buff1{}, Buff2{};

        BMS LIFEPO4(Buff);
        BMS_Voltage Volt(Buff1, Buff2);
        BMS_Temperature Temp(Buff);
        BMS_Generic Generic(Buff);

    print("Seja bem-vindo ao Sistema de Telemetria da Equipe Vento Sul");
    print("Assim que a conexão estiver feita, iremos começar a plotar os dados");

while(1){
    //menu
    print("Menu:");
    print("0) Conectar");
    print("1) Visualizar Dados de Tensão");
    print("2) Visualizar Dados de Temperatura");
    print("3) Visualizar Dados Genéricos");
    print("Digite o código correspondente a opção desejada:");
    int num;
    cin>>num;
    switch(num){
        case 0: 
                //wifi connect
                cout<<endl<<endl<<endl;
                displayTime();
                        this_thread::sleep_for(10s);
                        cout<<endl<<endl<<endl<<endl<<endl;
                break;
        case 1:
                Volt.readMsg(&Buff1, &Buff2);
                displayTime();
                        this_thread::sleep_for(10s);
                        cout<<endl<<endl<<endl<<endl<<endl;
                Volt.saveMsg();
                break;
        case 2:
                Temp.readMsg(&Buff);
                displayTime();
                        this_thread::sleep_for(10s);
                        cout<<endl<<endl<<endl<<endl<<endl;
                Temp.setHistory(&Buff, 8);
                break;
        case 3:
                Generic.readMsg(&Buff);
                displayTime();
                        this_thread::sleep_for(10s);
                        cout<<endl<<endl<<endl<<endl<<endl;
                Generic.setHistory(&Buff, 8);
                break;
    }
}
return 0;
}