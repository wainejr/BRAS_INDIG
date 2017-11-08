#include "Fase.h"

Fase::Fase()
{
	///	MUDAR ISSO PARA AS DERIVADAS DA FASE DPS
	limX = 0;
	limY = 0;
	posRelX = 0;
	posRelY = 0;
	player1.builderJogador(10, ALT - 10, 20, 30, true, 100, &armaPlayer, 3);
	armaPlayer.builderEspada(0, 0, 5, 4, false, true, 1, &player1);
}


Fase::~Fase()
{

}


const bool Fase::personagemPodePular(Personagem* const pPers)
{
	return (colisaoChao(pPers));
}


void Fase::gerenciaColisoes()
{
	int i;
	Jogador* pJog;
	Mosqueteiro* pMosq;
	Espadachim* pEsp;
	EspadachimCavaleiro* pCav;
	Arma* pArma;
	Projetil* pProj;
	Rede* pRede;

	//colisoes com projeteis, plataformas 
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
			if(colisaoEntPlat(static_cast<Entidade*>(pProj)))
				projeteis.deleteObj(pProj);
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

	//colisão com ataques
	///MUDAR ESSE CÓDIGO PARA DENTRO DO DE CIMA
	for (i = 0; i < jogadores.numObjs(); i++)
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

	for (i = 0; i < espadachins.numObjs(); i++)
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


const bool Fase::colisaoChao(Personagem* const pPers)
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

//	Faz uma checagem análoga a da função "gereColisao", porém apenas
//	para o pé do personagem referenciado
const bool Fase::colisaoPersChao(Personagem* const pPers, Plataforma* const pPlataforma)
{
	//	checa apenas se o pe do personagem bateu no chão 
	if ((pPers->getY()) >= (pPlataforma->getY() - pPlataforma->getLimY()) &&
		pPers->getX() < (pPlataforma->getX() + pPlataforma->getLimX()) &&
		(pPers->getX() + pPers->getLimX()) > pPlataforma->getX())
	{
		//	se a diferença da entre a plataforma e a o ponto mais alto do 
		//	personagem for pelo menos da altura do player + velY + 1
		//	(valor para garantir que o personagem não passará reto da 
		//	plataforma) de altura e se o personagem estiver caindo...
		if (pPers->getVelY() <= 0 && (pPers->getY() -
			(pPlataforma->getY() - pPlataforma->getLimY())) <= (-pPers->getVelY()+1))
		{
			pPers->setY(pPlataforma->getY() - pPlataforma->getLimY());
			pPers->setVelY(0);
			return true;
		}
		return false;
	}
	return false;
}


const bool Fase::colisaoInimigo(Jogador* const pJog)
{
	Inimigo* pIni;
	bool colid = false;
	//	caso o jogador seja atingido pelo inimigo, toma o
	//	dobro de dano da arma desse
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


void Fase::atualizaFase()
{
	atualizaObjs();
	ataqueInimigos();
	gerenciaColisoes();
	atualizaAtivos();
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
			jogadores.objI(i)->atualizar();
		}
	}

	//atualizaInimigos();
	for (i = 0; i < espadachins.numObjs(); i++)
	{
		if (espadachins.objI(i)->getAtivo())
		{
			espadachins.objI(i)->atualizar();
		}
	}

	for (i = 0; i < mosqueteiros.numObjs(); i++)
	{
		if (mosqueteiros.objI(i)->getAtivo())
		{
			mosqueteiros.objI(i)->atualizar();
		}
	}

	for (i = 0; i < cavaleiros.numObjs(); i++)
	{
		if (cavaleiros.objI(i)->getAtivo())
		{
			cavaleiros.objI(i)->atualizar();
		}
	}

	Projetil* pProj;
	//atualizaProjeteis();
	for (i = 0; i < projeteis.numObjs(); i++)
	{
		pProj = projeteis.objI(i);
		if (pProj->getAtivo())
			pProj->atualizar();
	}

	Rede* pRede;
	for (i = 0; i < redes.numObjs(); i++)
	{
		pRede = redes.objI(i);
		if (pRede->getAtivo())
			pRede->atualizar();
	}
	Armadilha* pArmd;
	for (i = 0; i < armadilhas.numObjs(); i++)
	{
		pArmd = armadilhas.objI(i);
		if (pArmd->getAtivo())
			pArmd->atualizar();
	}
}


