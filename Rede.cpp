#include "Rede.h"



Rede::Rede()
{
	posX = 0;
	posY = 0;
	limX = LIM_X_REDE;
	limY = LIM_Y_REDE;
	velX = 0;
	velMaxX = 0;
	velMaxY = VEL_MAX_REDE;
	fisica = true;
	ativo = false;
	ID = REDE;
	listaAnim = nullptr;

	dano = DANO_REDE;

	ativada = false;
	linha = nullptr;
}


Rede::~Rede()
{
	delete(listaAnim);

	delete(linha);
}


Corda* const Rede::getCorda()
{
	return linha;
}


void Rede::builderRede(const int ax, const int ay, const int aLinhaX, const int aLinhaY, const bool aAtivo)
{
	posX = ax;
	posY = ay;
	velY = 0;
	ativo = aAtivo;

	ativada = false;
	if (linha == nullptr)
	{
		Corda* pLinha = new Corda;
		linha = pLinha;
		linha->builderCorda(aLinhaX, aLinhaY, LIM_X_LINHA_REDE, LIM_Y_LINHA_REDE, true, false);
	}
	linha->setAtivo(true);
	/*
	linha->setEscalavel(false);
	linha->setLimX(LIM_X_LINHA_REDE);
	linha->setLimY(LIM_Y_LINHA_REDE);
	linha->setX(aLinhaX);
	linha->setY(aLinhaY);
	*/
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
		linha->draw(aPosFaseX, aPosFaseY);
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

void Rede::initTimer()
{
}

void Rede::createTimer()
{

}

void Rede::resetaTimer()
{
}

void Rede::stopTimers()
{
}

void Rede::resumeTimers()
{
}