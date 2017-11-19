#include "Mosqueteiro.h"



Mosqueteiro::Mosqueteiro()
{
	posX = 0;
	posY = 0;
	limX = LIM_X_MOSQ;
	limY = LIM_Y_MOSQ;
	velX = 0;
	velY = 0;
	fisica = true;
	ativo = false;
	velMaxX = VEL_MAX_X_PERS;
	velMaxY = VEL_PULO;
	ID = MOSQUETEIRO;

	vida = VIDA_MAX_MOSQ;
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


Mosqueteiro::~Mosqueteiro()
{
	delete(listaAnim);

	delete (arma);
	al_destroy_timer(timer_ataque);
	al_destroy_timer(timer_atacando);
	al_destroy_timer(timer_invuneravel);

	alvo = nullptr;
}


void Mosqueteiro::builderMosqueteiro(const int ax, const int ay, const bool aAtivo, Jogador* const pAlvo)
{
	posX = ax;
	posY = ay;
	velX = 0;
	velY = 0;
	ativo = aAtivo;

	vida = VIDA_MAX_MOSQ;
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
	if(dir) 
		pProj->builderProjetil(arma->getX(), arma->getY(), VEL_MAX_PROJ, true, PROJETIL_MOSQ, arma);
	else
		pProj->builderProjetil(arma->getX(), arma->getY(), -VEL_MAX_PROJ, true, PROJETIL_MOSQ, arma);
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