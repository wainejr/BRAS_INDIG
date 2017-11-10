#include "Arma.h"

Arma::Arma()
{
	dano = 0;
	donoArma = NULL;
}


Arma::~Arma()
{
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
	if(pPers != NULL)
		donoArma = pPers;
}

Personagem* const Arma::getDonoArma()
{
	return donoArma;
}


void Arma::atualizar()
{

}
