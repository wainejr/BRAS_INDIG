#include "Arco.h"



Arco::Arco()
{
	forca = 0.0f;
	ID = ARCO;
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




void Arco::builderArco(const int ax, const int ay, const int aLimX, const int aLimY, const bool aFisica, const bool aAtivo, const int aDano, Personagem* const pDonoArma)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimY;
	fisica = aFisica;
	ativo = aAtivo;
	dano = aDano;
	if(pDonoArma != NULL)
		donoArma = pDonoArma;
}

void Arco::draw(const int aPosFaseX, const int aPosFaseY)
{

}