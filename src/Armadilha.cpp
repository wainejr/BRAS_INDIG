#include "Armadilha.h"



Armadilha::Armadilha():Obstaculo(DANO_ARMD, ARMADILHA, LIM_X_ARMD, LIM_Y_ARMD)
{
	acionada = false;
	timer_acionada = nullptr;
	criouTimer = false;
	desarmou = false;
}


Armadilha::~Armadilha()
{
	al_destroy_timer(timer_acionada);
}


void Armadilha::buildArmadilha(const int ax, const int ay, const bool aAtivo)
{
	posX = ax;
	posY = ay;
	velX = 0;
	velY = 0;
	ativo = aAtivo;

	acionada = false;
	if (listaAnim == nullptr)
		listaAnim = gerListaAnim.listaAnimEnt(ID);
	if (!criouTimer)
	{
		createTimer();
	}
	desarmou = false;
}


void Armadilha::draw(const int aPosFaseX, const int aPosFaseY)
{
	if (!acionada)
	{
		listaAnim->drawAnimacao(0, posX - aPosFaseX	+ limX/2, posY - aPosFaseY);
		//al_draw_filled_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX - aPosFaseX + limX, posY - aPosFaseY - limY, al_map_rgb(255, 255, 0));
	}
	else
	{
		listaAnim->drawAnimacao(1, posX - aPosFaseX + limX/2, posY - aPosFaseY);
		//al_draw_filled_rectangle(posX - aPosFaseX, posY - aPosFaseY - 10, posX - aPosFaseX + limX, posY - aPosFaseY - limY, al_map_rgb(255, 0, 0));
	}
}


void Armadilha::atualizar()
{
	if (acionada)
	{
		if (al_get_timer_count(timer_acionada) >= 1)
		{
			acionada = false;
			desarmou = true;
			al_stop_timer(timer_acionada);
			al_set_timer_count(timer_acionada, 0);
		}
	}
}


void Armadilha::acionar()
{
	if (!acionada)
	{
		acionada = true;
		al_resume_timer(timer_acionada);
		al_set_timer_count(timer_acionada, 0);
	}
}


const bool Armadilha::getAcionada()
{
	return acionada;
}


void Armadilha::setAcionada(const bool aAcionada)
{
	acionada = aAcionada;
}

void Armadilha::initTimer()
{
	al_start_timer(timer_acionada);
	// o timer s� ser� resumido quando a armadilha for acionada
	al_stop_timer(timer_acionada);
}

void Armadilha::createTimer()
{
	timer_acionada = al_create_timer(TEMP_ACION_ARMD);
	criouTimer = true;
}

void Armadilha::resetaTimer()
{
	al_set_timer_count(timer_acionada, 0);
	al_stop_timer(timer_acionada);
}


void Armadilha::stopTimers()
{
	al_stop_timer(timer_acionada);
}

void Armadilha::resumeTimers()
{
	if(acionada)
		al_resume_timer(timer_acionada);
}

const bool Armadilha::getDesarmou()
{
	return desarmou;
}
