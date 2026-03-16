#ifndef PASSIVO_HPP
#define PASSIVO_HPP


class Passivo {
	private:
		int par;
		int tam;
		int *listaPreferencias;

	public:
		Passivo(int qnt, int *v);
		void mudaPar(int novoPar);
		int analisaProposta(int id);
		int retornaPar();
		~Passivo();

};

#endif
