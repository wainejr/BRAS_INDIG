#include "Mosqueteiro.h"



Mosqueteiro::Mosqueteiro():Inimigo(VIDA_MAX_ESP, 0, 0, VEL_MAX_X_PERS, VEL_PULO, MOSQUETEIRO, true, 0, 0, LIM_X_MOSQ, LIM_Y_MOSQ, false)
{
}


Mosqueteiro::~Mosqueteiro()
{
	
}


void Mosqueteiro::buildMosqueteiro(const int ax, const int ay, const bool aAtivo, Jogador* const pAlvo)
{
	posX = ax;
	posY = ay;
	velX = 0;
	velY = 0;
	ativo = aAtivo;

	vida = VIDA_MAX_MOSQ;
	podeAtacar = true;
	atacando = false;
	invuneravel = false;
	if (arma == nullptr)
	{
		Arma* pArma = constroiArma();
		if (pArma != nullptr)
			arma = pArma;
	}
	if (!criouTimers)
	{
		createTimers();
	}

	if (pAlvo != nullptr)
	{
		alvo = pAlvo;
	}
}


void Mosqueteiro::mover()
{
	parar();
}


void Mosqueteiro::atualizar()
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
	if (!atacando)
		atualizaArma();
}


void Mosqueteiro::draw(const int aPosFaseX, const int aPosFaseY)
{
	if(!invuneravel)
		al_draw_filled_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(255, 0, 255));
	else
		al_draw_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(255, 0, 255), 2);
}

Projetil* const Mosqueteiro::atirar()
{
	//	OU ESPECIFICAR O TAMANHO DOS PROJETEIS
	Projetil* pProj = new Projetil();
	pProj->setID(PROJETIL_MOSQ);
	pProj->setLimX(LIM_X_PROJ_MOSQ);
	if(dir) 
		pProj->buildProjetil(arma->getX(), arma->getY(), VEL_MAX_PROJ, true, PROJETIL_MOSQ, arma);
	else
		pProj->buildProjetil(arma->getX()-pProj->getLimX(), arma->getY(), -VEL_MAX_PROJ, true, PROJETIL_MOSQ, arma);
	pProj->setArmaProj(arma);
	atacando = true;
	podeAtacar = false;
	al_resume_timer(timer_ataque);
	al_resume_timer(timer_atacando);
	al_set_timer_count(timer_ataque, 0);
	al_set_timer_count(timer_atacando, 0);
	return pProj;
}

void Mosqueteiro::createTimers()
{
	timer_ataque = al_create_timer(PER_ATAQ_MOSQ);
	timer_atacando = al_create_timer(TEMP_ATAQ_MOSQ);
	timer_invuneravel = al_create_timer(TEMP_INVUN_MOSQ);
	criouTimers = true;
}


void Mosqueteiro::reset(const int ax, const int ay, const bool aAtivo)
{
	posX = ax;
	posY = ay;
	velX = 0;
	velY = 0;
	ativo = aAtivo;

	vida = VIDA_MAX_MOSQ;
	podeAtacar = true;
	atacando = false;
	invuneravel = false;
}


void Mosqueteiro::atualizaAtaque()
{
	if (al_get_timer_count(timer_ataque) >= 1 && !podeAtacar && !atacando)
	{
		al_stop_timer(timer_ataque);
		if (velY == 0 && alvo->getY() > posY - limY && alvo->getY() - alvo->getLimY() < posY)
		{
			podeAtacar = true;
		}
	}
}