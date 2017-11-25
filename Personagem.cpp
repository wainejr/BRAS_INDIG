#include "Personagem.h"



Personagem::Personagem():Entidade(0, 0, 0, VEL_SUBIDA, -1, false)
{
	vida = 0;
	arma = nullptr;
	dir = true;
	podeAtacar = true;
	atacando = false;
	invuneravel = false;
	timer_ataque = nullptr;
	timer_atacando = nullptr;
	timer_invuneravel = nullptr;
	criouTimers = false;
}

Personagem::Personagem(const int aVida, const float aVelX, const float aVelY, const float aVelMaxX, const float aVelMaxY,
	const int aID, const bool aFisica, const float aPosX, const float aPosY, const int aLimX, 
	const int aLimY, const bool aAtivo):Entidade(aVelX, aVelY,  aVelMaxX, aVelMaxY,
		 aID, aFisica, aPosX, aPosY,  aLimX, aLimY, aAtivo)
{
	vida = aVida;
	arma = nullptr;
	dir = true;
	podeAtacar = true;
	atacando = false;
	invuneravel = false;
	timer_ataque = nullptr;
	timer_atacando = nullptr;
	timer_invuneravel = nullptr;
	criouTimers = false;
}


Personagem::~Personagem()
{
	delete(arma);

	al_destroy_timer(timer_ataque);
	al_destroy_timer(timer_atacando);
	al_destroy_timer(timer_invuneravel);
	
}

// recebe como parâmetro a aceleração de vY
void Personagem::cair(const float acAt)
{
	if (velY > -velMaxY)
		velY -= acAt;
	if (velY < -velMaxY)
		velY = -velMaxY;
}

void Personagem::atualizaArma()
{
	if (dir)
	{
		arma->setX(posX + limX);
	}
	else
		arma->setX(posX - arma->getLimX());

	arma->setY(posY-limY/2+arma->getLimY()/2);
}


void Personagem::setDir(bool const aDir)
{
	dir = aDir;
}


const bool Personagem::getDir()
{
	return dir;
}


Arma* const Personagem::getArma()
{
	return arma;
}


void Personagem::setArma(Arma* const pArma)
{
	if (pArma != nullptr)
	{
		arma = pArma;
		pArma->setDonoArma(this);
	}
}


const int Personagem::getVida()
{
	return vida;
}


void Personagem::setVida(const int aVida)
{
	vida = aVida;
}


void Personagem::parar()
{
	if (velX != 0) 
	{
		if (velX < ACEL_X_INI && velX > 0 || velX > -ACEL_X_INI && velX < 0)
		{
			velX = 0;
		}
		else if (velX > 0)
		{
			velX -= (float)ACEL_X_INI;
		}
		else
			velX += (float)ACEL_X_INI;
	}
}


void Personagem::setAtacando(const bool aAt)
{
	atacando = aAt;
}


const bool Personagem::getAtacando()
{
	return atacando;
}


void Personagem::initTimer()
{
	al_start_timer(timer_ataque);

	al_start_timer(timer_atacando);
	al_stop_timer(timer_atacando);
	//	o timer só será resumido quando a função "atacar" for acionada
	
	al_start_timer(timer_invuneravel);
	al_stop_timer(timer_invuneravel);
	//	o timer só será resumido quando a função "tomaDano" for acionada
}


void Personagem::destruirTimer()
{
	al_destroy_timer(timer_ataque);
	al_destroy_timer(timer_atacando);
	al_destroy_timer(timer_invuneravel);
}


const bool Personagem::persPodeAtacar()
{
	return podeAtacar;
}

//	para KB = 1, o personagem recebe um knock back para direita
//	para KB = -1, o personagem recebe um knock back para esquerda
//	para KB = 0, o personagem não recebe knock back
void Personagem::tomaDano(const int aDano, const int KB)
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

			//reseta o contador do timer
			al_set_timer_count(timer_invuneravel, 0);
			al_resume_timer(timer_invuneravel);
		}
	}
}

const bool Personagem::getInvuneravel()
{
	return invuneravel;
}


void Personagem::setInvuneravel(const bool aInv)
{
	invuneravel = aInv;
}

void Personagem::atualizaInvuneravel()
{
	if (invuneravel)
	{
		if (al_get_timer_count(timer_invuneravel) >= 1)
		{
			invuneravel = false;
			al_stop_timer(timer_invuneravel);
		}
	}
}


void Personagem::atualizaAtacando()
{
	if (atacando)
	{
		if (al_get_timer_count(timer_atacando) >= 1)
		{
			atacando = false;
			al_stop_timer(timer_atacando);
		}
	}
}


void Personagem::atualizaAtaque()
{
	if (al_get_timer_count(timer_ataque) >= 1)
	{
		al_stop_timer(timer_ataque);
	}
}


Arma* const Personagem::constroiArma()
{
	if (ID == TECA)
	{
		Espada* pEspada = new Espada;
		pEspada->buildEspada(posX + limX, posY - limY / 2, LIM_X_ESPADA_JOG, LIM_Y_ESPADA_JOG, true, DANO_ESPADA_JOG, static_cast<Personagem*>(this));
		return pEspada;
	}
	else if (ID == RAONI)
	{
		Arco* pArco = new Arco;
		pArco->buildArco(posX + limX, posY - limY / 2, true, static_cast<Personagem*>(this));
		return pArco;
	}
	else if (ID == MOSQUETEIRO)
	{
		Mosquete* pMosquete = new Mosquete;
		pMosquete->buildMosquete(posX + limX, posY - limY / 2, true, static_cast<Personagem*>(this));
		return pMosquete;
		
	}
	else if (ID == ESPADACHIM)
	{
		Espada* pEspada = new Espada;
		pEspada->buildEspada(posX + limX, posY - limY / 2, LIM_X_ESPADA_ESP, LIM_Y_ESPADA_ESP, true, DANO_ESPADA_ESP, static_cast<Personagem*>(this));
		return pEspada;
	}
	else if (ID == CAVALEIRO)
	{
		Lanca* pLanca = new Lanca;
		pLanca->buildLanca(posX + limX, posY - limY / 2, true, static_cast<Personagem*>(this));
		return pLanca;
	}
	return nullptr;
}


void Personagem::resetaTimers()
{
	al_set_timer_count(timer_atacando, 0);
	al_stop_timer(timer_atacando);
	al_set_timer_count(timer_ataque, 0);
	al_stop_timer(timer_ataque);
	al_set_timer_count(timer_invuneravel, 0);
	al_stop_timer(timer_invuneravel);
}


void Personagem::stopTimers()
{
	al_stop_timer(timer_atacando);
	al_stop_timer(timer_ataque);
	al_stop_timer(timer_invuneravel);
	if (listaAnim != nullptr)
		listaAnim->stopTimers();
}


void Personagem::resumeTimers()
{
	if(atacando)
		al_resume_timer(timer_atacando);
	al_resume_timer(timer_ataque);
	if(invuneravel)
		al_resume_timer(timer_invuneravel);
	if (listaAnim != nullptr)
		listaAnim->resumeTimers();
}
