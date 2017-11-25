#include "Mapa.h"



Mapa::Mapa()
{
	jog1 = nullptr;
	jog2 = nullptr;
	fundo = nullptr;
}


Mapa::~Mapa()
{
	retiraTodosObjs();
	al_destroy_bitmap(fundo);
}

void Mapa::retiraTodosObjs()
{
	Inimigo* pIni;
	Obstaculo* pObs;
	Projetil* pProj;
	Plataforma* pPlat;
	Entidade* pEnt;
	///	ADICIONAR UM CLEAR NA LISTA PARA SÓ CHAMAR ISSO AO FAZER ISSO

	while (entidades.numEnt() > 0)
	{
		pEnt = entidades.entPosI(0);
		entidades.retirarEnt(pEnt);
	}

	if (jog1 != nullptr)
	{
		jog1 = nullptr;
	}

	if (jog2 != nullptr)
	{
		jog2 = nullptr;
	}

	while (inimigos.numInim() > 0)
	{
		pIni = inimigos.inimPosi(0);
		inimigos.retiraInim(pIni);
	}

	//	projeteis são deletados por serem criados durante a execução da Mapa
	while (projeteis.numProj() > 0)
	{
		pProj = projeteis.projPosi(0);
		projeteis.retirarProj(pProj);
		delete(pProj);
	}

	while (plataformas.numPlat() > 0)
	{
		pPlat = plataformas.platPosi(0);
		plataformas.retiraPlat(pPlat);
	}

	while (obstaculos.numObst() > 0)
	{
		pObs = obstaculos.obstPosi(0);
		obstaculos.retirarObst(pObs);
	}
}


void Mapa::atualizaMapa()
{
	atualizaObjs();
	validaPosPers();
	gerenciaColisoes();
	if (jog1 != nullptr || jog2 != nullptr)
		atualizaAlvos();
	ataqueInimigos();
	atualizaAtivos();
	atualizaPosMapa();
}


void Mapa::atualizaObjs()
{
	int i;

	Entidade* pEnt;
	for (i = 0; i < entidades.numEnt(); i++)
	{
		pEnt = entidades.entPosI(i);
		if (pEnt->getAtivo())
		{
			pEnt->atualizar();
		}
	}
}


