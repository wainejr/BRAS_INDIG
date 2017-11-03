#include "Lanca.h"



Lanca::Lanca()
{
	ID = LANCA;
}


Lanca::~Lanca()
{
}


void Lanca::builderLanca(const int ax, const int ay, const int aLimX, const int aLimY, const bool aFisica, const bool aAtivo, const int aDano, Personagem* const pDonoArma)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimY;
	fisica = aFisica;
	ativo = aAtivo;
	dano = aDano;
	donoArma = pDonoArma;
}


void Lanca::atacar()
{
}
