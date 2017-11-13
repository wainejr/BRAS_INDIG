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
	void atacar();
	void atualizar();
	void draw(const int aPosFaseX, const int aPosFaseY);
	void builderMosqueteiro(const int ax, const int ay, const bool aAtivo, Jogador* const pAlvo);
	Projetil* const atirar();
	void createTimers();
	const bool persPodeAtacar();
	void reset(const int ax, const int ay, const bool aAtivo);
};

