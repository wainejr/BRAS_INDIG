#pragma once
#include "Fase.h"


class Fase1 :
	public Fase
{
private:
	Jogador** jogs;		///	SERÁ ALOCADO NA FASE
	
	///	PARA ALOCAMENTO E INICIALIZAÇÃO DO JOGO
	Mosqueteiro** mosqs;
	Espadachim** esps;
	EspadachimCavaleiro** cavs;

	Plataforma** plats;
	Corda** cords;

	Armadilha** armds;
	Espinho** espins;
	Rede** reds;

	Espada** espadas;
	Lanca** lancas;
	Mosquete** mosquetes;

	int num_mosq;
	int num_esps;
	int num_cavs;
	int num_plats;
	int num_cordas;
	int num_armds; 
	int num_espinhos;
	int num_redes;
	int num_espadas;
	int num_lancas;
	int num_mosquetes;


	///	TESTE
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
	Espinho espinho1;
	Armadilha armd1;
	Rede rede1;
	Corda rede1cord;

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

