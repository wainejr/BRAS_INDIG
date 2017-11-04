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
	if (alvo->getX() > posX)
		dir = false;
	else
		dir = true;
	atualizaArma();
}


void Mosqueteiro::draw(const int aPosFaseX, const int aPosFaseY)
{
	al_draw_filled_rectangle(posX-aPosFaseX, posY-aPosFaseY, posX + limX-aPosFaseX, posY - limY-aPosFaseY, al_map_rgb(255, 0, 255));
}

Projetil* const Mosqueteiro::atirar()
{
	//	OU ESPECIFICAR O TAMANHO DOS PROJETEIS
	Projetil* pProj = new Projetil();
	pProj->setID(PROJETIL_INI);
	float cadj = alvo->getX()+alvo->getLimX()/2 - arma->getX();
	float coposto = -(alvo->getY()-alvo->getLimY()/2 - arma->getY());
	float hip = sqrt(cadj*cadj + coposto*coposto);
	pProj->builderProjetil(arma->getX(), arma->getY(), 1, 1, VEL_MAX_PROJ*cadj / hip, VEL_MAX_PROJ*coposto / hip, true);
	pProj->setArmaProj(arma);
	return pProj;
}