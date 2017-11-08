#pragma once
#include "Obstaculo.h"
class Armadilha :
	public Obstaculo
{
private:
	bool acionada;
	ALLEGRO_TIMER* timer_acionada;
public:
	Armadilha();
	~Armadilha();
	void builderArmadilha(const int ax, const int ay, const int aLimX, const int aLimY, const bool aAtivo, const int aDano);
	void draw(const int aPosFaseX, const int aPosFaseY);
	void atualizar();
	void acionar();
	const bool getAcionada();
	void setAcionada(const bool aAcionada);
	void initTimer();
	void createTimer();
};

