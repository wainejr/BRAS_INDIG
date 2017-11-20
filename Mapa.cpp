#include "Mapa.h"



Mapa::Mapa()
{
}


Mapa::~Mapa()
{
	retiraTodosObjs();
}

void Mapa::retiraTodosObjs()
{
	while (jogadores.numObjs() > 0)
	{
		jogadores.objI(0)->resetaTimers();
		jogadores.retirarObj(jogadores.objI(0));
	}
	while (mosqueteiros.numObjs() > 0)
	{
		mosqueteiros.objI(0)->resetaTimers();
		mosqueteiros.retirarObj(mosqueteiros.objI(0));
	}
	while (espadachins.numObjs() > 0)
	{
		espadachins.objI(0)->resetaTimers();
		espadachins.retirarObj(espadachins.objI(0));
	}
	while (cavaleiros.numObjs() > 0)
	{
		cavaleiros.objI(0)->resetaTimers();
		cavaleiros.retirarObj(cavaleiros.objI(0));
	}
	//	projeteis são deletados por serem criados durante a execução da Mapa
	while (projeteis.numObjs() > 0)
		delete(projeteis.retirarObj(projeteis.objI(0)));

	while (cordas.numObjs() > 0)
		cordas.retirarObj(cordas.objI(0));

	while (plataformas.numObjs() > 0)
		plataformas.retirarObj(plataformas.objI(0));

	while (armadilhas.numObjs() > 0)
	{
		armadilhas.objI(0)->resetaTimer();
		armadilhas.retirarObj(armadilhas.objI(0));
	}
	while (espinhos.numObjs() > 0)
		espinhos.retirarObj(espinhos.objI(0));

	while (redes.numObjs() > 0)
		redes.retirarObj(redes.objI(0));
}


void Mapa::atualizaMapa()
{
	atualizaObjs();
	if (jogadores.numObjs() == 2)
		atualizaAlvos();
	ataqueInimigos();
	gerenciaColisoes();
	atualizaAtivos();
	atualizaPosMapa();
}


void Mapa::atualizaObjs()
{
	int i;
	Jogador* pJog;
	Espadachim* pEsp;
	Mosqueteiro* pMosq;
	EspadachimCavaleiro* pCav;
	Projetil* pProj;
	Rede* pRede;
	Armadilha* pArmd;

	for (i = 0; i < jogadores.numObjs(); i++)
	{
		pJog = jogadores.objI(i);
		if (pJog->getAtivo())
		{
			pJog->atualizar();
		}
	}

	for (i = 0; i < espadachins.numObjs(); i++)
	{
		pEsp = espadachins.objI(i);
		if (pEsp->getAtivo())
		{
			pEsp->atualizar();
		}
	}

	for (i = 0; i < mosqueteiros.numObjs(); i++)
	{
		pMosq = mosqueteiros.objI(i);
		if (pMosq->getAtivo())
		{
			pMosq->atualizar();
		}
	}

	for (i = 0; i < cavaleiros.numObjs(); i++)
	{
		pCav = cavaleiros.objI(i);
		if (pCav->getAtivo())
		{
			pCav->atualizar();
		}
	}

	for (i = 0; i < projeteis.numObjs(); i++)
	{
		pProj = projeteis.objI(i);
		if (pProj->getAtivo())
			pProj->atualizar();
	}

	for (i = 0; i < redes.numObjs(); i++)
	{
		pRede = redes.objI(i);
		if (pRede->getAtivo())
			pRede->atualizar();
	}

	for (i = 0; i < armadilhas.numObjs(); i++)
	{
		pArmd = armadilhas.objI(i);
		if (pArmd->getAtivo())
			pArmd->atualizar();
	}
}


