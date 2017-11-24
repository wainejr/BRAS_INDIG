#pragma once
#include "Fase.h"


class Fase1 :
	public Fase
{
private:
	void numEntidades();
	void buildEntidades();
	
public:
	Fase1();
	~Fase1();
	void initFase();
	void carregaFundoMapa();
};

