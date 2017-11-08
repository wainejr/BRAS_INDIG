#pragma once
#include "definesMacros.h"
#include "EntConcreteClasses.h"
#include "Lista.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>


/// FAZER UMA FUNÇÃO QUE TIRA E RETIRA OS ELEMENTOS DAS LISTAS, PARA NÃO FICAR COMPARANDO COM TODOS
///	UMA ESPÉCIE DE "TODASPLATAFORMAS", "TODOSMOSQUETEIROS" E AFINS

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
	Lista <Corda*> cordas;
	Lista <Armadilha*> armadilhas;
	Lista <Espinho*> espinhos;
	Lista <Rede*> redes;

	int limX;
	int limY;
	int posRelX;
	int posRelY;

	void gerenciaColisoes(); //tiros, ataques e afins
	void desenhaObjs();
	void atualizaObjs();
	const bool colisaoChao(Personagem* const pEnt);
	const bool colisaoInimigo(Jogador* const pJog);
	
public:
	Fase();
	~Fase();
	
	void addPlataforma(Plataforma* const pPlataforma);
	void addEspadachim(Espadachim* const pEsp);
	void addPlayer(Jogador* const pPlayer);
	void addProjetil(Projetil* const pProj);
	void addMosqueteiro(Mosqueteiro* const pMosq);

	const bool personagemPodePular(Personagem* const pPers);
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
	const bool colisaoPersChao(Personagem* const pPers, Plataforma* const pPlataforma);
	virtual void restart() = 0;
	void resetAllObjs();
	void initTimers();
	const bool colisaoEntEnt(Entidade* const pEnt1, Entidade* const pEnt2);
	void criarTimers();
	const bool colisaoPlat(Entidade* const pEnt);	//gere a colisão
	const bool colisaoEntPlat(Entidade* const pEnt);	//apenas vê se a colisão ocorreu
	const bool personagemPodeAtacar(Personagem* const pPers);
	void atualizaAtivos();
	const bool jogadorPodeSubir(Jogador* const  pJog);
	void addCorda(Corda* const pCorda);
	void desenhaCordas();
	const bool jogadorEstaNumaCorda(Jogador* const pJog);
	void addArmadilha(Armadilha* const pArmd);
	void addEspinho(Espinho* const pEspinho);
	void addRede(Rede* const pRede);
	void desenhaEspinhos();
	void desenhaRedes();
	void desenhaArmadilhas();
	void colisaoEspinhos(Personagem* const pPers);
	void gereColisao(Entidade* const pMovel, Entidade* const pParado);
	void colisaoArmadilhas(Jogador* const pJog);
	void colisaoLinhaRede(Jogador* const pJog);
	void colisaoRede(Jogador* const pJog);
};
