#include "Espada.h"



Espada::Espada():Arma(0, 0, 0)
{
}


Espada::~Espada()
{
}


void Espada::buildEspada(const int ax, const int ay, const int aLimX, const int aLimY, const bool aAtivo, const int aDano, Personagem* const pDonoArma)
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