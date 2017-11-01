#include "Personagem.h"



Personagem::Personagem()
{
	vida = 0;
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
			velX -= (float)ACEL10_X_PERS / 10;
		}
		else
			velX += (float)ACEL10_X_PERS / 10;
	}
}