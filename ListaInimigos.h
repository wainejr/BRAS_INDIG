#pragma once
#include "Lista.h"
#include "Inimigo.h"
class ListaInimigos
{
private:
	Lista<Inimigo*> inimigos;
public:
	ListaInimigos();
	~ListaInimigos();
	void addInim(Inimigo* const pInim);
	void retiraInim(Inimigo* const pInim);
	Inimigo* const inimPosi(const int i);
	const int numInim();
};

