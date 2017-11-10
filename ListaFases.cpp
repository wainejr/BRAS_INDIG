#include "ListaFases.h"



ListaFases::ListaFases()
{
}


ListaFases::~ListaFases()
{
}


void ListaFases::carregaFaseN(const int aN)
{
	/*a fazer*/
}


void ListaFases::listaFases()
{
	/*a fazer*/
}

bool ListaFases::defineNumJogadores(const int aNumJogs)
{
	if (aNumJogs == 2 || aNumJogs == 1)
	{
		numJogs = aNumJogs;
		return true;
	}
	else
		return false;
}