#pragma once
#include "Inimigo.h"
class Cavaleiro :
	public Inimigo
{
public:
	Cavaleiro();
	~Cavaleiro();
	void mover();
	void atualizar();
	void buildCav(int ax, const int ay, const bool aAtivo, Jogador* const pAlvo);
	virtual void draw(const int aPosFaseX, const int aPosFaseY);
	void createTimers();
	void atualizaAtaque();
};

