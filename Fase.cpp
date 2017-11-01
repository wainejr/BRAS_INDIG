#include "Fase.h"



Fase::Fase()
{
	limX = 0;
	limY = 0;
}


Fase::~Fase()
{
}


bool Fase::jogadorPodePular(Jogador* pJog)
{
	return (colisaoChao(static_cast<Entidade*>(pJog)));
}


void Fase::checaColisoes()
{
	/* a fazer */
}


bool Fase::colisaoChao(Entidade* pEnt)
{
	Entidade* pPlat;
	if (pEnt->getAtivo()) {
		for (int i = 0; i < plataformas.numEntidades(); i++)
		{
			pPlat = plataformas.entidadeI(i);
			if (pPlat->getAtivo())
				if (ColisaoPersChao(pEnt, pPlat))
					return true;

		}
	}
	return false;
}


bool Fase::colisaoInimigo(Jogador* const pJog)
{
	Entidade* pIni;
	if (pJog->getAtivo()) {
		for (int i = 0; i < inimigos.numEntidades(); i++)
		{
			pIni = inimigos.entidadeI(i);
			if (pIni->getAtivo())
				if (ColisaoPersChao(pJog, pIni))
					return true;
		}
	}
	return false;
}


bool Fase::ColisaoPersChao(Entidade* const pPers, Entidade* const pPlataforma)
{
	/* checa apenas o pe do personagem se bateu no chao */
	if (pPers->getY() > (pPlataforma->getY() - pPlataforma->getLimY()) &&
		pPers->getX() < (pPlataforma->getX() + pPlataforma->getLimX()) &&
		(pPers->getX() + pPers->getLimX()) > pPlataforma->getX())
		return true;

	return false;
}


bool Fase::colisaoPlayerInimigo(Entidade* const pPlayer, Entidade* const pInimigo)
{
	if (pPlayer->getY() > (pInimigo->getY() - pInimigo->getLimY()) &&
		pPlayer->getX() < (pInimigo->getX() + pInimigo->getLimX()) &&
		(pPlayer->getX() + pPlayer->getLimX()) > pInimigo->getX() &&
		(pPlayer->getY() - pPlayer->getLimY()) < pInimigo->getY())
		return true;

	return false;
}


void Fase::atualizaFase()
{
	atualizaObjs();
	checaColisoes();
}


void Fase::atualizaObjs()
{
	int i;
	for (i = 0; i < jogadores.numEntidades(); i++)
		jogadores.entidadeI(i)->atualizar();
	for (i = 0; i < inimigos.numEntidades(); i++)
		inimigos.entidadeI(i)->atualizar();
	for (i = 0; i < projeteis.numEntidades(); i++)
		projeteis.entidadeI(i)->atualizar();
}


void Fase::desenhaObjs()
{
	plataformas.desenhaAtivos();
	jogadores.desenhaAtivos();	
	inimigos.desenhaAtivos();
	projeteis.desenhaAtivos();
}


void Fase::desenhaFase()
{
	desenhaObjs();
}


void Fase::addPlataforma(Plataforma* const pPlataforma)
{
	plataformas.addEntidade(static_cast<Entidade*>(pPlataforma));
}


void Fase::addInimigo(Inimigo* const pInimigo)
{
	inimigos.addEntidade(static_cast<Entidade*>(pInimigo));
}


void Fase::addPlayer(Jogador* const pPlayer)
{
	jogadores.addEntidade(static_cast<Entidade*>(pPlayer));
}


void Fase::addProjetil(Projetil* const pProj)
{
	projeteis.addEntidade(static_cast<Entidade*>(pProj));
}


const int Fase::getLimX()
{
	return limX;
}


void Fase::setLimX(const int aLimX)
{
	limX = aLimX;
}


const int Fase::getLimY()
{
	return limY;
}


void Fase::setLimY(const int aLimY)
{
	limY = aLimY;
}