void Mapa::atualizaAtivos()
{
	int i;
	Inimigo* pIni;
	Projetil* pProj;
	Entidade* pEnt;
	Obstaculo* pObs;
	Armadilha* pArmd;

	//	Depois de o inimimigo ser "ultrapassado", ele é retirado da lista de inimigos
	//	já caso o inimigo seja "alcançado", ele é ativado.
	///	TALVEZ COLOCAR UMA TOLERÂNCIA AQUI
	///	FAZER O MESMO PARA REDES, ESPINHOS E ARMADILHAS

	for (i = 0; i < entidades.numEnt(); i++)
	{
		pEnt = entidades.entPosI(i);
		if (pEnt->getAtivo())
		{
			if (!estaNaTela(pEnt))
			{
				if (pEnt->getID() != REDE)
				{
					pEnt->setAtivo(false);
					if (pEnt->getID() == MOSQUETEIRO || pEnt->getID() == CAVALEIRO
						|| pEnt->getID() == ESPADACHIM)
					{
						static_cast<Inimigo*>(pEnt)->stopTimers();
					}
					else if (pEnt->getID() == ARMADILHA)
					{
						static_cast<Armadilha*>(pEnt)->stopTimers();
					}
				}
				else
				{
					Rede* pRede = static_cast<Rede*>(pEnt);
					if (!estaNaTela(pRede->getLinha()))
						pRede->setAtivo(false);
				}
			}
		}
		else
		{
			if (estaNaTela(pEnt))
			{
				pEnt->setAtivo(true);
				if (pEnt->getID() == MOSQUETEIRO || pEnt->getID() == CAVALEIRO
					|| pEnt->getID() == ESPADACHIM)
				{
					static_cast<Inimigo*>(pEnt)->resumeTimers();
				}
				else if (pEnt->getID() == ARMADILHA)
				{
					static_cast<Armadilha*>(pEnt)->resumeTimers();
				}
			}
			else if (pEnt->getID() == REDE)
			{
				Rede* pRede = static_cast<Rede*>(pEnt);
				if (estaNaTela(pRede->getLinha()))
					pRede->setAtivo(true);
			}

		}
	}

	//	Os comandos a seguir são mais fortes que "estar na tela" ou não
	if (jog1 != nullptr)
	{
		if (jog1->getAtivo() && !(*jog1))
		{
			jog1->setAtivo(false);
			jog1->resetaTimers();
			entidades.retirarEnt(static_cast<Entidade*>(jog1));
			jog1 = nullptr;
		}
	}

	if (jog2 != nullptr)
	{
		if (jog2->getAtivo() && !(*jog2))
		{
			jog2->setAtivo(false);
			jog2->resetaTimers();
			entidades.retirarEnt(static_cast<Entidade*>(jog2));
			jog2 = nullptr;
		}
	}


	for (i = 0; i < inimigos.numInim(); i++)
	{
		pIni = inimigos.inimPosi(i);
		if (pIni->getAtivo())
		{
			if (!(*pIni))
			{
				pIni->setAtivo(false);
				pIni->resetaTimers();
				inimigos.retiraInim(pIni);
				entidades.retirarEnt(static_cast<Entidade*>(pIni));
			}
		}
	}

	for (i = 0; i < projeteis.numProj(); i++)
	{
		pProj = projeteis.projPosi(i);
		if (!estaNaTela(static_cast<Entidade*>(pProj)))
		{
			projeteis.retirarProj(pProj);
			entidades.retirarEnt(static_cast<Entidade*>(pProj));
			delete(pProj);
		}
	}

	for (i = 0; i < obstaculos.numObst(); i++)
	{
		pObs = obstaculos.obstPosi(i);
		if (pObs->getID() == ARMADILHA)
		{
			pArmd = static_cast<Armadilha*>(pObs);
			if (pArmd->getDesarmou())
			{
				obstaculos.retirarObst(pObs);
				entidades.retirarEnt(static_cast<Entidade*>(pArmd));
			}
		}
	}
}


void Mapa::atualizaAlvos()
{
	Inimigo* pIni;
	for (int i = 0; i < inimigos.numInim(); i++)
	{
		pIni = inimigos.inimPosi(i);
		if (pIni->getAtivo())
		{
			alvoInimigo(pIni);
		}
	}
}


