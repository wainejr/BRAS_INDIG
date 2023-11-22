#pragma once
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_font.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class gerenciaPontuacoes
{
private:
	void organizaIDs();
	void organizaPont();
	ALLEGRO_BITMAP* fundo_salvar;
	ALLEGRO_FONT* font;
	bool carregou_fundo;
	void carregaFundo();
	void organiza();

	class Pontuacao
	{
	private:
		float pont;
		int ID;
	public:
		Pontuacao();
		Pontuacao(int aID, float aPont);
		~Pontuacao();
		void setID(const int aID);
		const int getID();
		const float getPontos();
		void setPontuacao(const float aPont);
	};

	vector<Pontuacao*> pontuacoes;

public:
	
	gerenciaPontuacoes();
	~gerenciaPontuacoes();
	void salvarPont(float const pPont, const int aN);

	void setFonte(ALLEGRO_FONT* const pFont);
	void desenhaPont(const int aID, const int posX, const int posY);
	void deleta();
	void salvaTxt();
	void carregaTxt();
};

