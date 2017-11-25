#pragma once
#include "Fase.h"
class Fase2 :
	public Fase
{
private:
	void numEntidades();
	void buildEntidades();
public:
	Fase2();
	~Fase2();
	void initFase();
	void carregaFundoMapa();
	
};

