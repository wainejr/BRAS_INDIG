#include "EspadachimCavaleiro.h"



EspadachimCavaleiro::EspadachimCavaleiro()
{
	ID = ESP_CAVALEIRO;
	fisica = true;
}


EspadachimCavaleiro::~EspadachimCavaleiro()
{
}


void EspadachimCavaleiro::builderEspadachimCav(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const int aVida, Arma* const pArma)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimy;
	ativo = aAtivo;
	vida = aVida;
	arma = pArma;
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