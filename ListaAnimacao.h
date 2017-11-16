#pragma once
#include "Animacao.h"
#include "Lista.h"
class ListaAnimacao
{
private:
	Lista <Animacao*> listaSprites;
public:
	ListaAnimacao();
	~ListaAnimacao();
	void addAnimacao(Animacao* pAnim);
	void drawAnimacao(const int aID, const int aPosX, const int aPosY);
	ListaAnimacao* const copiaListaAnim();
	void resetaAnims();
};

