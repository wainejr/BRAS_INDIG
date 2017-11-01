#pragma once
#include "Entidade.h"
class Projetil :
	public Entidade
{
public:
	Projetil();
	~Projetil();
	void builderProjetil();
	void atualizaProjetil();
};

