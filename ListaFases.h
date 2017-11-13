#pragma once
#include "Fase1.h"
#include "Fase2.h"
#include "FaseFinal.h"

class ListaFases
{
private:
	Fase1 fase1;
	Fase2 fase2;
	FaseFinal faseFinal;

	Jogador* raoni;
	Jogador* teca;
	
public:
	//	FAZER UMA FUNÇÃO PARA INICIALIZAR AS OPÇÕES E TALS QUANDO
	//	CLICAR PARA INICIAR O JOGO
	ListaFases();
	~ListaFases();
	bool defineNumJogadores(const int aNumJogs);
	void carregaFaseN(const int aN);
	void campanha();
	void defineJog(const int aID, const int aNum);
};

