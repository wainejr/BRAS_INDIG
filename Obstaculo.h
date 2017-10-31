#pragma once
#include "Entidade.h"
class Obstaculo :
	public Entidade
{
public:
	Obstaculo();
	~Obstaculo();
protected:
	int dano;
public:
	const int getDano();
	void setDano(const int aDano);
};

