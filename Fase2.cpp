#include "Fase2.h"



Fase2::Fase2()
{
}


Fase2::~Fase2()
{
	if (carregouAllegro)
	{
		al_destroy_timer(timer);
		al_destroy_font(arial18);
		al_destroy_event_queue(queue);
	}
}

void Fase2::restart(){}
void Fase2::initFase(){}