#include "Fase.h"

Fase::Fase()
{
	limX = 0;
	limY = 0;
	posRelX = 0;
}


Fase::~Fase()
{

}


bool Fase::personagemPodePular(Personagem* const pPers)
{
	return (colisaoChao(pPers));
}


void Fase::gerenciaColisoes()
{

}


bool Fase::colisaoChao(Personagem* const pEnt)
{
	Plataforma* pPlat;
	if (pEnt->getAtivo()) {
		for (int i = 0; i < plataformas.numObjs(); i++)
		{
			pPlat = plataformas.objI(i);
			if (pPlat->getAtivo())
				if (colisaoPersChao(pEnt, pPlat))
					return true;
		}
	}
	return false;
}


bool Fase::colisaoInimigo(Jogador* const pJog)
{
	Inimigo* pIni;
	if (pJog->getAtivo()) {
		for (int i = 0; i < inimigos.numObjs(); i++)
		{
			pIni = inimigos.objI(i);
			if (pIni->getAtivo())
				if (colisaoPlayerInimigo(pJog, pIni))
					return true;
		}
	}
	return false;
}


bool Fase::colisaoPersChao(Personagem* const pPers, Plataforma* const pPlataforma)
{
	//	checa apenas o pe do personagem se bateu no chao, caso 
	//	afirmativo coloca o pé do player na altura da plataforma
	if (pPers->getY() > (pPlataforma->getY() - pPlataforma->getLimY()) &&
		pPers->getX() < (pPlataforma->getX() + pPlataforma->getLimX()) &&
		(pPers->getX() + pPers->getLimX()) > pPlataforma->getX())
	{
		pPers->setY(pPlataforma->getY() - pPlataforma->getLimY());
		pPers->setVelY(0);
		return true;
	}
	return false;
}


bool Fase::colisaoPlayerInimigo(Jogador* const pPlayer, Inimigo* const pInimigo)
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
	gerenciaColisoes();
}


void Fase::atualizaObjs()
{
	int i;
	//atualizaPlayers();
	for (i = 0; i < jogadores.numObjs(); i++)
	{
		if (jogadores.objI(i)->getAtivo())
		{
			if (jogadores.objI(i)->getFisica() && !personagemPodePular(static_cast<Personagem*>(jogadores.objI(i))))
				jogadores.objI(i)->cair(((float)GRAV/FPS));
			jogadores.objI(i)->atualizar();
		}
	}

	//atualizaInimigos();
	for (i = 0; i < inimigos.numObjs(); i++)
	{
		if (inimigos.objI(i)->getAtivo())
		{
			if (inimigos.objI(i)->getFisica() && !personagemPodePular(static_cast<Personagem*>(inimigos.objI(i))))
				inimigos.objI(i)->cair(((float)GRAV /FPS));
			inimigos.objI(i)->atualizar();
		}
	}

	//atualizaProjeteis();
	for (i = 0; i < projeteis.numObjs(); i++)
	{
		if (projeteis.objI(i)->getAtivo())
			projeteis.objI(i)->atualizar();
	}

}


void Fase::desenhaObjs()
{
	desenhaProjeteis();
	desenhaPlataformas();
	desenhaInimigos();
	desenhaJogadores();
}


void Fase::desenhaFase()
{
	desenhaObjs();
}

void Fase::desenhaJogadores()
{
	for (int i = 0; i < jogadores.numObjs(); i++)
	{
		if (jogadores.objI(i)->getAtivo())
			jogadores.objI(i)->draw();
	}
}


void Fase::desenhaInimigos()
{
	for (int i = 0; i < inimigos.numObjs(); i++)
	{
		if (inimigos.objI(i)->getAtivo())
			inimigos.objI(i)->draw();
	}
}


void Fase::desenhaPlataformas()
{
	for (int i = 0; i < plataformas.numObjs(); i++)
	{
		if (plataformas.objI(i)->getAtivo())
			plataformas.objI(i)->draw();
	}
}


void Fase::desenhaProjeteis()
{
	for (int i = 0; i < projeteis.numObjs(); i++)
	{
		if (projeteis.objI(i)->getAtivo())
			projeteis.objI(i)->draw();
	}
}


void Fase::addPlataforma(Plataforma* const pPlataforma)
{
	plataformas.addObj(pPlataforma);
}


void Fase::addInimigo(Inimigo* const pInimigo)
{
	inimigos.addObj(pInimigo);
}


void Fase::addPlayer(Jogador* const pPlayer)
{
	jogadores.addObj(pPlayer);
}


void Fase::addProjetil(Projetil* const pProj)
{
	projeteis.addObj(pProj);
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