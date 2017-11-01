#include "Jogador.h"

int Jogador::num_jogs = 0;

Jogador::Jogador()
{
	//MUDAR PARA SINGLETON O ESQUEMA DE CONSTRUTOR
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
		velX++;
	if(velX > velMaxX)
		velX = velMaxX;
	dir = true;
}


void Jogador::moverEsq()
{
	if (velX > -velMaxX)
		velX--;
	else
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


// recebe como parâmetro a aceleração de vY
void Jogador::cair(const float acAt)
{
	//A VELOCIDADE ´MÁXIMA DE CAÍDA É A MESMA DO PULO
	if (velY > -VEL_PULO)
		velY -= acAt;
	if (velY < -VEL_PULO)
		velY = -VEL_PULO;
}


void Jogador::parar()
{
	if (velX != 0) {
		if (velX > 0 && velX > 1)
			velX--;
		else if (velX > 0 && velX < 1)
			velX = 0;
		else if (velX < 0 && velX < -1)
			velX++;
		else if (velX < 0 && velX > -1)
			velX = 0;
	}
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


