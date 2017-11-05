#include "Fase.h"

Fase::Fase()
{
	///	MUDAR ISSO PARA AS DERIVADAS DA FASE DPS
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
	//colisões com projeteis
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

	//colisoes com plataformas
	for (i = 0; i < jogadores.numObjs(); i++)
	{
		if (jogadores.objI(i)->getAtivo())
		{
			if (!personagemPodePular(static_cast<Personagem*>(jogadores.objI(i))))
				jogadores.objI(i)->cair(((float)GRAV / FPS));
			colisaoPlat(static_cast<Entidade*>(jogadores.objI(i)));
		}
	}
	for (i = 0; i < mosqueteiros.numObjs(); i++)
	{
		if (mosqueteiros.objI(i)->getAtivo())
		{
			if (mosqueteiros.objI(i)->getFisica() && !personagemPodePular(static_cast<Personagem*>(mosqueteiros.objI(i))))
				mosqueteiros.objI(i)->cair(((float)GRAV / FPS));
			colisaoPlat(static_cast<Entidade*>(mosqueteiros.objI(i)));
		}
	}
	for (i = 0; i < espadachins.numObjs(); i++)
	{
		if (espadachins.objI(i)->getAtivo())
		{
			if (espadachins.objI(i)->getFisica() && !personagemPodePular(static_cast<Personagem*>(espadachins.objI(i))))
				espadachins.objI(i)->cair(((float)GRAV / FPS));
			colisaoPlat(static_cast<Entidade*>(espadachins.objI(i)));
		}
	}
	for (i = 0; i < cavaleiros.numObjs(); i++)
	{
		if (cavaleiros.objI(i)->getAtivo())
		{
			if (cavaleiros.objI(i)->getFisica() && !personagemPodePular(static_cast<Personagem*>(cavaleiros.objI(i))))
				cavaleiros.objI(i)->cair(((float)GRAV / FPS));
			colisaoPlat(static_cast<Entidade*>(cavaleiros.objI(i)));
		}
	}
	for (i = 0; i < projeteis.numObjs(); i++)
	{
		if (projeteis.objI(i)->getAtivo())
		{
			if(colisaoProjPlat(projeteis.objI(i)))
				projeteis.deleteObj(projeteis.objI(i));
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
			{
				if (colisaoPersChao(pPers, pPlat))
					return true;
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
		//	personagem for pelo menos da altura do player + velY
		//	(valor para garantir que o personagem não passará reto da 
		//	plataforma) de altura e se o personagem estiver caindo...
		if (pPers->getVelY() <= 0 && (pPers->getY() -
			(pPlataforma->getY() - pPlataforma->getLimY())) <= (-pPers->getVelY()))
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

	//atualizaProjeteis();
	for (i = 0; i < projeteis.numObjs(); i++)
	{
		Projetil* pProj = projeteis.objI(i);
		///MUDAR ISSO PARA A FUNÇÃO DE ALTERAR ATIVOS E TALS
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
		if (pMosq->getAtivo() && pMosq->persPodeAtacar())
		{
			projeteis.addObj(pMosq->atirar());
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
					pPers->tomaDano(pProj->getArmaProj()->getDano());
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
		jogadores.objI(i)->initTimerInv();
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
	if ((pEnt1->getY()) > (pEnt2->getY() - pEnt2->getLimY()) &&
		(pEnt1->getY() - pEnt1->getLimY()) <= pEnt2->getY() &&
		pEnt1->getX() < (pEnt2->getX() + pEnt2->getLimX()) &&
		(pEnt1->getX() + pEnt1->getLimX()) > pEnt2->getX())
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
}


/// REFAZER ISSO PARA NAO DAR BUG E TALS
const bool Fase::colisaoPlat(Entidade* const pEnt)
{
	int i;
	bool colid = false;
	Plataforma* pPlat;
	for (i = 0; i < plataformas.numObjs(); i++)
	{
		pPlat = plataformas.objI(i);
		if (pPlat->getAtivo() && pPlat->getColisaoBaixo())
		{
			if (colisaoEntEnt(pEnt, static_cast<Entidade*>(pPlat)))
			{
				colid = true;
				///CONDIÇÕES ANÁLOGAS A DO "personagemPodePular"

				//	se a entidade estiver descendo, bateu na parte de cima
				//	da plataforma e a diferença entre a parte mais alta da 
				//	plataforma e a altura em y da entidade for no máximo de 
				//	-velY + 1 (valor para garantir que a colisão ocorreu 
				//	por causa da subida de altura da entidade)...
				if (pEnt->getVelY() <= 0 && (pEnt->getY()-pEnt->getLimY()) < (pPlat->getY()-pPlat->getLimY()) && (pEnt->getY() -
					(pPlat->getY() - pPlat->getLimY())) <= (-pEnt->getVelY()+1))
				{
					pEnt->setY(pPlat->getY() - pPlat->getLimY());
					pEnt->setVelY(0);
					return true;
				}

				//	se a entidade estiver subindo, bateu na parte debaixo
				//	da plataforma e a diferença entre a altura em y da 
				//	plataforma e a o ponto mais alto da entidade for no 
				//	máximo de velY + 1 (valor para garantir que a colisão 
				//	ocorreu por causa da subida de altura da entidade)...
				if (pEnt->getVelY() >= 0 && pEnt->getY() > pPlat->getY() && (pEnt->getY() - pEnt->getLimY())
					< pPlat->getY() && -(pEnt->getY()-pEnt->getLimY()-pPlat->getY()) <= (pEnt->getVelY()+1))
				{

					pEnt->setY(pPlat->getY() + pEnt->getLimY());
					pEnt->setVelY(0);
				}

				//	se a entidade estiver andando para direita, bateu na 
				//	parte esquerda da plataforma e a diferença entre a 
				//	direita da entidade e a esquerda da plataforma for no 
				//	máximo de velX + 1 (valor para garantir que a colisão 
				//	ocorreu por causa do movimento a direita do pers)...
				if (pEnt->getVelX() >= 0 && (pEnt->getX() + pEnt->getLimX()) > pPlat->getX() && 
					(pEnt->getX() + pEnt->getLimX() - pPlat->getX()) <= (pEnt->getVelX()+1))
				{
					pEnt->setX(pPlat->getX() - pEnt->getLimX());
					pEnt->setVelX(0);
				}
				//	se a entidade estiver andando para esquerda, bateu na 
				//	parte direita da plataforma e a diferença entre a 
				//	esquerda da entidade e a direita da plataforma for no 
				//	máximo de -velX + 1 (valor para garantir que a colisão 
				//	ocorreu por causa do movimento a direita do pers)...
				if	(pEnt->getVelX() <= 0 && pEnt->getX() < (pPlat->getX() + pPlat->getLimX()) && 
					(pPlat->getX()+pPlat->getLimX()-pEnt->getX()) <=(-pEnt->getVelX()+1))
				{
					pEnt->setX(pPlat->getX() + pPlat->getLimX());
					pEnt->setVelX(0);
				}
			}
		}
	}
	return colid;
}


const bool Fase::colisaoProjPlat(Projetil* const pProj)
{
	int i;
	bool colid = false;
	Plataforma* pPlat;
	for (i = 0; i < plataformas.numObjs(); i++)
	{
		pPlat = plataformas.objI(i);
		if (colisaoEntEnt(static_cast<Entidade*>(pProj), static_cast<Entidade*>(pPlat)))
			return true;
	}
	return false;
}
