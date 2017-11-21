#include "ListaInimigos.h"



ListaInimigos::ListaInimigos()
{
}


ListaInimigos::~ListaInimigos()
{
}


void ListaInimigos::addInim(Inimigo* const pInim)
{
	if(pInim != nullptr)
		inimigos.addObj(pInim);
}


void ListaInimigos::retiraInim(Inimigo* const pInim)
{
	if (pInim != nullptr)
		inimigos.retirarObj(pInim);
}


Inimigo* const ListaInimigos::inimPosi(const int i)
{
	return inimigos.objI(i);
}


const int ListaInimigos::numInim()
{
	return inimigos.numObjs();
}
