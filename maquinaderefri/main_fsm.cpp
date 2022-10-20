/*
Universidade Federal de Santa Catarina
Engenharia Eletrônica
Disciplina de Programação C++ para Sistemas Embarcados
Estudantes: Gabriel Goulart Müller e Henrique
Data: 19/10/2022

Arquivo: main_fsm.cpp

Descrição: Sistema embarcado para máquina de refrigerante, o programar deve funcionar 
nas plataformas Linux e Atlys
*/


#include "IO.cpp"
#include <iostream>
using namespace std;
#define OLED 1

if(!OLED){
    Linux disp;
}else{
    Atlys disp;
}

int main(){
    while(1){       
        disp.display();
        disp.menu();
    }

    return 0;
}