#include "Projetil.h"



Projetil::Projetil()
{
}


Projetil::~Projetil()
{
}


void Projetil::builderProjetil(const int ax, const int ay, const int aLimX, const int aLimY, const int aVelx, const int aVelY, const bool aAtivo)
{
}


void Projetil::atualizar()
{
}


void Projetil::setArmaProj(ArmaDeAlcance* const pArma)
{
	armaProjetil = pArma;
}


ArmaDeAlcance* const Projetil::getArmaProj()
{
	return armaProjetil;
}
