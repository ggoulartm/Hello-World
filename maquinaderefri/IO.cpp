/*
Universidade Federal de Santa Catarina
Engenharia Eletrônica
Disciplina de Programação C++ para Sistemas Embarcados
Estudantes: Gabriel Goulart Müller e Henrique
Data: 19/10/2022w

Arquivo: IO.cpp

Descrição: O objetivo desse arquivo é criar classes que façam a comunicação com 
o dispositivo no qual o sistema está embarcado
*/

#pragma once
#include <iostream>
#include <vector>
#include "fsm.cpp"
#include "Oled.cpp"
using namespace std;

#ifdef OLED
volatile unsigned int *button = (volatile unsigned int *)0x80000a00;
#endif

class FSM{
    protected:
    int saldo;
    public:
        virtual void menu()=0;
        virtual void display(char* credito)=0;
        void setSaldo(){
            saldo=Saldo;
        }
};

class Linux: public FSM {
    public:
    Linux(){
        cout<<"Iniciando Sistema"<<endl;
    }
    ~Linux(){
        cout<<endl<<endl<<endl<<endl;
        cout<<"Finalizando Sistema";
    }
    void display(char* credito){
        saldo=saldo+*credito;
        cout<<"Saldo"<<saldo<<endl;
    }
    void menu(){
        int menu;   
        cout<<"Selecione uma das opções:"<<endl;
        cout<<"1) Inserir"<<endl<<"2) Devolver"<<endl<<"3) Meets"<<endl<<"4)Etirps"<<endl;
        cout<<"Digite o código referente a opção desejada:";
        cin>>menu;
            switch(menu){    
                case 1:
                    inserir();
                    setSaldo();
                    break;
                case 2:
                    devolver();
                    setSaldo();
                    break;
                case 3:
                    get_meets();
                    setSaldo();
                    break;
                case 4:
                    get_etirps();
                    setSaldo();
                    break;
                default:
                    cout<<"menu incorreto"<<endl;
                    break;
                
            }       
    }
};

    char s1[] = "R$ 0,00";
    char s2[] = "R$ 0,25";
    char s3[] = "R$ 0,50";
    char s4[] = "R$ 0,75";
    char s5[] = "R$ 1,00";
    char s6[] =  "R$ 1,25";
    char s7[] =  "R$ 1,50";
    char takeMeets[]={"Pegue seu refrigerante Meets!"};
    char takeEtirps[] = "Pegue seu refrigerante Etirps!";
class Atlys: public FSM {
    public:
     void display(char* credito){
         //funções oled
        oledInit();
        oledClear();
        printString(credito);    
     }
     void callDisplay(){
        switch (saldo){
            case 150:
                display(s7);
                break;
            case 125:
                display(s6);
                break;
            case 100:
                display(s5);
                break;
            case 75:
                display(s4);
                break;
            case 50:
                display(s3);
                break;
            case 25:
                display(s2);
                break;
            default:
                display(s1);
                break;
        }
     }
     void menu(){
        callDisplay();
        delay(500000);
         //funções botões e switches
        setLine(0);
        char op[] = "Selecione uma das opções:";
        printString(op);
        setLine(1);
        char idme[] = "1) Inserir  2) Devolver  3) Meets  4)Etirps";
        printString(idme);
        setLine(2);
        char cod[] = "Mova o Switch referente a opção desejada";
        printString(cod);
	    while(*button == 822083584){};
            switch(*button){    
                case 822083840:
                    inserir();
                    setSaldo();
                    callDisplay();
                    break;
                case 822084096:
                    devolver();
                    setSaldo();
                    callDisplay();
                    break;
                case 822084608:
                    get_meets();
                    setSaldo();
                    oledClear();
                    setLine(0);
                    printString(takeMeets);
                    break;
                case 822085632:
                    get_etirps();
                    setSaldo();
                    oledClear();
                    setLine(0);
                    printString(takeEtirps);
                    break;
                default:
		    oledClear();
		    cout << "Current value of gpio lines: 0x" << *button << std::endl;
                    char menuErr[] = "menu incorreto"; 
                    printString(menuErr);
                    break;
            }   
     }
};
