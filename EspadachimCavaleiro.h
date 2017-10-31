#pragma once
#include "Inimigo.h"
class EspadachimCavaleiro :
	public Inimigo
{
public:
	EspadachimCavaleiro();
	~EspadachimCavaleiro();
//	void mover();
//	void atacar();
	virtual void mover();
	virtual void atacar();
protected:
	bool cavalo;
public:
	const bool getCavalo();
//	void setCavalo();
	void setCavalo(const bool aCavalo);
	virtual void atualizar();
	void builderEspadachimCav();
};

