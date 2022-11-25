#include <iostream>
#include <chrono>
#include <thread>
#include <queue>
#include <map>
#include "canmsg.cpp"
#include "mqqt.cpp"

using namespace std;

struct {
        string date;
        string event;
        int value;
} Relatorio;

template<typename T, typename Container = deque<T>>
void print_log(queue<T,Container> queue){
    
    cout << " Relatório : [";
    while(!queue.empty()){
        T item = queue.front();
        cout << " " << item ;
        queue.pop();
    }
    cout << "]" << std::endl;
    
}

string returnTime(){
    auto now = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(now);
  struct tm *horarioLocal=localtime(&time);
  string dia = to_string(horarioLocal->tm_mday);
  string mes = to_string(horarioLocal->tm_mon + 1);
  string ano = to_string(horarioLocal->tm_year + 1900);

  string hora = to_string(horarioLocal->tm_hour);
  string min  = to_string(horarioLocal->tm_min);
  string sec  = to_string(horarioLocal->tm_sec);

    string s={ dia + "/" + mes + "/" + ano + " " + hora + ":" + min + ":" + sec };
    return s;
}

void displayTime(){
        cout<<endl<<endl<<endl;
    auto now = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(now);
    
    cout << "Relógio: " << ctime(&end_time) << endl;
}

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

int main(int argc, char* argv[]){

	// A subscriber often wants the server to remember its messages when its
	// disconnected. In that case, it needs a unique ClientID and a
	// non-clean session.

	mqtt::async_client cli(SERVER_ADDRESS, CLIENT_ID);

	mqtt::connect_options connOpts("ggoulartm","YMCT4mVg5aUuyE6");
	connOpts.set_clean_session(false);

	// Install the callback(s) before connecting.
	callback cb(cli, connOpts);
	cli.set_callback(cb);

	// Start the connection.
	// When completed, the callback will subscribe to topic.

	try {
		std::cout << "Connecting to the MQTT server..." << std::flush;
		cli.connect(connOpts, nullptr, cb);
	}
	catch (const mqtt::exception& exc) {
		std::cerr << "\nERROR: Unable to connect to MQTT server: '"
			<< SERVER_ADDRESS << "'" << exc << std::endl;
		return 1;
	}


        queue<string> events;
        queue<int> log;
        map<string,int> logEventos;
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
    menu();
    cin>>num;
        switch(num){
        case 0: 
                //wifi connect
                cout<<"==============================//===================================="<<endl;
                cout<<endl<<endl<<endl<<endl;
                displayTime();
                        this_thread::sleep_for(10s);
                cout<<"==============================//===================================="<<endl;
                        cout<<endl<<endl<<endl<<endl<<endl;
                events.push(returnTime());
                events.push("Connect");
                break;
        case 1:
                Volt.readMsg(&Buff1, &Buff2);
                displayTime();
                        this_thread::sleep_for(10s);
                        cout<<endl<<endl<<endl<<endl<<endl;
                Volt.saveMsg();
                events.push(returnTime());
                log.push(Buff1);
                log.push(Buff2);
                events.push("Volt");
                break;
        case 2:
                Temp.readMsg(&Buff);
                displayTime();
                        this_thread::sleep_for(10s);
                        cout<<endl<<endl<<endl<<endl<<endl;
                Temp.setHistory(&Buff, 8);
                events.push(returnTime());
                log.push(Buff);
                events.push("Temp");
                break;
        case 3:
                Generic.readMsg(&Buff);
                displayTime();
                        this_thread::sleep_for(10s);
                        cout<<endl<<endl<<endl<<endl<<endl;
                Generic.setHistory(&Buff, 8);
                events.push(returnTime());
                log.push(Buff);
                events.push("Gen");
                break;
        case 4:
                print_log(log);
                print_log(events);
                break;
    }
    logEventos.insert(make_pair(events.back(),log.back()));
}

	// Just block till user tells us to quit.

	while (std::tolower(std::cin.get()) != 'q')
		;

	// Disconnect

	try {
		std::cout << "\nDisconnecting from the MQTT server..." << std::flush;
		cli.disconnect()->wait();
		std::cout << "OK" << std::endl;
	}
	catch (const mqtt::exception& exc) {
		std::cerr << exc << std::endl;
		return 1;
	}

return 0;
}