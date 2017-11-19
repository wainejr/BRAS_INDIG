#include "FaseFinal.h"



FaseFinal::FaseFinal()
{
	numEntidades();
	alocaEntidades();
}


FaseFinal::~FaseFinal()
{
	deletaEntidades();
	anulaJogs();
	if (carregouAllegro)
	{
		al_destroy_timer(timer);
		al_destroy_font(arial18);
		al_destroy_event_queue(queue);
	}
}

void FaseFinal::restart() {}
void FaseFinal::initFase() {}