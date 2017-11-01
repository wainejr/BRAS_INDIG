#pragma once
#include "definesMacros.h"
#include "EntConcreteClasses.h"
#include "Lista.h"

class Fase
{	
protected:
	//	DECIDIR SE AS LISTAS DE ENTIDADES SERÃO TEMPLATES OU SÓ RECEBERÃO 
	//	ENTIDADES OU FAZER LISTAS DERIVADAS DE LISTA ENTIDADE
	Lista <Plataforma*> plataformas;
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

	bool personagemPodePular(Personagem* const pPers);
	void atualizaFase();
	void atualizaPlayer();
	void atualizaInimigos();
	void atualizaProjeteis();

	void desenhaFase();

	const int getLimX();
	void setLimX(const int aLimX);
	const int getLimY();
	void setLimY(const int aLimY);
	
	
	void desenhaJogadores();
	void desenhaInimigos();
	void desenhaPlataformas();
	void desenhaProjeteis();
	const bool personagemPodeAndarDireita(Personagem* const pPers);
	const bool personagemPodeAndarEsquerda(Personagem* const pPers);
};
