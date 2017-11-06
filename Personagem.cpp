#include "Personagem.h"



Personagem::Personagem()
{
	fisica = true;
	vida = 10;
	dir = true;
	atacando = false;
}


Personagem::~Personagem()
{
}


void Personagem::atacar()
{
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
	arma = pArma;
	pArma->setDonoArma(this);
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
	if (velX != 0) {
		if (!(int)velX)
		{
			velX = 0;
		}
		else if (velX > 0)
		{
			velX -= (float)ACEL_X_PERS;
		}
		else
			velX += (float)ACEL_X_PERS;
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
	al_start_timer(timer_invuneravel);
	//	o timer só será resumido quando a função "atacar" for acionada
	al_stop_timer(timer_atacando);
	//	o timer só será resumido quando a função "tomaDano" for acionada
	al_stop_timer(timer_invuneravel);

}


void Personagem::destruirTimer()
{
	al_destroy_timer(timer_ataque);
	al_destroy_timer(timer_atacando);
	al_destroy_timer(timer_invuneravel);
}


const bool Personagem::persPodeAtacar()
{
	if (al_get_timer_count(timer_ataque) >= 1 && !atacando)
		return true;

	return false;
}

void Personagem::tomaDano(const int aDano)
{
	if (aDano > 0)
	{
		vida -= aDano;
		invuneravel = true;
		//reseta o contador do timer
		al_set_timer_count(timer_invuneravel, 0);
		al_resume_timer(timer_invuneravel);
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
