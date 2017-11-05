#include "Personagem.h"



Personagem::Personagem()
{
	fisica = true;
	vida = 10;
	dir = true;
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
		arma->setX(posX);

	arma->setY(posY-limY/2);
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

void Personagem::setAtaque(const bool aAt)
{
	ataque = aAt;
}


const bool Personagem::getAtaque()
{
	return ataque;
}


void Personagem::initTimer()
{
	al_start_timer(timer_ataque);
}


void Personagem::destruirTimer()
{
	al_destroy_timer(timer_ataque);
}


const bool Personagem::persPodeAtacar()
{
	if (al_get_timer_count(timer_ataque) >= 1)
		return true;

	return false;
}


void Personagem::resetTimer()
{
	al_set_timer_count(timer_ataque, 0);
}


void Personagem::tomaDano(const int aDano)
{
}
