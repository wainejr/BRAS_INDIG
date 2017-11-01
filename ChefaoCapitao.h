
#pragma once
#include "Inimigo.h"
#include "Lista.h"

class ChefaoCapitao :
	public Inimigo
{
public:
	ChefaoCapitao();
	~ChefaoCapitao();
private:
	Lista<Inimigo*> capangas1;
	Lista<Inimigo*> capangas2;
public:
	void mover();
	void atacar();
	void atualizar();
	void addCapanga1(Inimigo* pInimigo);
	void addCapangas2(Inimigo* pInimigo);
	void mandaCapangas1();
	void mandaCapangas2();
	void builderChefaoCapitao();
};