#include "ListaEntidades.h"



ListaEntidades::ListaEntidades()
{
	
}


ListaEntidades::~ListaEntidades()
{
	entidades.clear();
}

void ListaEntidades::addEntidade(Entidade* pEntidade)
{
	entidades.push_back(pEntidade);
}


void ListaEntidades::desenhaAtivos()
{
	for (int i = 0; i < (int)entidades.size(); i++)
	{
		if (entidades[i]->getAtivo())
			entidades[i]->draw();
	}
}


Entidade* const ListaEntidades::entidadeI(const int i)
{
	if (i < (int)entidades.size() && i >= 0)
		return entidades[i];
	else
		return NULL;
}


const int ListaEntidades::numEntidades()
{
	return entidades.size();
}
