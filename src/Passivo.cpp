#include "../include/Passivo.hpp"

Passivo::Passivo(int qnt, int *v) {
	par = -1;
	tam = qnt;
	listaPreferencias = new int[tam];

	for(int i = 0; i < tam; ++i) {
		listaPreferencias[v[i]] = i;
	}	
}

void Passivo::mudaPar(int novoPar) {
	par = novoPar;
}

int Passivo::analisaProposta(int id) {
	if(par == -1) {
		mudaPar(id);
		return -1;
	}
	
	if(listaPreferencias[id] < listaPreferencias[par]) {
		int antigoPar = par;
		mudaPar(id);
		return antigoPar;
	}

	return -2;
	
}

int Passivo::retornaPar() {
	return par;
}

Passivo::~Passivo() {
	delete[] listaPreferencias;
}
