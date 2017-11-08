#include "Armadilha.h"



Armadilha::Armadilha()
{
	ID = ARMADILHA;
	acionada = false;
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


void Armadilha::atualizar()
{
}


void Armadilha::acionar()
{
	acionada = true;
}


const bool Armadilha::getAcionada()
{
	return false;
}


const bool Armadilha::setAcionada(const bool aAcionada)
{
	return false;
}
