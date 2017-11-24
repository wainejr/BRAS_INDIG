#include "Mosquete.h"



Mosquete::Mosquete():Arma(DANO_MOSQUETE, 0, 0, MOSQUETE)
{
}


Mosquete::~Mosquete()
{
}


void Mosquete::buildMosquete(const int ax, const int ay, const bool aAtivo, Personagem* const pDonoArma)
{
	posX = ax;
	posY = ay;

	ativo = aAtivo;
	if (pDonoArma != nullptr)
		donoArma = pDonoArma;
}


void Mosquete::draw(const int aPosFaseX, const int aPosFaseY)
{
}
