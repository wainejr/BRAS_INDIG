#include "Botao.h"



Botao::Botao():ProtoEntidade()
{
	selec = false;
	spriteBot = nullptr;
	spriteBotSelec = nullptr;
	ativo = false;
}


Botao::~Botao()
{	
	al_destroy_bitmap(spriteBot);
	al_destroy_bitmap(spriteBotSelec);
}

Botao::Botao(ALLEGRO_BITMAP* const pBot, ALLEGRO_BITMAP* const pBotSelec, const float aPosX, 
	const float aPosY, const int aLimX, const int aLimY, const bool aAtivo):ProtoEntidade(aPosX, aPosY, aLimX, aLimY, aAtivo)
{
	selec = false;
	spriteBot = pBot;
	spriteBotSelec = pBotSelec;
}


void Botao::draw(const int aPosFaseX, const int aPosFaseY)
{
	if (!selec)
	{	
		al_draw_bitmap(spriteBot, posX - aPosFaseX, posY - aPosFaseY, 0);
	}
	else
	{
		al_draw_bitmap(spriteBotSelec, posX - aPosFaseX, posY - aPosFaseY, 0);
	}
}


void Botao::setSprite(ALLEGRO_BITMAP* const pSpriteBot, ALLEGRO_BITMAP* const 
	pSpriteBotSelec, const int aLarg, const int aAlt)
{
	if (pSpriteBot != nullptr)
		spriteBot = pSpriteBot;
	if (pSpriteBotSelec != nullptr)
		spriteBotSelec = pSpriteBotSelec;
	limX = aLarg;
	limY = aAlt;
}


void Botao::botaoSelec(bool const aSelec)
{
	selec = aSelec;
}


const bool Botao::getSelec()
{
	return selec;
}
