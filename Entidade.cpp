#include "Entidade.h"



Entidade::Entidade()
{
}

Entidade::~Entidade()
{
}


void Entidade::setX(const int px)
{
	posX = px;
}

const int Entidade::getX()
{
	return posX;
}

void Entidade::setY(const int py)
{
	posY = py;
}

const int Entidade::getY()
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
