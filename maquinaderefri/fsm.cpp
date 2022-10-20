#pragma
#include <iostream>
using namespace std;

typedef enum{
    S000,
    S025,
    S050,
    S075,
    S100,
    S125,
    S150,
} stateNames;

stateNames currentState=S000;

bool event=false;
int moeda=0;

bool event0(){
    if(moeda==25){
        cout<<"Foi inserida uma moeda de 25 centavos"<<endl;
    }
    return event;
}
bool event1(){
    if(moeda==50){
        cout<<"Foi inserida uma moeda de 50 centavos"<<endl;
    }
    return event;
}
bool event2(){
    if(moeda==100){
        cout<<"Foi inserida uma moeda de 50 centavos"<<endl;
    }
    return event;
}

void runFSM(){
    switch (currentState){
    case S000:
        cout<<"Saldo Atual R$ 0,00"<<endl;
        if(moeda==25){
            currentState=S025;
            cout<<"Saldo Atual R$ 0,25"<<endl;
        }
        if(moeda==50){
            currentState=S050;
            cout<<"Saldo Atual R$ 0,50"<<endl;
        }
        if(moeda==100){
            currentState=S100;
            cout<<"Saldo Atual R$ 1,00"<<endl;
        }
        break;
    
    case S025:
        cout<<"Saldo Atual R$ 0,25"<<endl;
        if(moeda==25){
            currentState=S050;
            cout<<"Saldo Atual R$ 0,50"<<endl;
        }
        if(moeda==50){
            currentState=S075;
            cout<<"Saldo Atual R$ 0,75"<<endl;
        }
        if(moeda==100){
            currentState=S125;
            cout<<"Saldo Atual R$ 1,25"<<endl;
        }
        break;
    

    case S050:
        cout<<"Saldo Atual R$ 0,50"<<endl;
        if(moeda==25){
            currentState=S075;
            cout<<"Saldo Atual R$ 0,75"<<endl;
        }
        if(moeda==50){
            currentState=S100;
            cout<<"Saldo Atual R$ 1,00"<<endl;
        }
        if(moeda==100){
            currentState=S150;
            cout<<"Saldo Atual R$ 1,50"<<endl;
        }
        break;
    
    case S075:
        cout<<"Saldo Atual R$ 0,75"<<endl;
        if(moeda==25){
            currentState=S100;
            cout<<"Saldo Atual R$ 1,00"<<endl;
        }
        if(moeda==50){
            currentState=S125;
            cout<<"Saldo Atual R$ 1,25"<<endl;
        }
        if(moeda==100){
            currentState=S150;
            cout<<"Saldo Atual R$ 1,50"<<endl;
        }
        break;

    case S100:
        cout<<"Saldo Atual R$ 1,00"<<endl;
        if(moeda==25){
            currentState=S125;
            cout<<"Saldo Atual R$ 1,25"<<endl;
        }
        if(moeda==50 || moeda==100){
            currentState=S150;
            cout<<"Saldo Atual R$ 1,50"<<endl;
        }
        break;


    case S125:
        cout<<"Saldo Atual R$ 1,25"<<endl;
        if(moeda==25 || moeda==50 || moeda==100){
            currentState=S150;
            cout<<"Saldo Atual R$ 1,50"<<endl;
        }
        break;


    case S150:
        cout<<"Saldo Atual R$ 1,50"<<endl;
        if(moeda==25 || moeda==50 || moeda==100){
            currentState=S150;
            cout<<"Saldo Atual R$ 1,50"<<endl;
        }
        break;

    default:
        cout<<"Erro"<<endl;
        break;
    }
}

int main(){
    while(1){
        cout<<"Insira uma moeda: "<<endl;
        while(!event){
            cin>>moeda;
            if(moeda==25){
                event=true;
                event0();
            }
            else if(moeda==50){
                event=true;
                event0();
            }
            else if(moeda==100){
                event=true;
                event0();
            }
            else{
                cout<<"Valor Inserido Inválido"<<endl;
            }
        }
        runFSM();
        moeda=0;
        event=false;
        cout<<currentState;
    }
}