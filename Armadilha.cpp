#include "Armadilha.h"



Armadilha::Armadilha()
{
	ID = ARMADILHA;
	acionada = false;
}


Armadilha::~Armadilha()
{
}


void Armadilha::builderArmadilha(const int ax, const int ay, const int aLimX, const int aLimY, const bool aAtivo, const int aDano)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimY;
	ativo = aAtivo;
	dano = aDano;
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
		if (al_get_timer_count(timer_acionada) >= 2)
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
