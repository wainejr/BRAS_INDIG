#pragma once
#include "Entidade.h"
class Personagem;

class Arma :
	public Entidade
{
protected:
	int dano;
	Entidade* donoArma;
public:
	Arma();
	~Arma();
	const int getDano();
	void setDano(const int aDano);
	virtual void atacar() = 0;

	void setDonoArma(Entidade* const pPers);
	Entidade* const getDonoArma();
};

