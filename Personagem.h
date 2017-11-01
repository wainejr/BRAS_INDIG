#pragma once
#include "Entidade.h"
#include "Arma.h"
#define VEL_PULO 30

class Personagem :
	public Entidade
{
protected:
	int vida;
	Arma* arma;
	//	verdadeiro para personagem virado para direita,
	//	falso para personagem virado para esquerda
	bool dir;

public:
	Personagem();
	~Personagem();
	const int getVida();
	void setVida(const int aVida);
	Arma* getArma();
	virtual void atacar();
	virtual void atualizar();
	void atualizaArma();
	virtual void draw() = 0;
	void setArma(Arma* const pArma);
	void setDir(bool const aDir);
	const bool getDir();
};

