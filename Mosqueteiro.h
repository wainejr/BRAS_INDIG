#pragma once
#include "Inimigo.h"
class Mosqueteiro :
	public Inimigo
{
public:
	Mosqueteiro();
	~Mosqueteiro();
	void mover();
	void atacar();
	void atualizar();
	void draw();
	void builderMosqueteiro(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const int aVida, Arma* const pArma);
};

