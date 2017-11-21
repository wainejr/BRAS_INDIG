#pragma once
#include "Obstaculo.h"
class Espinho :
	public Obstaculo
{
public:
	Espinho();
	~Espinho();
	void builderEspinho(const int ax, const int ay, const int aLimX, const int aLimY, const bool aAtivo);
	void draw(const int aPosFaseX, const int aPosFaseY);
	void atualizar();
	void initTimer();
	void createTimer();
	void resetaTimer();
	void stopTimers();
	void resumeTimers();
};

