#include "Espinho.h"



Espinho::Espinho()
{
	posX = 0;
	posY = 0;
	limX = 0;
	limY = 0;
	velX = 0;
	velY = 0;
	fisica = false;
	ativo = false;
	velMaxX = 0;
	velMaxY = 0;
	ID = ESPINHO;
	listaAnim = nullptr;

	dano = DANO_ESPINHO;
}


Espinho::~Espinho()
{
	delete(listaAnim);
}


void Espinho::builderEspinho(const int ax, const int ay, const int aLimX, const int aLimY, const bool aAtivo)
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