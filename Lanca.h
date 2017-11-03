#pragma once
#include "Arma.h"
class Lanca :
	public Arma
{
public:
	Lanca();
	~Lanca();
	void builderLanca(const int ax, const int ay, const int aLimX, const int aLimY, const bool aFisica, const bool aAtivo, const int aDano, Personagem* const pDonoArma);
	void atacar();
	void draw(const int aPosFaseX, const int aPosFaseY);
};