void Fase::desenhaObjs()
{
	desenhaProjeteis();
	desenhaCordas();
	desenhaPlataformas();
	desenhaEspinhos();
	desenhaArmadilhas();
	desenhaRedes();
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


void Fase::atualizaPosFase()
{
	if (posRelX >= 0)
	{
		//MUDAR ESSA CONODIÇÃO DEPOIS PARA QUANDO FOREM 2 PLAYERS
		if (jogadores.objI(0)->getX() > (posRelX+LARG/2))
		{
			posRelX = jogadores.objI(0)->getX() - LARG / 2;
		}
		else if (jogadores.objI(0)->getX() < (posRelX+LARG / 2))
		{
			posRelX = jogadores.objI(0)->getX() - LARG / 2;
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
				if (colisaoEntEnt(static_cast<Entidade*>(pPers), static_cast<Entidade*>(pProj)))
				{
					if (pProj->getVelX() > 0)
						pPers->tomaDano(pProj->getArmaProj()->getDano(), true);
					else
						pPers->tomaDano(pProj->getArmaProj()->getDano(), false);
					projeteis.deleteObj(pProj);
				}
			}
		}
	}
}


void Fase::resetAllObjs()
{
	//RESETAR OS TIMERS TAMBÉM
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


void Fase::initTimers()
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

	al_start_timer(timer);
}


const bool Fase::colisaoEntEnt(Entidade* const pEnt1, Entidade* const pEnt2)
{
	if ((pEnt1->getY()) >= (pEnt2->getY() - pEnt2->getLimY()) &&
		(pEnt1->getY() - pEnt1->getLimY()) <= pEnt2->getY() &&
		pEnt1->getX() <= (pEnt2->getX() + pEnt2->getLimX()) &&
		(pEnt1->getX() + pEnt1->getLimX()) >= pEnt2->getX())
		return true;
	return false;
}


void Fase::criarTimers()
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


const bool Fase::colisaoPlat(Entidade* const pEnt)
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


const bool Fase::colisaoEntPlat(Entidade* const pEnt)
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


const bool Fase::personagemPodeAtacar(Personagem* const pPers)
{
	return pPers->persPodeAtacar();
}


void Fase::atualizaAtivos()
{
	//FAZER A PARTE DO FORA DA TELA E DENTRO AINDA
	int i;
	Mosqueteiro* pMosq;
	Espadachim* pEsp;
	EspadachimCavaleiro* pCav;
	Projetil* pProj;

	//	Depois de o inimimigo ser "ultrapassado", ele é retirado da lista de inimigos
	//	já caso o inimigo seja "alcançado", ele é ativado.
	///TALVEZ COLOCAR UMA TOLERÂNCIA AQUI
	for (i = 0; i < mosqueteiros.numObjs(); i++)
	{
		pMosq = mosqueteiros.objI(i);
		if (pMosq->getAtivo())
		{
			if (pMosq->getVida() <= 0)
			{
				pMosq->setAtivo(false);
				mosqueteiros.retirarObj(pMosq);
			}
			else if ((pMosq->getX() + pMosq->getLimX()) < posRelX)
			{
				pMosq->setAtivo(false);
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
				espadachins.retirarObj(pEsp);
			}
			else if ((pEsp->getX() + pEsp->getLimX()) < posRelX)
			{
				pEsp->setAtivo(false);
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
				cavaleiros.retirarObj(pCav);
			}
			else if ((pCav->getX() + pCav->getLimX()) < posRelX)
			{
				pCav->setAtivo(false);
				cavaleiros.retirarObj(pCav);
			}
			
		}
		else if (!pCav->getAtivo() && (pCav->getX() - (posRelX + LARG)) < 0)
			pCav->setAtivo(true);
	}

	for (i = 0; i < projeteis.numObjs(); i++)
	{
		pProj = projeteis.objI(i);
		if (pProj->getAtivo() && (pProj->getX() > (LARG + posRelX + 20) || pProj->getX() < (posRelX - 20) ||
			pProj->getY() > (ALT - posRelY - 20) || pProj->getY() < (-posRelY + 20)))
			projeteis.deleteObj(pProj);
	}
}


