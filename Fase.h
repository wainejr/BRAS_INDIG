#pragma once
#include "definesMacros.h"
#include "EntConcreteClasses.h"
#include "Lista.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

class Fase
{	
protected:
	//VARIAVEIS ALLEGRO
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* queue = NULL;
	ALLEGRO_FONT* arial18 = NULL;

	Jogador player1;
	Mosquete armaPlayer;

	Lista <Plataforma*> plataformas;
	Lista <Mosqueteiro*> mosqueteiros;
	Lista <Inimigo*> inimigos;
	Lista <Jogador*> jogadores;
	Lista <Projetil*> projeteis;
	int limX;
	int limY;
	int posRelX;

	void gerenciaColisoes(); //tiros, ataques e afins
	void desenhaObjs();
	void atualizaObjs();
	bool colisaoPersChao(Personagem* const pPers, Plataforma* const pPlataforma);
	bool colisaoPlayerInimigo(Jogador* const pPlayer, Inimigo* const pInimigo);
	bool colisaoChao(Personagem* const pEnt);
	bool colisaoInimigo(Jogador* const pJog);
	
public:
	Fase();
	~Fase();
	
	void addPlataforma(Plataforma* const pPlataforma);
	void addInimigo(Inimigo* const pInimigo);
	void addPlayer(Jogador* const pPlayer);
	void addProjetil(Projetil* const pProj);
	void addMosqueteiro(Mosqueteiro* const pMosq);

	bool personagemPodePular(Personagem* const pPers);
	void atualizaFase();
	void atualizaPlayer();
	void atualizaInimigos();
	void atualizaProjeteis();

	const int getLimX();
	void setLimX(const int aLimX);
	const int getLimY();
	void setLimY(const int aLimY);
	
	
	void desenhaJogadores();
	void desenhaInimigos();
	void desenhaPlataformas();
	void desenhaProjeteis();
	virtual void initFase() = 0;
	virtual void execFase() = 0;
	void ataqueInimigos();
};
