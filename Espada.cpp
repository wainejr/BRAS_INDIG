#include "Espada.h"



Espada::Espada()
{
}


Espada::~Espada()
{
}


void Espada::builderEspada(const int ax, const int ay, const int aLimX, const int aLimY, const bool aFisica, const bool aAtivo, const int aDano, Personagem* const pDonoArma)
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


void Espada::atacar()
{
}


void Espada::draw()
{

}