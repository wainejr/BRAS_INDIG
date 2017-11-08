#pragma once
#include "Obstaculo.h"
class Espinho :
	public Obstaculo
{
public:
	Espinho();
	~Espinho();
	void builderEspinho(const int ax, const int ay, const int aLimX, const int aLimY, const bool aAtivo, const int aDano);
	void draw(const int aPosFaseX, const int aPosFaseY);
	void atualizar();
};

