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
	void builderPlataforma();
};

