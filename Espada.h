#pragma once
#include "Arma.h"
class Espada :
	public Arma
{
public:
	Espada();
	~Espada();
	void draw();
	void builderEspada(const int ax, const int ay, const int aLimX, const int aLimY, const bool aFisica, const bool aAtivo, const int aDano, Personagem* const pDonoArma);
	void atacar();
};

