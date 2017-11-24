#include "Plataforma.h"



Plataforma::Plataforma():Entidade(0, 0, 0, 0, PLATAFORMA, false)
{
	colisaoBaixo = false;
}

Plataforma::Plataforma(const bool aColisaoBaixo, const int aID, const int aPosX, const int aPosY, const int aLimX, const int aLimY):
	Entidade(0, 0, 0, 0, aID, false, aPosX, aPosY, aLimX, aLimY, false)
{
	colisaoBaixo = aColisaoBaixo;
}


Plataforma::~Plataforma()
{

}


void Plataforma::setColisaoBaixo(const bool aCol)
{
	colisaoBaixo = aCol;
}


const bool Plataforma::getColisaoBaixo()
{
	return colisaoBaixo;
}


void Plataforma::draw(const int aPosFaseX, const int aPosFaseY)
{
	if(colisaoBaixo)
		al_draw_filled_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(150, 150, 150));
	else
		al_draw_filled_rectangle(posX- aPosFaseX, posY- aPosFaseY, posX + limX- aPosFaseX, posY - limY- aPosFaseY, al_map_rgb(255, 255, 255));
	//	listaAnim->drawAnimacao(0, posX-aPosFaseX, posY-aPosFaseY);
}


void Plataforma::buildPlataforma(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const bool aColisaoBaixo)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimy;
	ativo = aAtivo;

	colisaoBaixo = aColisaoBaixo;
	if (listaAnim == nullptr) 
	{
		//listaAnim = gerListaAnim.listaAnimEnt(ID);
	}
}


void Plataforma::atualizar()
{
}
