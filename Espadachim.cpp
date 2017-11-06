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
	//	valor da distância para parar definido pela arma empunhada
	if ((posY - limY - alvo->getY()) <= DIFF_PIXELS_SEGUIR_Y || (posY - (alvo->getY() - alvo->getLimY())) <= -DIFF_PIXELS_SEGUIR_Y)
	{
		if (posX - (alvo->getX() + alvo->getLimX()) > arma->getLimX() - 1)
		{
			if (velX > -velMaxX)
				velX -= (float)ACEL_X_PERS;
			else
				velX = -velMaxX;
		}
		else if (alvo->getX() - (posX + limX) > arma->getLimX() - 1)
		{
			if (velX < velMaxX)
				velX += (float)ACEL_X_PERS;
			else
				velX = velMaxX;
		}
		else
			velX = 0;	// para facilitar e o personagem não ficar parado numa distância sem atacar
			//	parar();
	}
	else
		parar();
}


void Espadachim::atacar()
{
	atacando = true;
	al_resume_timer(timer_atacando);
	al_resume_timer(timer_ataque);
	al_set_timer_count(timer_atacando, 0);
	al_set_timer_count(timer_ataque, 0);
}


void Espadachim::atualizar()
{
	mover();
	posX += velX;
	posY -= velY;
	if (alvo->getX() > posX)
		dir = true;
	else
		dir = false;
	atualizaAtaque();
	atualizaInvuneravel();
	atualizaAtacando();
	atualizaArma();
}



void Espadachim::draw(const int aPosFaseX, const int aPosFaseY)
{
	if (!invuneravel)
		al_draw_filled_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(255, 0, 0));
	else
		al_draw_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(255, 0, 0), 2);
	if (atacando)
		al_draw_filled_rectangle(arma->getX() - aPosFaseX, arma->getY() - aPosFaseY, arma->getX() + arma->getLimX() - aPosFaseX, arma->getY() - arma->getLimY() - aPosFaseY, al_map_rgb(255, 150, 0));
}

void Espadachim::createTimers()
{
	timer_ataque = al_create_timer(PER_ATAQ_ESP);
	timer_atacando = al_create_timer(TEMP_ATAQ_JOG);
	timer_invuneravel = al_create_timer(TEMP_INVUN_ESP);
}

const bool Espadachim::persPodeAtacar()
{
	if (al_get_timer_count(timer_ataque) >= 1 && !atacando)
	{
		if (posX - (alvo->getX() + alvo->getLimX()) >= 0 && posX - (alvo->getX() + alvo->getLimX()) <= arma->getLimX())
			return true;
		else if (alvo->getX() - (posX + limX) >= 0 && alvo->getX() - (posX + limX) <= arma->getLimX())
			return true;
	}
	return false;
}