#include "Fase.h"

Fase::Fase()
{
	limX = 0;
	limY = 0;
	posRelX = 0;
	posRelY = 0;
	player1.builderJogador(10, ALT - 10, 20, 30, true, 100, &armaPlayer, 3);
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
	int i;
	for (i = 0; i < jogadores.numObjs(); i++)
	{
		if (jogadores.objI(i)->getAtivo() && !jogadores.objI(i)->getInvuneravel())
		{
			colisaoProjeteis(static_cast<Personagem*>(jogadores.objI(i)));
		}
	}
	for (i = 0; i < mosqueteiros.numObjs(); i++)
	{
		if (mosqueteiros.objI(i)->getAtivo())
		{
			colisaoProjeteis(static_cast<Personagem*>(mosqueteiros.objI(i)));
		}
	}
	for (i = 0; i < espadachins.numObjs(); i++)
	{
		if (espadachins.objI(i)->getAtivo())
		{
			colisaoProjeteis(static_cast<Personagem*>(espadachins.objI(i)));
		}
	}
	for (i = 0; i < cavaleiros.numObjs(); i++)
	{
		if (cavaleiros.objI(i)->getAtivo())
		{
			colisaoProjeteis(static_cast<Personagem*>(cavaleiros.objI(i)));
		}
	}
}


bool Fase::colisaoChao(Personagem* const pPers)
{
	Plataforma* pPlat;
	if (pPers->getAtivo()) 
	{
		for (int i = 0; i < plataformas.numObjs(); i++)
		{
			pPlat = plataformas.objI(i);
			if (pPlat->getAtivo())
			{	if (colisaoPersChao(pPers, pPlat))
				{
					return true;
				}
			}
		}
	}
	return false;
}


bool Fase::colisaoInimigo(Jogador* const pJog)
{
	Inimigo* pIni;
	if (pJog->getAtivo()) {
		for (int i = 0; i < espadachins.numObjs(); i++)
		{
			pIni = static_cast<Inimigo*>(espadachins.objI(i));
			if (pIni->getAtivo())
				if (colisaoPlayerInimigo(pJog, pIni))
					return true;
		}
		for (int i = 0; i < mosqueteiros.numObjs(); i++)
		{
			pIni = static_cast<Inimigo*>(mosqueteiros.objI(i));
			if (pIni->getAtivo())
				if (colisaoPlayerInimigo(pJog, pIni))
					return true;
		}
		for (int i = 0; i < cavaleiros.numObjs(); i++)
		{
			pIni = static_cast<Inimigo*>(cavaleiros.objI(i));
			if (pIni->getAtivo())
				if (colisaoPlayerInimigo(pJog, pIni))
					return true;
		}
	}
	return false;
}


