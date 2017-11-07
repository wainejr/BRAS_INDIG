#pragma once
#include "Fase.h"


class Fase1 :
	public Fase
{
private:
	Espadachim inimigo1;
	EspadachimCavaleiro cav1;
	Plataforma chao;
	Plataforma plat1;
	Plataforma plat2;
	Plataforma plat3;
	Plataforma plat4;
	Espada armaInimigo;
	Mosqueteiro inimigoMosq1;
	Mosquete armaMosq1;
	Lanca lanc1;
	Corda corda1;

	

public:
	Fase1();
	~Fase1();

	void initFase();
	void execFase();
	void initObjs();
	void initAllegroObjs();
	void initInimigos();
	void initPlataformas();
	void restart();

	//FUNÇÃO PARA TESTES RETIRAR DEPOIS
	void imprimeVida();
};

