#include "Mosquete.h"



Mosquete::Mosquete()
{
	ID = MOSQUETE;
}


Mosquete::~Mosquete()
{
}


void Mosquete::builderMosquete(const int ax, const int ay, const int aLimX, const int aLimY, const bool aFisica, const bool aAtivo, const int aDano, Personagem* const pDonoArma)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimY;
	fisica = aFisica;
	ativo = aAtivo;
	dano = aDano;
	donoArma = pDonoArma;
}


void Mosquete::atacar()
{
}


void Mosquete::draw(const int aPosFaseX, const int aPosFaseY)
{
}
