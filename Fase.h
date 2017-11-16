#pragma once
#include "Mapa.h"
#include "Botao.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>


/// FAZER UMA FUNÇÃO QUE TIRA E RETIRA OS ELEMENTOS DAS LISTAS, PARA NÃO FICAR COMPARANDO COM TODOS
///	UMA ESPÉCIE DE "TODASPLATAFORMAS", "TODOSMOSQUETEIROS" E AFINS

class Fase
{	
protected:
	//	VARIAVEIS ALLEGRO
	Mapa mapaFase;

	//	PARA ALOCAÇÃO
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

	ALLEGRO_DISPLAY* display;
	ALLEGRO_TIMER* timer;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_FONT* arial18;
	bool carregouAllegro;

	static Jogador* jog1;
	static Jogador* jog2;
	static int num_jogs;
	
	static bool campanha;
	bool fase_completa;
	
	void initTimers();
	void criarTimers();
	
	//	EXECUÇÃO DA FASE
	virtual void execFase() = 0;


	void initAllegroObjs();
	void destroyAllegroObjs();
	void restart();

	//	MOVER PARA FASE.H
	virtual void numEntidades() = 0;
	void alocaEntidades();
	void deletaEntidades();
	virtual void buildEntidades() = 0;
	void addEntidades();

public:
	Fase();
	~Fase();

	virtual void initFase() = 0;
	void setCampanha(const bool aCamp);
	const int getNumJogs();
	void setNumJogs(const int aNumJogs);
	
	Jogador* const getJog1();
	Jogador* const getJog2();
	void setJog1(Jogador* const pJog1);
	void setJog2(Jogador* const pJog2);

	void setFaseCompleta(const bool aCompleta);
	const bool getFaseCompleta();
};
