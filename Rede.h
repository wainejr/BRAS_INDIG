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
	void builderRede(const int ax, const int ay, const int aLinhaX, const int aLinhaY, const bool aAtivo);
	void ativar();
	const bool getAtivada();
	void draw(const int aPosFaseX, const int aPosFaseY);
	void atualizar();
	void reset(const int ax, const int ay, const bool aAtivo);
};

