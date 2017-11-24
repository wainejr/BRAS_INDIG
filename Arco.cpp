#include "Arco.h"



Arco::Arco():Arma(DANO_ARCO, 0, 0, ARCO)
{
}


Arco::~Arco()
{
}


void Arco::buildArco(const int ax, const int ay, const bool aAtivo, Personagem* const pDonoArma)
{
	posX = ax;
	posY = ay;
	
	ativo = aAtivo;
	if(pDonoArma != nullptr)
		donoArma = pDonoArma;
}

void Arco::draw(const int aPosFaseX, const int aPosFaseY)
{

}