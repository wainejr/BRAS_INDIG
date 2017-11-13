#pragma once
#include "Arma.h"
class Lanca :
	public Arma
{
public:
	Lanca();
	~Lanca();
	void builderLanca(const int ax, const int ay, const bool aAtivo, Personagem* const pDonoArma);
	void draw(const int aPosFaseX, const int aPosFaseY);
};

