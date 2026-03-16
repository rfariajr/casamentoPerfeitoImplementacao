#include "../include/Ativo.hpp"

Ativo::Ativo() : listaPreferencias() {
	par = -1;
	proxPropor = nullptr;
}

Ativo::Ativo(int qnt, int *v) : listaPreferencias() {
	par = -1;
	for(int i = 0; i < qnt; ++i) {
		listaPreferencias.insereFim(v[i]);
	}
	proxPropor = listaPreferencias.retornaInicio();
}

void Ativo::mudaPar(int novoPar) {
	par = novoPar;
}

int Ativo::mudaProxPropor() {
	if(proxPropor != nullptr) {
		proxPropor = proxPropor->prox;
		return 0;
	}
	return  1;
}

int Ativo::retornaIdProxPropor() {
	return proxPropor->dado;
}

void Ativo::desfazPar() {
	par = -1;
}

Ativo::~Ativo() {

}