void Mapa::atualizaAtivos()
{
	int i;
	Jogador* pJog;
	Mosqueteiro* pMosq;
	Espadachim* pEsp;
	EspadachimCavaleiro* pCav;
	Projetil* pProj;

	//	Depois de o inimimigo ser "ultrapassado", ele é retirado da lista de inimigos
	//	já caso o inimigo seja "alcançado", ele é ativado.
	///	TALVEZ COLOCAR UMA TOLERÂNCIA AQUI
	///	FAZER O MESMO PARA REDES, ESPINHOS E ARMADILHAS
	for (i = 0; i < jogadores.numObjs(); i++)
	{
		pJog = jogadores.objI(i);
		if (pJog->getAtivo() && pJog->getVida() <= 0)
		{
			pJog->setAtivo(false);
			pJog->resetaTimers();
			jogadores.retirarObj(pJog);
		}
	}
	for (i = 0; i < mosqueteiros.numObjs(); i++)
	{
		pMosq = mosqueteiros.objI(i);
		if (pMosq->getAtivo())
		{
			if (pMosq->getVida() <= 0)
			{
				pMosq->setAtivo(false);
				pMosq->resetaTimers();
				mosqueteiros.retirarObj(pMosq);
			}
			else if ((pMosq->getX() + pMosq->getLimX()) < posRelX)
			{
				pMosq->setAtivo(false);
				pMosq->resetaTimers();
				mosqueteiros.retirarObj(pMosq);
			}
		}
		else if (!pMosq->getAtivo() && (pMosq->getX() - (posRelX + LARG)) < 0)
			pMosq->setAtivo(true);
	}
	for (i = 0; i < espadachins.numObjs(); i++)
	{
		pEsp = espadachins.objI(i);
		if (pEsp->getAtivo())
		{
			if (pEsp->getVida() <= 0)
			{
				pEsp->setAtivo(false);
				pEsp->resetaTimers();
				espadachins.retirarObj(pEsp);
			}
			else if ((pEsp->getX() + pEsp->getLimX()) < posRelX)
			{
				pEsp->setAtivo(false);
				pEsp->resetaTimers();
				espadachins.retirarObj(pEsp);
			}
		}
		else if (!pEsp->getAtivo() && (pEsp->getX() - (posRelX + LARG)) < 0)
			pEsp->setAtivo(true);
	}
	for (i = 0; i < cavaleiros.numObjs(); i++)
	{
		pCav = cavaleiros.objI(i);
		if (pCav->getAtivo())
		{
			if (pCav->getVida() <= 0)
			{
				pCav->setAtivo(false);
				pCav->resetaTimers();
				cavaleiros.retirarObj(pCav);
			}
			else if ((pCav->getX() + pCav->getLimX()) < posRelX)
			{
				pCav->setAtivo(false);
				pCav->resetaTimers();
				cavaleiros.retirarObj(pCav);
			}

		}
		else if (!pCav->getAtivo() && (pCav->getX() - (posRelX + LARG)) < 0)
			pCav->setAtivo(true);
	}
	
	for (i = 0; i < projeteis.numObjs(); i++)
	{
		pProj = projeteis.objI(i);
		if (pProj->getAtivo() && (pProj->getX() >(LARG + posRelX + 20) || pProj->getX() < (posRelX - 20) ||
			pProj->getY() > (ALT - posRelY - 20) || pProj->getY() < (-posRelY + 20)))
			delete(projeteis.retirarObj(pProj));
	}
}


void Mapa::atualizaAlvos()
{
	Mosqueteiro* pMosq;
	Espadachim* pEsp;
	EspadachimCavaleiro* pCav;
	for (int i = 0; i < mosqueteiros.numObjs(); i++)
	{
		pMosq = mosqueteiros.objI(i);
		if (pMosq->getAtivo())
		{
			alvoInimigo(static_cast<Inimigo*>(pMosq));
		}
	}
	for (int i = 0; i < espadachins.numObjs(); i++)
	{
		pEsp = espadachins.objI(i);
		if (pEsp->getAtivo())
		{
			alvoInimigo(static_cast<Inimigo*>(pEsp));
		}
	}
	for (int i = 0; i < cavaleiros.numObjs(); i++)
	{
		pCav = cavaleiros.objI(i);
		if (pCav->getAtivo())
		{
			alvoInimigo(static_cast<Inimigo*>(pCav));
		}
	}
}


void Mapa::alvoInimigo(Inimigo* const pIni)
{
	Jogador* pJog1 = jogadores.objI(0);
	Jogador* pJog2 = jogadores.objI(1);
	//	se ambos os jogadores estão na mesma altura do inimigo...
	if (pJog1->getY() > pIni->getY() - pIni->getLimY() && pJog1->getY() - pJog1->getLimY() < pIni->getY() &&
		pJog2->getY() > pIni->getY() - pIni->getLimY() && pJog2->getY() - pJog2->getLimY() < pIni->getY())
	{
		int distIniJog1 = pJog1->getX() + pJog1->getLimX() / 2 - (pIni->getX() + pIni->getLimX() / 2);
		int distIniJog2 = pJog2->getX() + pJog2->getLimX() / 2 - (pIni->getX() + pIni->getLimX() / 2);
		if (distIniJog1 < 0)
		{
			distIniJog1 *= -1;
		}
		if (distIniJog2 < 0)
		{
			distIniJog2 *= -1;
		}

		if (distIniJog1 < distIniJog2)
		{
			pIni->setAlvo(pJog1);
		}
		else
		{
			pIni->setAlvo(pJog2);
		}
	}
	//	se só o jogador 1 está na altura do inimigo...
	else if (pJog1->getY() > pIni->getY() - pIni->getLimY() && pJog1->getY() - pJog1->getLimY() < pIni->getY())
	{
		pIni->setAlvo(pJog1);
	}
	//	se só o jogador 2 está na altura do inimigo...
	else if (pJog2->getY() > pIni->getY() - pIni->getLimY() && pJog2->getY() - pJog2->getLimY() < pIni->getY())
	{
		pIni->setAlvo(pJog2);
	}
}


void Mapa::gerenciaColisoes()
{
	gerenciaColisaoPlatObstProj();
	gerenciaColisaoAtaques();
}


