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
	//o cavalo passa do alvo, só começando a parar um tempo depois
	if ((posY) > (alvo->getY() - alvo->getLimY() - DIFF_PIXELS_SEGUIR_Y) && (posY - limY) < (alvo->getY() + DIFF_PIXELS_SEGUIR_Y))
	{
		if ((alvo->getX() + alvo->getLimX() - DIFF_PIXELS_CAV_PARAR) < posX && velX <= 0 && velX > -VEL_MAX_X_CAV)
			velX -= (float)ACEL_X_CAV;
		else if (velX < -VEL_MAX_X_CAV)
			velX = -VEL_MAX_X_CAV;
		else if ((alvo->getX() + DIFF_PIXELS_CAV_PARAR) > (posX + limX) && velX >= 0 && velX < VEL_MAX_X_CAV)
			velX += (float)ACEL_X_CAV;
		else if (velX > VEL_MAX_X_CAV)
			velX = VEL_MAX_X_CAV;
		else
			parar();
	}
	else
		parar();
}


void EspadachimCavaleiro::atacar()
{

}


void EspadachimCavaleiro::atualizar()
{
	mover();
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

void EspadachimCavaleiro::draw(const int aPosFaseX, const int aPosFaseY)
{
	al_draw_filled_rounded_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, -5, -5, al_map_rgb(155, 100, 55));
}