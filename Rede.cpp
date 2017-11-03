#include "Rede.h"



Rede::Rede()
{
	ID = REDE;
}


Rede::~Rede()
{
}


Corda* const Rede::getCorda()
{
	return linha;
}


void Rede::setCorda(Corda* const pCorda)
{
	linha = pCorda;
}


void Rede::builderRede(const int ax, const int ay, const int aLimX, const int aLimY, const bool aAtivo, const int aDano)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimY;
	ativo = aAtivo;
	dano = aDano;
}


void Rede::ativar()
{
	ativada = true;
}


const bool Rede::getAtivada()
{
	return ativada;
}
