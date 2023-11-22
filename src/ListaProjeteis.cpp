#include "ListaProjeteis.h"



ListaProjeteis::ListaProjeteis()
{
}


ListaProjeteis::~ListaProjeteis()
{
}


const int ListaProjeteis::numProj()
{
	return projeteis.numObjs();
}


void ListaProjeteis::addProj(Projetil* const pProj)
{
	if (pProj != nullptr)
		projeteis.addObj(pProj);
}


void ListaProjeteis::retirarProj(Projetil* const pProj)
{
	if (pProj != nullptr)
		projeteis.retirarObj(pProj);
}


Projetil* const ListaProjeteis::projPosi(const int i)
{
	return projeteis.objI(i);
}
