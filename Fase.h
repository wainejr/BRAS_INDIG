#pragma once
#include "ListaEntidades.h"
class Fase
{	
protected:
	ListaEntidades plataformas;
	ListaEntidades inimigos;
	ListaEntidades jogadores;
	void checaColisoes();
	void desenhaObjs();
	void atualizaObjs();
	void ColisaoPlayerPlataforma(Jogador* const pPlayer, Plataforma* const pPlataforma);
	void colisaoPlayerInimigo(Jogador* const pPlayer, Inimigo* const pInimigo);
public:
	Fase();
	~Fase();
	void addPlataforma(Plataforma* const pPlataforma);
	void addInimigo(Inimigo* const pInimigo);
	void addPlayer(Jogador* const pPlayer);
	void atualizaFase();
	void desenhaFase();
};