#pragma once
#include "Fase.h"


class Fase1 :
	public Fase
{
private:
	///	PARA ALOCAMENTO E INICIALIZAÇÃO DA FASE
	///	TALVEZ FAZER AS ARMAS SEREM CRIADAS NO BUILDER DOS INIMIGOS E JOGADORES
	void execFase();
	void initObjs();
	void initAllegroObjs();
	void restart();

	//	MOVER PARA FASE.H
	void numEntidades();
	void alocaEntidades();
	void deletaEntidades();
	void buildEntidades();
	void addEntidades();

	//FUNÇÃO PARA TESTES RETIRAR DEPOIS
	void imprimeVida();
	
public:
	Fase1();
	~Fase1();
	void initFase();
};

