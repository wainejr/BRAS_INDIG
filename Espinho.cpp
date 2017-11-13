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

	dano = DANO_ESPINHO;
}


Espinho::~Espinho()
{
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

	dano = DANO_ESPINHO;
}


void Espinho::draw(const int aPosFaseX, const int aPosFaseY)
{
	al_draw_filled_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(0, 0, 255));
}

void Espinho::atualizar()
{

}