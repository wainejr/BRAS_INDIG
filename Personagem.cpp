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


void Personagem::atualizar()
{
	atualizaArma();
}


void Personagem::atualizaArma()
{
	if (dir)
	{
		arma->setX(posX + limX);
	}
	else
		arma->setX(posX);

	arma->setY(posY);
}


void Personagem::setDir(bool const aDir)
{
	dir = aDir;
}


const bool Personagem::getDir()
{
	return dir;
}


Arma* Personagem::getArma()
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