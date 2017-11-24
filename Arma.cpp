#include "Arma.h"

Arma::Arma():Entidade(0, 0, 0, 0, -1, false, 0, 0, 0, 0)
{
	dano = 0;
	donoArma = nullptr;
}

Arma::Arma(const int aDano, const int aLimX, const int aLimY, const int aID):
	Entidade(0, 0, 0, 0, aID, false, 0, 0, aLimX, aLimY)
{
	dano = aDano;
}


Arma::~Arma()
{
	donoArma = nullptr;
}

const int Arma::getDano()
{
	return dano;
}


void Arma::setDano(const int aDano)
{
	dano = aDano;
}


void Arma::setDonoArma(Personagem* const pPers)
{
	if(pPers != nullptr)
		donoArma = pPers;
}

Personagem* const Arma::getDonoArma()
{
	return donoArma;
}


void Arma::atualizar()
{

}
