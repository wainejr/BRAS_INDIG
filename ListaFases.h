#pragma once
#include "Fase.h"

class ListaFases
{
private:
	vector<Fase*> listFases;
public:
	ListaFases();
	~ListaFases();
	void addFase(Fase* pFase);
	void carregaFaseN(const int aN);
	void listaFases();
};

