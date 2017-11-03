#pragma once
#include "Arma.h"
#include "Projetil.h"

class ArmaDeAlcance :
	public Arma
{
public:
	ArmaDeAlcance();
	~ArmaDeAlcance();
	virtual void atacar() = 0;
};

