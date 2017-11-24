#include "Rede.h"



Rede::Rede():Obstaculo(DANO_REDE, REDE, LIM_X_REDE, LIM_Y_REDE, 0, 0, 0, 0, 0, VEL_SUBIDA, false, false)
{
	ativada = false;
	linha = nullptr;
}


Rede::~Rede()
{
	delete(linha);
}


Corda* const Rede::getCorda()
{
	return linha;
}


void Rede::buildRede(const int ax, const int ay, const int aLinhaX, const int aLinhaY, const bool aAtivo)
{
	posX = ax;
	posY = ay;
	velY = 0;
	ativo = aAtivo;

	ativada = false;
	if (linha == nullptr)
	{
		Corda* pLinha = new Corda(false);
		linha = pLinha;
		linha->buildCorda(aLinhaX, aLinhaY, LIM_X_LINHA_REDE, LIM_Y_LINHA_REDE, true, false);
	}
	linha->setAtivo(true);
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