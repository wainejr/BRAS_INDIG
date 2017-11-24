#pragma once

#include "Jogador.h"

class Inimigo :
	public Personagem
{
protected:
	Jogador* alvo;

public:
	Inimigo();
	Inimigo(const int aVida, const float aVelX, const float aVelY, const float aVelMaxX,
		const float aVelMaxY, const int aID, const bool aFisica = true,
		const float aPosX = 0, const float aPosY = 0, const int aLimX = 0,
		const int aLimY = 0, const bool aAtivo = false);
	virtual ~Inimigo();
	virtual void mover() = 0;
	virtual void atacar();
	virtual void atualizar() = 0;
	virtual void draw(const int aPosFaseX, const int aPosFaseY) = 0;
	void setAlvo(Jogador* const pJog);
	Jogador* const getAlvo();
	virtual Projetil* const atirar();
};

