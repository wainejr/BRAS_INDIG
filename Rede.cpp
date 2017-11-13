#include "Rede.h"



Rede::Rede()
{
	posX = 0;
	posY = 0;
	limX = LIM_X_REDE;
	limY = LIM_Y_REDE;
	velX = 0;
	velY = 0;
	fisica = true;
	ativo = false;
	velMaxX = 0;
	velMaxY = 0;
	ID = REDE;

	dano = DANO_REDE;

	ativada = false;
	linha = NULL;
}


Rede::~Rede()
{
	delete(linha);
}


Corda* const Rede::getCorda()
{
	return linha;
}


void Rede::setCorda(Corda* const pCorda)
{
	if(pCorda != NULL)
		linha = pCorda;
}


void Rede::builderRede(const int ax, const int ay, const int aLinhaX, const int aLinhaY, const bool aAtivo)
{
	posX = 0;
	posY = 0;
	limX = LIM_X_REDE;
	limY = LIM_Y_REDE;
	velX = 0;
	velY = 0;
	fisica = true;
	ativo = false;
	velMaxX = 0;
	velMaxY = 0;
	ID = ARMADILHA;

	dano = DANO_ARMD;

	ativada = false;
	if (linha == NULL)
	{
		Corda* pLinha = new Corda;
		linha = pLinha;
		linha->setEscalavel(false);
		linha->setLimX(LIM_X_LINHA_REDE);
		linha->setLimY(LIM_Y_LINHA_REDE);
	}
	linha->setEscalavel(false);
	linha->setLimX(LIM_X_LINHA_REDE);
	linha->setLimY(LIM_Y_LINHA_REDE);
	linha->setX(aLinhaX);
	linha->setY(aLinhaY);

}


void Rede::ativar()
{
	if (!ativada)
	{
		ativada = true;
		linha->setAtivo(false);
	}
}


const bool Rede::getAtivada()
{
	return ativada;
}


void Rede::draw(const int aPosFaseX, const int aPosFaseY)
{
	al_draw_filled_rectangle(posX - aPosFaseX, posY - aPosFaseY, posX + limX - aPosFaseX, posY - limY - aPosFaseY, al_map_rgb(255, 255, 255));
	if(linha->getAtivo())
		al_draw_filled_rectangle(linha->getX() - aPosFaseX, linha->getY() - aPosFaseY, linha->getX() + linha->getLimX() - aPosFaseX, linha->getY() - linha->getLimY() - aPosFaseY, al_map_rgb(255, 0, 0));
}


void Rede::atualizar()
{
	if (ativada)
	{
		if (velY > -velMaxY)
			velY -= ACEL_REDE;
		else
			velY = -velMaxY;

		posY -= velY;
	}
}


void Rede::reset(const int ax, const int ay, const bool aAtivo)
{
	posX = ax;
	posY = ay;
	velX = 0;
	velY = 0;
	ativo = aAtivo;

	ativada = false;
}