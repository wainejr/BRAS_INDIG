#pragma once
#include "Fase.h"


class Fase1 :
	public Fase
{
private:
	Jogador* jog1;		///	SERÁ ALOCADO NA FASE.H
	Jogador* jog2;

	///	PARA ALOCAMENTO E INICIALIZAÇÃO DA FASE
	///	TALVEZ FAZER AS ARMAS SEREM CRIADAS NO BUILDER DOS INIMIGOS E JOGADORES
	Mosqueteiro** mosqs;
	Mosquete** mosquetes;
	int num_mosq;
	
	Espadachim** esps;
	Espada** espadas;
	int num_esps;

	EspadachimCavaleiro** cavs;
	Lanca** lancas;
	int num_cavs;

	Plataforma** plats;
	int num_plats;

	Corda** cords;
	int num_cordas;

	Armadilha** armds;
	int num_armds;

	Espinho** espins;
	int num_espinhos;

	Rede** reds;
	int num_redes;

	//	TESTE
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
	//


	void execFase();
	void initObjs();
	void initAllegroObjs();
	void restart();

	void numEntidades();
	void alocaEntidades();
	void deletaEntidades();
	void buildEntidades();
	void addEntidades();

	//FUNÇÃO PARA TESTES RETIRAR DEPOIS
	void imprimeVida();
	
public:
	Fase1();
	~Fase1();
	void initFase();
};

