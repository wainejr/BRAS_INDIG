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
	void builderEspadachim(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const int aVida, Arma* const pArma);
	void draw(const int aPosFaseX, const int aPosFaseY);
	void createTimers();
	const bool persPodeAtacar();
};

