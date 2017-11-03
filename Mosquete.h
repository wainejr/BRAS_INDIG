#pragma once
#include "ArmaDeAlcance.h"
class Mosquete :
	public ArmaDeAlcance
{
public:
	Mosquete();
	~Mosquete();
	void builderMosquete(const int ax, const int ay, const int aLimX, const int aLimY, const bool aFisica, const bool aAtivo, const int aDano, Personagem* const pDonoArma);
	void atacar();
	void draw();
};

