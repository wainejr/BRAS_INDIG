#pragma once
#include "Fase.h"
#include "gerenciaPontuacoes.h"

class FaseAnin;

class ListaFases
{
private:
	class FaseAnin // Fase aninhada
	{
	private:
		Fase* curr;
		FaseAnin* proxFase;
		FaseAnin* antFase;
	public:
		FaseAnin();
		~FaseAnin();
		void setProx(FaseAnin* const pAninFase);
		void setAnt(FaseAnin* const pAninFase);
		void setCurr(Fase* const pFase);
		FaseAnin* const getProx();
		FaseAnin* const getAnt();
		Fase* const getFase();
		const bool isThereProx();
	};
	FaseAnin* topo;
	FaseAnin* ultimo;
	gerenciaPontuacoes* gerPont;
public:
		
	ListaFases();
	~ListaFases();
	bool defineNumJogadores(const int aNumJogs);
	void carregaFaseN(const int aN);
	void campanha();
	void defineJog(Jogador* const pJog, const int aNum);
	void setDisplays(ALLEGRO_DISPLAY* const pDisplay);
	void addFaseIni(Fase* const pFase);
	void anulaJogs();
	void setGerPont(gerenciaPontuacoes* const pGer);
};

