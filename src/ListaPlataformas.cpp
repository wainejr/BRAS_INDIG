#include "ListaPlataformas.h"



ListaPlataformas::ListaPlataformas()
{
}


ListaPlataformas::~ListaPlataformas()
{
}


void ListaPlataformas::addPlat(Plataforma* const pPlat)
{
	if (pPlat != nullptr)
		plataformas.addObj(pPlat);
}


void ListaPlataformas::retiraPlat(Plataforma* const pPlat)
{
	if(pPlat != nullptr)
		plataformas.retirarObj(pPlat);
}


const int ListaPlataformas::numPlat()
{
	return plataformas.numObjs();
}


Plataforma* const ListaPlataformas::platPosi(const int i)
{
	return plataformas.objI(i);
}
