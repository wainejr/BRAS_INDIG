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
	void mover();
	const bool getCavalo();
	void setCavalo(const bool aCavalo);
	void atualizar();
	void builderEspadachimCav(int ax, const int ay, const bool aAtivo, Jogador* const pAlvo);
	virtual void draw(const int aPosFaseX, const int aPosFaseY);
	void createTimers();
	void atualizaAtaque();
};