void Mapa::gerenciaColisaoPlatObstProj()
{
	int i;
	Jogador* pJog;
	Mosqueteiro* pMosq;
	Espadachim* pEsp;
	EspadachimCavaleiro* pCav;
	Projetil* pProj;
	Rede* pRede;

	//	colisoes com projeteis, plataformas e obstaculos
	for (i = 0; i < jogadores.numObjs(); i++)
	{
		pJog = jogadores.objI(i);
		if (pJog->getAtivo())
		{
			if (!pJog->getInvuneravel())
			{
				colisaoRede(pJog);
				colisaoArmadilhas(pJog);
				colisaoInimigo(pJog);
				colisaoEspinhos(static_cast<Personagem*>(pJog));
				colisaoProjeteis(static_cast<Personagem*>(pJog));
			}
			if (pJog->getFisica() && !personagemPodePular(static_cast<Personagem*>(pJog)))
			{
				if (jogadorEstaNumaCorda(pJog))
				{
					if (!pJog->getSubindo())
						pJog->setVelY(0);
				}
				else
					pJog->cair(((float)GRAV / FPS));
			}
			colisaoLinhaRede(pJog);
			colisaoPlat(static_cast<Entidade*>(pJog));

		}
	}
	for (i = 0; i < mosqueteiros.numObjs(); i++)
	{
		pMosq = mosqueteiros.objI(i);
		if (pMosq->getAtivo())
		{
			if (!pMosq->getInvuneravel())
			{
				colisaoEspinhos(static_cast<Personagem*>(pMosq));
				colisaoProjeteis(static_cast<Personagem*>(pMosq));
			}
			if (pMosq->getFisica() && !personagemPodePular(static_cast<Personagem*>(pMosq)))
				pMosq->cair(((float)GRAV / FPS));
			colisaoPlat(static_cast<Entidade*>(pMosq));
		}
	}
	for (i = 0; i < espadachins.numObjs(); i++)
	{
		pEsp = espadachins.objI(i);
		if (pEsp->getAtivo())
		{
			if (!pEsp->getInvuneravel())
			{
				colisaoEspinhos(static_cast<Personagem*>(pEsp));
				colisaoProjeteis(static_cast<Personagem*>(pEsp));
			}
			if (pEsp->getFisica() && !personagemPodePular(static_cast<Personagem*>(pEsp)))
				pEsp->cair(((float)GRAV / FPS));
			colisaoPlat(static_cast<Entidade*>(pEsp));
		}
	}
	for (i = 0; i < cavaleiros.numObjs(); i++)
	{
		pCav = cavaleiros.objI(i);
		if (pCav->getAtivo())
		{
			if (!pCav->getInvuneravel())
			{
				colisaoEspinhos(static_cast<Personagem*>(pCav));
				colisaoProjeteis(static_cast<Personagem*>(pCav));
			}
			if (pCav->getFisica() && !personagemPodePular(static_cast<Personagem*>(pCav)))
				pCav->cair(((float)GRAV / FPS));
			colisaoPlat(static_cast<Entidade*>(pCav));
		}
	}
	for (i = 0; i < projeteis.numObjs(); i++)
	{
		pProj = projeteis.objI(i);
		if (pProj->getAtivo())
		{
			if (colisaoEntPlat(static_cast<Entidade*>(pProj)))
				delete(projeteis.retirarObj(pProj));
		}
	}
	for (i = 0; i < redes.numObjs(); i++)
	{
		pRede = redes.objI(i);
		if (pRede->getAtivo())
		{
			if (colisaoEntPlat(static_cast<Entidade*>(pRede)))
				redes.retirarObj(pRede);
		}
	}
}


void Mapa::gerenciaColisaoAtaques()
{
	Jogador* pJog;
	Espadachim* pEsp;
	Mosqueteiro* pMosq;
	EspadachimCavaleiro* pCav;
	Arma* pArma;
	//	colisão com ataques
	for (int i = 0; i < jogadores.numObjs(); i++)
	{
		pJog = jogadores.objI(i);
		if (pJog->getAtacando() && pJog->getAtivo())
		{
			pArma = pJog->getArma();
			int u;
			for (u = 0; u < espadachins.numObjs(); u++)
			{
				pEsp = espadachins.objI(u);
				if (pEsp->getAtivo() && !pEsp->getInvuneravel() && colisaoEntEnt
				(static_cast<Entidade*>(pEsp), static_cast<Entidade*>(pArma)))
				{
					if (((int)pJog->getX() + pJog->getLimX() / 2) < ((int)pEsp->getX() + pEsp->getLimX() / 2))
						pEsp->tomaDano(pArma->getDano(), 1);
					else
						pEsp->tomaDano(pArma->getDano(), -1);
				}
			}
			for (u = 0; u < mosqueteiros.numObjs(); u++)
			{
				pMosq = mosqueteiros.objI(u);
				if (pMosq->getAtivo() && !pMosq->getInvuneravel() && colisaoEntEnt
				(static_cast<Entidade*>(pMosq), static_cast<Entidade*>(pArma)))
				{
					if (((int)pJog->getX() + pJog->getLimX() / 2) < ((int)pMosq->getX() + pMosq->getLimX() / 2))
						pMosq->tomaDano(pArma->getDano(), 1);
					else
						pMosq->tomaDano(pArma->getDano(), -1);

				}
			}
			for (u = 0; u < cavaleiros.numObjs(); u++)
			{
				pCav = cavaleiros.objI(u);
				if (pCav->getAtivo() && !pCav->getInvuneravel() && colisaoEntEnt
				(static_cast<Entidade*>(pCav), static_cast<Entidade*>(pArma)))
				{
					pCav->tomaDano(pArma->getDano(), 0);
				}
			}
		}
	}

	for (int i = 0; i < espadachins.numObjs(); i++)
	{
		pEsp = espadachins.objI(i);
		pArma = pEsp->getArma();
		if (pEsp->getAtivo() && pEsp->getAtacando())
		{
			for (int u = 0; u < jogadores.numObjs(); u++)
			{
				pJog = jogadores.objI(u);
				if (pJog->getAtivo() && !pJog->getInvuneravel() && colisaoEntEnt
				(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pEsp->getArma())))
				{
					if (((int)pEsp->getX() + pEsp->getLimX() / 2) < ((int)pJog->getX() + pJog->getLimX() / 2))
						pJog->tomaDano(pArma->getDano(), 1);
					else
						pJog->tomaDano(pArma->getDano(), -1);
				}
			}
		}
	}
}


