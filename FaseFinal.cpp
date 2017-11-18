#include "FaseFinal.h"



FaseFinal::FaseFinal()
{
}


FaseFinal::~FaseFinal()
{
	if (carregouAllegro)
	{
		al_destroy_timer(timer);
		al_destroy_font(arial18);
		al_destroy_event_queue(queue);
	}
}

void FaseFinal::restart() {}
void FaseFinal::initFase() {}