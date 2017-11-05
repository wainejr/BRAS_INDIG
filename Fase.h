#pragma once
#include "definesMacros.h"
#include "EntConcreteClasses.h"
#include "Lista.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>


///FAZER UMA FUNÇÃO DO TIPO "PODE ANDAR PRA ESQUERDA/DIREITA"

class Fase
{	
protected:
	//VARIAVEIS ALLEGRO
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT_QUEUE* queue = NULL;
	ALLEGRO_FONT* arial18 = NULL;

	Jogador player1;
	Espada armaPlayer;

	Lista <Plataforma*> plataformas;
	Lista <Mosqueteiro*> mosqueteiros;
	Lista <Espadachim*> espadachins;
	Lista <EspadachimCavaleiro*> cavaleiros;
	Lista <Jogador*> jogadores;
	Lista <Projetil*> projeteis;

	int limX;
	int limY;
	int posRelX;
	int posRelY;

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
	void addEspadachim(Espadachim* const pEsp);
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
	void atualizaPosFase();
	void addCavaleiro(EspadachimCavaleiro* const pCav);
	void colisaoProjeteis(Personagem* const pPers);
	bool colisaoPersProj(Personagem* const pPers, Projetil* const pProj);
	virtual void restart() = 0;
	void resetAllObjs();
	void initTimers();
	const bool colisaoEntEnt(Entidade* const pEnt1, Entidade* const pEnt2);
	void criarTimers();
	const bool colisaoPlat(Entidade* const pEnt);
	const bool colisaoProjPlat(Projetil* const pProj);
};
