#include "Entidade.h"

Entidade::Entidade()
{
	velMaxX = 0.0f;
	velMaxY = 0.0f;
}


Entidade::~Entidade()
{
}


void Entidade::atualizar()
{

}


void Entidade::setX(const float px)
{
	posX = px;
}


const float Entidade::getX()
{
	return posX;
}


void Entidade::setY(const float py)
{
	posY = py;
}


const float Entidade::getY()
{
	return posY;
}


void Entidade::setLimX(const int aLimX)
{
	limX = aLimX;
}


const int Entidade::getLimX()
{
	return limX;
}


void Entidade::setLimY(const int aLimY)
{
	limY = aLimY;
}


const int Entidade::getLimY()
{
	return limY;
}


const bool Entidade::getAtivo()
{
	return ativo;
}


void Entidade::setAtivo(const bool aAtivo)
{
	ativo = aAtivo;
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