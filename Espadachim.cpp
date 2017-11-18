#include "Espadachim.h"



Espadachim::Espadachim()
{
	posX = 0;
	posY = 0;
	limX = LIM_X_ESP;
	limY = LIM_Y_ESP;
	velX = 0;
	velY = 0;
	fisica = true;
	ativo = false;
	velMaxX = VEL_MAX_X_PERS;
	velMaxY = VEL_PULO;
	ID = ESPADACHIM;

	vida = VIDA_MAX_ESP;
	arma = nullptr;
	dir = true;
	podeAtacar = false;
	atacando = false;
	invuneravel = false;
	timer_ataque = nullptr;
	timer_atacando = nullptr;
	timer_invuneravel = nullptr;

	alvo = nullptr;
}


Espadachim::~Espadachim()
{
}


void Espadachim::builderEspadachim(const int ax, const int ay, const bool aAtivo, Jogador* const pAlvo)
{
	posX = ax;
	posY = ay;
	velX = 0;
	velY = 0;
	ativo = aAtivo;

	vida = VIDA_MAX_ESP;
	podeAtacar = false;
	atacando = false;
	invuneravel = false;
	if (arma == nullptr)
	{
		Arma* pArma = constroiArma();
		if (pArma != nullptr)
			arma = pArma;
	}
	if (pAlvo != nullptr)
	{
		alvo = pAlvo;
	}
}


void Espadachim::mover()
{
	//	valor da distância para parar definido pela arma empunhada
	if (alvo != nullptr)
	{
		if ((posY - limY - alvo->getY()) <= DIFF_PIXELS_SEGUIR_Y || (posY - (alvo->getY() - alvo->getLimY())) <= -DIFF_PIXELS_SEGUIR_Y)
		{
			if (posX - (alvo->getX() + alvo->getLimX()) > arma->getLimX() - 1)
			{
				if (velX > -velMaxX)
					velX -= (float)ACEL_X_PERS;
				if(velX < -velMaxX)
					velX = -velMaxX;
			}
			else if (alvo->getX() - (posX + limX) > arma->getLimX() - 1)
			{
				if (velX < velMaxX)
					velX += (float)ACEL_X_PERS;
				if(velX > velMaxX)
					velX = velMaxX;
			}
			else
				parar();
		}
		else 
			parar();
	}
	else
		parar();
}


void Espadachim::atacar()
{
	atacando = true;
	podeAtacar = false;
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
	if (!atacando && alvo != nullptr)
	{
		if (alvo->getX() > posX)
			dir = true;
		else
			dir = false;
	}
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


void Espadachim::reset(const int ax, const int ay, const bool aAtivo)
{
	posX = ax;
	posY = ay;
	velX = 0;
	velY = 0;
	ativo = aAtivo;

	vida = VIDA_MAX_ESP;
	podeAtacar = true;
	atacando = false;
	invuneravel = false;
}

void Espadachim::atualizaAtaque()
{
	if (al_get_timer_count(timer_ataque) >= 1 && !podeAtacar && !atacando)
	{
		al_stop_timer(timer_ataque);
		if ((arma->getY() - arma->getLimY()) < alvo->getY() && arma->getY() > (alvo->getY() - alvo->getLimY()))
		{
			if (posX - (alvo->getX() + alvo->getLimX()) >= 0 && posX - (alvo->getX() + alvo->getLimX()) <= arma->getLimX())
				podeAtacar = true;
			else if (alvo->getX() - (posX + limX) >= 0 && alvo->getX() - (posX + limX) <= arma->getLimX())
				podeAtacar = true;
		}
	}
}