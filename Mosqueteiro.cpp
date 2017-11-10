#include "Mosqueteiro.h"



Mosqueteiro::Mosqueteiro()
{
	ID = MOSQUETEIRO;
	fisica = true;
}


Mosqueteiro::~Mosqueteiro()
{
}


void Mosqueteiro::builderMosqueteiro(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const int aVida, Arma* const pArma)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimy;
	ativo = aAtivo;
	vida = aVida;
	if(pArma != NULL)
		arma = pArma;
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
	if (!atacando)
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
		pProj->builderProjetil(arma->getX(), arma->getY(), 3, 3, VEL_MAX_PROJ, 0 , true);
	else
		pProj->builderProjetil(arma->getX(), arma->getY(), 3, 3, -VEL_MAX_PROJ, 0, true);
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
