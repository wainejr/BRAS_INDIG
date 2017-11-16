#pragma once
#define LARG_BOTAO 120
#define ALT_BOTAO 30
#include "ListaFases.h"

class Jogo
{
private:
	enum estadosJogo { MENU, ESCOLHA_NOVO_JOGO, ESCOLHA_NUM_PLAYER, ESCOLHA_PLAYER };
	//VARIAVEIS ALLEGRO
	ALLEGRO_DISPLAY* display;
	ALLEGRO_TIMER* timer;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_FONT* arial18;
	ALLEGRO_BITMAP* fundo;
	Botao botao_sair;
	Botao botao_novoJogo;
	Botao botao_campanha;
	Botao botao_faseN;
	Botao botao_numJogs;
	Botao botao_Jogs;
	//

	bool carregouAllegro;

	int estadoJogo;
	
	//OBJETOS
	ListaFases listaFases;

	//
	void initAllegroObjs();
	void destroyAllegroObjs();
	void draw();
	void carregaBotoes();
	void exec();
public:
	Jogo();
	~Jogo();
	bool mouseEstaNoBotao(Botao* const pBotao, const int mouseX, const int mouseY);
};

