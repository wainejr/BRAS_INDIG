#pragma once
#include "Lista.h"
#include "Corda.h"

class ListaPlataformas
{
	Lista<Plataforma*> plataformas;
public:
	ListaPlataformas();
	~ListaPlataformas();
	void addPlat(Plataforma* const pPlat);
	void retiraPlat(Plataforma* const pPlat);
	const int numPlat();
	Plataforma* const platPosi(const int i);
};

