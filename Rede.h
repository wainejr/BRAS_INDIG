#pragma once
#include "Obstaculo.h"
#include "Corda.h"
class Rede :
	public Obstaculo
{
public:
	Rede();
	~Rede();
private:
	Corda* linha;
	bool ativada;
public:
	Corda* const getCorda();
	void setCorda(Corda* const pCorda);
	void builderRede(const int ax, const int ay, const int aLimX, const int aLimY, const bool aAtivo, const int aDano);
	void ativar();
	const bool getAtivada();
	void draw(const int aPosFaseX, const int aPosFaseY);
};

