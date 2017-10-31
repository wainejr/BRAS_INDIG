#pragma once
#include "Personagem.h"
class Inimigo :
	public Personagem
{
public:
	Inimigo();
	~Inimigo();
	virtual void mover();
	virtual void atacar();
	virtual void atualizar();
//	virtual void draw();
	virtual void draw() = 0;
};

