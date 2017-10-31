#include "Jogador.h"



Jogador::Jogador()
{
	chances = 0;
}


Jogador::~Jogador()
{
}


void Jogador::atacar()
{
	//arma->setX(arma->getX()+limX);
}

void Jogador::moverDir()
{
	velX++;
}

void Jogador::moverEsq()
{
	velX--;
}

void Jogador::pular()
{
}


const int Jogador::getChances()
{
	return chances;
}


void Jogador::setChances(const int aChances)
{
	chances = aChances;
}


// para cordas
void Jogador::subir()
{
}


void Jogador::draw()
{
	al_draw_filled_rectangle(posX, posY, posX + limX, posY - limY, al_map_rgb(0, 255, 0));
}


const bool Jogador::getInvuneravel()
{
	return invuneravel;
}


void Jogador::setInvuneravel(const bool aInv)
{
	invuneravel = aInv;
}


void Jogador::builderJogador()
{
}
