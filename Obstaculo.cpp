#include "Obstaculo.h"



Obstaculo::Obstaculo():Entidade()
{
	dano = 0;
}

Obstaculo::Obstaculo(const int aDano, const int aID, const int aLimX, const int aLimY, const float aPosX, const float aPosY,
	const float aVelX, const float aVelY, const float aVelMaxX, const float aVelMaxY, const bool aAtivo, const bool aFisica):
	Entidade(aVelX, aVelY, aVelMaxX, aVelMaxY, aID, aFisica, aPosX, aPosY, aLimX, aLimY, aAtivo)
{
	dano = aDano;
}


Obstaculo::~Obstaculo()
{
}


const int Obstaculo::getDano()
{
	return dano;
}

void Obstaculo::setDano(const int aDano)
{
	dano = aDano;
}