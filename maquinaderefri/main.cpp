#include "maquinaderefri.cpp"

int main()
{
    S000 state;
    while(1){
    unsigned char menu;   
    cout<<"Selecione uma das opções"<<endl;
    cout<<"1) Inserir"<<endl<<"2) Devolver"<<endl<<"3) Meets"<<endl<<"4)Etirps"<<endl;
    cin>>menu;
        switch(menu){    
            case 1:
                int inserido;
                cin >> inserido;
                state.inserir(inserido);
                break;
            default:
                cout<<"menu incorreto";
                break;
            
        }
        
    }
    
    
    
    
    return 0;
}
