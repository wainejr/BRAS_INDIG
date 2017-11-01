#pragma once
#include "EntConcreteClasses.h"
#include <vector>

using namespace std;

/*	mudar implementação para um template mais específico	*/
class ListaEntidades
{
private:
	vector<Entidade*> entidades;
public:
	ListaEntidades();
	~ListaEntidades();
	void addEntidade(Entidade* pEntidade);
	void desenhaAtivos();

	// retorna entidade na posição i
	Entidade* const entidadeI(const int i);
	// retorna o numero de entidades
	const int numEntidades();
};

