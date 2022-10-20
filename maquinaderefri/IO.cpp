
#pragma once
#include <iostream>
#include "fsm.cpp"
using namespace std;


class FSM{
    protected:
    int saldo;
    public:
        virtual void display()=0;
        virtual void menu()=0;
        void setSaldo(int moeda){
            saldo=saldo+moeda;
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
                    break;
                case 2:
                    devolver();
                    break;
                case 3:
                    get_meets();
                    break;
                case 4:
                    get_etirps();
                    break;
                default:
                    cout<<"menu incorreto"<<endl;
                    break;
                
            }       
    }
};

// class Atlys: public FSM {
//     Atlys();
//     ~Atlys();
//     void display(){
//         //funções oled
//     }
//     void menu(){
//         //funções botões e switches
//     }
// };