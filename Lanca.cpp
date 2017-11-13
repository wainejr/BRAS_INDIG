#include "Lanca.h"



Lanca::Lanca()
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
	ID = ARCO;

	dano = DANO_LANCA;
	donoArma = NULL;
}


Lanca::~Lanca()
{
}


void Lanca::builderLanca(const int ax, const int ay, const bool aAtivo, Personagem* const pDonoArma)
{
	posX = ax;
	posY = ay;
	ativo = aAtivo;

	if (pDonoArma != NULL)
	{
		donoArma = pDonoArma;
	}
}


void Lanca::atacar()
{
}

void Lanca::draw(const int aPosFaseX, const int aPosFaseY)
{

}
