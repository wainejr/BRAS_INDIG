#pragma once
#include "EspadachimCavaleiro.h"
class Espadachim :
	public EspadachimCavaleiro
{
public:
	Espadachim();
	~Espadachim();
	void mover();
	void atacar();
	void atualizar();
	void builderEspadachim();
};

