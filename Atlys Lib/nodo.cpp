#include "nodo.h"

nodo::nodo(std::string txt, nodo* prox)
{
	texto = txt;
	proximo = prox;
}
nodo* nodo::getProx(){
	return proximo;
}
std::string nodo::getTxt(){
	return texto;
}

void nodo::setNxt(nodo* prox){
	proximo = prox;
}

void nodo::setTxt(std::string txt){
	texto = txt;
}

//nodo::~nodo(){}
