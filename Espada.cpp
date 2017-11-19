#include "Espada.h"



Espada::Espada()
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
	ID = ESPADA;
	listaAnim = nullptr;

	dano = 0;
	donoArma = nullptr;
}


Espada::~Espada()
{
	delete(listaAnim);

	donoArma = nullptr;
}


void Espada::builderEspada(const int ax, const int ay, const int aLimX, const int aLimY, const bool aAtivo, const int aDano, Personagem* const pDonoArma)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimY;
	ativo = aAtivo;

	if (pDonoArma != nullptr)
	{
		donoArma = pDonoArma;
	}
	dano = aDano;
}


void Espada::draw(const int aPosFaseX, const int aPosFaseY)
{

}