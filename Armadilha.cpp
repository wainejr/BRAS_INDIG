#include "Armadilha.h"



Armadilha::Armadilha()
{
	ID = ARMADILHA;
}


Armadilha::~Armadilha()
{
}


void Armadilha::builderArmadilha(const int ax, const int ay, const int aLimX, const int aLimY, const bool aAtivo, const int aDano)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimY;
	ativo = aAtivo;
	dano = aDano;
}


void Armadilha::draw(const int aPosFaseX, const int aPosFaseY)
{
}
