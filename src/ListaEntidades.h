#pragma once
#include "Lista.h"
#include "Entidade.h"
class ListaEntidades
{
private:
	Lista<Entidade*> entidades;

public:
	ListaEntidades();
	~ListaEntidades();
	void addEnt(Entidade* const pEnt);
	void retirarEnt(Entidade* const pEnt);
	const int numEnt();
	Entidade* const entPosI(const int i);
};

