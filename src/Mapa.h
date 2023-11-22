#pragma once
#include "EntConcreteClasses.h"
#include "Lista.h"
#include "ListaEntidades.h"
#include "ListaInimigos.h"
#include "ListaObstaculos.h"
#include "ListaProjeteis.h"
#include "ListaPlataformas.h"
#include "definesMacros.h"

// a cada RATE_MF de movimenta��o do mapa o fundo se move 1 pixel
#define RATE_MF 5
class Mapa
{
private:
	Jogador* jog1;
	Jogador* jog2;

	ALLEGRO_BITMAP* fundo;

	ListaEntidades entidades;
	ListaInimigos inimigos;
	ListaProjeteis projeteis;
	ListaObstaculos obstaculos;
	ListaPlataformas plataformas;
	
	//	PROPRIEDADES DE POSI��O DO MAPA
	int limX;
	int limY;
	int posRelX;
	int posRelY;
	
	void atualizaPosMapa();

	//	CHAMA O ATUALIZAR DAS ENTIDADES
	void atualizaObjs();

	//	ATUALIZA QUAIS ENTIDADES EST�O ATIVAS
	void atualizaAtivos();

	//	ATUALIZA QUAIS OS ALVOS DOS INIMIGOS
	void atualizaAlvos();
	void alvoInimigo(Inimigo* const pIni);

	//	GERENCIA COLIS�ES E DANO ENTRE PERSONAGENS
	void gerenciaColisoes();

	void gerenciaColisaoAtaques();
	void gerenciaColisaoPlatObstProj();

	const bool colisaoChao(Personagem* const pEnt);
	const bool colisaoInimigo(Jogador* const pJog);
	const bool colisaoPlat(Entidade* const pEnt);		//	gere a colis�o
	const bool colisaoEntPlat(Entidade* const pEnt);	//	apenas v� se a colis�o ocorreu

	void colisaoProjeteis(Personagem* const pPers);
	void colisaoLinhaRede(Jogador* const pJog);

	const bool colisaoPersChao(Personagem* const pPers, Plataforma* const pPlataforma);
	const bool colisaoEntEnt(Entidade* const pEnt1, Entidade* const pEnt2);
	void gereColisao(Entidade* const pMovel, Entidade* const pParado);

	//	GERENCIA OS ATAQUES DOS INIMGOS
	void ataqueInimigos();

	void colisaoObstaculos(Personagem* const pPers);
	const int diffCent(Entidade* const pEnt1, Entidade* const pEnt2);

	void desenhaFundo();
	
	void validaPosPers();
	const bool estaNaTela(Entidade* const pEnt);

public:
	Mapa();
	~Mapa();

	//	ATUALIZA TODO O MAPA
	void atualizaMapa();

	//	DESENHA AS ENTIDADES DO MAPA
	void desenhaObjs();

	//	GERENCIA PERMISS�ES DO PERSONAGEM
	const bool personagemPodeAtacar(Personagem* const pPers);
	const bool jogadorPodeSubir(Jogador* const  pJog);
	const bool personagemPodePular(Personagem* const pPers);
	const bool jogadorEstaNumaCorda(Jogador* const pJog);
	const bool persPodeDescerPlat(Personagem* const pPers);
	void perDescePlat(Personagem* const pPers);			//	desce o personagem da plataforma caso poss�vel

	//	RETIRA TODOS AS ENTIDADES DO MAPA
	void retiraTodosObjs();

	void addPlayer(Jogador* const pPlayer);
	void addPlataforma(Plataforma* const pPlataforma);
	void addInimigo(Inimigo* const pIni);
	void addProjetil(Projetil* const pProj);
	void addObstaculo(Obstaculo* const pObs);

	void criarTimers();
	void initTimers();
	void stopTimers();
	void resumeTimers();
	void resetTimers();

	void setFundo(ALLEGRO_BITMAP* const pFundo);

	const int getLimX();
	void setLimX(const int aLimX);
	const int getLimY();
	void setLimY(const int aLimY);
	const bool haInimigos();
};

