#include "Projetil.h"



Projetil::Projetil()
{
	ID = PROJETIL;
}


Projetil::~Projetil()
{
}


void Projetil::builderProjetil(const int ax, const int ay, const int aLimX, const int aLimY, const int aVelx, const int aVelY, const bool aAtivo)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimY;
	velX = aVelx;
	velY = aVelY;
	ativo = aAtivo;
}


void Projetil::atualizar()
{
	posX += velX;
	posY -= velY;
}


void Projetil::setArmaProj(Arma* const pArma)
{
	armaProjetil = pArma;
}


Arma* const Projetil::getArmaProj()
{
	return armaProjetil;
}


void Projetil::draw(const int aPosFaseX, const int aPosFaseY)
{
	 al_draw_circle(posX + limX / 2 - aPosFaseX, posY + limY / 2 - aPosFaseY, 10, al_map_rgb(0, 0, 255),1);
}
