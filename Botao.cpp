#include "Botao.h"



Botao::Botao()
{
	larg = 0;
	alt = 0;
	selec = false;
	sprite = nullptr;
	posX = 0;
	posY = 0;
}


Botao::~Botao()
{
	if(sprite != nullptr)
		al_destroy_bitmap(sprite);
}


void Botao::draw()
{
	if (!selec)
	{
		al_draw_bitmap(sprite, posX, posY, 0);
	}
	else
	{
		al_draw_bitmap(sprite, posX, posY, 0);
		al_draw_line(posX, posY + alt, posX + larg, posY, al_map_rgb(0, 255, 0), 2);
	}
}


void Botao::setSprite(ALLEGRO_BITMAP* const pSprite, const int aLarg, const int aAlt)
{
	if (pSprite != nullptr)
		sprite = pSprite;
	larg = aLarg;
	alt = aAlt;
}


void Botao::botaoSelec(bool const aSelec)
{
	selec = aSelec;
}


const bool Botao::getSelec()
{
	return selec;
}


const int Botao::getLarg()
{
	return larg;
}


const int Botao::getAlt()
{
	return alt;
}


void Botao::setX(const int ax)
{
	posX = ax;
}


void Botao::setY(const int ay)
{
	posY = ay;
}


const int Botao::getX()
{
	return posX;
}


const int Botao::getY()
{
	return posY;
}
