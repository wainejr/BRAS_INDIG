#pragma once
#include "Inimigo.h"
#include "Mosquete.h"

class Mosqueteiro :
	public Inimigo
{
public:
	Mosqueteiro();
	~Mosqueteiro();
	void mover();
	void atualizar();
	void draw(const int aPosFaseX, const int aPosFaseY);
	void buildMosqueteiro(const int ax, const int ay, const bool aAtivo, Jogador* const pAlvo);
	Projetil* const atirar();
	void createTimers();
	void atualizaAtaque();
	void reset(const int ax, const int ay, const bool aAtivo);
};

