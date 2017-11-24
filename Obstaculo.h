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
	Obstaculo(const int aDano, const int aID = -1, const int aLimX = 0, const int aLimY = 0, 
		const float aPosX = 0, const float aPosY = 0, const float aVelX = 0, const float aVelY = 0,
		const float aVelMaxX = 0, const float aVelMaxY = 0,
		const bool aAtivo = false, const bool aFisica = false);
	virtual ~Obstaculo();
	const int getDano();
	void setDano(const int aDano);
	virtual void initTimer() = 0;
	virtual void createTimer() = 0;
	virtual void resetaTimer() = 0;
	virtual void stopTimers() = 0;
	virtual void resumeTimers() = 0;
};

