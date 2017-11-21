#include "Corda.h"



Corda::Corda()
{
	posX = 0;
	posY = 0;
	limX = 0;
	limY = 0;
	velX = 0;
	velY = 0;
	fisica = false;
	ativo = false;
	velMaxX = 0;
	velMaxY = 0;
	ID = CORDA;

	colisaoBaixo = false;

	escalavel = false;
}


Corda::~Corda()
{
	//delete(listaAnim);
}


void Corda::setEscalavel(const bool aEscalav)
{
	escalavel = aEscalav;
}


const bool Corda::getEscalavel()
{
	return escalavel;
}

void Corda::builderCorda(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const bool aEscalavel)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimy;
	ativo = aAtivo;

	escalavel = aEscalavel;

	if (listaAnim == nullptr)
		listaAnim = gerListaAnim.listaAnimEnt(ID);
}

void Corda::draw(const int posRelX, const int posRelY)
{
	if (escalavel)
		listaAnim->drawDeAte_Y(0, posX - posRelX + limX/2, posY - posRelY - limY, posY - posRelY);
	else
		listaAnim->drawAnimacao(1, posX - posRelX + limX/2, posY - posRelY);
}

void Corda::atualizar()
{

}