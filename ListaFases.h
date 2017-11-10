#pragma once
#include "Fase1.h"
#include "Fase2.h"
#include "FaseFinal.h"

class ListaFases
{
private:
	int numJogs;
	
	Fase1 fase1;
	//Fase2 fase2;
	//FaseFinal faseFinal;

public:
	ListaFases();
	~ListaFases();
	bool defineNumJogadores(const int aNumJogs);
	void carregaFaseN(const int aN);
	void listaFases();
};

