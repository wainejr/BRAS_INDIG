#pragma once
#include "Fase.h"
#include "vector"

using namespace std;

class ListaFases
{
private:
	vector<Fase*> fases;
	vector<Fase*>::iterator it;
	
public:
	//	FAZER UMA FUNÇÃO PARA INICIALIZAR AS OPÇÕES E TALS QUANDO
	//	CLICAR PARA INICIAR O JOGO
	ListaFases();
	~ListaFases();
	bool defineNumJogadores(const int aNumJogs);
	void carregaFaseN(const int aN);
	void campanha();
	void defineJog(Jogador* const pJog, const int aNum);
	void setDisplays(ALLEGRO_DISPLAY* const pDisplay);
	void addFase(Fase* const pFase);
	void anulaJogs();
};

