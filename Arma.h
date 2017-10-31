#pragma once
#include "Entidade.h"
class Arma :
	public Entidade
{
public:
	Arma();
	~Arma();
protected:
	int dano;
public:
	const int getDano();
	void setDano(const int aDano);
};

