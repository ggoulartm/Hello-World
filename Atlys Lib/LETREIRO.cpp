#include <iostream>
#include "controle_propaganda.cpp"
#include "fila.cpp"
#include <string>

using namespace std;

int main()
{

	int cont = 0;
	string txt;
	fila* fila_a_ser_exibida = new fila;
	int tempo = 10;

	controle_propaganda* controle = new controle_propaganda;
//
//
////	fila_a_ser_exibida = 0;

	while (txt != "5"){

		cout << "\nIndique uma funcao \n";
		cout << "1. Adicionar propaganda \n";
		cout << "2. Exibir fila \n";
		cout << "3. Voltar ou Iniciar \n";
		cout << "4. Indicar tempo \n";
		cout << "5. Sair\n";
		cin >> txt;
//
		if (txt == "1"){
			cout << "Digite a propaganda: ";
			cin >> txt;
//			
			fila_a_ser_exibida->inserir(txt);
			 cont = cont++;
		}
		if (txt == "2"){
			for (int i = 1; i <= cont; i++){
				cout << fila_a_ser_exibida->getProp() << endl;
				fila_a_ser_exibida->proximo();
			}

		}
		if (txt == "3"){
			controle->exibir(fila_a_ser_exibida, tempo);
			cont = 0;
			fila_a_ser_exibida->limpa();
		}

//
		if (txt == "4"){
			cout << "Digite o tempo: ";
			cin >> tempo;
		}
//
	}
//
//
	return 0;
}

