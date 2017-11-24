#include "Projetil.h"



Projetil::Projetil()
{
	posX = 0;
	posY = 0;
	limX = 0;
	limY = 0;
	velX = 0;
	velY = 0;
	fisica = false;
	ativo = false;
	velMaxX = VEL_MAX_PROJ;
	velMaxY = VEL_MAX_PROJ;
	ID = -1;
	listaAnim = nullptr;

	armaProjetil = nullptr;
}

Projetil::Projetil(Arma* const pArma, const int aLimX, const int aLimY):Entidade(VEL_MAX_PROJ, 0, VEL_MAX_PROJ, 0, -1, false, 0, 0, aLimX, aLimY)
{
	if(pArma != nullptr)
		armaProjetil = pArma;
}


Projetil::~Projetil()
{	
	armaProjetil = nullptr;
}


void Projetil::buildProjetil(const int ax, const int ay, const int aVelX, const bool aAtivo, const int aID, Arma* const pArma)
{
	posX = ax;
	posY = ay;
	velX = aVelX;
	ativo = aAtivo;
	ID = aID;

	if (pArma != nullptr)
	{
		armaProjetil = pArma;
	}

	if (aID == PROJETIL_MOSQ)
	{
		limX = LIM_X_PROJ_MOSQ;
		limY = LIM_Y_PROJ_MOSQ;
	}
	else if (aID == PROJETIL_ARCO)
	{
		limX = LIM_X_PROJ_ARCO;
		limY = LIM_Y_PROJ_ARCO;
	}

}


void Projetil::atualizar()
{
	posX += velX;
	posY -= velY;
}


void Projetil::setArmaProj(Arma* const pArma)
{
	if(pArma != nullptr)
		armaProjetil = pArma;
}


Arma* const Projetil::getArmaProj()
{
	return armaProjetil;
}


void Projetil::draw(const int aPosFaseX, const int aPosFaseY)
{
	 al_draw_filled_rectangle(posX-aPosFaseX, posY-aPosFaseY, posX+limX-aPosFaseX, posY-limY-aPosFaseY, al_map_rgb(0, 255, 255));
}
