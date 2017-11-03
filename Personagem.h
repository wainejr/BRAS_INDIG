#pragma once
#include "Entidade.h"
#include "Arma.h"

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
	Arma* const getArma();
	void parar();
	virtual void atacar();
	virtual void atualizar() = 0;
	void atualizaArma();
	virtual void draw(const int aPosFaseX, const int aPosFaseY) = 0;

	void setArma(Arma* const pArma);
	void setDir(bool const aDir);
	const bool getDir();
	void cair(const float acAt);
};

