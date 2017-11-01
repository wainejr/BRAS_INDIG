#include "Corda.h"



Corda::Corda()
{
}


Corda::~Corda()
{
}


void Corda::setEscalavel(const bool aEscalav)
{
	escalavel = aEscalav;
}


const bool Corda::getEscalavel()
{
	return escalavel;
}


void Corda::draw()
{
}


void Corda::builderCorda(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const bool aEscalavel)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimy;
	ativo = aAtivo;
	escalavel = aEscalavel;
}
