#include "Jogador.h"

int Jogador::num_jogs = 0;

Jogador::Jogador()
{
	//MUDAR PARA SINGLETON O ESQUEMA DE CONSTRUTOR
	velMaxX = VEL_MAX_X_JOG;
	velMaxY = VEL_PULO;
	num_jogs++;
	chances = 0;
}


Jogador::~Jogador()
{

}


void Jogador::builderJogador()
{

}


void Jogador::atacar()
{
	
}


void Jogador::moverDir()
{
	if (velX < velMaxX)
		velX+=(float) ACEL10_X_PERS/10;
	if(velX > velMaxX)
		velX = velMaxX;
	dir = true;
}


void Jogador::moverEsq()
{
	if (velX > -velMaxX)
		velX-= (float) ACEL10_X_PERS / 10;
	if(velX < -velMaxX)
		velX = -velMaxX;
	dir = false;
}


void Jogador::pular()
{
	if (velY == 0) 
	{
		velY = VEL_PULO;
	}
}


// para cordas
void Jogador::subir()
{

}

void Jogador::atualizar()
{
	atualizaArma();
	posY -= velY;
	posX += velX;
	// continuar
}


void Jogador::draw()
{
	al_draw_filled_rectangle(posX, posY, posX + limX, posY - limY, al_map_rgb(0, 255, 0));
}


const int Jogador::getChances()
{
	return chances;
}


void Jogador::setChances(const int aChances)
{
	chances = aChances;
}


const bool Jogador::getInvuneravel()
{
	return invuneravel;
}


void Jogador::setInvuneravel(const bool aInv)
{
	invuneravel = aInv;
}


