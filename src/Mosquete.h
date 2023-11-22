#pragma once
#include "Arma.h"
class Mosquete :
	public Arma
{
public:
	Mosquete();
	~Mosquete();
	void buildMosquete(const int ax, const int ay, const bool aAtivo, Personagem* const pDonoArma);
	void draw(const int aPosFaseX, const int aPosFaseY);
};

