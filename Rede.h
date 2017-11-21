#pragma once
#include "Obstaculo.h"
#include "Corda.h"
class Rede :
	public Obstaculo
{
private:
	Corda* linha;
	bool ativada;
	void initTimer();
	void createTimer();
	void resetaTimer();
	void stopTimers();
	void resumeTimers();
public:
	Rede();
	~Rede();	
	Corda* const getCorda();
	void builderRede(const int ax, const int ay, const int aLinhaX, const int aLinhaY, const bool aAtivo);
	void ativar();
	const bool getAtivada();
	void draw(const int aPosFaseX, const int aPosFaseY);
	void atualizar();
	void reset(const int ax, const int ay, const bool aAtivo);
};

