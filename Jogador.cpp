#include "Jogador.h"

int Jogador::num_jogs = 0;

Jogador::Jogador()
{
	//MUDAR PARA SINGLETON O ESQUEMA DE CONSTRUTOR
	velMaxX = VEL_MAX_X_JOG;
	velMaxY = VEL_PULO;
	num_jogs++;
	chances = 3;
	fisica = true;
	if (num_jogs == 1)
		ID = JOGADOR1;
	else if (num_jogs == 2)
		ID = JOGADOR2;
}


Jogador::~Jogador()
{

}


void Jogador::builderJogador(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const int aVida, Arma* const pArma, const int aChances)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimy;
	ativo = aAtivo;
	vida = aVida;
	arma = pArma;
	chances = aChances;
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
	velY = VEL_PULO;
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


void Jogador::draw(const int aPosFaseX, const int aPosFaseY)
{
	al_draw_filled_rectangle(posX- aPosFaseX, posY - aPosFaseY, posX + limX- aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(0, 255, 0));
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