void Mapa::perDescePlat(Personagem* const pPers)
{
	if (pPers->getAtivo() && persPodeDescerPlat(pPers))
	{
		pPers->setY(pPers->getY() + 3);
	}
}


const bool Mapa::colisaoChao(Personagem* const pPers)
{
	Plataforma* pPlat;
	if (pPers->getAtivo())
	{
		for (int i = 0; i < plataformas.numObjs(); i++)
		{
			pPlat = plataformas.objI(i);
			if (pPlat->getAtivo())
			{
				if (colisaoPersChao(pPers, pPlat))
					return true;
			}
		}
	}
	return false;
}


const bool Mapa::colisaoInimigo(Jogador* const pJog)
{
	Inimigo* pIni;
	bool colid = false;
	if (pJog->getAtivo())
	{
		for (int i = 0; i < cavaleiros.numObjs(); i++)
		{
			pIni = static_cast<Inimigo*>(cavaleiros.objI(i));
			if (pIni->getAtivo())
				if (colisaoEntEnt(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pIni)))
				{
					if (pIni->getVelX() <= 0)
						pJog->tomaDano(pIni->getArma()->getDano(), -1);
					else
						pJog->tomaDano(pIni->getArma()->getDano(), 1);
					colid = true;
				}
		}
		for (int i = 0; i < espadachins.numObjs(); i++)
		{
			pIni = static_cast<Inimigo*>(espadachins.objI(i));
			if (pIni->getAtivo())
				if (colisaoEntEnt(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pIni)))
				{
					if (pIni->getX() + pIni->getLimX() / 2 >= pJog->getX() + pJog->getLimX() / 2)
						pJog->tomaDano(pIni->getArma()->getDano(), -1);
					else
						pJog->tomaDano(pIni->getArma()->getDano(), 1);
					colid = true;
				}

		}
		for (int i = 0; i < mosqueteiros.numObjs(); i++)
		{
			pIni = static_cast<Inimigo*>(mosqueteiros.objI(i));
			if (pIni->getAtivo())
				if (colisaoEntEnt(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pIni)))
				{
					if (pIni->getX() + pIni->getLimX() / 2 >= pJog->getX() + pJog->getLimX() / 2)
						pJog->tomaDano(pIni->getArma()->getDano(), -1);
					else
						pJog->tomaDano(pIni->getArma()->getDano(), 1);
					colid = true;
				}
		}
	}
	return colid;
}


const bool Mapa::colisaoPlat(Entidade* const pEnt)
{
	int i;
	bool colid = false;
	Plataforma* pPlat;
	for (i = 0; i < plataformas.numObjs(); i++)
	{
		pPlat = plataformas.objI(i);
		if (pPlat->getAtivo())
		{
			if (colisaoEntEnt(pEnt, static_cast<Entidade*>(pPlat)) && pPlat->getColisaoBaixo())
			{
				colid = true;
				gereColisao(pEnt, static_cast<Entidade*>(pPlat));
			}
		}
	}
	return colid;
}


const bool Mapa::colisaoEntPlat(Entidade* const pEnt)
{
	int i;
	bool colid = false;
	Plataforma* pPlat;
	for (i = 0; i < plataformas.numObjs(); i++)
	{
		pPlat = plataformas.objI(i);
		if (colisaoEntEnt(pEnt, static_cast<Entidade*>(pPlat)))
			return true;
	}
	return false;
}


