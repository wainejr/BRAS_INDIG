#include "Entidade.h"


Entidade::Entidade():ProtoEntidade()
{
	velX = 0;
	velY = 0;
	velMaxX = 0;
	velMaxY = 0;
	ID = -1;
	fisica = false;
	listaAnim = nullptr;
}

Entidade::Entidade(const int aVelX, const int aVelY, const int aVelMaxX, const int aVelMaxY,
	const int aID, const bool aFisica, const float aPosX, const float aPosY, 
	const int aLimX, const int aLimY, const bool aAtivo):ProtoEntidade(aPosX, aPosY, aLimX, aLimY, aAtivo)
{
	velX = aVelX;
	velY = aVelY;
	velMaxX = aVelMaxX;
	velMaxY = aVelMaxY;
	ID = aID;
	fisica = aFisica;
	listaAnim = nullptr;
}


Entidade::~Entidade()
{
	delete(listaAnim);
}


const bool Entidade::getFisica()
{
	return fisica;
}


void Entidade::setFisica(const bool aFisica)
{
	fisica = aFisica;
}


const int Entidade::getID()
{
	return ID;
}


const float Entidade::getVelMaxX()
{
	return velMaxX;
}


void Entidade::setVelMaxX(const float aVelMaxX)
{
	velMaxY = aVelMaxX;
}


const float Entidade::getVelMaxY()
{
	return velMaxY;
}


void Entidade::setVelMaxY(const float aVelMaxY)
{
	velMaxY = aVelMaxY;
}

void Entidade::setVelX(const float aVelX)
{
	velX = aVelX;
}


const int Entidade::getVelX()
{
	return velX;
}


void Entidade::setVelY(const float aVelY)
{
	velY = aVelY;
}


const int Entidade::getVelY()
{
	return velY;
}


void Entidade::setID(const int aID)
{
	ID = aID;
}



void Entidade::resumeTimerAnim()
{
	if(listaAnim != nullptr)
		listaAnim->resumeTimers();
}


void Entidade::stopTimerAnim()
{
	if(listaAnim != nullptr)
		listaAnim->stopTimers();
}
