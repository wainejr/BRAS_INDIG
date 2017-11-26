#include "Jogador.h"

Jogador::Jogador():Personagem(VIDA_MAX_JOG, 0, 0, VEL_MAX_X_JOG, VEL_PULO, -1, true, 0, 0, LIM_X_JOG, LIM_Y_JOG, false)
{
	chances = 3; //	3 chances é o padrão inicial
	subindo = false;
	subiu = false;
	imovel = false;
	timer_imovel = nullptr;
}

Jogador::Jogador(const int aChances, const int aID, const int aVida, const float aVelX,
	const float aVelY, const float aVelMaxX, const float aVelMaxY, const bool aFisica, const float aPosX,
	const float aPosY, const int aLimX, const int aLimY, const bool aAtivo):
	Personagem(aVida, aVelX, aVelY, aVelMaxX, aVelMaxY, aID, aFisica, aPosX, aPosY, aLimX, aLimY, aAtivo)
{
	chances = aChances;
	ID = aID;

	arma = nullptr;
	dir = true;
	podeAtacar = false;
	atacando = false;
	invuneravel = false;
	timer_ataque = nullptr;
	timer_atacando = nullptr;
	timer_invuneravel = nullptr;
	criouTimers = false;

	subindo = false;
	subiu = false;
	imovel = false;
	timer_imovel = nullptr;
}


Jogador::~Jogador()
{
	al_destroy_timer(timer_imovel);
}


void Jogador::buildJogador(const int ax, const int ay, const bool aAtivo, const int aID, const int aChances)
{
	posX = ax;
	posY = ay;
	velX = 0;
	velY = 0;
	ativo = aAtivo;
	if (aID != -1)
		ID = aID;
	if (listaAnim == nullptr)
	{
		listaAnim = gerListaAnim.listaAnimEnt(ID);
	}

	vida = VIDA_MAX_JOG;
	podeAtacar = false;
	atacando = false;
	invuneravel = false;
	if (arma == nullptr)
	{
		Arma* pArma = constroiArma();
		if (pArma != nullptr)
			arma = pArma;
	}
	if (!criouTimers)
	{
		createTimers();
	}
	
	if (aChances != -1)
		chances = aChances;
	subindo = false;
	subiu = false;
	imovel = false;
}


void Jogador::atacar()
{
	if (arma->getID() == ESPADA)
	{
		atacando = true;
		podeAtacar = false;
		al_resume_timer(timer_atacando);
		al_resume_timer(timer_ataque);
		al_set_timer_count(timer_atacando, 0);
		al_set_timer_count(timer_ataque, 0);
	}
}


void Jogador::moverDir()
{
	if (!imovel)
	{
		if (velX < velMaxX)
			velX += (float)ACEL_X_JOG;
		if (velX > velMaxX)
			velX = velMaxX;
		if (!atacando)
			dir = true;
	}
}


void Jogador::moverEsq()
{
	if (!imovel)
	{
		if (velX > -velMaxX)
			velX -= (float)ACEL_X_JOG;
		if (velX < -velMaxX)
			velX = -velMaxX;
		if (!atacando)
			dir = false;
	}
}


void Jogador::pular()
{
	if (!imovel)
		velY = VEL_PULO;
}


// para cordas
void Jogador::subir()
{
	if (!imovel)
	{
		velY = VEL_SUBIDA;
		subiu = true;
	}
}


void Jogador::atualizar()
{
	if (imovel)
		parar();
	posY -= velY;
	posX += velX;
	if (subiu)
		subindo = true;
	else
		subindo = false;

	subiu = false;
	atualizaAtaque();
	atualizaInvuneravel();
	atualizaAtacando();
	atualizaParado();
	atualizaArma();
}


void Jogador::draw(const int aPosFaseX, const int aPosFaseY)
{
	if (!invuneravel)
		al_draw_filled_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(0, 255, 0));
	else
		al_draw_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(0, 255, 0), 2);
	if (atacando)
		al_draw_filled_rectangle(arma->getX() - aPosFaseX, arma->getY() - aPosFaseY, arma->getX() + arma->getLimX()
			- aPosFaseX, arma->getY() - arma->getLimY() - aPosFaseY, al_map_rgb(255, 150, 0));

	if (ID == RAONI)
	{
		if (velX > 0.5)
			listaAnim->drawAnimacao(0, posX - aPosFaseX + limX / 2, posY - aPosFaseY);
		else if (velX < -0.5)
			listaAnim->drawAnimacaoInver(0, posX - aPosFaseX + limX / 2, posY - aPosFaseY);
	}
}


const int Jogador::getChances()
{
	return chances;
}


void Jogador::setChances(const int aChances)
{
	chances = aChances;
}


void Jogador::createTimers()
{
	timer_ataque = al_create_timer(PER_ATAQ_JOG);
	timer_invuneravel = al_create_timer(TEMP_INVUN_JOG);
	timer_atacando = al_create_timer(TEMP_ATAQ_JOG);
	timer_imovel = al_create_timer(TEMP_IMOVEL);
	criouTimers = true;
}


const bool Jogador::getSubindo()
{
	return subindo;
}


void Jogador::setSubindo(const bool aSubindo)
{
	subindo = aSubindo;
}


void Jogador::descer()
{
	if (!imovel)
	{
		velY = -VEL_SUBIDA;
	}
}


