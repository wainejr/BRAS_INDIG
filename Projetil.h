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
	void builderProjetil(const int ax, const int ay, const int aVelX, const bool aAtivo, const int aID, Arma* const pArma);
	void atualizar();
	void setArmaProj(Arma* const pArma);
	Arma* const getArmaProj();
	void draw(const int aPosFaseX, const int aPosFaseY);
};

