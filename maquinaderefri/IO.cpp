/*
Universidade Federal de Santa Catarina
Engenharia Eletrônica
Disciplina de Programação C++ para Sistemas Embarcados
Estudantes: Gabriel Goulart Müller e Henrique
Data: 19/10/2022

Arquivo: IO.cpp

Descrição: O objetivo desse arquivo é criar classes que façam a comunicação com 
o dispositivo no qual o sistema está embarcado
*/

#pragma once
#include <iostream>
#include "fsm.cpp"
#include "Oled.cpp"
using namespace std;

class FSM{
    protected:
    int saldo;
    public:
        virtual void display()=0;
        virtual void menu()=0;
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
    void display(){
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

class Atlys: public FSM {
     Atlys();
     ~Atlys();
     void display(){
         //funções oled
        oledInit();
        oledClear();
        printString(to_string(saldo));    
     }
     void menu(){
         //funções botões e switches
        setLine(0);
        printString("Selecione uma das opções:");
        setLine(1);
        printString("1) Inserir  2) Devolver  3) Meets  4)Etirps");
        setLine(2);
        printString("Digite o código referente a opção desejada:");
            switch(*data){    
                case 256:
                    inserir();
                    setSaldo();
                    break;
                case 512:
                    devolver();
                    setSaldo();
                    break;
                case 1024:
                    get_meets();
                    setSaldo();
                    oledClear();
                    setLine(0);
                    printString("Pegue seu refrigerante Meets!");
                    break;
                case 2048:
                    get_etirps();
                    setSaldo();
                    oledClear();
                    setLine(0);
                    printString("Pegue seu refrigerante Meets!");
                    break;
                default:
                    printString("menu incorreto");
                    break;
                
            }   
     }
};