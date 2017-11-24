#pragma once
#include "allegro5\allegro.h"
#include "allegro5\allegro_image.h"
#include "allegro5\allegro_primitives.h" //	PARA TESTES
#include "ProtoEntidade.h"

class Botao :
	public ProtoEntidade
{
private:
	// FAZER DUAS SPRITES PELO MENOS, UM PRA NORMAL OUTRO PRA PRESSOINADO/BOTAO EM CIMA
	ALLEGRO_BITMAP* spriteBot;
	ALLEGRO_BITMAP* spriteBotSelec;
	bool selec;

public:
	Botao();
	~Botao();
	Botao(ALLEGRO_BITMAP* const pBot, ALLEGRO_BITMAP* const pBotSelec, const float aPosX = 0,
		const float aPosY = 0, const int aLimX = 0, const int aLimY = 0, const bool aAtivo = false);
	void draw(const int aPosFaseX = 0, const int aPosFaseY = 0);
	void setSprite(ALLEGRO_BITMAP* const pSpriteBot, ALLEGRO_BITMAP* const
		pSpriteBotSelec, const int aLarg, const int aAlt);
	void botaoSelec(bool const aSelec);
	const bool getSelec();
};

