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
	if (colisaoBaixo)
	{
		//	esses numeros vem das sprites da plataforma
		if(limY <= 30)
			listaAnim->drawDeAte_X(0, posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX);
		else
		{
			Animacao* pAux = listaAnim->getAnimacaoID(0);
			int alt1 = pAux->getAlt();
			listaAnim->drawDeAte_X(0, posX - aPosFaseX, posY - aPosFaseY-limY+pAux->getAlt(), posX + limX - aPosFaseX);
			pAux = listaAnim->getAnimacaoID(1);
			for (int i = 1; limY - i *  pAux->getAlt() > 0; i++)
			{
				listaAnim->drawDeAte_X(1, posX - aPosFaseX, posY + alt1 - aPosFaseY - limY + i * pAux->getAlt(), posX + limX - aPosFaseX);
			}
			listaAnim->drawDeAte_X(1, posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX);
		}
	}
	else
	{
		al_draw_filled_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(255, 255, 255));
	}
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
		listaAnim = gerListaAnim.listaAnimEnt(ID);
	}
}


void Plataforma::atualizar()
{
}