const bool Fase::jogadorPodeSubir(Jogador* const pJog)
{
	if (pJog->getAtivo())
	{
		for (int i = 0; i < cordas.numObjs(); i++)
		{
			Corda* pCorda = cordas.objI(i);
			if (pCorda->getAtivo() && pCorda->getEscalavel())
			{
				//	se o jogador colidiu com a corda e está com o no mínimo 
				//	2 pixels "mais baixo" que a parte mais alta da corda...	
				//	Obs.: o valor dos pixels de diferença devem ser maior que o 
				//	"VEL_SUBIDA" pela sequência de atualizações que a fase segue
				if (colisaoEntEnt(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pCorda)))
				{
					if ((pJog->getY() - (pCorda->getY() - pCorda->getLimY())) > 2)
						return true;
					else
						pJog->setVelY(0);
					return false;
				}
			}
		}
	}
	return false;
}


void Fase::addCorda(Corda* const pCorda)
{
	cordas.addObj(pCorda);
}


void Fase::desenhaCordas()
{
	Corda* pCorda;
	for (int i = 0; i < cordas.numObjs(); i++)
	{
		pCorda = cordas.objI(i);
		if (pCorda->getAtivo())
			pCorda->draw(posRelX, posRelY);
	}
}


const bool Fase::jogadorEstaNumaCorda(Jogador* const pJog)
{
	if (pJog->getAtivo())
	{
		Corda* pCorda;
		for (int i = 0; i < cordas.numObjs(); i++)
		{
			pCorda = cordas.objI(i);
			if (pCorda->getAtivo() && pCorda->getEscalavel())
				if (colisaoEntEnt(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pCorda)))
					return true;
		}
	}
	return false;
}

void Fase::addArmadilha(Armadilha* const pArmd)
{
	armadilhas.addObj(pArmd);
}


void Fase::addEspinho(Espinho* const pEspinho)
{
	espinhos.addObj(pEspinho);
}


void Fase::addRede(Rede* const pRede)
{
	redes.addObj(pRede);
}


void Fase::desenhaEspinhos()
{
	Espinho* pEspinho;
	for (int i = 0; i < espinhos.numObjs(); i++)
	{
		pEspinho = espinhos.objI(i);
		if (pEspinho->getAtivo())
			pEspinho->draw(posRelX, posRelY);
	}
}


void Fase::desenhaRedes()
{
	Rede* pRede;
	for (int i = 0; i < redes.numObjs(); i++)
	{
		pRede = redes.objI(i);
		if (pRede->getAtivo())
			pRede->draw(posRelX, posRelY);
	}
}


void Fase::desenhaArmadilhas()
{
	Armadilha* pArmd;
	for (int i = 0; i < armadilhas.numObjs(); i++)
	{
		pArmd = armadilhas.objI(i);
		if (pArmd->getAtivo())
			pArmd->draw(posRelX, posRelY);
	}
}


void Fase::colisaoEspinhos(Personagem* const pPers)
{
	int i;
	Espinho* pEspinho;
	for (i = 0; i < espinhos.numObjs(); i++)
	{
		pEspinho = espinhos.objI(i);
		if (colisaoEntEnt(static_cast<Entidade*>(pPers), static_cast<Entidade*>(pEspinho)))
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


void Fase::gereColisao(Entidade* const pMovel, Entidade* const pParado)
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

	//gambiarra final pra não dar erro na ponta da plataforma
	if (pMovel->getX() + pMovel->getLimX() == pParado->getX() && pMovel->getY() == pParado->getY() - pParado->getLimY())
		pMovel->setX(pMovel->getX() + 1);
	if (pMovel->getX() == pParado->getX()+pParado->getLimX() && pMovel->getY() == pParado->getY() - pParado->getLimY())
		pMovel->setX(pMovel->getX() - 1);
}


void Fase::colisaoArmadilhas(Jogador* const pJog)
{
	Armadilha* pArmd;
	for (int i = 0; i < armadilhas.numObjs(); i++)
	{
		pArmd = armadilhas.objI(i);
		if (pArmd->getAtivo() && colisaoEntEnt(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pArmd)))
		{
			pJog->tomaDano(pArmd->getDano(), 2);
			pArmd->acionar();
		}
	}
}


void Fase::colisaoLinhaRede(Jogador* const pJog)
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
			else
			{
				if (colisaoEntEnt(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pRede)))
				{
					pJog->tomaDano(pRede->getDano(), 3);
				}
			}
		}
	}
}


void Fase::colisaoRede(Jogador* const pJog)
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
