#include "maquinaderefri.h"

void Estado::devolver(){
    cout<<"Foi devolvido "<<saldo<<" centavos."<<endl;
    S000 state;
}

void S000::inserir(int inserido){
    switch(inserido){
        case 25:
            S025 state;
            break;    
        case 50:
            S050 state;
            break;    
        case 100:
            S100 state;
            break;
        default:
            cout << "Valor inserido não é válido >:(" << endl;
            break;
    };
}

void S025::inserir(int inserido){
    switch(inserido){
        case 25:
            S050 state;
            break;    
        case 50:
            S075 state;
            break;    
        case 100:
            S125 state;
            break;
        default:
            cout << "Valor inserido não é válido >:(" << endl;
            break;
    };
}

void S050::inserir(int inserido){
    switch(inserido){
        case 25:
            S075 state;
            break;    
        case 50:
            S100 state;
            break;    
        case 100:
            S150 state;
            break;
        default:
            cout << "Valor inserido não é válido >:(" << endl;
            break;
    };
}

void S075::inserir(int inserido){
    switch(inserido){
        case 25:
            S100 state;
            break;    
        case 50:
            S125 state;
            break;    
        case 100:
            //sobra 25
            cout << "Devolvendo 25 centavos." << endl;
            S150 state;
            break;
        default:
            cout << "Valor inserido não é válido >:(" << endl;
            break;
    };
}

void S100::inserir(int inserido){
    switch(inserido){
        case 25:
            S125 state;
            break;    
        case 50:
            S150 state;
            break;    
        case 100:
            cout << "Devolvendo 50 centavos." << endl;
            S150 state;
            break;
        default:
            cout << "Valor inserido não é válido >:(" << endl;
            break;
    };
}

void S125::inserir(int inserido){
    switch(inserido){
        case 25:
            S150 state;
            break;    
        case 50:
            cout << "Devolvendo 25 centavos." << endl;
            S150 state;
            break;    
        case 100:
            cout << "Devolvendo 75 centavos." << endl;
            S150 state;
            break;
        default:
            cout << "Valor inserido não é válido >:(" << endl;
            break;
    };
}

void S150::inserir(int inserido){
    //Devolver tudo que foi inserido
    if(inserido==25 || inserido==50 || inserido ==100){
        cout << "Devolvendo " << inserido << " centavos." << endl;
    }
    else{
        cout << "Valor inserido não é válido >:(" << endl;
    }
}