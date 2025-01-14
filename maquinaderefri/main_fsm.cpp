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



Atlys disp1;
Linux disp2;
FSM* disp=&disp2;

int main(){
    if(OLED){
        disp=&disp1;
    }
    
    while(1){       
        disp->menu();
    }

    return 0;
}