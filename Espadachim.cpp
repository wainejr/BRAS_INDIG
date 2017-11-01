#include "Espadachim.h"



Espadachim::Espadachim()
{
}


Espadachim::~Espadachim()
{
}


void Espadachim::builderEspadachim()
{
}


void Espadachim::mover()
{
	//VALOR DE DISTÂNCIA PARA PARAR DECIDO EMPIRICAMENTE
	if (posY > (alvo->getY()-alvo->getLimY()) && (posY-limY) < alvo->getY())
	{
		if (posX - 10 > (alvo->getX() + alvo->getLimX()))
		{
			if (velX > -velMaxX)
				velX--;
			else
				velX = -velMaxX;
		}
		else if ((posX + limX) < (alvo->getX() - 10))
		{
			if (velX < velMaxX)
				velX++;
			else
				velX = velMaxX;
		}
		else
			parar();
	}
	else
		parar();
}


void Espadachim::atacar()
{
}


void Espadachim::atualizar()
{
	mover();
	posX += velX;
	posY -= velY;
	atualizaArma();
}



void Espadachim::draw()
{
	al_draw_filled_rectangle(posX, posY, posX + limX, posY - limY, al_map_rgb(255, 0, 0));
}