void Mapa::colisaoProjeteis(Personagem* const pPers)
{
	Projetil* pProj;
	for (int i = 0; i < projeteis.numObjs(); i++)
	{
		pProj = projeteis.objI(i);
		if (pProj->getAtivo())
		{
			//	se o projetil for do inimigo e o alvo jogador ou se o projetil
			//	for do jogador e o alvo inimigo...
			if (((pPers->getID() == RAONI || pPers->getID() == TECA) &&
				pProj->getID() == PROJETIL_MOSQ) || ((pPers->getID() == ESP_CAVALEIRO ||
					pPers->getID() == ESPADACHIM || pPers->getID() == MOSQUETEIRO ||
					pPers->getID() == CHEFAO_CAP) && pProj->getID() == PROJETIL_ARCO))
			{
				if (colisaoEntEnt(static_cast<Entidade*>(pPers), static_cast<Entidade*>(pProj)))
				{
					if (pPers->getID() != ESP_CAVALEIRO)
					{
						if (pProj->getVelX() > 0)
							pPers->tomaDano(pProj->getArmaProj()->getDano(), 1);
						else
							pPers->tomaDano(pProj->getArmaProj()->getDano(), -1);
					}
					else
						pPers->tomaDano(pProj->getArmaProj()->getDano(), 0);
					delete(projeteis.retirarObj(pProj));
				}
			}
		}
	}
}


void Mapa::colisaoEspinhos(Personagem* const pPers)
{
	int i;
	Espinho* pEspinho;
	for (i = 0; i < espinhos.numObjs(); i++)
	{
		pEspinho = espinhos.objI(i);
		if (pEspinho->getAtivo() && colisaoEntEnt(static_cast<Entidade*>(pPers), static_cast<Entidade*>(pEspinho)))
		{
			//	caso o player esteja andando para direita ou parado
			//	recebe dano e um knock back para esquerda, caso 
			//	contrário recebe dano e um knock back para direita
			if (pPers->getVelX() >= 0)
				pPers->tomaDano(pEspinho->getDano(), -1);
			else
				pPers->tomaDano(pEspinho->getDano(), 1);
		}
	}
}


void Mapa::colisaoArmadilhas(Jogador* const pJog)
{
	Armadilha* pArmd;
	for (int i = 0; i < armadilhas.numObjs(); i++)
	{
		pArmd = armadilhas.objI(i);
		if (pArmd->getAtivo() && !pArmd->getAcionada() && (pJog->getY()) >= (pArmd->getY() - pArmd->getLimY()) &&
			(pJog->getY() - pJog->getLimY()) <= pArmd->getY())
		{
			int diffCent = pJog->getX() + pJog->getLimX()/2 - (pArmd->getX() + pArmd->getLimX()/2);
			if (diffCent < 0)
				diffCent = -diffCent;
			if (diffCent < DIFFCENT_ARMD)
			{
				pJog->tomaDano(pArmd->getDano(), 2);
				pArmd->setX(pJog->getX() + pJog->getLimX() / 2 - pArmd->getLimX() / 2);
				pArmd->acionar();
			}
		}
	}
}


void Mapa::colisaoLinhaRede(Jogador* const pJog)
{
	Corda* pCorda;
	Rede* pRede;
	for (int i = 0; i < redes.numObjs(); i++)
	{
		pRede = redes.objI(i);
		if (pRede->getAtivo())
		{
			if (!pRede->getAtivada())
			{
				pCorda = pRede->getCorda();
				if (pCorda->getAtivo())
				{
					if (colisaoEntEnt(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pCorda)))
						pRede->ativar();
				}
			}
		}
	}
}


void Mapa::colisaoRede(Jogador* const pJog)
{
	Rede* pRede;
	for (int i = 0; i < redes.numObjs(); i++)
	{
		pRede = redes.objI(i);
		if (pRede->getAtivo() && pRede->getAtivada())
		{
			if (colisaoEntEnt(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pRede)))
			{
				pJog->tomaDano(pRede->getDano(), 3);
				pRede->setAtivo(false);
			}
		}
	}
}


//	Faz uma checagem análoga a da função "gereColisao", porém apenas
//	para o pé do personagem referenciado
const bool Mapa::colisaoPersChao(Personagem* const pPers, Plataforma* const pPlataforma)
{
	//	checa apenas se o pe do personagem bateu no chão 
	if ((pPers->getY()) >= (pPlataforma->getY() - pPlataforma->getLimY()) &&
		pPers->getX() <= (pPlataforma->getX() + pPlataforma->getLimX()) &&
		(pPers->getX() + pPers->getLimX()) >= pPlataforma->getX())
	{
		//	se a diferença da entre a plataforma e a o ponto mais alto do 
		//	personagem for pelo menos da altura do player + velY + 1
		//	(valor para garantir que o personagem não passará reto da 
		//	plataforma) de altura e se o personagem estiver caindo...
		if (pPers->getVelY() <= 0 && (pPers->getY() -
			(pPlataforma->getY() - pPlataforma->getLimY())) <= (-pPers->getVelY() + 1))
		{
			pPers->setY(pPlataforma->getY() - pPlataforma->getLimY());
			pPers->setVelY(0);
			return true;
		}
		return false;
	}
	return false;
}


const bool Mapa::colisaoEntEnt(Entidade* const pEnt1, Entidade* const pEnt2)
{
	if ((pEnt1->getY()) >= (pEnt2->getY() - pEnt2->getLimY()) &&
		(pEnt1->getY() - pEnt1->getLimY()) <= pEnt2->getY() &&
		pEnt1->getX() <= (pEnt2->getX() + pEnt2->getLimX()) &&
		(pEnt1->getX() + pEnt1->getLimX()) >= pEnt2->getX())
		return true;
	return false;
}


