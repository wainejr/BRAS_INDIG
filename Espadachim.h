#pragma once
#include "Inimigo.h"
class Espadachim :
	public Inimigo
{
public:
	Espadachim();
	~Espadachim();
	void mover();
	void atacar();
	void atualizar();
	void buildEspadachim(int ax, const int ay, const bool aAtivo, Jogador* const pAlvo);
	void draw(const int aPosFaseX, const int aPosFaseY);
	void createTimers();
	void atualizaAtaque();
};

