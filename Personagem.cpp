#include "Personagem.h"



Personagem::Personagem()
{
	vida = 0;
}

Personagem::~Personagem()
{
}

const int Personagem::getVida()
{
	return vida;
}

void Personagem::setVida(const int aVida)
{
	vida = aVida;
}

Arma* Personagem::getArma()
{
	return arma;
}

void Personagem::setArma(Arma* const pArma)
{
	arma = pArma;
}

void Personagem::atacar()
{
}

void Personagem::atualizar()
{
}