void Mapa::gereColisao(Entidade* const pMovel, Entidade* const pParado)
{
	//	se a entidade movel estiver descendo, bateu na parte de cima
	//	da entidade estática e a diferença entre a parte mais alta da 
	//	entidade estática e a altura em y da entidade movel for no máximo 
	//	de -velY + 1 (valor para garantir que a colisão ocorreu por 
	//	causa da descida da entidade movel)...
	if (pMovel->getVelY() <= 0 && (pMovel->getY() - pMovel->getLimY()) < (pParado->getY() - pParado->getLimY()) && (pMovel->getY() -
		(pParado->getY() - pParado->getLimY())) <= (-pMovel->getVelY() + 1))
	{
		pMovel->setY(pParado->getY() - pParado->getLimY());
		pMovel->setVelY(0);
	}

	//	se a entidade movel estiver subindo, bateu na parte debaixo
	//	da plataforma e a diferença entre a altura em y da 
	//	plataforma e a o ponto mais alto da entidade movel for no 
	//	máximo de velY + 1 (valor para garantir que a colisão 
	//	ocorreu por causa da subida de altura da entidade movel)...
	if (pMovel->getVelY() >= 0 && pMovel->getY() > pParado->getY() && (pMovel->getY() - pMovel->getLimY())
		< pParado->getY() && -(pMovel->getY() - pMovel->getLimY() - pParado->getY()) <= (pMovel->getVelY() + 1))
	{
		pMovel->setY(pParado->getY() + pMovel->getLimY());
		pMovel->setVelY(0);
	}

	//	se a entidade movel estiver andando para direita, bateu na 
	//	parte esquerda da plataforma e a diferença entre a 
	//	direita da entidade movel e a esquerda da plataforma for no 
	//	máximo de velX + 1 (valor para garantir que a colisão 
	//	ocorreu por causa do movimento a direita da entidade movel)...
	if (pMovel->getVelX() >= 0 && (pMovel->getX() + pMovel->getLimX()) > pParado->getX() &&
		(pMovel->getX() + pMovel->getLimX() - pParado->getX()) <= (pMovel->getVelX() + 1))
	{
		pMovel->setX(pParado->getX() - pMovel->getLimX());
		pMovel->setVelX(0);
	}

	//	se a entidade movel estiver andando para esquerda, bateu na 
	//	parte direita da plataforma e a diferença entre a 
	//	esquerda da entidade movel e a direita da plataforma for no 
	//	máximo de -velX + 1 (valor para garantir que a colisão 
	//	ocorreu por causa do movimento a direita da entidade movel)...					
	if (pMovel->getVelX() <= 0 && pMovel->getX() < (pParado->getX() + pParado->getLimX()) &&
		(pParado->getX() + pParado->getLimX() - pMovel->getX()) <= (-pMovel->getVelX() + 1))
	{
		pMovel->setX(pParado->getX() + pParado->getLimX());
		pMovel->setVelX(0);
	}
}


void Mapa::ataqueInimigos()
{
	Mosqueteiro* pMosq;
	Espadachim* pEsp;
	for (int i = 0; i < mosqueteiros.numObjs(); i++)
	{
		pMosq = mosqueteiros.objI(i);
		if (pMosq->getAtivo() && pMosq->persPodeAtacar())
		{
			projeteis.addObj(pMosq->atirar());
		}
	}
	for (int i = 0; i < espadachins.numObjs(); i++)
	{
		pEsp = espadachins.objI(i);
		if (pEsp->getAtivo() && pEsp->persPodeAtacar())
		{
			pEsp->atacar();
		}
	}
}


const bool Mapa::personagemPodeAtacar(Personagem* const pPers)
{
	return pPers->persPodeAtacar();
}


const bool Mapa::jogadorPodeSubir(Jogador* const pJog)
{
	if (pJog->getAtivo())
	{
		for (int i = 0; i < cordas.numObjs(); i++)
		{
			Corda* pCorda = cordas.objI(i);
			if (pCorda->getAtivo() && pCorda->getEscalavel())
			{
				//	se a diferença entre o centro do jogador e da corda for menor
				//	ou igual DIFFCENT_CORDA e o jogador está com a no mínimo VEL_SUBIDA+1 
				//	pixels "mais baixo" que a parte mais alta da corda...	
				//	Obs.: o valor dos pixels de diferença devem ser maior que o 
				//	"VEL_SUBIDA" pela sequência de atualizações que o Mapa segue
				{
					if (colisaoEntEnt(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pCorda)))
					{
						int diffCent = pJog->getX() + pJog->getLimX() / 2 - (pCorda->getX() + pCorda->getLimX() / 2);
						if (diffCent < 0)
							diffCent = -diffCent;
						if (diffCent <= DIFFCENT_CORDA)
						{
							if ((pJog->getY() - (pCorda->getY() - pCorda->getLimY())) > VEL_SUBIDA + 1)
								return true;
							else
								pJog->setVelY(0);
						}
					}
				}
			}
		}
	}
	return false;
}


const bool Mapa::personagemPodePular(Personagem* const pPers)
{
	return (colisaoChao(pPers));
}


