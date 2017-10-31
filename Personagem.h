#pragma once
#include "Entidade.h"
#include "Arma.h"
class Personagem :
	public Entidade
{
protected:
	int vida;
	Arma* arma;

public:
	Personagem();
	~Personagem();
	const int getVida();
	void setVida(const int aVida);
	Arma* getArma();
	virtual void atacar();
	virtual void atualizar();
	virtual void draw() = 0;
	void setArma(Arma* const pArma);
};

