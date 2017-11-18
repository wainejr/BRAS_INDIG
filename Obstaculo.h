#pragma once
#include "Entidade.h"
class Obstaculo :
	public Entidade
{
protected:
	int dano;
public:
	Obstaculo();
	virtual ~Obstaculo();
	const int getDano();
	void setDano(const int aDano);
};

