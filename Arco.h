#pragma once
#include "Arma.h"
class Arco :
	public Arma
{
public:
	Arco();
	~Arco();
	void buildArco(const int ax, const int ay, const bool aAtivo, Personagem* const pDonoArma);
	void draw(const int aPosFaseX, const int aPosFaseY);
};

