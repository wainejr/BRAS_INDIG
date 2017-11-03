#include "Mosqueteiro.h"



Mosqueteiro::Mosqueteiro()
{
	ID = MOSQUETEIRO;
	fisica = true;
}


Mosqueteiro::~Mosqueteiro()
{
}


void Mosqueteiro::builderMosqueteiro(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const int aVida, Arma* const pArma)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimy;
	ativo = aAtivo;
	vida = aVida;
	arma = pArma;
}


void Mosqueteiro::mover()
{
}


void Mosqueteiro::atacar()
{
}


void Mosqueteiro::atualizar()
{
	posX += velX;
	posY -= velY;
	atualizaArma();
}


void Mosqueteiro::draw()
{
	al_draw_filled_rectangle(posX, posY, posX + limX, posY - limY, al_map_rgb(255, 0, 255));
}

Projetil* const Mosqueteiro::atirar(const int ax, const int ay)
{
	//	NAO ESQUECER DE DAR DELETE DEPOIS DE MUDAR 
	//	OU ESPECIFICAR O TAMANHO DOS PROJETEIS
	Projetil* pProj = new Projetil();
	pProj->builderProjetil(posX, posY, 1, 1, VEL_MAX_PROJ*(ax-posX) / sqrt((ax- posX)*(ax- posX) + (ay-posY)*(ay-posY)), VEL_MAX_PROJ*(-(ay - posY)) / sqrt((ax - posX)*(ax - posX) + (ay - posY)*(ay - posY)), true);
	return pProj;
}