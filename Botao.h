#pragma once
#include "allegro5\allegro.h"
#include "allegro5\allegro_image.h"
#include "allegro5\allegro_primitives.h" //	PARA TESTES
#define LARG_BOTAO 120
#define ALT_BOTAO 30

class Botao
{
public:
	Botao();
	~Botao();
	void draw();
	void setSprite(ALLEGRO_BITMAP* const pSprite, const int aLarg, const int aAlt);
	void botaoSelec(bool const aSelec);
private:
	// FAZER DUAS SPRITES PELO MENOS, UM PRA NORMAL OUTRO PRA PRESSOINADO/BOTAO EM CIMA
	ALLEGRO_BITMAP* sprite;
	int larg;
	int alt;
	bool selec;
public:
	const bool getSelec();
	const int getLarg();
	const int getAlt();
private:
	int posX;
	int posY;
public:
	void setX(const int ax);
	void setY(const int ay);
	const int getX();
	const int getY();
private:
	bool ativo;
public:
	void setAtivo(const bool aAtivo);
	const bool getAtivo();
};

