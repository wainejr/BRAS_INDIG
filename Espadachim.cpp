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
	//VALOR DE DISTÂNCIA PARA PARAR DECIDIDO EMPIRICAMENTE
	if ((posY) > (alvo->getY()-alvo->getLimY()-DIFF_PIXELS_SEGUIR_Y) && (posY-limY) < (alvo->getY()+DIFF_PIXELS_SEGUIR_Y))
	{
		if (posX - DIFF_PIXELS_PARAR_X > (alvo->getX() + alvo->getLimX()))
		{
			if (velX > -velMaxX)
				velX-= (float) ACEL10_X_PERS / 10;
			else
				velX = -velMaxX;
		}
		else if ((posX + limX) < (alvo->getX() - DIFF_PIXELS_PARAR_X))
		{
			if (velX < velMaxX)
				velX+= (float)ACEL10_X_PERS / 10;
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

