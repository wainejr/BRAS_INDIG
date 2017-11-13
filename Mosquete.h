#pragma once
#include "Arma.h"
class Mosquete :
	public Arma
{
public:
	Mosquete();
	~Mosquete();
	void builderMosquete(const int ax, const int ay, const bool aAtivo, Personagem* const pDonoArma);
	void atacar();
	void draw(const int aPosFaseX, const int aPosFaseY);
};

