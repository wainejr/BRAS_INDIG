#pragma once
#include "allegro5\allegro.h"
#include "allegro5\allegro_image.h"
#include "allegro5\allegro_primitives.h" //	PARA TESTES
#define LARG_BOTAO 128
#define ALT_BOTAO 32

class Botao
{
private:
	// FAZER DUAS SPRITES PELO MENOS, UM PRA NORMAL OUTRO PRA PRESSOINADO/BOTAO EM CIMA
	ALLEGRO_BITMAP* spriteBot;
	ALLEGRO_BITMAP* spriteBotSelec;
	int larg;
	int alt;
	bool selec;
	int posX;
	int posY;
	bool ativo;
public:
	Botao();
	~Botao();
	void draw();
	void setSprite(ALLEGRO_BITMAP* const pSpriteBot, ALLEGRO_BITMAP* const
		pSpriteBotSelec, const int aLarg, const int aAlt);
	void botaoSelec(bool const aSelec);
	const bool getSelec();
	const int getLarg();
	const int getAlt();
	void setX(const int ax);
	void setY(const int ay);
	const int getX();
	const int getY();
	void setAtivo(const bool aAtivo);
	const bool getAtivo();
};

