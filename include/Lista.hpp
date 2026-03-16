#ifndef LISTA_HPP
#define LISTA_HPP

struct No {
	int dado;
	No *prox;
	
	No(int dado) {
		this->dado = dado;
		prox = nullptr;
	}
};

class Lista {
	private:
		int tam;
		No* inicio;
		No* fim;

	public:
		Lista();
		void insereFim(int d);
		No* retornaInicio();
		void removeInicio();
		int retornaTam();
		~Lista();

};

#endif
