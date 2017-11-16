#include "ListaAnimacao.h"



ListaAnimacao::ListaAnimacao()
{
}


ListaAnimacao::~ListaAnimacao()
{
	while (listaSprites.numObjs() > 0)
	{
		listaSprites.objI(0)->~Animacao();
		delete(listaSprites.objI(0));
	}
}


void ListaAnimacao::addAnimacao(Animacao* pAnim)
{
	if (pAnim != nullptr)
	{
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
