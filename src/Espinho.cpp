#include "Espinho.h"



Espinho::Espinho(const int aLimX, const int aLimY):Obstaculo(DANO_ESPINHO, ESPINHO, aLimX, aLimY)
{
}


Espinho::~Espinho()
{
}


void Espinho::buildEspinho(const int ax, const int ay, const int aLimX, const int aLimY, const bool aAtivo)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimY;
	velX = 0;
	velY = 0;
	ativo = aAtivo;
	fisica = false;
	velMaxX = 0;
	velMaxY = 0;
	ID = ESPINHO;
	if (listaAnim == nullptr)
	{
		listaAnim = gerListaAnim.listaAnimEnt(ID);
	}

	dano = DANO_ESPINHO;
}


void Espinho::draw(const int aPosFaseX, const int aPosFaseY)
{
	if(limX > limY)
		listaAnim->drawDeAte_X(0, posX - aPosFaseX, posY - aPosFaseY, posX - aPosFaseX + limX);
}

void Espinho::atualizar()
{

}


void Espinho::initTimer()
{
}

void Espinho::createTimer()
{

}

void Espinho::resetaTimer()
{
}

void Espinho::stopTimers()
{
}

void Espinho::resumeTimers()
{
}