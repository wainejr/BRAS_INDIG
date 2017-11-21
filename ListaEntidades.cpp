#include "ListaEntidades.h"



ListaEntidades::ListaEntidades()
{
}


ListaEntidades::~ListaEntidades()
{
}


void ListaEntidades::addEnt(Entidade* const pEnt)
{
	if (pEnt != nullptr)
		entidades.addObj(pEnt);
}


void ListaEntidades::retirarEnt(Entidade* const pEnt)
{
	if (pEnt != nullptr)
		entidades.retirarObj(pEnt);
}


const int ListaEntidades::numEnt()
{
	return entidades.numObjs();
}


Entidade* const ListaEntidades::entPosI(const int i)
{
	return entidades.objI(i);
}
