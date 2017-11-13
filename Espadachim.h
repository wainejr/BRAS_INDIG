#pragma once
#include "EspadachimCavaleiro.h"
class Espadachim :
	public EspadachimCavaleiro
{
public:
	Espadachim();
	~Espadachim();
	void mover();
	void atacar();
	void atualizar();
	void builderEspadachim(int ax, const int ay, const bool aAtivo, Jogador* const pAlvo);
	void draw(const int aPosFaseX, const int aPosFaseY);
	void createTimers();
	const bool persPodeAtacar();
	void reset(const int ax, const int ay, const bool aAtivo);
};

