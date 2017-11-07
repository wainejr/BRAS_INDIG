#include "Corda.h"



Corda::Corda()
{
	ID = CORDA;
}


Corda::~Corda()
{
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