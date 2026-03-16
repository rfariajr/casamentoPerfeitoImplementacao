#include <chrono>
#include <iostream>

#include "../include/Ativo.hpp"
#include "../include/Passivo.hpp"

int main() {
  //Inicializando variáveis para calcular o tempo de execução
  std::chrono::time_point<std::chrono::high_resolution_clock> inicio, fim;
  std::chrono::duration<float> duracao;
  inicio = std::chrono::high_resolution_clock::now();
  
  //Quantidades de agentes
  int qnt = 0;
  std::cin >> qnt;

  //Cria os vetores de armazenamento das estruturas
  Ativo** vetorAtivos = new Ativo*[qnt];
  Passivo** vetorPassivos = new Passivo*[qnt];

  //Cria a lista de execução
  Lista listaAtivos;

  //Cria vetor que armazena os dados de entrada
  int vetorAux[qnt];

  //Loop que preenche o vetor de Ativos
  for(int i = 0; i < qnt; ++i) {
  	for(int j = 0; j < qnt; ++j) {
		std::cin >> vetorAux[j];
	}
	vetorAtivos[i] = new Ativo(qnt, vetorAux);
	listaAtivos.insereFim(i);
  }

  //Loop que preeche o vetor de Passivos
  for(int i = 0; i < qnt; ++i) {
  	for(int j = 0; j < qnt; ++j) {
		std::cin >> vetorAux[j];
	}
	vetorPassivos[i] = new Passivo(qnt, vetorAux);
  }

  //Loop principal
  while(listaAtivos.retornaTam() != 0) {
	int idAtivoAtual = listaAtivos.retornaInicio()->dado;
	int parFormado = 0;
	while(!parFormado) {
		int idPassivoAtual = vetorAtivos[idAtivoAtual]->retornaIdProxPropor();
		int resultado = vetorPassivos[idPassivoAtual]->analisaProposta(idAtivoAtual);
		if(resultado == -1) {
			parFormado = 1;
			//Muda par no vetorAtivos[idAtivoAtual]
			vetorAtivos[idAtivoAtual]->mudaPar(idPassivoAtual);
			std::cout << "Par formado entre Ativo " << idAtivoAtual << " e Passivo " << idPassivoAtual << std::endl;
		}

		else if(resultado != -2) {
			parFormado = 1;
			//Desfaz o par no vetorAtivos[resultado]
			vetorAtivos[resultado]->desfazPar();
			std::cout << "Par desfeito entre Ativo " << resultado << " e Passivo " << idPassivoAtual << std::endl; 
			//Muda par no vetorAtivos[idAtivoAtual]
			vetorAtivos[idAtivoAtual]->mudaPar(idPassivoAtual);
			std::cout << "Par formado entre Ativo " << idAtivoAtual << " e Passivo " << idPassivoAtual << std::endl;
			//Colocar o vetorAtivos[resultado] no fim da fila
			listaAtivos.insereFim(resultado);
		}
		
		else {			
			std::cout << "Ativo " << idAtivoAtual << " é rejeitado por Passivo " << idPassivoAtual << std::endl;
			//muda proxPropor no vetorAtivos[idAtivoAtual]
			vetorAtivos[idAtivoAtual]->mudaProxPropor();
		}
	}
	listaAtivos.removeInicio();
  }

  //Imprimindo o resultado
  for(int i = 0; i < qnt; ++i) {
  	std::cout << i << " " << vetorPassivos[i]->retornaPar() << std::endl;
  }

  //Liberando a memória vetorAtivos
  for(int i = 0; i < qnt; ++i) {
  	delete vetorAtivos[i];
  }
  delete[] vetorAtivos;

  //Liberando a memória vetorPassivos
  for(int i = 0; i < qnt; ++i) {
  	delete vetorPassivos[i];
  }
  delete[] vetorPassivos;

  //Calculando o tempo de execução total
  fim = std::chrono::high_resolution_clock::now();
  duracao = fim - inicio;
  float ms = duracao.count() * 1000.f;
  
  //Escrevendo o tempo de exeução total no arquivo da saída
  std::cout << "Tempo de execução: " << ms << "ms";

  return 0;
}
