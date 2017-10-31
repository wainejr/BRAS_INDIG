#include "Fase.h"



Fase::Fase()
{
}


Fase::~Fase()
{
}


void Fase::addPlataforma(Plataforma* const pPlataforma)
{
	plataformas.addEntidade(pPlataforma);
}


void Fase::addInimigo(Inimigo* const pInimigo)
{
	inimigos.addEntidade(pInimigo);
}


void Fase::addPlayer(Jogador* const pPlayer)
{
	jogadores.addEntidade(pPlayer);
}


void Fase::ColisaoPlayerPlataforma(Jogador* const pPlayer, Plataforma* const pPlataforma)
{
	/* a fazer */
}

void Fase::checaColisoes()
{
	/* a fazer */
}


void Fase::colisaoPlayerInimigo(Jogador* const pPlayer, Inimigo* const pInimigo)
{
}


void Fase::atualizaFase()
{
	atualizaObjs();
	checaColisoes();
}


void Fase::desenhaObjs()
{
	
	plataformas.desenhaAtivos();
	jogadores.desenhaAtivos();	
	inimigos.desenhaAtivos();
}


void Fase::atualizaObjs()
{

}


void Fase::desenhaFase()
{
	desenhaObjs();
}
