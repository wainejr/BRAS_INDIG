#include "Arco.h"



Arco::Arco()
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

	dano = DANO_ARCO;
	donoArma = NULL;

	forca = 0.0f;
}


Arco::~Arco()
{
}


void Arco::atacar()
{
}


void Arco::setForca(const float aForca)
{
	forca = aForca;
}


const float Arco::getForca()
{
	return forca;
}




void Arco::builderArco(const int ax, const int ay, const bool aAtivo, Personagem* const pDonoArma)
{
	posX = ax;
	posY = ay;
	
	ativo = aAtivo;
	if(pDonoArma != NULL)
		donoArma = pDonoArma;
}

void Arco::draw(const int aPosFaseX, const int aPosFaseY)
{

}