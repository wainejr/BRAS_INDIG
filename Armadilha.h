#pragma once
#include "Obstaculo.h"
class Armadilha :
	public Obstaculo
{
public:
	Armadilha();
	~Armadilha();
	void builderArmadilha(const int ax, const int ay, const int aLimX, const int aLimY, const bool aAtivo, const int aDano);
	void draw(const int aPosFaseX, const int aPosFaseY);
	void atualizar();
	void acionar();
private:
	bool acionada;
public:
	const bool getAcionada();
	const bool setAcionada(const bool aAcionada);
};

