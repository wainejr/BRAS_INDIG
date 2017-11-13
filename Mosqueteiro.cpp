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
	arma = NULL;
	dir = true;
	podeAtacar = true;
	atacando = false;
	invuneravel = false;
	timer_ataque = NULL;
	timer_atacando = NULL;
	timer_invuneravel = NULL;

	alvo = NULL;
}


Mosqueteiro::~Mosqueteiro()
{
}


void Mosqueteiro::builderMosqueteiro(const int ax, const int ay, const bool aAtivo, Jogador* const pAlvo)
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
	if (arma == NULL)
	{
		Arma* pArma = constroiArma();
		if (pArma != NULL)
			arma = pArma;
	}

	if (pAlvo != NULL)
	{
		alvo = pAlvo;
	}
}


void Mosqueteiro::mover()
{
	parar();
}


void Mosqueteiro::atacar()
{

}


void Mosqueteiro::atualizar()
{
	mover();
	posX += velX;
	posY -= velY;
	if (!atacando && alvo != NULL)
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
	pProj->setID(PROJETIL_INI);
	if(dir) 
		pProj->builderProjetil(arma->getX(), arma->getY(), VEL_MAX_PROJ, true, PROJETIL_INI, arma);
	else
		pProj->builderProjetil(arma->getX(), arma->getY(), -VEL_MAX_PROJ, true, PROJETIL_INI, arma);
	pProj->setArmaProj(arma);
	atacando = true;
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

const bool Mosqueteiro::persPodeAtacar()
{

	if (velY == 0 && al_get_timer_count(timer_ataque) >= 1 && !atacando)
	{
		if (alvo->getY() > posY - limY && alvo->getY() - alvo->getLimY() < posY)
			return true;
	}
	return false;
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