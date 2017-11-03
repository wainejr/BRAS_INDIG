#pragma once
#include "Fase.h"


class Fase1 :
	public Fase
{
private:
	Espadachim inimigo1;
	Plataforma chao;
	Espada armaInimigo;
	Mosqueteiro inimigoMosq1;
	Mosquete armaMosq1;

public:
	Fase1();
	~Fase1();

	void initFase();
	void execFase();
};

