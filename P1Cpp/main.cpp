#include <iostream>
#include <string>
#include <time.h>

using namespace std;

class DispositivoSaida {
    protected:
    long int codigo;
    string descricao;
    double preco;
    public:
        void setDescricao(string novaDescr);
        virtual void imprimir(void) = 0;
};

void DispositivoSaida::setDescricao(string novaDescr){
    descricao = novaDescr;
}

// INCLUIR AS NOVAS CLASSES AQUI!!

class DisplayLCD: public DispositivoSaida{
    public:
        DisplayLCD(long int cod, string desc){
            codigo = cod;
            cout<<"novo código: "<<codigo<<endl;
            setDescricao(desc);
            cout<<"nova descrição: ";
                cout<<desc<<endl;
        }
        DisplayLCD(){
            codigo = rand( ) % 10000;
            cout<<"novo código (aleatório): "<<codigo<<endl;
            cout<<"nova descrição: ";
                cout<<"SEM DESCRIÇÃO!!!"<<endl;
        }
        ~DisplayLCD(){
            cout<<"Destrutor: removeu "<<codigo<<endl;
        }
        void setPrice(double price){
            preco=price;
            cout<<"alterou preco de "<<descricao<<" (codigo: "<<codigo<<") para "<<price<<endl;
        }
        void imprimir(void){
            cout<<endl;
            cout<<"================================================="<<endl;
            cout<<"Dados do Produto: "<<codigo<<", "<<descricao<<','<<" R$ "<<preco<<endl;
            cout<<"================================================="<<endl<<endl;
        }
};

class Display7seg: public DispositivoSaida{
    public:
        Display7seg(long int cod, string desc){
            codigo = cod;
            cout<<"novo código: "<<cod<<endl;
            setDescricao(desc);
            cout<<"nova descrição: ";
                cout<<desc<<endl;
        }
        Display7seg(){
            codigo = rand( ) % 10000;
            cout<<"novo código (aleatório): "<<codigo<<endl;
            cout<<"nova descrição: ";
                cout<<"SEM DESCRIÇÃO!!!"<<endl;
        }
        ~Display7seg(){
            cout<<"Destrutor: removeu "<<codigo<<endl;
        }
        void setPrice(double price){
            preco=price;
            cout<<"alterou preco de "<<descricao<<" (codigo: "<<codigo<<") para "<<price<<endl;
        }
        void imprimir(void){
            cout<<endl;
            cout<<"================================================="<<endl;
            cout<<"Dados do Produto: "<<codigo<<", "<<descricao<<','<<" R$ "<<preco<<endl;
            cout<<"================================================="<<endl<<endl;
        }
};

int main(){
    srand((unsigned int)(time(NULL)));
// INCLUIR O PROGRAMA DE TESTE AQUI!!
cout<<"Mensagem gerada pelo construtor do Display LCD:"<<endl;
DisplayLCD d1_lcd;
cout<<"Mensagem gerada pelo construtor do Display LCD:"<<endl;
DisplayLCD d2_lcd;
cout<<"Mensagem gerada pelo construtor do Display LCD:"<<endl;
DisplayLCD d3_lcd(120,"Display LCD 2 linhas");
cout<<"Mensagem gerada pelo construtor do produto Display 7-seg:"<<endl;
Display7seg d1_7seg;
cout<<"Mensagem gerada pelo construtor do produto Display 7-seg:"<<endl;
Display7seg d2_7seg;

d1_lcd.setDescricao("Display LCD 1 linha");
d1_lcd.setPrice(0.8);

d2_lcd.setDescricao("Display LCD Colorido");
d2_lcd.setPrice(0.9);
cout<<endl;

DispositivoSaida* ptr= &d1_lcd;
cout<<"Mensagem gerada pela funcao imprimir na classe derivada:";

ptr->imprimir();
cout<<endl;

ptr=&d2_lcd;
cout<<"Mensagem gerada pela funcao imprimir na classe derivada:";
ptr->imprimir();
cout<<endl;

ptr=&d3_lcd;
cout<<"Mensagem gerada pela funcao imprimir na classe derivada:";
ptr->imprimir();
cout<<endl;

d1_7seg.setDescricao("Display 7-seg Vermelho ");
cout<<"Mensagem gerada pela funcao de alteracao de preco:"<<endl;
d1_7seg.setPrice(1.2);
cout<<endl;

ptr=&d1_7seg;
cout<<"Mensagem gerada pela funcao imprimir na classe derivada:";
ptr->imprimir();
}