#include "Corda.h"



Corda::Corda(const bool aEscalavel):Plataforma(false, CORDA)
{
	escalavel = aEscalavel;
}


Corda::~Corda()
{
}


void Corda::setEscalavel(const bool aEscalav)
{
	escalavel = aEscalav;
}


const bool Corda::getEscalavel()
{
	return escalavel;
}

void Corda::buildCorda(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const bool aEscalavel)
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