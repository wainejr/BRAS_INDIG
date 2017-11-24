#pragma once
#include "Entidade.h"
class Plataforma :
	public Entidade
{
protected:
	bool colisaoBaixo;
public:
	Plataforma();
	Plataforma(const bool aColisaoBaixo, const int aID = PLATAFORMA, const int aPosX = 0, const int aPosY = 0, const int aLimX = 100, const int aLimY = 10);
	~Plataforma();
	void setColisaoBaixo(const bool aCol);
	const bool getColisaoBaixo();
	void draw(const int aPosFaseX, const int aPosFaseY);
	void buildPlataforma(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const bool aColisaoBaixo);
	virtual void atualizar();
};

