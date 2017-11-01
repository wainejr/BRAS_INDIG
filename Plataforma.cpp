#include "Plataforma.h"



Plataforma::Plataforma()
{
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


void Plataforma::draw()
{
	al_draw_filled_rectangle(posX, posY, posX + limX, posY - limY, al_map_rgb(255, 255, 255));
}


void Plataforma::builderPlataforma()
{
}


void Plataforma::atualizar()
{
}
