#ifndef ATIVO_HPP
#define ATIVO_HPP

#include "../include/Lista.hpp"

class Ativo {
	private:
		int par;
		Lista listaPreferencias;
		No *proxPropor;		
	public:
		Ativo();
		Ativo(int qnt, int *v);
		void mudaPar(int novoPar);
		int mudaProxPropor();
		int retornaIdProxPropor();
		void desfazPar();
		~Ativo();
};

#endif
