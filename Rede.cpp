#include "Rede.h"



Rede::Rede()
{
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


void Rede::builderCorda()
{
}
