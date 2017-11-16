#include "Inimigo.h"

Inimigo::Inimigo()
{
	velMaxX = VEL_MAX_X_PERS;
	velMaxY = VEL_PULO;
	fisica = true;
	alvo = nullptr;
}


Inimigo::~Inimigo()
{
}


void Inimigo::mover()
{
}


void Inimigo::atacar()
{
}


void Inimigo::atualizar()
{
	mover();
	posX += velX;
	posY -= velY;
	atualizaArma();
}


void Inimigo::setAlvo(Jogador* const pJog)
{
	if(pJog != nullptr)
		alvo = pJog;
}


Jogador* const Inimigo::getAlvo()
{
	return alvo;
}
