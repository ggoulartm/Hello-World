/*
Universidade Federal de Santa Catarina
Engenharia Eletrônica
Disciplina de Programação C++ para Sistemas Embarcados
Estudantes: Gabriel Goulart Müller e Henrique
Data: 19/10/2022

Arquivo: fsm.cpp

Descrição: esse arquivo serve para implementar a máquina de estados finitos do sistema embarcado
*/


#pragma once
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
int Saldo=0;

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
        if(moeda==25){
            currentState=S025;
            cout<<"Saldo Atual R$ 0,25"<<endl;
            Saldo=25;
        }
        if(moeda==50){
            currentState=S050;
            cout<<"Saldo Atual R$ 0,50"<<endl;
            Saldo = 50;
        }
        if(moeda==100){
            currentState=S100;
            cout<<"Saldo Atual R$ 1,00"<<endl;
            Saldo = 100;
        }
        break;
    
    case S025:
        if(moeda==25){
            currentState=S050;
            cout<<"Saldo Atual R$ 0,50"<<endl;
            Saldo = 50;
        }
        if(moeda==50){
            currentState=S075;
            cout<<"Saldo Atual R$ 0,75"<<endl;
            Saldo = 75;
        }
        if(moeda==100){
            currentState=S125;
            cout<<"Saldo Atual R$ 1,25"<<endl;
            Saldo = 100;
        }
        break;
    

    case S050:
        if(moeda==25){
            currentState=S075;
            cout<<"Saldo Atual R$ 0,75"<<endl;
            Saldo = 75;
        }
        if(moeda==50){
            currentState=S100;
            cout<<"Saldo Atual R$ 1,00"<<endl;
            Saldo = 100;
        }
        if(moeda==100){
            currentState=S150;
            cout<<"Saldo Atual R$ 1,50"<<endl;
            Saldo = 150;
        }
        break;
    
    case S075:
        if(moeda==25){
            currentState=S100;
            cout<<"Saldo Atual R$ 1,00"<<endl;
            Saldo = 100;
        }
        if(moeda==50){
            currentState=S125;
            cout<<"Saldo Atual R$ 1,25"<<endl;
            Saldo = 125;
        }
        if(moeda==100){
            currentState=S150;
            cout<<"Saldo Atual R$ 1,50"<<endl;
            Saldo = 150;
        }
        break;

    case S100:
        if(moeda==25){
            currentState=S125;
            cout<<"Saldo Atual R$ 1,25"<<endl;
            Saldo = 125;
        }
        if(moeda==50 || moeda==100){
            currentState=S150;
            cout<<"Saldo Atual R$ 1,50"<<endl;
            Saldo = 150;
        }
        break;


    case S125:
        if(moeda==25 || moeda==50 || moeda==100){
            currentState=S150;
            cout<<"Saldo Atual R$ 1,50"<<endl;
            Saldo = 150;
        }
        break;


    case S150:
        if(moeda==25 || moeda==50 || moeda==100){
            currentState=S150;
            cout<<"Saldo Atual R$ 1,50"<<endl;
            Saldo = 150;
        }
        break;

    default:
        cout<<"Erro"<<endl;
        break;
    }
}

void inserir(){

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

void devolver(){
    currentState=S000;
}

void get_meets(){
    if(Saldo==150){
        cout<<"Pegue seu refrigerante Meets!"<<endl;
        Saldo=0;
    }
    else{
        cout<<"Saldo Insuficiente";
    }
}

void get_etirps(){
    if(Saldo==150){
        cout<<"Pegue seu refrigerante Etirps!"<<endl;
        Saldo=0;
    }
    else{
        cout<<"Saldo Insuficiente";
    }
}
