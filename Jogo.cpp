#include "Jogo.h"

Jogo::Jogo()
{

	exec();
}


Jogo::~Jogo()
{
	///destroyObjs();
	///destroyAllegroObjs();
}


void Jogo::exec()
{
	fasePrototipo.initFase();
}
