#pragma once
#include "Entidade.h"
class Obstaculo :
	public Entidade
{
protected:
	int dano;
	bool criouTimer;
public:
	Obstaculo();
	virtual ~Obstaculo();
	const int getDano();
	void setDano(const int aDano);
	virtual void initTimer() = 0;
	virtual void createTimer() = 0;
	virtual void resetaTimer() = 0;
	virtual void stopTimers() = 0;
	virtual void resumeTimers() = 0;
};

