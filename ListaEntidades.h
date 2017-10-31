#pragma once
#include "Jogador.h"
#include "Mosqueteiro.h"
#include "Espada.h"
#include "Corda.h"
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
};

