#pragma once
#include "Mapa.h"
#include "gerenciadorBotoes.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#define PER_FASECOMP 2.5
#define PER_PONT 0.02

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

	Cavaleiro** cavs;
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
	ALLEGRO_TIMER* tempo_pontuacao;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_FONT* arial18;
	
	ALLEGRO_BITMAP* fundo_pause;
	ALLEGRO_BITMAP* logo_pause;
	ALLEGRO_BITMAP* logo_colonizado;
	ALLEGRO_BITMAP* logo_fase_completa;
	bool carregouAllegro;
	bool carregouFundoMapa;
	
	//	OBJETOS COMUNS A TODAS FASES
	static Jogador* jog1;
	static Jogador* jog2;
	static int num_jogs;
	gerenciadorBotoes gerBotoesFase;
	Botao botao_continuar;	
	Botao botao_menu;
	bool carregouBotoes;


	static bool campanha;
	bool fase_completa;
	bool derrota;
	
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
	void drawLayout();
	virtual void carregaFundoMapa() = 0;
	void drawPause();

public:
	Fase();
	virtual ~Fase();

	void initFase();
	void setCampanha(const bool aCamp);
	const int getNumJogs();
	void setNumJogs(const int aNumJogs);
	
	static Jogador* const getJog1();
	static Jogador* const getJog2();
	static void setJog1(Jogador* const pJog1);
	static void setJog2(Jogador* const pJog2);

	void setFaseCompleta(const bool aCompleta);
	const bool getFaseCompleta();
	static void anulaJogs();
	void setDisplay(ALLEGRO_DISPLAY* const pDisplay);
	void resumeTimers();
	void stopTimers();
	const float getPontuacao();
};
