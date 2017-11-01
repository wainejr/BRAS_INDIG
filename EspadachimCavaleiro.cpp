#include "EspadachimCavaleiro.h"



EspadachimCavaleiro::EspadachimCavaleiro()
{
}


EspadachimCavaleiro::~EspadachimCavaleiro()
{
}


void EspadachimCavaleiro::builderEspadachimCav()
{
}


void EspadachimCavaleiro::mover()
{
}


void EspadachimCavaleiro::atacar()
{
}


void EspadachimCavaleiro::atualizar()
{
	posX += velX;
	posY -= velY;
	atualizaArma();
}



const bool EspadachimCavaleiro::getCavalo()
{
	return cavalo;
}


void EspadachimCavaleiro::setCavalo(const bool aCavalo)
{
	cavalo = aCavalo;
}