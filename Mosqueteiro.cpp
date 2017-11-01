#include "Mosqueteiro.h"



Mosqueteiro::Mosqueteiro()
{
}


Mosqueteiro::~Mosqueteiro()
{
}


void Mosqueteiro::builderMosqueteiro()
{
}


void Mosqueteiro::mover()
{
}


void Mosqueteiro::atacar()
{
}


void Mosqueteiro::atualizar()
{
	posX += velX;
	posY -= velY;
	atualizaArma();
}


void Mosqueteiro::draw()
{
	al_draw_filled_rectangle(posX, posY, posX + limX, posY - limY, al_map_rgb(255, 0, 0));
}



