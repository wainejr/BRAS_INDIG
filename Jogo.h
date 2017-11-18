#pragma once
#include "ListaFases.h"
#include "gerenciadorBotoes.h"
#include "MenuPrincipal.h"

class Jogo
{
private:
	enum estadosJogo { MENU, ESCOLHA_FASE, ESCOLHA_PLAYER };
	//VARIAVEIS ALLEGRO
	ALLEGRO_DISPLAY* display;
	ALLEGRO_TIMER* timer;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_FONT* arial18;
	ALLEGRO_BITMAP* fundo;
	
	//	OBJETOS
	ListaFases listaFases;
	gerenciadorBotoes gerBotoes;
	Botao botao_sair;
	Botao botao_controles; //	A FAZER E IMPLEMENTAR UM NOVO ESTADO NO JOGO
	Botao botao_novoJogo;
	Botao botao_campanha;
	Botao botao_fase1;
	Botao botao_fase2;
	Botao botao_fase3;
	Botao botao_tecaRaoni;
	Botao botao_raoniTeca;
	Botao botao_teca;
	Botao botao_raoni;
	Botao botao_voltar;
	
	//	MANUTENÇÃO DA FASE
	bool carregouAllegro;
	static bool done;
	int estadoJogo;
	//

	void initAllegroObjs();
	void destroyAllegroObjs();
	void draw();
	void carregaBotoes();
	void resetaBotoesExceto(Botao* const pBotao);
	void addBotoes();
	void exec();
public:
	Jogo();
	~Jogo();
	static void setDone(const bool aDone);
};

