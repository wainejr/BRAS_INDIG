#pragma once
#include "Entidade.h"
class Plataforma :
	public Entidade
{
protected:
	bool colisaoBaixo;
public:
	Plataforma();
	~Plataforma();
	void setColisaoBaixo(const bool aCol);
	const bool getColisaoBaixo();
	virtual void draw();
	void builderPlataforma(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo);
	virtual void atualizar();
};

