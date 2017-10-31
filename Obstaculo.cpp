#include "Obstaculo.h"



Obstaculo::Obstaculo()
{
	dano = 0;
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