void Mapa::alvoInimigo(Inimigo* const pIni)
{
	Jogador* pJog1 = jog1;
	Jogador* pJog2 = jog2;
	if (pJog1 != nullptr && pJog2 != nullptr)
	{
		//	se ambos os jogadores estão na mesma altura do inimigo...
		if (pJog1->getY() > pIni->getY() - pIni->getLimY() && pJog1->getY() - pJog1->getLimY() < pIni->getY() &&
			pJog2->getY() > pIni->getY() - pIni->getLimY() && pJog2->getY() - pJog2->getLimY() < pIni->getY())
		{
			int distIniJog1 = diffCent(static_cast<Entidade*> (jog1), static_cast<Entidade*>(pIni));
			int distIniJog2 = diffCent(static_cast<Entidade*> (jog2), static_cast<Entidade*>(pIni));
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
		else
		{
			int catAdjJog1 = diffCent(static_cast<Entidade*> (jog1), static_cast<Entidade*>(pIni));
			int catAdjJog2 = diffCent(static_cast<Entidade*> (jog2), static_cast<Entidade*>(pIni));
			int catOpsJog1 = jog1->getY() - jog1->getLimY() / 2 - (pIni->getY() - pIni->getLimY() / 2);
			int catOpsJog2 = jog2->getY() - jog2->getLimY() / 2 - (pIni->getY() - pIni->getLimY() / 2);
			//	define como inimigo o jogador que está mais perto
			if (catAdjJog1*catAdjJog1 + catOpsJog1*catOpsJog1 > catAdjJog2*catAdjJog2 + catOpsJog2*catOpsJog2)
				pIni->setAlvo(jog1);
			else
				pIni->setAlvo(jog2);
		}
	}
	else if (pJog1 != nullptr)
	{
		pIni->setAlvo(pJog1);
	}
	else
		pIni->setAlvo(pJog2);
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
	Inimigo* pIni;
	Projetil* pProj;
	Obstaculo* pObs;

	//	colisoes com projeteis, plataformas e obstaculos
	for (i = 0; i < 2; i++)
	{
		if (i == 0)
			pJog = jog1;
		else
			pJog = jog2;
		if (pJog != nullptr)
		{
			if (pJog->getAtivo())
			{
				if (!pJog->getInvuneravel())
				{
					colisaoObstaculos(static_cast<Personagem*>(pJog));
					colisaoInimigo(pJog);
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
	}

	for (i = 0; i < inimigos.numInim(); i++)
	{
		pIni = inimigos.inimPosi(i);
		if (pIni->getAtivo())
		{
			if (!pIni->getInvuneravel())
			{
				colisaoObstaculos(static_cast<Personagem*>(pIni));
				colisaoProjeteis(static_cast<Personagem*>(pIni));
			}
			if (pIni->getFisica() && !personagemPodePular(static_cast<Personagem*>(pIni)))
				pIni->cair(((float)GRAV / FPS));
			colisaoPlat(static_cast<Entidade*>(pIni));
		}
	}

	for (i = 0; i < projeteis.numProj(); i++)
	{
		pProj = projeteis.projPosi(i);
		if (pProj->getAtivo())
		{
			if (colisaoEntPlat(static_cast<Entidade*>(pProj)))
			{
				projeteis.retirarProj(pProj);
				entidades.retirarEnt(static_cast<Entidade*>(pProj));
				delete(pProj);
			}
		}
	}

	for (int i = 0; i < obstaculos.numObst(); i++)
	{
		pObs = obstaculos.obstPosi(i);
		if (pObs->getAtivo() && pObs->getID() == REDE)
		{
			if (colisaoEntPlat(static_cast<Entidade*>(pObs)))
			{
				pObs->setAtivo(false);
				obstaculos.retirarObst(pObs);
				entidades.retirarEnt(static_cast<Entidade*>(pObs));
			}
		}
	}
}


void Mapa::gerenciaColisaoAtaques()
{
	Jogador* pJog;
	Inimigo* pIni;
	Arma* pArma;
	//	colisão com ataques
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
			pJog = jog1;
		else
			pJog = jog2;
		if (pJog != nullptr)
		{
			if (pJog->getAtacando() && pJog->getAtivo() && pJog->getArma()->getID() == ESPADA)
			{
				pArma = pJog->getArma();
				int u;
				for (u = 0; u < inimigos.numInim(); u++)
				{
					pIni = inimigos.inimPosi(u);
					if (pIni->getAtivo() && !pIni->getInvuneravel() && colisaoEntEnt
					(static_cast<Entidade*>(pIni), static_cast<Entidade*>(pArma)))
					{
						if (pIni->getID() != CAVALEIRO)
						{
							if (((int)pJog->getX() + pJog->getLimX() / 2) < ((int)pIni->getX() + pIni->getLimX() / 2))
								pIni->tomaDano(pArma->getDano(), 1);
							else
								pIni->tomaDano(pArma->getDano(), -1);
						}
						else
							pIni->tomaDano(pArma->getDano(), 0);
					}
				}
			}
		}
	}
	for (int i = 0; i < inimigos.numInim(); i++)
	{
		pIni = inimigos.inimPosi(i);
		if (pIni->getAtivo() && pIni->getID() == ESPADACHIM && pIni->getAtacando())
		{
			pArma = pIni->getArma();
			for (int u = 0; u < 2; u++)
			{
				if (u == 0)
					pJog = jog1;
				else
					pJog = jog2;
				if (pJog != nullptr)
				{
					if (pJog->getAtivo() && !pJog->getInvuneravel() && colisaoEntEnt
					(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pArma)))
					{
						if (((int)pIni->getX() + pIni->getLimX() / 2) < ((int)pJog->getX() + pJog->getLimX() / 2))
							pJog->tomaDano(pArma->getDano(), 1);
						else
							pJog->tomaDano(pArma->getDano(), -1);
					}
				}
			}
		}
	}

}


void Mapa::perDescePlat(Personagem* const pPers)
{
	if (pPers->getAtivo() && persPodeDescerPlat(pPers))
	{
		//	3 pixels para não haver risco de voltar a posição do 
		//	personagem na sequência da atualização da fase
		pPers->setY(pPers->getY() + 3);
	}
}


const bool Mapa::colisaoChao(Personagem* const pPers)
{
	Plataforma* pPlat;
	if (pPers->getAtivo())
	{
		for (int i = 0; i < plataformas.numPlat(); i++)
		{
			pPlat = plataformas.platPosi(i);
			if (pPlat->getAtivo() && pPlat->getID() == PLATAFORMA)
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
		for (int i = 0; i < inimigos.numInim(); i++)
		{
			pIni = inimigos.inimPosi(i);
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
	for (i = 0; i < plataformas.numPlat(); i++)
	{
		pPlat = plataformas.platPosi(i);
		if (pPlat->getAtivo() && pPlat->getID() == PLATAFORMA)
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
	for (i = 0; i < plataformas.numPlat(); i++)
	{
		pPlat = plataformas.platPosi(i);
		if (pPlat->getID() == PLATAFORMA && colisaoEntEnt(pEnt, static_cast<Entidade*>(pPlat)))
			return true;
	}
	return false;
}


void Mapa::colisaoProjeteis(Personagem* const pPers)
{
	Projetil* pProj;
	for (int i = 0; i < projeteis.numProj(); i++)
	{
		pProj = projeteis.projPosi(i);
		if (pProj->getAtivo())
		{
			//	se o projetil for do inimigo e o alvo jogador ou se o projetil
			//	for do jogador e o alvo inimigo...
			if (((pPers->getID() == RAONI || pPers->getID() == TECA) &&
				pProj->getID() == PROJETIL_MOSQ) || ((pPers->getID() == CAVALEIRO ||
					pPers->getID() == ESPADACHIM || pPers->getID() == MOSQUETEIRO) 
					&& pProj->getID() == PROJETIL_ARCO))
			{
				if (colisaoEntEnt(static_cast<Entidade*>(pPers), static_cast<Entidade*>(pProj)))
				{
					if (pPers->getID() != CAVALEIRO)
					{
						if (pProj->getVelX() > 0)
							pPers->tomaDano(pProj->getArmaProj()->getDano(), 1);
						else
							pPers->tomaDano(pProj->getArmaProj()->getDano(), -1);
					}
					else
						pPers->tomaDano(pProj->getArmaProj()->getDano(), 0);
					projeteis.retirarProj(pProj);
					entidades.retirarEnt(static_cast<Entidade*>(pProj));
					delete(pProj);
				}
			}
		}
	}
}

const int Mapa::diffCent(Entidade* const pEnt1, Entidade* const pEnt2)
{
	int diffCent = pEnt1->getX() + pEnt1->getLimX() / 2 - (pEnt2->getX() + pEnt2->getLimX() / 2);
	if (diffCent < 0)
		diffCent = -diffCent;
	return diffCent;
}

void Mapa::colisaoObstaculos(Personagem* const pPers)
{
	int i;
	Obstaculo* pObs;
	Jogador* pJog;
	if (!pPers->getInvuneravel())
	{
		for (i = 0; i < obstaculos.numObst(); i++)
		{
			pObs = obstaculos.obstPosi(i);
			if (pObs->getAtivo())
			{
				if (pObs->getID() == ESPINHO)
				{
					//	COLISAO PARA TODOS
					if (colisaoEntEnt(static_cast<Entidade*>(pPers), static_cast<Entidade*>(pObs)))
					{
						//	caso o personagem esteja andando para direita ou parado
						//	recebe dano e um knock back para esquerda, caso 
						//	contrário recebe dano e um knock back para direita
						if (pPers->getVelX() >= 0)
							pPers->tomaDano(pObs->getDano(), -1);
						else
							pPers->tomaDano(pObs->getDano(), 1);
					}
				}
				//	COLISAO APENAS PARA JOGADORES
				else if (pPers->getID() == RAONI || pPers->getID() == TECA)
				{
					pJog = static_cast<Jogador*>(pPers);
					if (pObs->getID() == ARMADILHA)
					{
						if (!static_cast<Armadilha*>(pObs)->getAcionada())
						{
							if (diffCent(static_cast<Entidade*>(pPers), static_cast<Entidade*>(pObs)) <= DIFFCENT_ARMD &&
								pObs->getY() >= pPers->getY() - pPers->getLimY() && pObs->getY() - pObs->getLimY() <= pPers->getY())
							{
								pJog->tomaDano(pObs->getDano(), 2);
								static_cast<Armadilha*>(pObs)->acionar();
							}
						}
					}
					else if (pObs->getID() == REDE)
					{
						if (static_cast<Rede*>(pObs)->getAtivada() && colisaoEntEnt
						(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pObs)))
						{
							pJog->tomaDano(pObs->getDano(), 3);
							pObs->setAtivo(false);
							obstaculos.retirarObst(pObs);
							entidades.retirarEnt(static_cast<Entidade*>(pObs));
						}
					}
				}
			}
		}
	}
}


void Mapa::colisaoLinhaRede(Jogador* const pJog)
{
	Corda* pCorda;
	Rede* pRede;
	Obstaculo* pObs;
	for (int i = 0; i < obstaculos.numObst(); i++)
	{
		pObs = obstaculos.obstPosi(i);
		if (pObs->getID() == REDE && pObs->getAtivo())
		{
			pRede = static_cast<Rede*>(pObs);
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
	Inimigo* pIni;
	Projetil* pProj;
	for (int i = 0; i < inimigos.numInim(); i++)
	{
		pIni = inimigos.inimPosi(i);
		if (pIni->getAtivo() && pIni->persPodeAtacar())
		{
			if (pIni->getID() == ESPADACHIM)
				pIni->atacar();
			else if (pIni->getID() == MOSQUETEIRO)
			{
				pProj = pIni->atirar();
				projeteis.addProj(pProj);
				entidades.addEnt(static_cast<Entidade*>(pProj));
			}
		}
	}
}


const bool Mapa::personagemPodeAtacar(Personagem* const pPers)
{
	return pPers->persPodeAtacar();
}


const bool Mapa::jogadorPodeSubir(Jogador* const pJog)
{
	Plataforma* pPlat;
	Corda* pCorda;
	if (pJog->getAtivo())
	{
		for (int i = 0; i < plataformas.numPlat(); i++)
		{
			pPlat = plataformas.platPosi(i);
			if (pPlat->getAtivo() && pPlat->getID() == CORDA)
			{
				pCorda = static_cast<Corda*>(pPlat);
				if (pCorda->getEscalavel())
				{
					//	se a diferença entre o centro do jogador e da corda for menor
					//	ou igual DIFFCENT_CORDA e o jogador está com a no mínimo VEL_SUBIDA+1 
					//	pixels "mais baixo" que a parte mais alta da corda...	
					//	Obs.: o valor dos pixels de diferença devem ser maior que o 
					//	"VEL_SUBIDA" pela sequência de atualizações que o Mapa segue
					{
						if (colisaoEntEnt(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pCorda)))
						{
							int diff = diffCent(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pCorda));
							if (diff <= DIFFCENT_CORDA)
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
	}
	return false;
}


const bool Mapa::personagemPodePular(Personagem* const pPers)
{
	return (colisaoChao(pPers));
}


const bool Mapa::jogadorEstaNumaCorda(Jogador* const pJog)
{
	Plataforma* pPlat;
	Corda* pCorda;
	if (pJog->getAtivo())
	{
		for (int i = 0; i < plataformas.numPlat(); i++)
		{
			pPlat = plataformas.platPosi(i);
			if (pPlat->getAtivo() && pPlat->getID() == CORDA)
			{
				pCorda = static_cast<Corda*>(pPlat);
				if (pCorda->getEscalavel())
				{
					if (colisaoEntEnt(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pCorda)))
					{
						int diff = diffCent(static_cast<Entidade*>(pJog), static_cast<Entidade*>(pCorda));
						if (diff <= DIFFCENT_CORDA)
							return true;
					}
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
		for (int i = 0; i < plataformas.numPlat(); i++)
		{
			pPlat = plataformas.platPosi(i);
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
	Entidade* pEnt;
	desenhaFundo();

	//	layers
	for (int i = 0; i < entidades.numEnt(); i++)
	{
		pEnt = entidades.entPosI(i);
		if (pEnt->getAtivo() && pEnt->getID() == PROJETIL_ARCO || pEnt->getID() == PROJETIL_MOSQ)
		{
			pEnt->draw(posRelX, posRelY);
		}
	}
	for (int i = 0; i < entidades.numEnt(); i++)
	{
		pEnt = entidades.entPosI(i);
		if (pEnt->getAtivo() && pEnt->getID() == PLATAFORMA || pEnt->getID() == CORDA)
		{
			pEnt->draw(posRelX, posRelY);
		}
	}
	for (int i = 0; i < entidades.numEnt(); i++)
	{
		pEnt = entidades.entPosI(i);
		if (pEnt->getAtivo() && pEnt->getID() == ARMADILHA || pEnt->getID() == REDE || pEnt->getID() == ESPINHO)
		{
			pEnt->draw(posRelX, posRelY);
		}
	}
	for (int i = 0; i < entidades.numEnt(); i++)
	{
		pEnt = entidades.entPosI(i);
		if (pEnt->getAtivo() && pEnt->getID() == CAVALEIRO|| pEnt->getID() == MOSQUETEIRO|| pEnt->getID() == ESPADACHIM)
		{
			pEnt->draw(posRelX, posRelY);
		}
	}
	for (int i = 0; i < entidades.numEnt(); i++)
	{
		pEnt = entidades.entPosI(i);
		if (pEnt->getAtivo() && pEnt->getID() == RAONI || pEnt->getID() == TECA)
		{
			pEnt->draw(posRelX, posRelY);
		}
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
	if (pPlataforma != nullptr)
	{
		plataformas.addPlat(pPlataforma);
		entidades.addEnt(static_cast<Entidade*>(pPlataforma));
	}
}


void Mapa::addPlayer(Jogador* const pPlayer)
{
	if (pPlayer != nullptr)
	{
		if (jog1 == nullptr)
		{
			jog1 = pPlayer;
			entidades.addEnt(static_cast<Entidade*>(jog1));
		}
		else if (jog2 == nullptr)
		{
			jog2 = pPlayer;
			entidades.addEnt(static_cast<Entidade*>(jog2));
		}
	}
}


void Mapa::addProjetil(Projetil* const pProj)
{
	if (pProj != nullptr)
	{
		projeteis.addProj(pProj);
		entidades.addEnt(static_cast<Entidade*>(pProj));
	}
}

void Mapa::addObstaculo(Obstaculo* const pObs)
{
	if (pObs != nullptr)
		obstaculos.addObst(pObs);
	entidades.addEnt(static_cast<Entidade*>(pObs));
}


void Mapa::addInimigo(Inimigo* const pIni)
{
	if (pIni != nullptr)
	{
		inimigos.addInim(pIni);
		entidades.addEnt(static_cast<Entidade*>(pIni));
	}
}

void Mapa::atualizaPosMapa()
{
	if (posRelX >= 0)
	{
		if (jog1 != nullptr && jog2 == nullptr || jog1 == nullptr && jog2 != nullptr)
		{
			Jogador* pJog1;
			if (jog1 != nullptr)
				pJog1 = jog1;
			else
				pJog1 = jog2;
			//MUDAR ESSA CONODIÇÃO DEPOIS PARA QUANDO FOREM 2 PLAYERS
			if (pJog1->getX() + pJog1->getLimX() > (posRelX + LARG / 2) && posRelX + LARG < limX)
			{
				posRelX = pJog1->getX() + pJog1->getLimX() - LARG / 2;
			}
			else if (pJog1->getX() < (posRelX + LARG / 3))
			{
				posRelX = pJog1->getX() - LARG / 3;
			}
		}
		else if (jog1 != nullptr && jog2 != nullptr)
		{
			Jogador* pJog1 = jog1;
			Jogador* pJog2 = jog2;

			//	se a média da posição dos jogadores não está dentro dos limites
			//	definidos da fase...
			if ((pJog1->getX() + pJog1->getLimX() / 2 + pJog2->getX() + pJog2->getLimX() / 2) / 2 > (posRelX + LARG / 2) && posRelX + LARG < limX)
			{
				posRelX = (pJog1->getX() + pJog1->getLimX() / 2 + pJog2->getX() + pJog2->getLimX() / 2) / 2 - LARG / 2;
			}
			else if ((pJog1->getX() + pJog1->getLimX() / 2 + pJog2->getX() + pJog2->getLimX() / 2) / 2 < (posRelX + LARG / 4))
			{
				posRelX = (pJog1->getX() + pJog1->getLimX() / 2 + pJog2->getX() + pJog2->getLimX() / 2) / 2 - LARG / 4;
			}

			//	se o jogador 1 está "para trás" da fase...
			if (pJog1->getX() < posRelX && pJog1->getVelX() < 0)
			{
				//	coloca-o na posição relativa da fase e zera sua velocidade em x
				pJog1->setX(posRelX);
				pJog1->setVelX(0);
			}
			//	se o jogador 1 está "para frente" da fase...
			else if (pJog1->getX() + pJog1->getLimX() > posRelX + LARG && pJog1->getVelX() > 0)
			{
				//	coloca-o no "fim da tela" e zera sua velocidade em x
				pJog1->setX(posRelX + LARG - pJog1->getLimX());
				pJog1->setVelX(0);
			}

			//	se o jogador 2 está "para trás" da fase...
			if (pJog2->getX() < posRelX && pJog2->getVelX() < 0)
			{
				//	coloca-o na posição relativa da fase e zera sua velocidade em x
				pJog2->setX(posRelX);
				pJog2->setVelX(0);
			}
			//	se o jogador 2 está "para frente" da fase...
			else if (pJog2->getX() + pJog2->getLimX() > posRelX + LARG && pJog2->getVelX() > 0)
			{
				//	coloca-o no "fim da tela" e zera sua velocidade em x
				pJog2->setX(posRelX + LARG - pJog2->getLimX());
				pJog2->setVelX(0);
			}
		}
	}
	if (posRelX < 0)
		posRelX = 0;
	else if (posRelX > limX - LARG)
	{
		posRelX = limX - LARG;
	}
}

void Mapa::criarTimers()
{
	int i;
	Inimigo* pIni;
	Obstaculo* pObs;
	Jogador* pJog;
	for (i = 0; i < 2; i++)
	{
		if (i == 0)
			pJog = jog1;
		else
			pJog = jog2;

		if (pJog != nullptr)
			pJog->createTimers();
	}
	for (i = 0; i < inimigos.numInim(); i++)
	{
		pIni = inimigos.inimPosi(i);
		pIni->createTimers();
	}
	for (i = 0; i < obstaculos.numObst(); i++)
	{
		pObs = obstaculos.obstPosi(i);
		pObs->createTimer();
	}
}


void Mapa::initTimers()
{
	int i;
	Obstaculo* pObs;
	Inimigo* pIni;
	Jogador* pJog;
	for (i = 0; i < 2; i++)
	{
		if (i == 0)
			pJog = jog1;
		else
			pJog = jog2;

		if (pJog != nullptr)
			pJog->initTimer();
	}

	for (i = 0; i < inimigos.numInim(); i++)
	{
		pIni = inimigos.inimPosi(i);
		pIni->initTimer();
	}


	for (i = 0; i < obstaculos.numObst(); i++)
	{
		pObs = obstaculos.obstPosi(i);
		pObs->initTimer();
	}
}

void Mapa::stopTimers()
{
	int i;
	Obstaculo* pObs;
	Inimigo* pIni;
	Jogador* pJog;
	for (i = 0; i < 2; i++)
	{
		if (i == 0)
			pJog = jog1;
		else
			pJog = jog2;

		if (pJog != nullptr)
			pJog->stopTimers();
	}
	for (i = 0; i < inimigos.numInim(); i++)
	{
		pIni = inimigos.inimPosi(i);
		pIni->stopTimers();
	}

	for (i = 0; i < obstaculos.numObst(); i++)
	{
		pObs = obstaculos.obstPosi(i);
		pObs->stopTimers();
	}

}


void Mapa::resumeTimers()
{
	int i;
	Inimigo* pIni;
	Obstaculo* pObs;
	Jogador* pJog;
	for (i = 0; i < 2; i++)
	{
		if (i == 0)
			pJog = jog1;
		else
			pJog = jog2;

		if (pJog != nullptr)
			pJog->resumeTimers();
	}
	for (i = 0; i < inimigos.numInim(); i++)
	{
		pIni = inimigos.inimPosi(i);
		pIni->resumeTimers();
	}

	for (i = 0; i < obstaculos.numObst(); i++)
	{
		pObs = obstaculos.obstPosi(i);
		pObs->resumeTimers();
	}
}

void Mapa::resetTimers()
{
	int i;
	Inimigo* pIni;
	Obstaculo* pObs;
	Jogador* pJog;
	for (i = 0; i < 2; i++)
	{
		if (i == 0)
			pJog = jog1;
		else
			pJog = jog2;

		if (pJog != nullptr)
			pJog->resetaTimers();
	}
	for (i = 0; i < inimigos.numInim(); i++)
	{
		pIni = inimigos.inimPosi(i);
		pIni->resetaTimers();
	}

	for (i = 0; i < obstaculos.numObst(); i++)
	{
		pObs = obstaculos.obstPosi(i);
		pObs->resetaTimer();
	}
}


void Mapa::setFundo(ALLEGRO_BITMAP* const pFundo)
{
	if (pFundo != nullptr)
	{
		fundo = pFundo;
	}
}

void Mapa::desenhaFundo()
{
	if (fundo != nullptr)
	{
		int posMapa = posRelX / RATE_MF;
		int larg_fundo = al_get_bitmap_width(fundo);
		posMapa %= larg_fundo;
		int posDirFundo = posMapa + LARG;
		if (posDirFundo <= larg_fundo)
			al_draw_bitmap_region(fundo, posMapa, 0, LARG, ALT, 0, 0, 0);
		else
		{
			al_draw_bitmap_region(fundo, posMapa, 0, LARG - (larg_fundo - posDirFundo), ALT, 0, 0, 0);
			al_draw_bitmap_region(fundo, 0, 0, posDirFundo - larg_fundo, ALT, larg_fundo - posMapa, 0, 0);
		}
	}
}


//	garante que os jogadores e os inimigos estejam nos limites da fase
void Mapa::validaPosPers()
{
	if (jog1 != nullptr)
	{
		if (jog1->getX() < 0)
		{
			jog1->setX(0);
			jog1->setVelX(0);
		}
		else if (jog1->getX() + jog1->getLimX() > limX)
		{
			jog1->setX(limX - jog1->getLimX());
			jog1->setVelX(0);
		}
	}
	if (jog2 != nullptr)
	{
		if (jog2->getX() < 0)
		{
			jog2->setX(0);
			jog2->setVelX(0);
		}
		else if (jog2->getX() + jog2->getLimX() > limX)
		{
			jog2->setX(limX - jog2->getLimX());
			jog2->setVelX(0);
		}
	}
	Inimigo* pIni;
	for (int i = 0; i < inimigos.numInim(); i++)
	{
		pIni = inimigos.inimPosi(i);
		if (pIni->getX() < 0)
		{
			pIni->setX(0);
			pIni->setVelX(0);
		}
		else if (pIni->getX() + pIni->getLimX() > limX)
		{
			pIni->setX(limX - pIni->getLimX());
			pIni->setVelX(0);
		}
	}
}


const bool Mapa::estaNaTela(Entidade* const pEnt)
{
	if (pEnt->getX() + pEnt->getLimX() < posRelX || pEnt->getX() > posRelX + LARG
		|| pEnt->getY() - pEnt->getLimY() > (ALT - posRelY) || pEnt->getY() < (-posRelY))
		return false;
	return true;
}


const bool Mapa::haInimigos()
{
	if (inimigos.numInim() > 0)
		return true;
	return false;
}
