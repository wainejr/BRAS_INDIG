#pragma once
#include "Fase.h"


class Fase1 :
	public Fase
{
private:

	void numEntidades();
	void buildEntidades();

	//FUNÇÃO PARA TESTES RETIRAR DEPOIS
	void imprimeVida();
	
public:
	Fase1();
	~Fase1();
	void initFase();
};

