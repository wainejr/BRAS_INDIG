#pragma once

#include "Jogador.h"

class Inimigo :
	public Personagem
{
protected:
	Jogador* alvo;

public:
	Inimigo();
	~Inimigo();
	virtual void mover();
	virtual void atacar();
	virtual void atualizar();
	virtual void draw() = 0;
	void setAlvo(Jogador* const pJog);
	Jogador* const getAlvo();
};

