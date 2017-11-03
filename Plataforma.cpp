#include "Plataforma.h"



Plataforma::Plataforma()
{
	ID = PLATAFORMA;
}


Plataforma::~Plataforma()
{
}


void Plataforma::setColisaoBaixo(const bool aCol)
{
	colisaoBaixo = aCol;
}


const bool Plataforma::getColisaoBaixo()
{
	return colisaoBaixo;
}


void Plataforma::draw(const int aPosFaseX, const int aPosFaseY)
{
	al_draw_filled_rectangle(posX- aPosFaseX, posY- aPosFaseY, posX + limX- aPosFaseX, posY - limY- aPosFaseY, al_map_rgb(255, 255, 255));
}


void Plataforma::builderPlataforma(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimy;
	ativo = aAtivo;

}


void Plataforma::atualizar()
{
}
