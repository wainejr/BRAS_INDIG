#pragma once
#include "Entidade.h"
class Corda :
	public Entidade
{
private:
	bool escalavel;
public:
	Corda();
	~Corda();
	void setEscalavel(const bool aEscalav);
	const bool getEscalavel();
	void draw(const int aPosFaseX, const int aPosFaseY);
	void builderCorda(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const bool aEscalavel);
	void atualizar();
};

