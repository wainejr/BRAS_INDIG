#pragma once
#include "Fase.h"
class Fase2 :
	public Fase
{
public:
	Fase2();
	~Fase2();

	void carregaFundoMapa();
	void restart();
	void initFase();

	void numEntidades() {}
	void buildEntidades() {}
};

