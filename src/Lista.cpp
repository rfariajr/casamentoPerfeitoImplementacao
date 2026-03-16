#include "../include/Lista.hpp"

Lista::Lista() {
	tam = 0;
	inicio = nullptr;
	fim = nullptr;
}

void Lista::insereFim(int d) {
	No* novoNo = new No(d);
	if(inicio == nullptr) {
		inicio = novoNo;
		fim = novoNo;
	}
	else {
		fim->prox = novoNo;
		fim = novoNo;
	}
	++tam;
}

No* Lista::retornaInicio() {
	return inicio;
}

void Lista::removeInicio() {
	if(inicio == nullptr) return;
	
	No* aux = inicio;

	if(inicio == fim) {
		inicio = nullptr;
		fim = nullptr;
	}
	else {
		inicio = inicio->prox;
	}

	delete aux;	
	--tam;
}

int Lista::retornaTam() {
	return tam;
}

Lista::~Lista() {
	No* atual = inicio;
	No* aux = inicio;
	while(atual != nullptr) {
		aux = aux->prox;
		delete atual;
		atual = aux;
	}
	tam = 0;
	inicio = nullptr;
	fim = nullptr;
}
