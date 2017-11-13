#include "Mosquete.h"



Mosquete::Mosquete()
{
	posX = 0;
	posY = 0;
	limX = 0;
	limY = 0;
	velX = 0;
	velY = 0;
	fisica = false;
	ativo = false;
	velMaxX = 0;
	velMaxY = 0;
	ID = MOSQUETE;

	dano = DANO_MOSQUETE;
	donoArma = NULL;
}


Mosquete::~Mosquete()
{
}


void Mosquete::builderMosquete(const int ax, const int ay, const bool aAtivo, Personagem* const pDonoArma)
{
	posX = ax;
	posY = ay;

	ativo = aAtivo;
	if (pDonoArma != NULL)
		donoArma = pDonoArma;
}


void Mosquete::atacar()
{
}


void Mosquete::draw(const int aPosFaseX, const int aPosFaseY)
{
}
