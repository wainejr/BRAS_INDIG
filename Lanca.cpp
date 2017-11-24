#include "Lanca.h"



Lanca::Lanca():Arma(DANO_LANCA, 0, 0, LANCA)
{
}


Lanca::~Lanca()
{
}


void Lanca::buildLanca(const int ax, const int ay, const bool aAtivo, Personagem* const pDonoArma)
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
