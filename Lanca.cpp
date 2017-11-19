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
	ID = LANCA;
	listaAnim = nullptr;

	dano = DANO_LANCA;
	donoArma = nullptr;
}


Lanca::~Lanca()
{
	delete(listaAnim);

	donoArma = nullptr;
}


void Lanca::builderLanca(const int ax, const int ay, const bool aAtivo, Personagem* const pDonoArma)
{
	posX = ax;
	posY = ay;
	ativo = aAtivo;

	if (pDonoArma != nullptr)
	{
		donoArma = pDonoArma;
	}
}


void Lanca::draw(const int aPosFaseX, const int aPosFaseY)
{

}
