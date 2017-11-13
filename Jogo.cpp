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
	listaFases.defineNumJogadores(2);
	listaFases.defineJog(RAONI, 1);
	listaFases.defineJog(TECA, 2);
	listaFases.carregaFaseN(1);
}
