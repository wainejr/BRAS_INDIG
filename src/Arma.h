#pragma once
#include "Entidade.h"
#include "Projetil.h"

class Personagem;

class Arma :
	public Entidade
{
protected:
	int dano;
	Personagem* donoArma;
public:
	Arma();
	Arma(const int aDano, const int aLimX, const int aLimY, const int aID = -1);
	virtual ~Arma();
	const int getDano();
	void setDano(const int aDano);
	void setDonoArma(Personagem* const pPers);
	Personagem* const getDonoArma();
	void atualizar();
};