const bool Mapa::jogadorEstaNumaCorda(Jogador* const pJog)
{
	if (pJog->getAtivo())
	{
		Corda* pCorda;
		for (int i = 0; i < cordas.numObjs(); i++)
		{
			pCorda = cordas.objI(i);
			if (pCorda->getAtivo() && pCorda->getEscalavel()){
				if (colisaoEntEnt(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pCorda)))
				{
					int diffCent = pJog->getX() + pJog->getLimX() / 2 - (pCorda->getX() + pCorda->getLimX() / 2);
					if (diffCent < 0)
						diffCent = -diffCent;

					if (diffCent <= DIFFCENT_CORDA)
						return true;
				}
			}
		}
	}
	return false;
}


const bool Mapa::persPodeDescerPlat(Personagem* const pPers)
{
	Plataforma* pPlat;
	if (pPers->getAtivo())
	{
		for (int i = 0; i < plataformas.numObjs(); i++)
		{
			pPlat = plataformas.objI(i);
			if (pPlat->getAtivo() && !pPlat->getColisaoBaixo())
			{
				if (colisaoPersChao(pPers, pPlat))
					return true;
			}
		}
	}
	return false;
}


void Mapa::desenhaObjs()
{
	desenhaProjeteis();
	desenhaPlataformas();
	desenhaCordas();
	desenhaEspinhos();
	desenhaRedes();
	desenhaInimigos();
	desenhaJogadores();	

	desenhaArmadilhas();
}


void Mapa::desenhaProjeteis()
{
	for (int i = 0; i < projeteis.numObjs(); i++)
	{
		if (projeteis.objI(i)->getAtivo())
			projeteis.objI(i)->draw(posRelX, posRelY);
	}
}


void Mapa::desenhaCordas()
{
	Corda* pCorda;
	for (int i = 0; i < cordas.numObjs(); i++)
	{
		pCorda = cordas.objI(i);
		if (pCorda->getAtivo())
			pCorda->draw(posRelX, posRelY);
	}
}


void Mapa::desenhaPlataformas()
{
	for (int i = 0; i < plataformas.numObjs(); i++)
	{
		if (plataformas.objI(i)->getAtivo())
			plataformas.objI(i)->draw(posRelX, posRelY);
	}
}


void Mapa::desenhaEspinhos()
{
	Espinho* pEspinho;
	for (int i = 0; i < espinhos.numObjs(); i++)
	{
		pEspinho = espinhos.objI(i);
		if (pEspinho->getAtivo())
			pEspinho->draw(posRelX, posRelY);
	}
}


void Mapa::desenhaArmadilhas()
{
	Armadilha* pArmd;
	for (int i = 0; i < armadilhas.numObjs(); i++)
	{
		pArmd = armadilhas.objI(i);
		if (pArmd->getAtivo())
			pArmd->draw(posRelX, posRelY);
	}
}


void Mapa::desenhaRedes()
{
	Rede* pRede;
	for (int i = 0; i < redes.numObjs(); i++)
	{
		pRede = redes.objI(i);
		if (pRede->getAtivo())
			pRede->draw(posRelX, posRelY);
	}
}


void Mapa::desenhaInimigos()
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


void Mapa::desenhaJogadores()
{
	for (int i = 0; i < jogadores.numObjs(); i++)
	{
		if (jogadores.objI(i)->getAtivo())
			jogadores.objI(i)->draw(posRelX, posRelY);
	}
}


const int Mapa::getLimX()
{
	return limX;
}


void Mapa::setLimX(const int aLimX)
{
	limX = aLimX;
}


const int Mapa::getLimY()
{
	return limY;
}


void Mapa::setLimY(const int aLimY)
{
	limY = aLimY;
}


void Mapa::addPlataforma(Plataforma* const pPlataforma)
{
	plataformas.addObj(pPlataforma);
}


void Mapa::addEspadachim(Espadachim* const pEsp)
{
	espadachins.addObj(pEsp);
}


void Mapa::addMosqueteiro(Mosqueteiro* const pMosq)
{
	mosqueteiros.addObj(pMosq);
}


void Mapa::addPlayer(Jogador* const pPlayer)
{
	jogadores.addObj(pPlayer);
}


void Mapa::addProjetil(Projetil* const pProj)
{
	projeteis.addObj(pProj);
}


void Mapa::addCavaleiro(EspadachimCavaleiro* const pCav)
{
	cavaleiros.addObj(pCav);
}


void Mapa::addCorda(Corda* const pCorda)
{
	cordas.addObj(pCorda);
}


void Mapa::addArmadilha(Armadilha* const pArmd)
{
	armadilhas.addObj(pArmd);
}


void Mapa::addEspinho(Espinho* const pEspinho)
{
	espinhos.addObj(pEspinho);
}


void Mapa::addRede(Rede* const pRede)
{
	redes.addObj(pRede);
}


