#include "Inimigo.h"

Inimigo::Inimigo():Personagem()
{
	alvo = nullptr;
}


Inimigo::Inimigo(const int aVida, const float aVelX, const float aVelY, const float aVelMaxX, const float aVelMaxY, const int aID,
	const bool aFisica, const float aPosX, const float aPosY, const int aLimX, const int aLimY, const bool aAtivo):
	Personagem (aVida, aVelX, aVelY, aVelMaxX, aVelMaxY, aID, aFisica, aPosX, aPosY, aLimX, aLimY, aAtivo)
{
	alvo = nullptr;
}



Inimigo::~Inimigo()
{
	alvo = nullptr;
}


void Inimigo::mover()
{
}


void Inimigo::atacar()
{
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


Projetil* const Inimigo::atirar()
{
	return nullptr;
}
