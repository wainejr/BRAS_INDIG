#include "ProtoEntidade.h"



ProtoEntidade::ProtoEntidade()
{
	posX = 0;
	posY = 0;
	limX = 0;
	limY = 0;
	ativo = false;
}

ProtoEntidade::ProtoEntidade(const float aPosX, const float aPosY, const int aLimX, const int aLimY, const bool aAtivo)
{
	posX = aPosX;
	posY = aPosY;
	limX = aLimX;
	limY = aLimY;
	ativo = aAtivo;
}


ProtoEntidade::~ProtoEntidade()
{
}



void ProtoEntidade::setX(const float px)
{
	posX = px;
}


const float ProtoEntidade::getX()
{
	return posX;
}


void ProtoEntidade::setY(const float py)
{
	posY = py;
}


const float ProtoEntidade::getY()
{
	return posY;
}


void ProtoEntidade::setLimX(const int aLimX)
{
	limX = aLimX;
}


const int ProtoEntidade::getLimX()
{
	return limX;
}


void ProtoEntidade::setLimY(const int aLimY)
{
	limY = aLimY;
}


const int ProtoEntidade::getLimY()
{
	return limY;
}


const bool ProtoEntidade::getAtivo()
{
	return ativo;
}


void ProtoEntidade::setAtivo(const bool aAtivo)
{
	ativo = aAtivo;
}
