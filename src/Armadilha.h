#pragma once
#include "Obstaculo.h"
class Armadilha :
	public Obstaculo
{
private:
	bool acionada;
	bool desarmou;
	ALLEGRO_TIMER* timer_acionada;
	
public:
	Armadilha();
	~Armadilha();
	void buildArmadilha(const int ax, const int ay, const bool aAtivo);
	void draw(const int aPosFaseX, const int aPosFaseY);
	void atualizar();
	void acionar();
	const bool getAcionada();
	void setAcionada(const bool aAcionada);
	void initTimer();
	void createTimer();
	void resetaTimer();
	void stopTimers();
	void resumeTimers();
	const bool getDesarmou();
};

