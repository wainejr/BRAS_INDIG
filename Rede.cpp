#include "Rede.h"



Rede::Rede()
{
	ID = REDE;
	velMaxY = VEL_MAX_REDE;
	ativada = false;
	linha = NULL;
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
	if(pCorda != NULL)
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
	ativada = false;
}


void Rede::ativar()
{
	if (!ativada)
	{
		ativada = true;
		linha->setAtivo(false);
	}
}


const bool Rede::getAtivada()
{
	return ativada;
}


void Rede::draw(const int aPosFaseX, const int aPosFaseY)
{
	al_draw_filled_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(255, 255, 255));
	if(linha->getAtivo())
		al_draw_filled_rectangle(linha->getX() - aPosFaseX, linha->getY() - aPosFaseY, linha->getX() + linha->getLimX() - aPosFaseX, linha->getY() - linha->getLimY() - aPosFaseY, al_map_rgb(255, 0, 0));
}


void Rede::atualizar()
{
	if (ativada)
	{
		// aceleração não incluída par
		if (velY > -velMaxY)
			velY -= ACEL_REDE;
		else
			velY = -velMaxY;

		posY -= velY;
	}
}
