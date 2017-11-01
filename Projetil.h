#pragma once
#include "ArmaDeAlcance.h"
class Projetil :
	public Entidade
{
private:
	ArmaDeAlcance* armaProjetil;
public:
	Projetil();
	~Projetil();
	void builderProjetil(const int ax, const int ay, const int aLimX, const int aLimY, const int aVelx, const int aVelY, const bool aAtivo);
	void atualizar();
	void setArmaProj(Arma* const pArma);
	ArmaDeAlcance* const getArmaProj();
};