bool Fase::colisaoPersChao(Personagem* const pPers, Plataforma* const pPlataforma)
{
	//	checa apenas se o pe do personagem se bateu no chão 
	if ((pPers->getY()) >= (pPlataforma->getY() - pPlataforma->getLimY()) &&
		pPers->getX() < (pPlataforma->getX() + pPlataforma->getLimX()) &&
		(pPers->getX() + pPers->getLimX()) > pPlataforma->getX())
	{
		//	se a diferença da entre a plataforma e a o ponto mais alto do 
		//	personagem for pelo menos da altura do player - VEL_PULO - 1 
		//	(valor para garantir que o personagem não passará reto da 
		//	plataforma) de altura e se o personagem estiver caindo...
		if (pPers->getVelY() <= 0 && (pPers->getY() -
			(pPlataforma->getY() - pPlataforma->getLimY())) < VEL_PULO+1)
		{
			pPers->setY(pPlataforma->getY() - pPlataforma->getLimY());
			pPers->setVelY(0);
			return true;
		}
		return false;
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
	ataqueInimigos();
	gerenciaColisoes();
	atualizaPosFase();
}


void Fase::atualizaObjs()
{
	int i;
	//atualizaPlayers();
	for (i = 0; i < jogadores.numObjs(); i++)
	{
		if (jogadores.objI(i)->getAtivo())
		{
			if (jogadores.objI(i)->getFisica())
				if (!personagemPodePular(static_cast<Personagem*>(jogadores.objI(i))))
					jogadores.objI(i)->cair(((float)GRAV / FPS));
			jogadores.objI(i)->atualizar();
		}
	}

	//atualizaInimigos();
	for (i = 0; i < espadachins.numObjs(); i++)
	{
		if (espadachins.objI(i)->getAtivo())
		{
			if (espadachins.objI(i)->getFisica() && !personagemPodePular(static_cast<Personagem*>(espadachins.objI(i))))
				espadachins.objI(i)->cair(((float)GRAV /FPS));
			espadachins.objI(i)->atualizar();
		}
	}

	for (i = 0; i < mosqueteiros.numObjs(); i++)
	{
		if (mosqueteiros.objI(i)->getAtivo())
		{
			if (mosqueteiros.objI(i)->getFisica() && !personagemPodePular(static_cast<Personagem*>(mosqueteiros.objI(i))))
				mosqueteiros.objI(i)->cair(((float)GRAV / FPS));
			mosqueteiros.objI(i)->atualizar();
		}
	}

	for (i = 0; i < cavaleiros.numObjs(); i++)
	{
		if (cavaleiros.objI(i)->getAtivo())
		{
			if (cavaleiros.objI(i)->getFisica() && !personagemPodePular(static_cast<Personagem*>(cavaleiros.objI(i))))
				cavaleiros.objI(i)->cair(((float)GRAV / FPS));
			cavaleiros.objI(i)->atualizar();
		}
	}


	//atualizaProjeteis();
	for (i = 0; i < projeteis.numObjs(); i++)
	{
		Projetil* pProj = projeteis.objI(i);
		// se estiver fora da tela, com uma tolerância de 20 pixels, exclui o projetil
		if (pProj->getX() > (LARG+posRelX+20) || pProj->getX() < (posRelX-20) ||
			pProj->getY() > (ALT-posRelY-20) || pProj->getY() < (-posRelY+20) )
			projeteis.deleteObj(pProj);
		else if (pProj->getAtivo())
			pProj->atualizar();
	}

}


void Fase::desenhaObjs()
{
	desenhaProjeteis();
	desenhaPlataformas();
	desenhaInimigos();
	desenhaJogadores();
}


void Fase::desenhaJogadores()
{
	for (int i = 0; i < jogadores.numObjs(); i++)
	{
		if (jogadores.objI(i)->getAtivo())
			jogadores.objI(i)->draw(posRelX, posRelY);
	}
}


void Fase::desenhaInimigos()
{
	for (int i = 0; i < espadachins.numObjs(); i++)
	{
		if (espadachins.objI(i)->getAtivo())
			espadachins.objI(i)->draw(posRelX, posRelY);
	}
	for (int i = 0; i < mosqueteiros.numObjs(); i++)
	{
		if (mosqueteiros.objI(i)->getAtivo())
			mosqueteiros.objI(i)->draw(posRelX, posRelY);
	}
	for (int i = 0; i < cavaleiros.numObjs(); i++)
	{
		if (cavaleiros.objI(i)->getAtivo())
			cavaleiros.objI(i)->draw(posRelX, posRelY);
	}
}


void Fase::desenhaPlataformas()
{
	for (int i = 0; i < plataformas.numObjs(); i++)
	{
		if (plataformas.objI(i)->getAtivo())
			plataformas.objI(i)->draw(posRelX, posRelY);
	}
}


void Fase::desenhaProjeteis()
{
	for (int i = 0; i < projeteis.numObjs(); i++)
	{
		if (projeteis.objI(i)->getAtivo())
			projeteis.objI(i)->draw(posRelX, posRelY);
	}
}


void Fase::addPlataforma(Plataforma* const pPlataforma)
{
	plataformas.addObj(pPlataforma);
}


void Fase::addEspadachim(Espadachim* const pEsp)
{
	espadachins.addObj(pEsp);
}


void Fase::addMosqueteiro(Mosqueteiro* const pMosq)
{
	mosqueteiros.addObj(pMosq);
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


void Fase::ataqueInimigos()
{
	for (int i = 0; i < mosqueteiros.numObjs(); i++)
	{
		Mosqueteiro* pMosq = mosqueteiros.objI(i);
		if (pMosq->getAtivo())
		{
			if (al_get_timer_count(timer_mosq1) > 0)
			{
				projeteis.addObj(pMosq->atirar());
				al_set_timer_count(timer_mosq1, 0);
			}	
		}
	}
}


void Fase::atualizaPosFase()
{
	if (posRelX >= 0)
	{
		//MUDAR ESSA CONODIÇÃO DEPOIS PARA QUANDO FOREM 2 PLAYERS
		if (jogadores.objI(0)->getX() > (posRelX+LARG/2))
		{
			posRelX = jogadores.objI(0)->getX() - LARG / 2;
		}
		else if (jogadores.objI(0)->getX() < (posRelX+LARG / 10))
		{
			posRelX = jogadores.objI(0)->getX() - LARG / 10;
		}
	}
	if (posRelX < 0)
		posRelX = 0;
}


void Fase::addCavaleiro(EspadachimCavaleiro* const pCav)
{
	cavaleiros.addObj(pCav);
}


void Fase::colisaoProjeteis(Personagem* const pPers)
{
	Projetil* pProj;
	for (int i = 0; i < projeteis.numObjs(); i++)
	{
		pProj = projeteis.objI(i);
		if (pProj->getAtivo())
		{
			//	se o projetil for do inimigo e o alvo jogador ou se o projetil
			//	for do jogador e o alvo inimigo...
			if (((	pPers->getID() == JOGADOR1 || pPers->getID() == JOGADOR2) &&
					pProj->getID() == PROJETIL_INI) || ((pPers->getID() == ESP_CAVALEIRO ||
					pPers->getID() == ESPADACHIM || pPers->getID() == MOSQUETEIRO ||
					pPers->getID() == CHEFAO_CAP) && pProj->getID() == PROJETIL_JOG))
			{
				if (colisaoPersProj(pPers, pProj))
				{
					pPers->setVida(pPers->getVida() - pProj->getArmaProj()->getDano());
					projeteis.deleteObj(pProj);
				}
			}
		}
	}
}


bool Fase::colisaoPersProj(Personagem* const pPers, Projetil* const pProj)
{
	// checa se o projetil "encostou" no personagem
	if ((pPers->getY()) >= (pProj->getY() - pProj->getLimY()) &&
		(pPers->getY()-pPers->getLimY()) <= pProj->getY() &&
		pPers->getX() <= (pProj->getX() + pProj->getLimX()) &&
		(pPers->getX() + pPers->getLimX()) >= pProj->getX())
	{
		return true;
	}
	return false;
}


void Fase::resetAllObjs()
{
	int i;
	
	for (i = 0; i < jogadores.numObjs(); i++)
		jogadores.retirarObj(jogadores.objI(i));
	for (i = 0; i < mosqueteiros.numObjs(); i++)
		mosqueteiros.retirarObj(mosqueteiros.objI(i));
	for (i = 0; i < espadachins.numObjs(); i++)
		espadachins.retirarObj(espadachins.objI(i));
	for (i = 0; i < cavaleiros.numObjs(); i++)
		cavaleiros.retirarObj(cavaleiros.objI(i));
	//	os projeteis devem ser excluidos de trás para frente par não 
	//	interferência do tamanho do vetor e a posição desse durante
	//	as exlusões
	for (i = projeteis.numObjs()-1; i >= 0; i--)
		projeteis.deleteObj(projeteis.objI(i));
}
