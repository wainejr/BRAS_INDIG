#include "Corda.h"



Corda::Corda()
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
	ID = CORDA;

	colisaoBaixo = false;

	escalavel = false;
}


Corda::~Corda()
{
	delete(listaAnim);
}


void Corda::setEscalavel(const bool aEscalav)
{
	escalavel = aEscalav;
}


const bool Corda::getEscalavel()
{
	return escalavel;
}

void Corda::builderCorda(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const bool aEscalavel)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimy;
	ativo = aAtivo;

	escalavel = aEscalavel;
}

void Corda::draw(const int posRelX, const int posRelY)
{
	al_draw_filled_rectangle(posX - posRelX, posY - posRelY, posX + limX - posRelX, posY - limY - posRelY, al_map_rgb(84, 255, 84));
}