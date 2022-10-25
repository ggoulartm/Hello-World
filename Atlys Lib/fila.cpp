#include "fila.h"


fila::fila()
{
	primeiro = 0;
	ultimo = 0;
}


//fila::~fila() // Apaga um por um os elementos
//{
//	nodo* cursor = primeiro;
//	while (primeiro){
//		cursor = cursor->getProx();
//		delete primeiro;
//		primeiro = cursor;
//	}
//	cursor = ultimo;
//	while (ultimo){
//		cursor = cursor->getProx();
//		delete ultimo;
//		ultimo = cursor;
//	}
//	ultimo = 0;
//	primeiro = 0;
//}

void fila::inserir(std::string prop) {
	if (primeiro == 0){
		primeiro = new nodo(prop, 0);
		ultimo = primeiro;
		ultimo->setNxt(primeiro);
		primeiro->setNxt(ultimo);
	}
	else
	{
		
		nodo * aux;
		aux = new nodo(prop, primeiro);
		ultimo->setNxt(aux);
		ultimo = aux;
	}
}
void fila::retirar(){
	if (primeiro != 0){
		primeiro = primeiro->getProx();
		ultimo->setNxt(primeiro);
	}

}

void fila::proximo(){
	ultimo = primeiro;
	primeiro = primeiro->getProx();
	
}

std::string fila::getProp(){
	return primeiro->getTxt();
}

void fila::juntar(fila* nova){
	if (primeiro == 0){
		ultimo = nova->ultimo;
		primeiro = nova->primeiro;
	} 
	else{
		ultimo->setNxt(nova->primeiro);
		nova->ultimo->setNxt(primeiro);
		ultimo = nova->ultimo;
	}
}

void fila::limpa(){
	primeiro = 0;
	ultimo = 0;
}
