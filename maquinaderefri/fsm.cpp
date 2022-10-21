/*
Universidade Federal de Santa Catarina
Engenharia Eletrônica
Disciplina de Programação C++ para Sistemas Embarcados
Estudantes: Gabriel Goulart Müller e Henrique
Data: 19/10/2022

Arquivo: fsm.cpp

Descrição: esse arquivo serve para implementar a máquina de estados finitos do sistema embarcado
*/

#define OLED 1

#pragma once
#include <iostream>
#include <cmath>
#include "Oled.cpp"
#include "utils.cpp"
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
volatile unsigned int *btn = (volatile unsigned int *)0x80000a00;

bool event0(){
    if(moeda==25){
            char coin[]="Foi inserida uma moeda de 25 centavos";
            printGeneric(coin,2);
    }
    return event;
}
bool event1(){
    if(moeda==50){
            char coin[]="Foi inserida uma moeda de 50 centavos";
            printGeneric(coin,2);
    }
    return event;
}
bool event2(){
    if(moeda==100){
            char coin[]="Foi inserida uma moeda de 1 real";
            printGeneric(coin,2);
    }
    return event;
}

void runFSM(){
    switch (currentState){
    case S000:
        if(moeda==25){
            currentState=S025;
            char atual25[]="Saldo Atual R$ 0,25";
            printGeneric(atual25,1);
            Saldo=25;
        }
        if(moeda==50){
            currentState=S050;
            char atual50[]="Saldo Atual R$ 0,50";
            printGeneric(atual50,1);
            Saldo = 50;
        }
        if(moeda==100){
            currentState=S100;
            char atual100[]="Saldo Atual R$ 1,00";
            printGeneric(atual100,1);
            Saldo = 100;
        }
        break;
    
    case S025:
        if(moeda==25){
            currentState=S050;
            char atual50[]="Saldo Atual R$ 0,50";
            printGeneric(atual50,1);
            Saldo = 50;
        }
        if(moeda==50){
            currentState=S075;
            char atual75[]="Saldo Atual R$ 0,75";
            printGeneric(atual75,1);
            Saldo = 75;
        }
        if(moeda==100){
            currentState=S125;
            char atual125[]="Saldo Atual R$ 1,25";
            printGeneric(atual125,1);
            Saldo = 100;
        }
        break;
    

    case S050:
        if(moeda==25){
            currentState=S075;
            char atual75[]="Saldo Atual R$ 0,75";
            printGeneric(atual75,1);
            Saldo = 75;
        }
        if(moeda==50){
            currentState=S100;
            char atual100[]="Saldo Atual R$ 1,00";
            printGeneric(atual100,1);
            Saldo = 100;
        }
        if(moeda==100){
            currentState=S150;
            char atual150[]="Saldo Atual R$ 1,50";
            printGeneric(atual150,1);
            Saldo = 150;
        }
        break;
    
    case S075:
        if(moeda==25){
            currentState=S100;
            char atual100[]="Saldo Atual R$ 1,00";
            printGeneric(atual100,1);
            Saldo = 100;
        }
        if(moeda==50){
            currentState=S125;
            char atual125[]="Saldo Atual R$ 1,25";
            printGeneric(atual125,1);
            Saldo = 125;
        }
        if(moeda==100){
            currentState=S150;
            char atual150[]="Saldo Atual R$ 1,50";
            printGeneric(atual150,1);
            Saldo = 150;
        }
        break;

    case S100:
        if(moeda==25){
            currentState=S125;
            char atual125[]="Saldo Atual R$ 1,25";
            printGeneric(atual125,1);
            Saldo = 125;
        }
        if(moeda==50 || moeda==100){
            currentState=S150;
            char atual150[]="Saldo Atual R$ 1,50";
            printGeneric(atual150,1);
            Saldo = 150;
        }
        break;


    case S125:
        if(moeda==25 || moeda==50 || moeda==100){
            currentState=S150;
            char atual150[]="Saldo Atual R$ 1,50";
            printGeneric(atual150,1);
            Saldo = 150;
        }
        break;


    case S150:
        if(moeda==25 || moeda==50 || moeda==100){
            currentState=S150;
            char atual150[]="Saldo Atual R$ 1,50";
            printGeneric(atual150,1);
            Saldo = 150;
        }
        break;

    default:
        char error[]="Erro";
        printGeneric(error,1);
        break;
    }
}

void inserir(){

        cout<<"Insira uma moeda: "<<endl;
        while(!event){
            if(OLED){
                moeda=25*(*btn)/pow(2,16);
            }else{
                cin>>moeda;
            }
            
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
                char err[]="Valor Inserido Inválido";
                printGeneric(err, 1);
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
        char takeMeet[] = "Pegue seu refrigerante Meets!";
        printGeneric(takeMeet, 1);
        Saldo=0;
    }
    else{
        char saldoInsuficiente[]="Saldo Insuficiente";
        printGeneric(saldoInsuficiente,1);
    }
}

void get_etirps(){
    if(Saldo==150){
        char takeEtirp[]="Pegue seu refrigerante Etirps!";
        printGeneric(takeEtirp,1);
        Saldo=0;
    }
    else{
        char saldoInsuficiente[]="Saldo Insuficiente";
        printGeneric(saldoInsuficiente,1);
    }
}
