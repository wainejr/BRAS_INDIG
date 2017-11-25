#pragma once
#include "Animacao.h"
#include "Lista.h"
class ListaAnimacao
{
private:
	Lista <Animacao*> listaSprites;
	bool temIDigual(Animacao* const pAnim);
public:
	ListaAnimacao();
	~ListaAnimacao();
	void addAnimacao(Animacao* pAnim);
	void drawAnimacao(const int aID, const int aPosX, const int aPosY);
	void resetaAnims();
	void stopTimers();
	void resumeTimers();
	void drawDeAte_X(const int aID, const int aPosX, const int aPosY, const int aPosLimX);
	void drawDeAte_Y(const int aID, const int aPosX, const int aPosY, const int aPosLimY);
	void drawAnimacaoInver(const int aID, const int aPosX, const int aPosY);
	Animacao* const getAnimacaoID(const int aID);
};

