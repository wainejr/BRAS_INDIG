#pragma once

#include "Jogador.h"

class Inimigo :
	public Personagem
{
protected:
	Jogador* alvo;

public:
	Inimigo();
	virtual ~Inimigo();
	virtual void mover() = 0;
	virtual void atacar();
	virtual void atualizar() = 0;
	virtual void draw(const int aPosFaseX, const int aPosFaseY) = 0;
	void setAlvo(Jogador* const pJog);
	Jogador* const getAlvo();
};

