#include "Plataforma.h"



Plataforma::Plataforma()
{
	posX = 0;
	posY = 0;
	limX = 0;
	limY = 0;
	velX = 0;
	velY = 0;
	fisica = false;
	ativo = false;
	velMaxX = 0;
	velMaxY = 0;
	ID = PLATAFORMA;
	listaAnim = nullptr;

	colisaoBaixo = false;
}


Plataforma::~Plataforma()
{
	delete(listaAnim);
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
	listaAnim->drawAnimacao(0, posX-aPosFaseX, posY-aPosFaseY);
}


void Plataforma::builderPlataforma(const int ax, const int ay, const int aLimX, const int aLimy, const bool aAtivo, const bool aColisaoBaixo)
{
	posX = ax;
	posY = ay;
	limX = aLimX;
	limY = aLimy;
	ativo = aAtivo;

	colisaoBaixo = aColisaoBaixo;
	if (listaAnim == nullptr)
		listaAnim = gerListaAnim.listaAnimEnt(ID);
}


void Plataforma::atualizar()
{
}
