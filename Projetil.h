#pragma once
#include "Entidade.h"
class Arma;

class Projetil :
	public Entidade
{
private:
	Arma* armaProjetil;
public:
	Projetil();
	~Projetil();
	void builderProjetil(const int ax, const int ay, const int aLimX, const int aLimY, const int aVelx, const int aVelY, const bool aAtivo);
	void atualizar();
	void setArmaProj(Arma* const pArma);
	Arma* const getArmaProj();
	void draw(const int aPosFaseX, const int aPosFaseY);
};

