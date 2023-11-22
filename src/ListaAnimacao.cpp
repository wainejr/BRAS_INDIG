#include "ListaAnimacao.h"



ListaAnimacao::ListaAnimacao()
{
}


ListaAnimacao::~ListaAnimacao()
{
	Animacao* pAnim;
	while (listaSprites.numObjs() > 0)
	{
		pAnim = listaSprites.objI(0);
		listaSprites.retirarObj(pAnim);
	}
}


void ListaAnimacao::addAnimacao(Animacao* pAnim)
{
	if (pAnim != nullptr)
	{
		if (!temIDigual(pAnim))
			listaSprites.addObj(pAnim);
	}
}



void ListaAnimacao::drawAnimacao(const int aID, const int aPosX, const int aPosY)
{
	Animacao* pAnim;
	for (int i = 0; i < listaSprites.numObjs(); i++)
	{
		pAnim = listaSprites.objI(i);
		if (pAnim->getID() == aID)
		{
			pAnim->draw(aPosX, aPosY);
		}
		else
			pAnim->resetaAnim();
	}
}


void ListaAnimacao::resetaAnims()
{
	Animacao* pAnim;
	for (int i = 0; i < listaSprites.numObjs(); i++)
	{
		pAnim = listaSprites.objI(i);
		pAnim->resetaAnim();
	}
}


bool ListaAnimacao::temIDigual(Animacao* const pAnim)
{
	Animacao* pAux;
	for (int i = 0; i < listaSprites.numObjs(); i++)
	{
		pAux = listaSprites.objI(i);
		if (pAnim->getID() == pAux->getID())
			return true;
	}
	return false;
}


void ListaAnimacao::stopTimers()
{
	Animacao* pAnim;
	for (int i = 0; i < listaSprites.numObjs(); i++)
	{
		pAnim = listaSprites.objI(i);
		pAnim->stopTimer();
	}
}


void ListaAnimacao::resumeTimers()
{
	Animacao* pAnim;
	for (int i = 0; i < listaSprites.numObjs(); i++)
	{
		pAnim = listaSprites.objI(i);
		pAnim->resumeTimer();
	}
}


void ListaAnimacao::drawDeAte_X(const int aID, const int aPosX, const int aPosY, const int aPosLimX)
{
	Animacao* pAnim;
	for (int i = 0; i < listaSprites.numObjs(); i++)
	{
		pAnim = listaSprites.objI(i);
		if (pAnim->getID() == aID)
		{
			pAnim->drawDeAte_X(aPosX, aPosY, aPosLimX);
		}
		else
			pAnim->resetaAnim();
	}
}


void ListaAnimacao::drawDeAte_Y(const int aID, const int aPosX, const int aPosY, const int aPosLimY)
{
	Animacao* pAnim;
	for (int i = 0; i < listaSprites.numObjs(); i++)
	{
		pAnim = listaSprites.objI(i);
		if (pAnim->getID() == aID)
		{
			pAnim->drawDeAte_Y(aPosX, aPosY, aPosLimY);
		}
		else
			pAnim->resetaAnim();
	}
}

void ListaAnimacao::drawAnimacaoInver(const int aID, const int aPosX, const int aPosY)
{
	Animacao* pAnim;
	for (int i = 0; i < listaSprites.numObjs(); i++)
	{
		pAnim = listaSprites.objI(i);
		if (pAnim->getID() == aID)
		{
			pAnim->drawInvertido(aPosX, aPosY);
			
		}
		else
			pAnim->resetaAnim();
	}
}

Animacao * const ListaAnimacao::getAnimacaoID(const int aID)
{
	Animacao* pAnim;
	for (int i = 0; i < listaSprites.numObjs(); i++)
	{
		pAnim = listaSprites.objI(i);
		if (pAnim->getID() == aID)
		{
			return pAnim;
		}
	}
	return nullptr;
}
