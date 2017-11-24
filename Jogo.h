#pragma once
#include "ListaFases.h"
#include "Fase1.h"
#include "Fase2.h"
#include "FaseFinal.h"
#include "gerenciadorBotoes.h"
#include "Jogador.h"


class Jogo
{
private:
	enum estadosJogo { MENU, ESCOLHA_FASE, ESCOLHA_PLAYER, PONTUACAO };

	//VARIAVEIS ALLEGRO
	ALLEGRO_DISPLAY* display;
	ALLEGRO_TIMER* timer;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_FONT* arial18;
	ALLEGRO_BITMAP* fundo;
	ALLEGRO_BITMAP* tipo_brasilIndig;
	ALLEGRO_BITMAP* tipo_1jogador;
	ALLEGRO_BITMAP* tipo_2jogadores;
	
	//	OBJETOS
	ListaFases listaFases;
	gerenciadorBotoes gerBotoes;
	gerenciaPontuacoes gerPont;
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
	Botao botao_pontuacao;
	
	Fase1 fase1;
	Fase2 fase2;
	FaseFinal faseFinal;

	Jogador raoni;
	Jogador teca;

	//	MANUTENÇÃO DA FASE
	bool carregouAllegro;
	static bool done;
	int estadoJogo;
	//

	void initAllegroObjs();
	void destroyAllegroObjs();
	void draw();
	void carregaBotoes();
	void buildJogadores();
	void resetaJogs();
	void resetaBotoesExceto(Botao* const pBotao);
	void addBotoes();
	void exec();
public:
	Jogo();
	~Jogo();
	static void setDone(const bool aDone);
	void salvaPontuacao(const float aPont, const int aN);
};