//	para KB = 1, o jogador recebe um knock back para direita
//	para KB = -1, o jogador recebe um knock back para esquerda
//	para KB = 0, o jogador não recebe knock back
//	para KB = 2, o jogador fica parado por um tempo
//	para KB = 3, o jogador toma o efeito de quando é capturado por uma rede
void Jogador::tomaDano(const int aDano, const int KB)
{
	if (!invuneravel && aDano > 0)
	{
		vida -= aDano;
		if (vida >= 0)
		{
			invuneravel = true;
			if (KB == 1)
			{
				velX = VEL_X_KB;
				velY = VEL_Y_KB;
			}
			else if (KB == -1)
			{
				velX = -VEL_X_KB;
				velY = VEL_Y_KB;
			}
			else if (KB == 2)
			{
				if (velY > 0)
					velY = 0;
				velX = 0;
				imovel = true;
				al_set_timer_count(timer_imovel, 0);
				al_resume_timer(timer_imovel);
			}
			else if (KB == 3)
			{
				if (velY > 0)
					velY = 0;
				velX = 0;
				imovel = true;
				//	o jogador fica 3x mais tempo imovel ao ser capturado por uma rede
				al_set_timer_count(timer_imovel, -2);
				al_resume_timer(timer_imovel);
			}

			//reseta o contador do timer
			al_set_timer_count(timer_invuneravel, 0);
			al_resume_timer(timer_invuneravel);
		}
	}
}


void Jogador::atualizaParado()
{
	if (imovel)
	{
		if (al_get_timer_count(timer_imovel) >= 1)
		{
			al_stop_timer(timer_imovel);
			imovel = false;
		}
	}
}


void Jogador::destruirTimer()
{
	al_destroy_timer(timer_ataque);
	al_destroy_timer(timer_atacando);
	al_destroy_timer(timer_invuneravel);
	al_destroy_timer(timer_imovel);
}


void Jogador::initTimer()
{
	al_start_timer(timer_ataque);
	//	o timer só será resumido quando a função "atacar" for acionada 

	al_start_timer(timer_imovel);
	al_stop_timer(timer_imovel);
	//	o timer só será resumido quando o jogador ficar em estado imovel

	al_start_timer(timer_atacando);
	al_stop_timer(timer_atacando);
	//	o timer só será resumido quando a função "atacar" for acionada

	al_start_timer(timer_invuneravel);
	al_stop_timer(timer_invuneravel);
	al_set_timer_count(timer_invuneravel, 0);
	//	o timer só será resumido quando a função "tomaDano" for acionada
}


Projetil* const Jogador::atirar()
{
	if (arma->getID() == ARCO)
	{
		Projetil* pProj = new Projetil();
		pProj->setID(PROJETIL_ARCO);
		pProj->setLimX(LIM_X_PROJ_ARCO);
		if (dir)
			pProj->buildProjetil(arma->getX(), arma->getY(), VEL_MAX_PROJ, true, PROJETIL_ARCO, arma);
		else
			pProj->buildProjetil(arma->getX()-pProj->getLimX(), arma->getY(), -VEL_MAX_PROJ, true, PROJETIL_ARCO, arma);

		pProj->setArmaProj(arma);
		atacando = true;
		podeAtacar = false;
		al_resume_timer(timer_atacando);
		al_resume_timer(timer_ataque);
		al_set_timer_count(timer_atacando, 0);
		al_set_timer_count(timer_ataque, -1);	//jogador demora o dobro de tempo para atacar com o arco
		return pProj;
	}
	return nullptr;
}


void Jogador::reset(const int ax, const int ay, const bool aAtivo)
{
	posX = ax;
	posY = ay;
	velX = 0;
	velY = 0;
	ativo = aAtivo;

	vida = VIDA_MAX_JOG;
	podeAtacar = false;
	atacando = false;
	invuneravel = false;

	subindo = false;
	subiu = false;
	imovel = false;
}


void Jogador::resetChances()
{
	chances = 3;
}


void Jogador::atualizaAtaque()
{
	if (!podeAtacar && !atacando && !imovel && al_get_timer_count(timer_ataque) >= 1)
	{
		al_stop_timer(timer_ataque);
		podeAtacar = true;
	}
	else
		al_resume_timer(timer_ataque);
}

void Jogador::resetaTimers()
{
	al_set_timer_count(timer_atacando, 0);
	al_stop_timer(timer_atacando);
	al_set_timer_count(timer_ataque, 0);
	al_stop_timer(timer_ataque);
	al_set_timer_count(timer_imovel, 0);
	al_stop_timer(timer_imovel);
	al_set_timer_count(timer_invuneravel, 0);
	al_stop_timer(timer_invuneravel);
}


void Jogador::stopTimers()
{
	if (atacando)
		al_stop_timer(timer_atacando);
	al_stop_timer(timer_ataque);
	if (imovel)
		al_stop_timer(timer_imovel);
	if (invuneravel)
		al_stop_timer(timer_invuneravel);
	if (listaAnim != nullptr)
		listaAnim->stopTimers();
}


void Jogador::resumeTimers()
{
	if (atacando)
		al_resume_timer(timer_atacando);
	al_resume_timer(timer_ataque);
	if (imovel)
		al_resume_timer(timer_imovel);
	if (invuneravel)
		al_resume_timer(timer_invuneravel);
	if (listaAnim != nullptr)
		listaAnim->resumeTimers();
}