void Mapa::atualizaPosMapa()
{
	if (posRelX >= 0)
	{
		if (jogadores.numObjs() == 1)
		{
			Jogador* pJog1 = jogadores.objI(0);
			//MUDAR ESSA CONODIÇÃO DEPOIS PARA QUANDO FOREM 2 PLAYERS
			if (pJog1->getX() > (posRelX + LARG / 2))
			{
				posRelX = pJog1->getX() - LARG / 2;
			}
			else if (pJog1->getX() < (posRelX + LARG / 3))
			{
				posRelX = pJog1->getX() - LARG / 3;
			}
		}
		else if (jogadores.numObjs() == 2)
		{
			Jogador* pJog1 = jogadores.objI(0);
			Jogador* pJog2 = jogadores.objI(1);

			//	se a média da posição dos jogadores não está dentro dos limites
			//	definidos da fase...
			if ((pJog1->getX() + pJog2->getX()) / 2 > (posRelX + LARG / 2))
			{
				posRelX = (jogadores.objI(0)->getX() + pJog2->getX()) / 2 - LARG / 2;
			}
			else if ((pJog1->getX() + pJog2->getX()) / 2 < (posRelX + LARG / 3))
			{
				posRelX = (pJog1->getX() + pJog2->getX()) / 2 - LARG / 3;
			}

			//	se o jogador 1 está "para trás" da fase...
			if (pJog1->getX() < posRelX)
			{
				//	coloca-o na posição relativa da fase e zera sua velocidade em x
				pJog1->setX(posRelX);
				pJog1->setVelX(0);
			}
			//	se o jogador 1 está "para frente" da fase...
			else if (pJog1->getX() + pJog1->getLimX() > posRelX + LARG)
			{
				//	coloca-o no "fim da tela" e zera sua velocidade em x
				pJog1->setX(posRelX + LARG - pJog1->getLimX());
				pJog1->setVelX(0);
			}

			//	se o jogador 2 está "para trás" da fase...
			if (pJog2->getX() < posRelX)
			{
				//	coloca-o na posição relativa da fase e zera sua velocidade em x
				pJog2->setX(posRelX);
				pJog2->setVelX(0);
			}
			//	se o jogador 2 está "para frente" da fase...
			else if (pJog2->getX() + pJog2->getLimX() > posRelX + LARG)
			{
				//	coloca-o no "fim da tela" e zera sua velocidade em x
				pJog2->setX(posRelX + LARG - pJog2->getLimX());
				pJog2->setVelX(0);
			}


		}
	}
	if (posRelX < 0)
		posRelX = 0;
}

void Mapa::criarTimers()
{
	int i;
	for (i = 0; i < jogadores.numObjs(); i++)
	{
		jogadores.objI(i)->createTimers();
	}
	for (i = 0; i < mosqueteiros.numObjs(); i++)
	{
		mosqueteiros.objI(i)->createTimers();
	}
	for (i = 0; i < espadachins.numObjs(); i++)
	{
		espadachins.objI(i)->createTimers();
	}
	for (i = 0; i < cavaleiros.numObjs(); i++)
	{
		cavaleiros.objI(i)->createTimers();
	}
	for (i = 0; i < armadilhas.numObjs(); i++)
	{
		armadilhas.objI(i)->createTimer();
	}
}


void Mapa::initTimers()
{
	int i;
	for (i = 0; i < jogadores.numObjs(); i++)
	{
		jogadores.objI(i)->initTimer();
	}
	for (i = 0; i < mosqueteiros.numObjs(); i++)
	{
		mosqueteiros.objI(i)->initTimer();
	}
	for (i = 0; i < espadachins.numObjs(); i++)
	{
		espadachins.objI(i)->initTimer();
	}
	for (i = 0; i < cavaleiros.numObjs(); i++)
	{
		cavaleiros.objI(i)->initTimer();
	}
	for (i = 0; i < armadilhas.numObjs(); i++)
	{
		armadilhas.objI(i)->initTimer();
	}
}

void Mapa::stopTimers()
{
	int i;
	for (i = 0; i < jogadores.numObjs(); i++)
	{
		jogadores.objI(i)->stopTimers();
	}
	for (i = 0; i < mosqueteiros.numObjs(); i++)
	{
		mosqueteiros.objI(i)->stopTimers();
	}
	for (i = 0; i < espadachins.numObjs(); i++)
	{
		espadachins.objI(i)->stopTimers();
	}
	for (i = 0; i < cavaleiros.numObjs(); i++)
	{
		cavaleiros.objI(i)->stopTimers();
	}
	for (i = 0; i < armadilhas.numObjs(); i++)
	{
		armadilhas.objI(i)->stopTimers();
	}
}


void Mapa::resumeTimers()
{
	int i;

	for (i = 0; i < jogadores.numObjs(); i++)
	{
		jogadores.objI(i)->resumeTimers();
	}
	for (i = 0; i < mosqueteiros.numObjs(); i++)
	{
		mosqueteiros.objI(i)->resumeTimers();
	}
	for (i = 0; i < espadachins.numObjs(); i++)
	{
		espadachins.objI(i)->resumeTimers();
	}
	for (i = 0; i < cavaleiros.numObjs(); i++)
	{
		cavaleiros.objI(i)->resumeTimers();
	}
	for (i = 0; i < armadilhas.numObjs(); i++)
	{
		armadilhas.objI(i)->resumeTimers();
	}
}
