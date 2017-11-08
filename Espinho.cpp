#include "Espinho.h"



Espinho::Espinho()
{
	ID = ESPINHO;
}


Espinho::~Espinho()
{
}


void Espinho::builderEspinho(const int ax, const int ay, const int aLimX, const int aLimY, const bool aAtivo, const int aDano)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimY;
	ativo = aAtivo;
	dano = aDano;
}


void Espinho::draw(const int aPosFaseX, const int aPosFaseY)
{
	al_draw_filled_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(0, 0, 255));
}

void Espinho::atualizar()
{

}
