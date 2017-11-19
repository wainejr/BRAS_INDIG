#include "Botao.h"



Botao::Botao()
{
	larg = 0;
	alt = 0;
	selec = false;
	spriteBot = nullptr;
	spriteBotSelec = nullptr;
	ativo = false;
	posX = 0;
	posY = 0;
}


Botao::~Botao()
{	
	al_destroy_bitmap(spriteBot);
	al_destroy_bitmap(spriteBotSelec);
}


void Botao::draw()
{
	if (!selec)
	{	
		al_draw_bitmap(spriteBot, posX, posY, 0);
	}
	else
	{
		al_draw_bitmap(spriteBotSelec, posX, posY, 0);
	}
}


void Botao::setSprite(ALLEGRO_BITMAP* const pSpriteBot, ALLEGRO_BITMAP* const 
	pSpriteBotSelec, const int aLarg, const int aAlt)
{
	if (pSpriteBot != nullptr)
		spriteBot = pSpriteBot;
	if (pSpriteBotSelec != nullptr)
		spriteBotSelec = pSpriteBotSelec;
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


void Botao::setAtivo(const bool aAtivo)
{
	ativo = aAtivo;
}


const bool Botao::getAtivo()
{
	return ativo;
}
