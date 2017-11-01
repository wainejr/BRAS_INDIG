#pragma once
#include "definesMacros.h"
#include "ListaEntidades.h"

class Fase
{	
protected:
	//	DECIDIR SE AS LISTAS DE ENTIDADES SERÃO TEMPLATES OU SÓ RECEBERÃO 
	//	ENTIDADES OU FAZER LISTAS DERIVADAS DE LISTA ENTIDADE
	ListaEntidades plataformas;
	ListaEntidades inimigos;
	ListaEntidades jogadores;
	ListaEntidades projeteis;
	int limX;
	int limY;

	void checaColisoes(); //tiros, ataques e afins
	void desenhaObjs();
	void atualizaObjs();
	bool ColisaoPersChao(Entidade* const pPers, Entidade* const pPlataforma);
	bool colisaoPlayerInimigo(Entidade* const pPlayer, Entidade* const pInimigo);
	bool colisaoChao(Entidade* pEnt);
	
public:
	Fase();
	~Fase();
	
	void addPlataforma(Plataforma* const pPlataforma);
	void addInimigo(Inimigo* const pInimigo);
	void addPlayer(Jogador* const pPlayer);
	void addProjetil(Projetil* const pProj);

	bool jogadorPodePular(Jogador* pJog);
	void atualizaFase();
	void desenhaFase();

	const int getLimX();
	void setLimX(const int aLimX);
	const int getLimY();
	void setLimY(const int aLimY);
	bool colisaoInimigo(Jogador* const pJog);
	void atualizaPlayer();
	void atualizaInimigos();
	void atualizaProjeteis();
};