#pragma once
#include "Inimigo.h"
class EspadachimCavaleiro :
	public Inimigo
{
protected:
	bool cavalo;

public:
	EspadachimCavaleiro();
	~EspadachimCavaleiro();
	virtual void mover();
	virtual void atacar();
	const bool getCavalo();
	void setCavalo(const bool aCavalo);
	virtual void atualizar();
	void builderEspadachimCav(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const int aVida, Arma* const pArma);
	virtual void draw(const int aPosFaseX, const int aPosFaseY);
};

