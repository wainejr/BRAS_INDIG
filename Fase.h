#pragma once
#include "Mapa.h"
#include "gerenciadorBotoes.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

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
	//

	ALLEGRO_DISPLAY* display;
	ALLEGRO_TIMER* timer;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_FONT* arial18;
	ALLEGRO_BITMAP* fundo;
	ALLEGRO_BITMAP* fundo_pause;
	ALLEGRO_BITMAP* tipo_pause;
	bool carregouAllegro;
	
	//	OBJETOS COMUNS A TODAS FASES
	static Jogador* jog1;
	static Jogador* jog2;
	static int num_jogs;
	gerenciadorBotoes gerBotoesFase;
	Botao botao_continuar;	//MUDAR PARA PONTEIRO PARA BOTÃO DEPOIS
	Botao botao_menu;
	bool carregouBotoes;


	static bool campanha;
	bool fase_completa;
	int numFase;
	
	void initTimers();
	void criarTimers();
	void carregaBotoes();
	void initBotoes();

	//	EXECUÇÃO DA FASE
	void execFase();
	
	void initAllegroObjs();
	void destroyAllegroObjs();
	void restart();

	virtual void numEntidades() = 0;
	void alocaEntidades();
	void deletaEntidades();
	virtual void buildEntidades() = 0;
	void addEntidades();
	
public:
	Fase();
	virtual ~Fase();

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
	static void anulaJogs();
	void setDisplay(ALLEGRO_DISPLAY* const pDisplay);
	void drawPause();
	const int getNumFase();
};
