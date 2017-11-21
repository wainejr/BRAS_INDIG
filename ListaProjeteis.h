#pragma once
#include "Lista.h"
#include "Projetil.h"
class ListaProjeteis
{
private:
	Lista<Projetil*> projeteis;

public:
	ListaProjeteis();
	~ListaProjeteis();
	const int numProj();
	void addProj(Projetil* const pProj);
	void retirarProj(Projetil* const pProj);
	Projetil* const projPosi(const int i);
};

