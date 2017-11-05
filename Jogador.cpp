#include "Jogador.h"

int Jogador::num_jogs = 0;

Jogador::Jogador()
{
	//MUDAR PARA SINGLETON O ESQUEMA DE CONSTRUTOR
	vida = VIDA_MAX_JOG;
	velMaxX = VEL_MAX_X_JOG;
	velMaxY = VEL_PULO;
	num_jogs++;
	chances = 3;
	fisica = true;
	if (num_jogs == 1)
		ID = JOGADOR1;
	else if (num_jogs == 2)
		ID = JOGADOR2;
}


Jogador::~Jogador()
{

}


void Jogador::builderJogador(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const int aVida, Arma* const pArma, const int aChances)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimy;
	ativo = aAtivo;
	vida = aVida;
	arma = pArma;
	chances = aChances;
}


void Jogador::atacar()
{
	ataque = true;
}


void Jogador::moverDir()
{
	if (velX < velMaxX)
		velX += (float)ACEL_X_PERS;
	if(velX > velMaxX)
		velX = velMaxX;
	dir = true;
}


void Jogador::moverEsq()
{
	if (velX > -velMaxX)
		velX -= (float)ACEL_X_PERS;
	if(velX < -velMaxX)
		velX = -velMaxX;
	dir = false;
}


void Jogador::pular()
{
	velY = VEL_PULO;
}


// para cordas
void Jogador::subir()
{

}

void Jogador::atualizar()
{
	posY -= velY;
	posX += velX;
	if (invuneravel)
	{
		if (al_get_timer_count(timer_invuneravel) >= 1)
		{
			invuneravel = false;
			al_stop_timer(timer_invuneravel);
		}
	}
	atualizaArma();
	// continuar
}


void Jogador::draw(const int aPosFaseX, const int aPosFaseY)
{
	if(invuneravel)
		al_draw_filled_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(255, 0, 255));
	else
		al_draw_filled_rectangle(posX- aPosFaseX, posY - aPosFaseY, posX + limX- aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(0, 255, 0));
	

}


const int Jogador::getChances()
{
	return chances;
}


void Jogador::setChances(const int aChances)
{
	chances = aChances;
}


const bool Jogador::getInvuneravel()
{
	return invuneravel;
}


void Jogador::setInvuneravel(const bool aInv)
{
	invuneravel = aInv;
}

void Jogador::initTimerInv()
{
	al_start_timer(timer_invuneravel);
	//para o jogador n�o come�ar invuner�vel
	al_set_timer_count(timer_invuneravel, 1);
}


void Jogador::tomaDano(const int aDano)
{
	vida -= aDano;
	invuneravel = true;
	//reseta o contador do timer
	al_set_timer_count(timer_invuneravel, 0);
	al_resume_timer(timer_invuneravel);
}


void Jogador::destroyTimerInv()
{
	al_destroy_timer(timer_invuneravel);
}


void Jogador::createTimers()
{
	timer_ataque = al_create_timer(PER_ATAQ_JOG);
	timer_invuneravel = al_create_timer(TEMP_INVUN);
}
