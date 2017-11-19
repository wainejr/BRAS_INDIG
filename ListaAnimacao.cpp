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
		delete(pAnim);
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


ListaAnimacao* const ListaAnimacao::copiaListaAnim()
{
	ListaAnimacao* pListaAnim = new ListaAnimacao;
	Animacao* pAnim;
	for (int i = 0; i < listaSprites.numObjs(); i++)
	{
		pAnim = listaSprites.objI(i);
		if (pAnim != nullptr)
		{
			pListaAnim->addAnimacao(pAnim->copiaAnimacao());
		}
	}
	return pListaAnim;
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
