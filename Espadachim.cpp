#include "Espadachim.h"



Espadachim::Espadachim()
{
	ID = ESPADACHIM;
	fisica = true;
}


Espadachim::~Espadachim()
{
}


void Espadachim::builderEspadachim(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const int aVida, Arma* const pArma)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimy;
	ativo = aAtivo;
	vida = aVida;
	arma = pArma;
	
}


void Espadachim::mover()
{
	//VALOR DE DISTÂNCIA PARA PARAR DECIDIDO EMPIRICAMENTE
	if ((posY) > (alvo->getY()-alvo->getLimY()-DIFF_PIXELS_SEGUIR_Y) && (posY-limY) < (alvo->getY()+DIFF_PIXELS_SEGUIR_Y))
	{
		if (posX - DIFF_PIXELS_PARAR_X > (alvo->getX() + alvo->getLimX()))
		{
			if (velX > -velMaxX)
				velX-= (float)ACEL_X_PERS;
			else
				velX = -velMaxX;
		}
		else if ((posX + limX) < (alvo->getX() - DIFF_PIXELS_PARAR_X))
		{
			if (velX < velMaxX)
				velX+= (float) ACEL_X_PERS;
			else
				velX = velMaxX;
		}
		else
			parar();
	}
	else
		parar();
}


void Espadachim::atacar()
{
	if (persPodeAtacar())
	{

	}
}


void Espadachim::atualizar()
{
	mover();
	posX += velX;
	posY -= velY;
	atualizaArma();
}



void Espadachim::draw(const int aPosFaseX, const int aPosFaseY)
{
	al_draw_filled_rectangle(posX-aPosFaseX, posY-aPosFaseY, posX + limX-aPosFaseX, posY - limY-aPosFaseY, al_map_rgb(255, 0, 0));
}

void Espadachim::createTimers()
{
	timer_ataque = al_create_timer(PER_ATAQ_ESP);
}