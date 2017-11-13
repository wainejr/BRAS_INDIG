#include "Fase.h"

Fase::Fase()
{

}


Fase::~Fase()
{
	
}

bool Fase::campanha = false;


int Fase::num_jogs = 0;


Jogador* Fase::jog1 = NULL;
Jogador* Fase::jog2 = NULL;


void Fase::initTimers()
{
	mapaFase.initTimers();
	al_start_timer(timer);
}


void Fase::criarTimers()
{
	mapaFase.criarTimers();
}


void Fase::setCampanha(const bool aCamp)
{
	campanha = aCamp;
}


const int Fase::getNumJogs()
{
	return num_jogs;
}


void Fase::setNumJogs(const int aNumJogs)
{
	num_jogs = aNumJogs;
}


Jogador* const Fase::getJog1()
{
	return jog1;
}


Jogador* const Fase::getJog2()
{
	return jog2;
}


void Fase::setJog1(Jogador* const pJog1)
{
	if (pJog1 != NULL && pJog1 != jog2)
		jog1 = pJog1;
}


void Fase::setJog2(Jogador* const pJog2)
{
	if (pJog2 != NULL && pJog2 != jog1)
		jog2 = pJog2;
}


void Fase::setFaseCompleta(const bool aCompleta)
{
	fase_completa = aCompleta;
}


const bool Fase::getFaseCompleta()
{
	return fase_completa;
}
