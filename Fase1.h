#pragma once
#include "Fase.h"


class Fase1 :
	public Fase
{
private:
	///	PARA ALOCAMENTO E INICIALIZAÇÃO DA FASE
	///	TALVEZ FAZER AS ARMAS SEREM CRIADAS NO BUILDER DOS INIMIGOS E JOGADORES
	Mosqueteiro** mosqs;
	int num_mosq;
	
	Espadachim** esps;
	int num_esps;

	EspadachimCavaleiro** cavs;
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

