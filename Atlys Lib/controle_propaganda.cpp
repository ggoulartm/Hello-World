#include "controle_propaganda.h"
#include <stdlib.h>  //para numeros aleatorios
using namespace std;



void controle_propaganda::exibir(fila * prop, int t){
	string var;
	time_t start;
	OLED_driver tela;
	int rando;
	srand(time(NULL));
	char buffer[20];
//	if (fila_em_exibicao == 0){
//		fila_em_exibicao = prop;
//	}
//	else {
		fila_em_exibicao->juntar(prop);
		tela.liga();

		//ver hora
		time_t rawtime;
		struct tm * timeinfo;
		

		cout << "EM OPERACAO" << endl;

//	while (tela.atualiza() == 0){
		while (tela.atualiza()){


			time(&rawtime);
			timeinfo = localtime(&rawtime);

			var = asctime(timeinfo);
			var = var.substr(10, 10);
		    tela.apagar_tela();
			rando = rand() % 4;
			if (rando == 1){
				tela.mostra(var);
			}
			else { tela.mostra(fila_em_exibicao->getProp());  }
			
			clock_t tempo = clock();
			while (clock() < tempo + (t*1000000)){}
					if (tela.apaga() == 1){
						cout << "Apagar? (s/n)" << endl;
						cin >> var;
						if (var == "s"){ fila_em_exibicao->retirar(); }
					}
					fila_em_exibicao->proximo();
		}
		tela.apagar_tela();

//		tela.mostra(fila_em_exibicao->getProp());
//while (val > difftime(time(NULL),start)){
//		}
	
		

//		tela.apagar_tela();
	
}




controle_propaganda::controle_propaganda()
{
	//fila_a_ser_exibida = new fila();
	//fila_a_ser_exibida = 0;
	fila_em_exibicao = new fila();
//	fila_em_exibicao = 0;

}


controle_propaganda::~controle_propaganda()
{
	//delete fila_a_ser_exibida;
	//delete fila_em_exibicao;
}
