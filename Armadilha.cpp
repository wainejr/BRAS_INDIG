#include "Armadilha.h"



Armadilha::Armadilha()
{
	posX = 0;
	posY = 0;
	limX = LIM_X_ARMD;
	limY = LIM_Y_ARMD;
	velX = 0;
	velY = 0;
	fisica = true;
	ativo = false;
	velMaxX = 0;
	velMaxY = 0;
	ID = ARMADILHA;

	dano = DANO_ARMD;

	acionada = false;
	timer_acionada = nullptr;
}


Armadilha::~Armadilha()
{
}


void Armadilha::builderArmadilha(const int ax, const int ay, const bool aAtivo)
{
	posX = ax;
	posY = ay;
	velX = 0;
	velY = 0;
	ativo = aAtivo;

	acionada = false;
}


void Armadilha::draw(const int aPosFaseX, const int aPosFaseY)
{
	if(!acionada)
		al_draw_filled_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX - aPosFaseX + limX, posY - aPosFaseY - limY, al_map_rgb(255, 255, 0));
	else
		al_draw_filled_rectangle(posX - aPosFaseX, posY - aPosFaseY- 10, posX - aPosFaseX + limX, posY - aPosFaseY - limY, al_map_rgb(255, 0, 0));
}


void Armadilha::atualizar()
{
	if (acionada)
	{
		if (al_get_timer_count(timer_acionada) >= 1)
		{
			ativo = false;
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
	// o timer só será resumido quando a armadilha for acionada
	al_stop_timer(timer_acionada);
}

void Armadilha::createTimer()
{
	timer_acionada = al_create_timer(TEMP_ACION_ARMD);
}


void Armadilha::reset(const int ax, const int ay, const bool aAtivo)
{
	posX = ax;
	posY = ay;
	velX = 0;
	velY = 0;
	ativo = aAtivo;

	acionada = false;
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
	al_resume_timer(timer_acionada);
}