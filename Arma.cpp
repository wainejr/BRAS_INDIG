#include "Arma.h"



Arma::Arma()
{
	dano = 0;
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
